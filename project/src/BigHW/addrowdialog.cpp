#include "addrowdialog.h"

#include <QColor>
#include <QMessageBox>

#include "ui_addrowdialog.h"

AddRowDialog::AddRowDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::AddRowDialog) {  // сам по себе диалог
    ui->setupUi(this);

    QObject::connect(ui->okButton, SIGNAL(clicked()), this,
                     SLOT(saveAddedRow()));  // связь Ок и сохранить
    QObject::connect(
        ui->cancelButton, SIGNAL(clicked()), this,
        SLOT(reject()));  // связь кнопки отмена и отменить (уже прописан в qt)
}

void AddRowDialog::saveAddedRow() {
    _newRow.push_back(ui->FileLineEdit->text() + ".jpg");

    convertToColor(ui->LineEditColor1->text());
    convertToColor(ui->LineEditColor2->text());
    convertToColor(ui->LineEditColor3->text());
    convertToColor(ui->LineEditColor4->text());
    convertToColor(ui->LineEditColor5->text());

    convertToPers(ui->LineEditPers1->text());
    convertToPers(ui->LineEditPers2->text());
    convertToPers(ui->LineEditPers3->text());
    convertToPers(ui->LineEditPers4->text());
    convertToPers(ui->LineEditPers5->text());

    checkAndSaveNewRow();
}

bool AddRowDialog::check100Pers() {  // cheking not more 100%
    int persantage = _newRow[6].toInt() + _newRow[7].toInt() +
                     _newRow[8].toInt() + _newRow[9].toInt() +
                     _newRow[10].toInt();
    if (persantage > 100) {
        _newRow.clear();
        return true;
    } else {
        return false;
    }
}

bool AddRowDialog::checkFileIsCorrect() {  // cheking input of file
    QString name = ui->FileLineEdit->text();
    if (name.length() == 0) {
        _newRow.clear();
        return true;
    } else {
        return false;
    }
}

void AddRowDialog::convertToColor(const QString& color) {  // translate input
                                                           // into color
    if (color == "")
        _newRow.push_back("#000000");
    else if (color.toLower().length() < 7) {
        QString word = color.toLower();
        int lenth = word.length();
        for (int i = 0; i < 7 - lenth; i++)
            word += "0";  // with no full size adding 0
        _newRow.push_back(word);
    } else
        _newRow.push_back(color.toLower());
}

bool AddRowDialog::checkColor(
    const QVariant& color) const {  // check if color is valid
    if (QColor(color.toString()).isValid()) {
        return true;
    } else {
        return false;
    }
}

void AddRowDialog::convertToPers(
    const QString& pers) {  // translate input into int
    if (pers == "")
        _newRow.push_back(0);
    else
        _newRow.push_back(pers.toInt());
}

void AddRowDialog::checkAndSaveNewRow() {  // checks all nessassary conditions
                                           // and
                                           // accept if all is ok
    if (check100Pers())
        QMessageBox::warning(
            this, "Warning",
            "Summ of persentages is more than 100, check input");
    else if (checkFileIsCorrect()) {
        QMessageBox::warning(this, "Warning",
                             "file name is empty, check input");
    } else if (!checkColor(_newRow[1]) or !checkColor(_newRow[2]) or
               !checkColor(_newRow[3]) or !checkColor(_newRow[4]) or
               !checkColor(_newRow[5])) {
        QMessageBox::warning(this, "Warning",
                             "One of the colors is not correct, check input");
        _newRow.clear();
    } else
        accept();
}

const QList<QVariant>& AddRowDialog::getNewRow() { return _newRow; }

AddRowDialog::~AddRowDialog() { delete ui; }
