#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point() = default;
    Point(const double x, const double y, const double z);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(const double x);
    void setY(const double y);
    void setZ(const double z);

private:
    double _x;
    double _y;
    double _z;
};

#endif // POINT_H
