#ifndef ADDROWDIALOG_H
#define ADDROWDIALOG_H

#include <QDialog>

namespace Ui {
class AddRowDialog;
}

class AddRowDialog : public QDialog {
    Q_OBJECT

   public:
    explicit AddRowDialog(QWidget *parent = nullptr);
    ~AddRowDialog();
    const QList<QVariant> &getNewRow();

   private slots:
    void saveAddedRow();

   private:
    void convertToColor(const QString &);
    bool checkColor(const QVariant &) const;
    void convertToPers(const QString &);

    bool check100Pers();
    bool checkFileIsCorrect();
    void checkAndSaveNewRow();

    QList<QVariant> _newRow;
    Ui::AddRowDialog *ui;
};

#endif  // ADDROWDIALOG_H
