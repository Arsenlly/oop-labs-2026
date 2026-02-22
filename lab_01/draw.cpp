#include "draw.h"
#include "qt_draw.h"
#include "point.h"
#include "edge.h"
#include "error.h"

void draw_edge(const edge_t &edge, const points_arr_t &points, QGraphicsScene *scene)
{
    point_t point_start = points.arr[edge.start_ind];
    point_t point_end = points.arr[edge.end_ind];

    draw_line(point_start.x, point_start.y, point_end.x, point_end.y, scene);
}

err_t draw_edges(const edges_arr_t &edges, const points_arr_t &points, QGraphicsScene *scene)
{
    if (!edges.arr || edges.len == 0 || !points.arr || points.len == 0)
        return ERR_NO_DATA;

    for (int i = 0;i < edges.len;i++)
    {
        draw_edge(edges.arr[i], points, scene);
    }

    return ERR_OK;
}

err_t draw_model(const model_t &model, QGraphicsScene *scene)
{
    clear_scene(scene);

    err_t rc = draw_edges(model.edges, model.points, scene);

    return rc;
}
