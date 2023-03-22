#include "examplemodel.h"

#include <QColor>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

ExampleModel::ExampleModel(QObject *parent) : QAbstractTableModel(parent) {}

void ExampleModel::fillDataTableFromFile(
    QString path) {  // заполняем таблицу из датасета
    QFile inputFile(path);
    inputFile.open(QFile::ReadOnly |
                   QFile::Text);  //файл открыт на чтение и в нем чтение

    QTextStream inputStream(&inputFile);

    QString firstline = inputStream.readLine();  // читаем первую строку
    if (_headerList.size() == 0)  //если нет заголовка, то создаем из файла
        for (QString &item : firstline.split(",")) _headerList.append(item);

    while (!inputStream.atEnd()) {  // добавляем строки из файла в таблицу
        QString line = inputStream.readLine();

        QList<QVariant> dataRow;
        int columnIdx = 0;
        for (QString &item : line.split(",")) {
            // случаи с цветами
            if (columnIdx == 1 || columnIdx == 2 || columnIdx == 3 ||
                columnIdx == 4 || columnIdx == 5)
                dataRow.append(QColor(item));
            // случаи с процентами
            else if (columnIdx == 6 || columnIdx == 7 || columnIdx == 8 ||
                     columnIdx == 9 || columnIdx == 10)
                dataRow.append(item.toInt());
            else
                dataRow.append(item);  // только случай filename

            ++columnIdx;
        }
        _dataTable.append(dataRow);
    }
    inputFile.close();
}

void ExampleModel::saveDataTableToFile(QString path) {
    QFile outputFile(path);
    outputFile.open(QFile::WriteOnly | QFile::Text);
    QTextStream outputStream(&outputFile);

    bool first = true;
    for (QString &item : _headerList) {  // запись хедера в файл
        if (first) {
            outputStream << item;
            first = false;
        } else {
            outputStream << ",";
            outputStream << item;
        }
    }
    outputStream << "\n";

    for (QList<QVariant> &row : _dataTable) {  // запись строк в файл
        bool first = true;
        for (QVariant &item : row) {
            if (first) {
                outputStream << item.toString();
                first = false;
            } else {
                outputStream << ",";
                outputStream << item.toString();
            }
        }
        outputStream << "\n";
    }

    outputFile.close();
}

int ExampleModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) return 0;

    return _dataTable.size();
}

int ExampleModel::columnCount(const QModelIndex &parent) const {
    if (parent.isValid()) return 0;

    if (_dataTable.empty()) {
        return 0;
    }

    return _dataTable[0].size();
}

QVariant ExampleModel::headerData(int section, Qt::Orientation orientation,
                                  int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        return _headerList[section];
    }
    return QVariant();
}

void ExampleModel::changeCheckBox(bool value) { checkBoxColor = value; }

QVariant ExampleModel::data(const QModelIndex &index,
                            int role) const {  // default function
    if (!index.isValid()) return QVariant();
    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        return _dataTable[row][col];
    }
    if (role == Qt::BackgroundRole && checkBoxColor)
        if (col == 1 or col == 2 or col == 3 or col == 4 or col == 5)
            return (QBrush(QColor(_dataTable[row][col].toString())));

    return QVariant();
}

bool ExampleModel::setData(const QModelIndex &index, const QVariant &value,
                           int role) {  // изменения даннных
    if (data(index, role) != value) {
        int row = index.row();
        int col = index.column();

        if (isDataRight(col, value)) {  // checking for right input
            if (col == 1 or col == 2 or col == 3 or col == 4 or col == 5)
                _dataTable[row][col] = value.toString().toLower();
            else if (col == 0)
                _dataTable[row][col] = value.toString();
            else
                _dataTable[row][col] = value.toInt();
            emit dataChanged(index, index, {role});
            return true;
        }
    }
    return false;
}

Qt::ItemFlags ExampleModel::flags(
    const QModelIndex &index) const {  // def function
    if (!index.isValid()) return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool ExampleModel::isDataRight(const int col, const QVariant &value) {
    if (col == 0 and value.toString().size() > 4) {
        QString file_name = value.toString();
        int size = file_name.size();
        if (file_name[size - 4] == "." and file_name[size - 3] == "j" and
            file_name[size - 2] == "p" and file_name[size - 1] == "g")
            return true;
    } else if (col == 1 or col == 2 or col == 3 or col == 4 or col == 5) {
        if (QColor(value.toString()).isValid()) return true;
    } else if (col == 6 or col == 7 or col == 8 or col == 9 or col == 10)
        if (value.userType() == QMetaType::Int and value.toInt() >= 0 and
            value.toInt() < 101) {
            return true;
        }

    QMessageBox warning;
    warning.setWindowTitle("Warning");
    warning.setText("Input is not correct, return previous value");
    warning.exec();
    return false;
}

void ExampleModel::appendRow(const QList<QVariant> &row) {  // new row
    size_t newRowNumber = rowCount();
    beginInsertRows(QModelIndex(), newRowNumber, newRowNumber);
    _dataTable.append(row);
    endInsertRows();
}

void ExampleModel::createHeader() {  // создает хедр, так как знаем хедр
    _headerList.clear();
    {
        _headerList.push_back("filename");
        _headerList.push_back("color1");
        _headerList.push_back("color2");
        _headerList.push_back("color3");
        _headerList.push_back("color4");
        _headerList.push_back("color5");
        _headerList.push_back("perc1");
        _headerList.push_back("perc2");
        _headerList.push_back("perc3");
        _headerList.push_back("perc4");
        _headerList.push_back("perc5");
    }
}

void ExampleModel::removeRow(size_t idx) {  // delete row
    beginRemoveRows(QModelIndex(), idx, idx);
    _dataTable.removeAt(idx);
    endRemoveRows();
}
