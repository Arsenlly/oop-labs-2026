#ifndef REQUEST_H
#define REQUEST_H

#include <QGraphicsScene>
#include "error.h"
#include "qt_draw.h"
#include "transform.h"

enum type_request_t
{
    LOAD,
    MOVE,
    SCALE,
    ROTATE,
    DRAW,
    EXIT
};

struct request_t
{
    type_request_t type_request;
    union
    {
        draw_field_t draw_field;
        const char *filename;
        scale_t scale;
        rotate_t rotate;
        move_t move;
    };
};

err_t handle_request(const request_t &request);

#endif // REQUEST_H
