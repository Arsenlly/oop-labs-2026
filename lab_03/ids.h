#ifndef IDS_H
#define IDS_H

#include <cstddef>

enum InternalReprId: std::size_t
{
    ListRepr = 0,
    MatrixRepr
};

enum ModelDirectorId: std::size_t
{
    SkeletonModelDirectorId = 0
};

#endif // IDS_H
