#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point() = default;
    Point(const double x, const double y, const double z);
    Point(const double x, const double y, const double z, const double w);

    double getX() const;
    double getY() const;
    double getZ() const;
    double getW() const;

    void setX(const double x);
    void setY(const double y);
    void setZ(const double z);
    void setW(const double w);

private:
    double _x;
    double _y;
    double _z;
    double _w;
};

#endif // POINT_H
