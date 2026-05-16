#include "matrixmodelbuilder.h"

#include <iostream>

MatrixModelBuilder::MatrixModelBuilder(std::shared_ptr<ModelReader> reader): BaseModelBuilder(reader)
{
    std::cout << "matrix\n";
}

void MatrixModelBuilder::reset()
{
}

void MatrixModelBuilder::buildPoints()
{
}

void MatrixModelBuilder::buildEdges()
{
}

void MatrixModelBuilder::buildCenter()
{

}

std::shared_ptr<BaseModel> MatrixModelBuilder::getResult()
{
    return _model;
}
