#ifndef EXAMPLEMODEL_H
#define EXAMPLEMODEL_H

#include <QAbstractTableModel>

class ExampleModel : public QAbstractTableModel {
    Q_OBJECT

   public:
    bool checkBoxColor = false;

    explicit ExampleModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    QVariant data(const QModelIndex &index,
                  int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    QVariant paintCells(const QModelIndex &index, int role) const;

    bool isDataRight(const int col, const QVariant &value);

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void fillDataTableFromFile(QString path);
    void saveDataTableToFile(QString path);
    void appendRow(const QList<QVariant> &row);
    void createHeader();
    void removeRow(size_t idx);

    void changeCheckBox(bool value);

   private:
    QList<QList<QVariant>> _dataTable;
    QList<QString> _headerList;
};

#endif  // EXAMPLEMODEL_H
