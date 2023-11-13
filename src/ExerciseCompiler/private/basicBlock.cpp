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

void BasicBlock::AddSuccessor(const std::string &tag, const BasicBlock &successor)
{
    _successorsBlocks.emplace(tag, std::make_shared<BasicBlock>(successor));
}

void BasicBlock::RemoveSuccessor(const std::string& tag){
    if(_successorsBlocks.contains(tag)){
        _successorsBlocks.erase(tag);
    }
}
