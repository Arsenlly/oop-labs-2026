#ifndef QT_DRAW_H
#define QT_DRAW_H

#include "point.h"

#include <QGraphicsScene>

struct line_t
{
    double x1;
    double y1;
    double x2;
    double y2;
};

struct draw_field_t
{
    QGraphicsScene *scene;
};

void init_line(line_t &line, const point_t point1, const point_t point2);
void clear_scene(const draw_field_t &draw_field);
err_t draw_line(const line_t &line, const draw_field_t &draw_field);
void init_draw_field(draw_field_t &draw_field, QGraphicsScene *scene);

#endif // QT_DRAW_H
