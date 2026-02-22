#include <QGraphicsScene>


void clear_scene(QGraphicsScene *scene)
{
    scene->clear();
}

void draw_line(const double x1, const double y1, const double x2, const double y2, QGraphicsScene *scene)
{
    scene->addLine(x1, y1, x2, y2, QPen(Qt::green));
}
