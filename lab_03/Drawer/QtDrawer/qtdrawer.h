#ifndef QTDRAWER_H
#define QTDRAWER_H

#include "basedrawer.h"
#include "qtdrawerfactory.h"

#include <memory>

#include <QGraphicsScene>

class QtDrawer: public BaseDrawer
{
public:
    QtDrawer() = delete;
    QtDrawer(QGraphicsScene* scene);

    virtual ~QtDrawer() override = default;

    virtual void drawLine(const Point &start, const Point &end) override;
    virtual void clear() override;

private:
    QGraphicsScene* _scene;
};

#endif // QTDRAWER_H
