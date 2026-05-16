#ifndef QTDRAWERFACTORY_H
#define QTDRAWERFACTORY_H

#include "basedrawerfactory.h"
#include "basedrawer.h"
#include "qtdrawer.h"

#include <QGraphicsScene>

class QtDrawerFactory: public BaseDrawerFactory
{
public:
    QtDrawerFactory() = delete;
    QtDrawerFactory(QGraphicsScene* scene);

    virtual ~QtDrawerFactory() override = default;

    virtual std::shared_ptr<BaseDrawer> createDrawer() override;

private:
    QGraphicsScene* _scene;
};

#endif // QTDRAWERFACTORY_H
