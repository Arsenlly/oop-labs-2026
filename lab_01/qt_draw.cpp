#include "qt_draw.h"
#include "point.h"

#include <QGraphicsScene>

void init_line(Line &line, const point_t point1, const point_t point2)
{
    line.x1 = point1.x;
    line.y1 = point1.y;
    line.x2 = point2.x;
    line.y2 = point2.y;
}

void clear_scene(QGraphicsScene *scene)
{
    scene->clear();
}

err_t draw_line(const Line &line, QGraphicsScene *scene)
{
    if (!scene)
        return ERR_NO_SCENE;
    scene->addLine(line.x1, line.y1, line.x2, line.y2, QPen(Qt::green));
    return ERR_OK;
}
