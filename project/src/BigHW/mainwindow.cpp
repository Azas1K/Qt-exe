#include "mainwindow.h"

#include <QColor>
#include <QFileDialog>
#include <QKeyEvent>
#include <iostream>
#include <string>

#include "addrowdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    _exampleModel = new ExampleModel(this);  // создание модели с данными

    _proxyModel = new QSortFilterProxyModel(this);  // создание прокси моделей
    _proxyModel2 = new QSortFilterProxyModel(this);
    _proxyModelPers = new CustomProxyModel(this);

    _proxyModel->setSourceModel(
        _exampleModel);  // установление родителя для прокси
    _proxyModel2->setSourceModel(_proxyModel);
    _proxyModelPers->setSourceModel(_proxyModel2);

    ui->tableDetailsView->setModel(
        _proxyModelPers);  // отображение финальной модели
    ui->tableDetailsView->setSortingEnabled(true);  //включить сортировку

    _proxyModel->setFilterKeyColumn(0);  // за какие столбцы отвечает сортировка
    _proxyModel2->setFilterKeyColumn(-1);

    QObject::connect(ui->loadButto, SIGNAL(clicked()), this,
                     SLOT(loadFile()));  // загрузить файл
    QObject::connect(ui->saveButton, SIGNAL(clicked()), this,
                     SLOT(saveFile()));  //сохранить файл

    QObject::connect(ui->addRowButton, SIGNAL(clicked()), this,
                     SLOT(addRowSlot()));  // добавляем новую строку
    QObject::connect(ui->deliteRowButton, SIGNAL(clicked()), this,
                     SLOT(deleteRowSlot()));  // удаляем выбранную строку

    QObject::connect(ui->actionLoad, SIGNAL(triggered()), this,
                     SLOT(loadFile()));  //загрузка через контекст
    QObject::connect(ui->actionSave, SIGNAL(triggered()), this,
                     SLOT(saveFile()));  //выгрузка через контекст

    QObject::connect(ui->actionAbout, SIGNAL(triggered()), this,
                     SLOT(showAbout()));  // кнопка вызова окна about

    //изменение информации выводимой о строке
    QObject::connect(ui->tableDetailsView, SIGNAL(clicked(QModelIndex)), this,
                     SLOT(changeCurrentRowSlot()));
    QObject::connect(ui->tableDetailsView->selectionModel(),
                     SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this,
                     SLOT(changeCurrentRowSlot()));

    QObject::connect(ui->checkBoxColorCells, SIGNAL(stateChanged(int)), this,
                     SLOT(colorTable()));

    QObject::connect(
        ui->nameFilterlineEdit, SIGNAL(textChanged(QString)), this,
        SLOT(updateFilter(QString)));  //фильтр по filename (wildcart)
    QObject::connect(
        ui->lineEdit, SIGNAL(textChanged(QString)), this,
        SLOT(updateFilter2(QString)));  //фильтр по всем строкам (fixed string)

    QObject::connect(
        ui->linePersFrom, SIGNAL(textChanged(QString)), this,
        SLOT(updateFilterMinPersS(QString)));  // измение фильтра из line edit
    QObject::connect(ui->linePersTo, SIGNAL(textChanged(QString)), this,
                     SLOT(updateFilterMaxPersS(QString)));

    QObject::connect(
        ui->SliderPersFrom, SIGNAL(valueChanged(int)), this,
        SLOT(updateFilterMinPers(int)));  // изменение фильтра из ползунка
    QObject::connect(ui->SliderPersTo, SIGNAL(valueChanged(int)), this,
                     SLOT(updateFilterMaxPers(int)));
}

void MainWindow::updateFilterMinPers(int pers) {  // изменяет фильтр из ползунка
    _proxyModelPers->setPersMinimum(pers);
    ui->linePersFrom->setText(QVariant(pers).toString());
    if (ui->SliderPersFrom->value() >
        ui->SliderPersTo->value()) {  // козависимые слайдеры
        _proxyModelPers->setPersMaximum(pers);
        ui->linePersTo->setText(QVariant(pers).toString());
    }
}
void MainWindow::updateFilterMinPersS(
    QString line) {  // изменяет фильтр из строки
    ui->SliderPersFrom->setValue(line.toInt());  // вводит значение в слайдер
    ui->linePersFrom->setText(QVariant(ui->SliderPersFrom->value())
                                  .toString());  //берет значение из слайдера,
                                                 //чтобы не превышало 0 или 100
    _proxyModelPers->setPersMinimum(
        ui->SliderPersFrom->value());  // дает ввод в фильтр
}

void MainWindow::updateFilterMaxPers(int pers) {  // изменяет фильтр из ползунка
    _proxyModelPers->setPersMaximum(pers);
    ui->linePersTo->setText(QVariant(pers).toString());
    if (ui->SliderPersFrom->value() >
        ui->SliderPersTo->value()) {  // козависимые слайдеры
        _proxyModelPers->setPersMinimum(pers);
        ui->linePersFrom->setText(QVariant(pers).toString());
    }
}
void MainWindow::updateFilterMaxPersS(
    QString line) {  // изменяет фильтр из строки
    ui->SliderPersTo->setValue(line.toInt());  // вводит значение в слайдер
    ui->linePersTo->setText(QVariant(ui->SliderPersTo->value())
                                .toString());  //берет значение из слайдера,
                                               //чтобы не превышало 0 или 100
    _proxyModelPers->setPersMaximum(
        ui->SliderPersTo->value());  // дает ввод в фильтр
}

