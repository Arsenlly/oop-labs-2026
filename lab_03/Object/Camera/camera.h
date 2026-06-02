#ifndef CAMERA_H
#define CAMERA_H

#include "invisibleobject.h"
#include "visitor.h"
#include "defaultcamerastructure.h"

class Camera: public InVisibleObject
{
public:
    Camera();

    ~Camera() = default;

    //virtual const Point &getCenter() override;
    const Point& getForward();
    const Point& getUp();
    const Point& getRight();

    void setCenter(const Point &pos);
    void setForward(const Point &forward);
    void setUp(const Point &up);
    void setRight(const Point &right);

    virtual void accept(const Visitor &visitor) override;

private:
    Point _pos;
    Point _forward;
    Point _up;
    Point _right;

    std::shared_ptr<DefaultCameraStructure> _structure;
};

#endif // CAMERA_H
