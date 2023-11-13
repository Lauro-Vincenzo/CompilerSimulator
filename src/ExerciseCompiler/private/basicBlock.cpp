#include "basicBlock.h"

#include <iostream>

BasicBlock::BasicBlock(const std::string& name) : _name{name}{

}

std::string BasicBlock::Run() const
{
    std::string outputString{};
    for(const auto& successor : _successorsBlocks){
        outputString += _name;
        outputString += "->";
        outputString += successor.second->GetName();
        outputString += ";\n";

        outputString += successor.second->Run();
    }
    return outputString;
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
