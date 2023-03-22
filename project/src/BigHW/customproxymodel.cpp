#include "customproxymodel.h"

CustomProxyModel::CustomProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent} {
    _maxPers = 100;
    _minPers = 0;
}

bool CustomProxyModel::filterAcceptsRow(int sourceRow,
                                        const QModelIndex &sourceParent) const {
    QModelIndex mostUsingPersent =
        sourceModel()->index(sourceRow, 6, sourceParent);

    return persentInRange(sourceModel()->data(mostUsingPersent).toInt());
}

bool CustomProxyModel::persentInRange(const int pers) const {
    return pers >= _minPers &&
           pers <= _maxPers;  //условие по которому отображает
}

void CustomProxyModel::setPersMinimum(int pers) {
    _minPers = pers;
    invalidateFilter();  // updating filter
}

void CustomProxyModel::setPersMaximum(int pers) {
    _maxPers = pers;
    invalidateFilter();
}
