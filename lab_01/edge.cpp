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

err_t allocate_edges_arr(edge_t *&arr_edges, const int n_edges)
{
    arr_edges = (edge_t *)malloc(sizeof(edge_t) * n_edges);
    if (!arr_edges)
        return ERR_MEMORY;

    return ERR_OK;
}

err_t read_edge(edge_t &edge, FILE *file)
{
    if (fscanf(file, "%d %d", &edge.start_ind, &edge.end_ind) != 2)
        return ERR_READ_FILE;
    return ERR_OK;
}

err_t read_n_edges(int &n_edges, FILE *file)
{
    err_t rc = ERR_OK;
    if (fscanf(file, "%d", &n_edges) != 1)
        rc = ERR_READ_FILE;
    else
    {
        if (n_edges <= 0)
            rc = ERR_RANGE_N_EDGES;
    }
    return rc;
}

err_t read_edges(edges_arr_t &edges, FILE *file)
{
    err_t rc = ERR_OK;

    rc = read_n_edges(edges.len, file);
    if (!rc)
    {
        rc= allocate_edges_arr(edges.arr, edges.len);
        if (!rc)
        {
            for (int i = 0;!rc && i < edges.len;i++)
            {
                rc = read_edge(edges.arr[i], file);
            }
            if (rc)
                free_edges(edges);
        }
    }

    return rc;
}
