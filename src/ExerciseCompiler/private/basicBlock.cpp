#include "basicBlock.h"

#include <iostream>

BasicBlock::BasicBlock(const std::string& name) : _name{name}{

}

void BasicBlock::Run() const
{
    std::cout << "Running Basic Block with Name: " << _name << std::endl;
}

std::string BasicBlock::GetName() const{
    return _name;
}