void MainWindow::updateFilter(const QString &text) {  // изменяют фильтр поиска
    _proxyModel->setFilterWildcard(text);
}
void MainWindow::updateFilter2(const QString &text) {
    _proxyModel2->setFilterFixedString(text);
}

void MainWindow::loadFile() {  // загрузка файла
    delete _exampleModel;  // удаляет старую модель и создает новую
    _exampleModel = new ExampleModel(this);

    _exampleModel->checkBoxColor = ui->checkBoxColorCells->checkState();

    QString fileName =
        QFileDialog::getOpenFileName(this, "Open File", "../", "Data (*.csv)");
    _exampleModel->fillDataTableFromFile(fileName);

    ui->pathLable->setText(fileName);  // измение строки пути
    ui->imagesTotal->setText(
        (QVariant(_exampleModel->rowCount()))
            .toString());  // меняет значение количества картинок
    _proxyModel->setSourceModel(_exampleModel);  // изменяет родителя прокси

    ui->color1->setText("no color");
    ui->color2->setText("no color");
    ui->color3->setText("no color");
    ui->color4->setText("no color");
    ui->color5->setText("no color");

    ui->color1->setStyleSheet(QString("color: #ffffff"));
    ui->color2->setStyleSheet(QString("color: #ffffff"));
    ui->color3->setStyleSheet(QString("color: #ffffff"));
    ui->color4->setStyleSheet(QString("color: #ffffff"));
    ui->color5->setStyleSheet(QString("color: #ffffff"));
}

void MainWindow::saveFile() {  // сохраняет файл поуказанному пути
    QString fileName =
        QFileDialog::getSaveFileName(this, "Save File", "../", "Data (*.csv)");
    _exampleModel->saveDataTableToFile(fileName);
}

void MainWindow::addRowSlot() {  // добавление строки
    AddRowDialog d(this);
    if (d.exec() == QDialog::Accepted) {  // если принят то
        if (_exampleModel->rowCount() == 0)
            _exampleModel->createHeader();  // создается хедр если не было
        _exampleModel->appendRow(d.getNewRow());  // создается новая строка
    }

    ui->imagesTotal->setText(
        (QVariant(_exampleModel->rowCount()))
            .toString());  //обновление показателя количества картинок (можно
                           //было сделать в иф и просто добавить + 1)
}

void MainWindow::deleteRowSlot() {  // удаление строки

    QModelIndexList indexesOfRows =
        ui->tableDetailsView->selectionModel()->selection().indexes();
    if (!indexesOfRows.isEmpty()) {
        QList<QModelIndex> realIndexesOfRows;
        size_t previous = -1;
        for (const QModelIndex &ind : qAsConst(indexesOfRows)) {
            QModelIndex idx1 = ind;  // значение текущего выбранного индекса
            QModelIndex idx2 = _proxyModelPers->mapToSource(idx1);
            QModelIndex idx3 = _proxyModel2->mapToSource(idx2);
            QModelIndex idx4 = _proxyModel->mapToSource(
                idx3);  // находим исходный индекс в _exampleModel (идем
                        // наоборот от того как назначи прокси)
            realIndexesOfRows.append(idx4);
        }

        std::sort(realIndexesOfRows.begin(), realIndexesOfRows.end());
        std::reverse(realIndexesOfRows.begin(), realIndexesOfRows.end());

        for (const QModelIndex &ind : qAsConst(realIndexesOfRows)) {
            if (ind.row() !=
                previous) {  // проверяем, чтобы индексы не были с одной строки
                _exampleModel->removeRow(
                    ind.row());  // удаляем выбранную строку
                previous = ind.row();
            }
        }
        ui->imagesTotal->setText(
            (QVariant(_exampleModel->rowCount())).toString());
    }
}

void MainWindow::showAbout() {
    windowAbout = new About(this);
    windowAbout->exec();
}

void MainWindow::colorTable() {
    _exampleModel->checkBoxColor = ui->checkBoxColorCells->checkState();
    ui->tableDetailsView->viewport()->update();
}

void MainWindow::changeCurrentRowSlot() {
    QModelIndex idx1 = ui->tableDetailsView->selectionModel()->currentIndex();
    QModelIndex idx2 = _proxyModelPers->mapToSource(idx1);
    QModelIndex idx3 = _proxyModel2->mapToSource(idx2);
    QModelIndex idx4 = _proxyModel->mapToSource(idx3);
    int row = idx4.row();
    // obtain real sell and then changing data

    QModelIndex color = _exampleModel->index(row, 1);
    QVariant Data = _exampleModel->data(color);
    ui->color1->setText(Data.toString());
    ui->color1->setStyleSheet(QString("color: %1").arg(Data.toString()));

    color = _exampleModel->index(row, 2);
    Data = _exampleModel->data(color);
    ui->color2->setText(Data.toString());
    ui->color2->setStyleSheet(QString("color: %1").arg(Data.toString()));

    color = _exampleModel->index(row, 3);
    Data = _exampleModel->data(color);
    ui->color3->setText(Data.toString());
    ui->color3->setStyleSheet(QString("color: %1").arg(Data.toString()));

    color = _exampleModel->index(row, 4);
    Data = _exampleModel->data(color);
    ui->color4->setText(Data.toString());
    ui->color4->setStyleSheet(QString("color: %1").arg(Data.toString()));

    color = _exampleModel->index(row, 5);
    Data = _exampleModel->data(color);
    ui->color5->setText(Data.toString());
    ui->color5->setStyleSheet(QString("color: %1").arg(Data.toString()));
}

MainWindow::~MainWindow() { delete ui; }
