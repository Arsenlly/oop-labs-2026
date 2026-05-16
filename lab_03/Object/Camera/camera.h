#ifndef CAMERA_H
#define CAMERA_H

#include "invisibleobject.h"
#include "visitor.h"

class Camera: public InVisibleObject
{
public:
    Camera();
    Camera(const Point &p);
    Camera(const Camera &c);

    ~Camera() = default;

    const Point& getPos();
    const Point& getForward();
    const Point& getUp();
    const Point& getRight();

    void setPos(const Point &pos);
    void setForward(const Point &forward);
    void setUp(const Point &up);
    void setRight(const Point &right);

    virtual void accept(const Visitor &visitor) override;

private:
    Point _pos;
    Point _forward;
    Point _up;
    Point _right;
};

#endif // CAMERA_H
