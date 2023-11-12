#include "basicBlock.h"

BasicBlock::BasicBlock(const std::string& name) : _name{name}{

}

std::string BasicBlock::GetName() const{
    return _name;
}