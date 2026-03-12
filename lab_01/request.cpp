#include "request.h"
#include "error.h"
#include "model.h"
#include "draw.h"

err_t handle_request(const request_t &request)
{

    static model_t model = create_model();
    err_t rc = ERR_OK;

    switch(request.type_request)
    {
    case LOAD:
        rc = load_model(model, request.filename);
        break;

    case MOVE:
        rc = move_model(model, request.move);
        break;

    case ROTATE:
        rc = rotate_model(model, request.rotate);
        break;

    case SCALE:
        rc = scale_model(model, request.scale);
        break;

    case DRAW:
        rc = draw_model(model, request.draw_field);
        break;

    case EXIT:
        free_model(model);
        break;

    default:
        rc = ERR_UNKNOWN_TYPE_REQ;
        break;
    }
    return rc;
}
