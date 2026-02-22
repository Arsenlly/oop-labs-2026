#ifndef MODEL_H
#define MODEL_H

#include "error.h"
#include "point.h"
#include "edge.h"
#include "transform.h"

struct model_t
{
    point_t center;
    points_arr_t points;
    edges_arr_t edges;
};

model_t create_model();
err_t load_model(model_t &model, const char *filename);
err_t move_model(model_t &model, const move_t &move);
err_t scale_model(model_t &model, const scale_t &scale);
err_t rotate_model(model_t &model, const rotate_t &rotate);
void free_model(model_t &model);

#endif // MODEL_H
