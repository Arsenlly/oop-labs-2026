#include "rotateaction.h"

RotateAction::RotateAction(double x_angle, double y_angle, double z_angle)
{
    Eigen::Matrix4d x_matr({{1, 0, 0, 0},
                            {0, cos(x_angle), -sin(x_angle), 0},
                            {0, sin(x_angle), cos(x_angle), 0},
                            {0, 0, 0, 1}});

    Eigen::Matrix4d y_matr({{cos(y_angle), 0, sin(y_angle), 0},
                            {0, 1, 0, 0},
                            {-sin(y_angle), 0, cos(y_angle), 0},
                            {0, 0, 0, 1}});

    Eigen::Matrix4d z_matr({{cos(z_angle), -sin(z_angle), 0, 0},
                            {sin(z_angle), cos(z_angle), 0, 0},
                            {0, 0, 1, 0},
                            {0, 0, 0, 1}});

    transform_matrix = x_matr * y_matr * z_matr;
}
