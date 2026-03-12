#include "qt_draw.h"
#include "point.h"

#include <QGraphicsScene>

void init_line(line_t &line, const point_t point1, const point_t point2)
{
    line.x1 = point1.x;
    line.y1 = point1.y;
    line.x2 = point2.x;
    line.y2 = point2.y;
}

void clear_scene(const draw_field_t &draw_field)
{
    draw_field.scene->clear();
}

err_t draw_line(const line_t &line, const draw_field_t &draw_field)
{
    if (!draw_field.scene)
        return ERR_NO_SCENE;
    draw_field.scene->addLine(line.x1, line.y1, line.x2, line.y2, QPen(Qt::green));
    return ERR_OK;
}

void init_draw_field(draw_field_t &draw_field, QGraphicsScene *scene)
{
    draw_field.scene = scene;
}
