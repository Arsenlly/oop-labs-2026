#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsScene>

#include "error.h"
#include "model.h"

err_t draw_model(const model_t &model, QGraphicsScene *scene);

#endif // DRAW_H
