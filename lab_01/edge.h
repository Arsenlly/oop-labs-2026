#ifndef EDGE_H
#define EDGE_H

#include "error.h"

struct edge_t
{
    int start_ind;
    int end_ind;
};

struct edges_arr_t
{
    edge_t *arr;
    int len;
};

void init_edges(edges_arr_t &edges);
void free_edges(edges_arr_t &edges);
err_t read_edges(edges_arr_t &edges, FILE *file);

#endif // EDGE_H
