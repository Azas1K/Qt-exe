/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionAbout;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *color2;
    QLabel *FilePath;
    QLabel *label_7;
    QGroupBox *fareGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *fareToLabel;
    QLabel *label_2;
    QLineEdit *linePersFrom;
    QLineEdit *linePersTo;
    QLabel *label_8;
    QSlider *SliderPersTo;
    QLabel *fareFromLabel;
    QLabel *label_9;
    QSlider *SliderPersFrom;
    QLabel *pathLable;
    QLabel *color4;
    QLabel *color3;
    QLabel *color1;
    QPushButton *addRowButton;
    QLabel *label_3;
    QLabel *color5;
    QLineEdit *lineEdit;
    QPushButton *loadButto;
    QPushButton *deliteRowButton;
    QLineEdit *nameFilterlineEdit;
    QTableView *tableDetailsView;
    QLabel *label_4;
    QLabel *imagse_total;
    QCheckBox *checkBox;
    QLabel *label_5;
    QLabel *imagesTotal;
    QLabel *label_6;
    QPushButton *saveButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 750);
        MainWindow->setMinimumSize(QSize(905, 748));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        color2 = new QLabel(centralwidget);
        color2->setObjectName(QString::fromUtf8("color2"));

        gridLayout->addWidget(color2, 11, 5, 1, 1);

        FilePath = new QLabel(centralwidget);
        FilePath->setObjectName(QString::fromUtf8("FilePath"));

        gridLayout->addWidget(FilePath, 16, 0, 1, 1, Qt::AlignRight);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 14, 4, 1, 1);

        fareGroupBox = new QGroupBox(centralwidget);
        fareGroupBox->setObjectName(QString::fromUtf8("fareGroupBox"));
        gridLayout_2 = new QGridLayout(fareGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(fareGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        fareToLabel = new QLabel(fareGroupBox);
        fareToLabel->setObjectName(QString::fromUtf8("fareToLabel"));

        gridLayout_2->addWidget(fareToLabel, 3, 0, 1, 1);

        label_2 = new QLabel(fareGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 4, 0, 1, 1);

        linePersFrom = new QLineEdit(fareGroupBox);
        linePersFrom->setObjectName(QString::fromUtf8("linePersFrom"));
        linePersFrom->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(linePersFrom, 2, 1, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        linePersTo = new QLineEdit(fareGroupBox);
        linePersTo->setObjectName(QString::fromUtf8("linePersTo"));
        linePersTo->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(linePersTo, 5, 1, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);

        label_8 = new QLabel(fareGroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 1, 2, 1, 1);

        SliderPersTo = new QSlider(fareGroupBox);
        SliderPersTo->setObjectName(QString::fromUtf8("SliderPersTo"));
        SliderPersTo->setMaximum(100);
        SliderPersTo->setSliderPosition(100);
        SliderPersTo->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(SliderPersTo, 4, 1, 1, 1);

        fareFromLabel = new QLabel(fareGroupBox);
        fareFromLabel->setObjectName(QString::fromUtf8("fareFromLabel"));

        gridLayout_2->addWidget(fareFromLabel, 0, 0, 1, 2);

        label_9 = new QLabel(fareGroupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 4, 2, 1, 1);

        SliderPersFrom = new QSlider(fareGroupBox);
        SliderPersFrom->setObjectName(QString::fromUtf8("SliderPersFrom"));
        SliderPersFrom->setMaximum(100);
        SliderPersFrom->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(SliderPersFrom, 1, 1, 1, 1);


        gridLayout->addWidget(fareGroupBox, 8, 4, 1, 3);

        pathLable = new QLabel(centralwidget);
        pathLable->setObjectName(QString::fromUtf8("pathLable"));
        pathLable->setMaximumSize(QSize(16777, 16777215));
        pathLable->setAcceptDrops(false);

        gridLayout->addWidget(pathLable, 16, 1, 1, 1);

        color4 = new QLabel(centralwidget);
        color4->setObjectName(QString::fromUtf8("color4"));

        gridLayout->addWidget(color4, 13, 5, 1, 1);

        color3 = new QLabel(centralwidget);
        color3->setObjectName(QString::fromUtf8("color3"));

        gridLayout->addWidget(color3, 12, 5, 1, 1);

        color1 = new QLabel(centralwidget);
        color1->setObjectName(QString::fromUtf8("color1"));

        gridLayout->addWidget(color1, 10, 5, 1, 1);

        addRowButton = new QPushButton(centralwidget);
        addRowButton->setObjectName(QString::fromUtf8("addRowButton"));

        gridLayout->addWidget(addRowButton, 6, 4, 1, 3);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 10, 4, 1, 1);

        color5 = new QLabel(centralwidget);
        color5->setObjectName(QString::fromUtf8("color5"));

        gridLayout->addWidget(color5, 14, 5, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setClearButtonEnabled(true);

        gridLayout->addWidget(lineEdit, 1, 3, 1, 1);

        loadButto = new QPushButton(centralwidget);
        loadButto->setObjectName(QString::fromUtf8("loadButto"));

        gridLayout->addWidget(loadButto, 5, 4, 1, 3);

        deliteRowButton = new QPushButton(centralwidget);
        deliteRowButton->setObjectName(QString::fromUtf8("deliteRowButton"));

        gridLayout->addWidget(deliteRowButton, 7, 4, 1, 3);

        nameFilterlineEdit = new QLineEdit(centralwidget);
        nameFilterlineEdit->setObjectName(QString::fromUtf8("nameFilterlineEdit"));
        nameFilterlineEdit->setClearButtonEnabled(true);

        gridLayout->addWidget(nameFilterlineEdit, 1, 2, 1, 1);

        tableDetailsView = new QTableView(centralwidget);
        tableDetailsView->setObjectName(QString::fromUtf8("tableDetailsView"));

        gridLayout->addWidget(tableDetailsView, 5, 0, 11, 4);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 11, 4, 1, 1);

        imagse_total = new QLabel(centralwidget);
        imagse_total->setObjectName(QString::fromUtf8("imagse_total"));
        QFont font;
        font.setPointSize(15);
        imagse_total->setFont(font);

        gridLayout->addWidget(imagse_total, 15, 5, 1, 1);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout->addWidget(checkBox, 9, 4, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 12, 4, 1, 1);

        imagesTotal = new QLabel(centralwidget);
        imagesTotal->setObjectName(QString::fromUtf8("imagesTotal"));
        imagesTotal->setFont(font);

        gridLayout->addWidget(imagesTotal, 15, 4, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 13, 4, 1, 1);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        gridLayout->addWidget(saveButton, 1, 4, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAbout->menuAction());
        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuAbout->addAction(actionAbout);
        menuAbout->addSeparator();
        menuAbout->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Images on the table", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as...", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        color2->setText(QCoreApplication::translate("MainWindow", "no color", nullptr));
        FilePath->setText(QCoreApplication::translate("MainWindow", "File", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "color5:", nullptr));
        fareGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Filtering by percent", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        fareToLabel->setText(QCoreApplication::translate("MainWindow", "To", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        linePersFrom->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        linePersTo->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        fareFromLabel->setText(QCoreApplication::translate("MainWindow", "From", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        pathLable->setText(QCoreApplication::translate("MainWindow", "//", nullptr));
        color4->setText(QCoreApplication::translate("MainWindow", "no color", nullptr));
        color3->setText(QCoreApplication::translate("MainWindow", "no color", nullptr));
        color1->setText(QCoreApplication::translate("MainWindow", "no color", nullptr));
        addRowButton->setText(QCoreApplication::translate("MainWindow", "Add row", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "color1:", nullptr));
        color5->setText(QCoreApplication::translate("MainWindow", "no color", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter color", nullptr));
        loadButto->setText(QCoreApplication::translate("MainWindow", "Load File", nullptr));
        deliteRowButton->setText(QCoreApplication::translate("MainWindow", "Delete row", nullptr));
        nameFilterlineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter filename", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "color2:", nullptr));
        imagse_total->setText(QCoreApplication::translate("MainWindow", "Images total", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Show colors", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "color3:", nullptr));
        imagesTotal->setText(QCoreApplication::translate("MainWindow", "__", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "color4:", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save File", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "Main", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
