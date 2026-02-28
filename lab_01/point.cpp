#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "point.h"
#include "error.h"
#include "transform.h"

void init_point(point_t &point)
{
    point.x = 0;
    point.y = 0;
    point.z = 0;
}

void init_points(points_arr_t &points)
{
    points.arr = NULL;
    points.len = 0;
}

void free_points(points_arr_t &points)
{
    free(points.arr);
    init_points(points);
}

double x_point(const point_t &point)
{
    return point.x;
}

double y_point(const point_t &point)
{
    return point.y;
}

double z_point(const point_t &point)
{
    return point.z;
}

err_t allocate_points_arr(point_t *&arr_points, const int n_points)
{
    arr_points = (point_t *)malloc(sizeof(point_t) * n_points);
    if (!arr_points)
        return ERR_MEMORY;

    return ERR_OK;
}

err_t read_point(point_t &point, FILE *file)
{
    if (fscanf(file, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
        return ERR_READ_FILE;
    return ERR_OK;
}

err_t read_n_points(int &n_points, FILE *file)
{
    err_t rc = ERR_OK;
    if (fscanf(file, "%d", &n_points) != 1)
        rc = ERR_READ_FILE;
    else
    {
        if (n_points <= 0)
            rc = ERR_RANGE_N_POINTS;
    }
    return rc;
}

err_t read_points(points_arr_t &points, FILE *file)
{
    err_t rc = ERR_OK;

    rc = read_n_points(points.len, file);
    if (!rc)
    {
        rc = allocate_points_arr(points.arr, points.len);
        if (!rc)
        {
            for (int i = 0;!rc && i < points.len;i++)
            {
                rc = read_point(points.arr[i], file);
            }
            if (rc)
                free_points(points);
        }
    }
    return rc;
}

err_t calc_center(point_t &center, points_arr_t &points)
{
    if (!points.arr || points.len == 0)
        return ERR_NO_POINTS;

    init_point(center);
    for (int i = 0;i < points.len;i++)
    {
        center.x += x_point(points.arr[i]);
        center.y += y_point(points.arr[i]);
        center.z += z_point(points.arr[i]);
    }

    center.x = center.x / points.len;
    center.y = center.y / points.len;
    center.z = center.z / points.len;

    return ERR_OK;
}

void move_point(point_t &point, const move_t move)
{
    point.x += move.dx;
    point.y += move.dy;
    point.z += move.dz;
}

void scale_point(point_t &point, const point_t center, const scale_t scale)
{
    point.x = center.x + scale.kx * (point.x - center.x);
    point.y = center.y + scale.ky * (point.y - center.y);
    point.z = center.z + scale.kz * (point.z - center.z);
}

void rotate_point_x(point_t &point, const point_t center, const double angle)
{
    double y_dif = point.y - center.y;
    double z_dif = point.z - center.z;

    point.y = center.y + y_dif * cos(angle) - z_dif * sin(angle);
    point.z = center.z + y_dif * sin(angle) + z_dif * cos(angle);
}

void rotate_point_y(point_t &point, const point_t center, const double angle)
{
    double x_dif = point.x - center.x;
    double z_dif = point.z - center.z;

    point.x = center.x + x_dif * cos(angle) + z_dif * sin(angle);
    point.z = center.z - x_dif * sin(angle) + z_dif * cos(angle);
}

void rotate_point_z(point_t &point, const point_t center, const double angle)
{
    double x_dif = point.x - center.x;
    double y_dif = point.y - center.y;

    point.x = center.x + x_dif * cos(angle) - y_dif * sin(angle);
    point.y = center.y + x_dif * sin(angle) + y_dif * cos(angle);
}

void rotate_point(point_t &point, const point_t center, const rotate_t rotate)
{
    rotate_point_x(point, center, rotate.x_angle);
    rotate_point_y(point, center, rotate.y_angle);
    rotate_point_z(point, center, rotate.z_angle);
}

err_t move_points(points_arr_t &points, const move_t &move)
{
    if (!points.arr || points.len == 0)
        return ERR_NO_POINTS;

    for (int i = 0;i < points.len;i++)
        move_point(points.arr[i], move);

    return ERR_OK;
}

err_t scale_points(points_arr_t &points, const point_t center, const scale_t &scale)
{
    if (!points.arr || points.len == 0)
        return ERR_NO_POINTS;

    for (int i = 0;i < points.len;i++)
        scale_point(points.arr[i], center, scale);

    return ERR_OK;
}

err_t rotate_points(points_arr_t &points, const point_t center, const rotate_t &rotate)
{
    if (!points.arr || points.len == 0)
        return ERR_NO_POINTS;

    for (int i = 0;i < points.len;i++)
        rotate_point(points.arr[i], center, rotate);

    return ERR_OK;
}
