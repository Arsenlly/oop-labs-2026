#ifndef DRAWQTCOMMAND_H
#define DRAWQTCOMMAND_H

#include "basedrawcommand.h"
#include "qtdrawerfactory.h"

#include <memory>
#include <QGraphicsScene>

class DRawQtCommand: public BaseDrawCommand
{
public:
    DRawQtCommand() = delete;
    DRawQtCommand(QGraphicsScene* scene);

    virtual ~DRawQtCommand() override = default;

    virtual void execute();

private:
    QGraphicsScene* _scene;
};

#endif // DRAWQTCOMMAND_H
