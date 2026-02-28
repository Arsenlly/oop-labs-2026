#ifndef ERROR_H
#define ERROR_H

enum err_t
{
    ERR_OK = 0,
    ERR_UNKNOWN_TYPE_REQ,
    ERR_FILEOPEN,
    ERR_MEMORY,
    ERR_READ_FILE,
    ERR_NO_EDGES,
    ERR_NO_POINTS,
    ERR_RANGE_N_POINTS,
    ERR_RANGE_N_EDGES,
    ERR_NO_SCENE
};

void error_message(err_t rc);

#endif // ERROR_H
