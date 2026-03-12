#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsScene>

#include "error.h"
#include "model.h"
#include "qt_draw.h"

err_t draw_model(const model_t &model, const draw_field_t &draw_field);

#endif // DRAW_H
