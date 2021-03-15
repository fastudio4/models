#include "modelctr.h"
namespace MODEL {


ModelCTR::ModelCTR(QObject *parent)
    :QAbstractItemModel(parent)
{

}

ModelCTR::~ModelCTR()
{

}

QModelIndex ModelCTR::index(int row, int column, const QModelIndex &parent) const
{
    return QModelIndex();
}

QModelIndex ModelCTR::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int ModelCTR::rowCount(const QModelIndex &parent) const
{
    return 0;
}

int ModelCTR::columnCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant ModelCTR::data(const QModelIndex &index, int role) const
{
    return QVariant();
}

} // namespace MODEL
