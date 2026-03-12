#ifndef POINT_H
#define POINT_H

#include <stdio.h>

#include "error.h"
#include "transform.h"

struct point_t
{
    double x;
    double y;
    double z;
};

struct points_arr_t
{
    point_t *arr;
    int len;
};

void init_point(point_t &point);
void init_points(points_arr_t &points);
void free_points(point_t *points_arr);
err_t read_points(points_arr_t &points, FILE *file);
err_t calc_center(point_t &center, points_arr_t &points);
err_t move_points(points_arr_t &points, const move_t &move);
void move_point(point_t &point, const move_t move);
err_t scale_points(points_arr_t &points, const point_t center, const scale_t &scale);
err_t rotate_points(points_arr_t &points, const point_t center, const rotate_t &rotate);

#endif // POINT_H
