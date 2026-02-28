#include <stdio.h>

#include "model.h"
#include "error.h"
#include "point.h"
#include "edge.h"

#include <iostream>

void init_model(model_t &model)
{
    init_point(model.center);
    init_points(model.points);
    init_edges(model.edges);
}

model_t create_model()
{
    model_t model;
    init_model(model);
    return model;
}

void free_model(model_t &model)
{
    init_point(model.center);
    free_points(model.points);
    free_edges(model.edges);
}

err_t read_model(model_t &model, FILE *file)
{
    init_model(model);
    err_t rc = ERR_OK;

    rc = read_points(model.points, file);
    if (!rc)
    {
        rc = read_edges(model.edges, file);
        if (rc)
            free_points(model.points);
    }
    return rc;
}

err_t load_model(model_t &model, const char *filename)
{
    FILE *file = fopen(filename, "r");
    err_t rc = ERR_OK;

    if (!file)
    {
        rc = ERR_FILEOPEN;
    }
    else
    {
        model_t tmp_model;
        rc = read_model(tmp_model, file);

        fclose(file);

        if (!rc)
        {
            rc = calc_center(tmp_model.center, tmp_model.points);
            if (!rc)
            {
                free_model(model);
                model = tmp_model;
            }
        }
    }
    return rc;
}

err_t move_model(model_t &model, const move_t &move)
{
    err_t rc = ERR_OK;
    rc = move_points(model.points, move);
    if (!rc)
        move_point(model.center, move);
    return rc;
}

err_t scale_model(model_t &model, const scale_t &scale)
{
    err_t rc = ERR_OK;
    rc = scale_points(model.points, model.center, scale);
    return rc;
}

err_t rotate_model(model_t &model, const rotate_t &rotate)
{
    err_t rc = ERR_OK;
    rc = rotate_points(model.points, model.center, rotate);
    return rc;
}
