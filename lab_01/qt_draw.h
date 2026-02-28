#ifndef QT_DRAW_H
#define QT_DRAW_H

#include "point.h"

#include <QGraphicsScene>

struct Line
{
    double x1;
    double y1;
    double x2;
    double y2;
};

void init_line(Line &line, const point_t point1, const point_t point2);
void clear_scene(QGraphicsScene *scene);
err_t draw_line(const Line &line, QGraphicsScene *scene);

#endif // QT_DRAW_H
