#ifndef CUSTOMPROXYMODEL_H
#define CUSTOMPROXYMODEL_H

#include <QSortFilterProxyModel>

class CustomProxyModel : public QSortFilterProxyModel {
    Q_OBJECT

   public:
    CustomProxyModel(QObject *parent = nullptr);

    int filterMinimumPers() const { return _minPers; }
    void setPersMinimum(int pers);

    int filterMaximumPers() const { return _maxPers; }
    void setPersMaximum(int pers);

   protected:
    bool filterAcceptsRow(int sourceRow,
                          const QModelIndex &sourceParent) const override;

   private:
    bool persentInRange(int pers) const;

    int _minPers;
    int _maxPers;
};

#endif  // CUSTOMPROXYMODEL_H
