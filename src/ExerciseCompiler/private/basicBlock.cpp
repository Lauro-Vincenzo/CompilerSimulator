#include "basicBlock.h"

#include <iostream>

BasicBlock::BasicBlock(const std::string& name) : _name{name}{

}

void BasicBlock::Run() const
{
    std::cout << "Start Running Basic Block with Name: " << _name << std::endl;
    std::cout << "Now Running " << _successorsBlocks.size() << " successors.\n";

    for(const auto& successor : _successorsBlocks){
        successor.second->Run();
    }

    std::cout << "End Running Basic Block with Name: " << _name << std::endl;
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
