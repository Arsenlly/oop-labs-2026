#include <stdio.h>
#include <stdlib.h>

#include "edge.h"
#include "error.h"

void init_edges(edges_arr_t &edges)
{
    edges.arr = NULL;
    edges.len = 0;
}

void free_edges(edges_arr_t &edges)
{
    free(edges.arr);
    init_edges(edges);
}

err_t allocate_edges_arr(edges_arr_t &edges, int n_edges)
{
    edges.arr = (edge_t *)malloc(sizeof(edge_t) * n_edges);
    if (!edges.arr)
        return ERR_MEMORY;

    edges.len = n_edges;

    return ERR_OK;
}

err_t read_edge(edge_t &edge, FILE *file)
{
    if (fscanf(file, "%d %d", &edge.start_ind, &edge.end_ind) != 2)
        return ERR_READ_FILE;
    return ERR_OK;
}

err_t read_edges(edges_arr_t &edges, FILE *file)
{
    int n_edges;

    if (fscanf(file, "%d", &n_edges) != 1)
        return ERR_READ_FILE;
    if (n_edges <= 0)
        return ERR_READ_FILE;

    err_t rc = allocate_edges_arr(edges, n_edges);
    if (rc)
        return rc;

    for (int i = 0;!rc && i < n_edges;i++)
    {
        rc = read_edge(edges.arr[i], file);
    }
    if (rc)
        free_edges(edges);

    return rc;
}
