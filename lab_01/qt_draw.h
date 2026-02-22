#ifndef QT_DRAW_H
#define QT_DRAW_H

#include <QGraphicsScene>

void clear_scene(QGraphicsScene *scene);
void draw_line(const double x1, const double y1, const double x2, const double y2, QGraphicsScene *scene);

#endif // QT_DRAW_H
