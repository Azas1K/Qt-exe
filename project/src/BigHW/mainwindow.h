#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>

#include "./ui_mainwindow.h"
#include "about.h"
#include "customproxymodel.h"
#include "examplemodel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   private slots:
    void loadFile();
    void saveFile();
    void addRowSlot();
    void showAbout();
    void changeCurrentRowSlot();
    void deleteRowSlot();
    void colorTable();

    void updateFilter(const QString &text);
    void updateFilter2(const QString &text);

    void updateFilterMinPers(int value);
    void updateFilterMaxPers(int value);

    void updateFilterMinPersS(QString line);
    void updateFilterMaxPersS(QString line);

   private:
    QSortFilterProxyModel *_proxyModel;
    QSortFilterProxyModel *_proxyModel2;
    CustomProxyModel *_proxyModelPers;
    ExampleModel *_exampleModel;
    About *windowAbout;
    Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
