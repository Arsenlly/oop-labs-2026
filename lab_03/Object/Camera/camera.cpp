#include "camera.h"

Camera::Camera()
{
    _pos = Point(0, 0, 0);
    _forward = Point(0, 0, 1, 0);
    _up = Point(0, 1, 0, 0);
    _right = Point(1, 0, 0, 0);
}

Camera::Camera(const Point &p)
{
    _pos = p;
    _forward = Point(0, 0, 1, 0);
    _up = Point(0, 1, 0, 0);
    _right = Point(1, 0, 0, 0);
}

Camera::Camera(const Camera &c)
{
    this->_pos = c._pos;
    this->_forward = c._forward;
    this->_up = c._up;
    this->_right = c._right;
}

const Point& Camera::getCenter()
{
    return _pos;
}

const Point& Camera::getForward()
{
    return _forward;
}

const Point& Camera::getUp()
{
    return _up;
}

const Point& Camera::getRight()
{
    return _right;
}

void Camera::setCenter(const Point &pos)
{
    _pos = pos;
}

void Camera::setForward(const Point &forward)
{
    _forward = forward;
}

void Camera::setUp(const Point &up)
{
    _up = up;
}

void Camera::setRight(const Point &right)
{
    _right = right;
}

void Camera::accept(const Visitor &visitor)
{
    visitor.visit(*this);
}
