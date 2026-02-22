#ifndef TRANSFORM_H
#define TRANSFORM_H

struct move_t
{
    double dx;
    double dy;
    double dz;
};

struct scale_t
{
    double kx;
    double ky;
    double kz;
};

struct rotate_t
{
    double x_angle;
    double y_angle;
    double z_angle;
};

#endif // TRANSFORM_H
