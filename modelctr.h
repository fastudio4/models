#ifndef MODELCTR_H
#define MODELCTR_H
#include <QAbstractItemModel>

namespace MODEL {


class ModelCTR : public QAbstractItemModel
{
    Q_OBJECT
public:
    ModelCTR(QObject *parent = nullptr);
    virtual ~ModelCTR();


    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
private:


};
} //namespace MODEL
#endif // MODELCTR_H
