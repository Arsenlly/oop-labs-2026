#include "draw.h"
#include "qt_draw.h"
#include "point.h"
#include "edge.h"
#include "error.h"

err_t draw_edge(const edge_t &edge, const points_arr_t &points, QGraphicsScene *scene)
{
    if (!points.arr || points.len == 0)
        return ERR_NO_POINTS;
    else if (!scene)
        return ERR_NO_SCENE;

    point_t point_start = points.arr[edge.start_ind];
    point_t point_end = points.arr[edge.end_ind];

    Line line;
    init_line(line, point_start, point_end);

    err_t rc = ERR_OK;
    rc = draw_line(line, scene);
    return rc;
}

err_t draw_edges(const edges_arr_t &edges, const points_arr_t &points, QGraphicsScene *scene)
{
    if (!edges.arr || edges.len == 0)
        return ERR_NO_EDGES;
    else if (!points.arr || points.len == 0)
        return ERR_NO_POINTS;
    else if (!scene)
        return ERR_NO_SCENE;

    err_t rc = ERR_OK;
    for (int i = 0;!rc && i < edges.len;i++)
    {
        rc = draw_edge(edges.arr[i], points, scene);
    }

    return rc;
}

err_t draw_model(const model_t &model, QGraphicsScene *scene)
{
    if (!scene)
        return ERR_NO_SCENE;

    clear_scene(scene);

    err_t rc = draw_edges(model.edges, model.points, scene);

    if (rc)
        clear_scene(scene);

    return rc;
}
