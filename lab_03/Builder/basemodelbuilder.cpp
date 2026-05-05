#include "basemodelbuilder.h"

BaseModelBuilder::BaseModelBuilder(std::shared_ptr<ModelReader> reader): _reader(reader){}

BaseModelBuilder::~BaseModelBuilder() {}
