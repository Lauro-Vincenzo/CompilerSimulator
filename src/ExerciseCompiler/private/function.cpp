#include <cassert>
#include <iostream>
#include "function.h"

Function::Function(const std::string& name) : _name{name}{
    _basicBlocks.push_back(std::make_unique<BasicBlock>("EntryBasicBlock"));
    assert(_basicBlocks.size() == 1);
}

void Function::Run() const
{
    std::cout << "Start Running Function with Name: " << _name << std::endl;
    for(const auto& basicBlock : _basicBlocks){
        basicBlock->Run();
    }

    std::cout << "End Running Function with Name: " << _name << std::endl;
}

std::string Function::GetName() const{
    return _name;
}

void Function::AddSuccessorBlock(const std::string& basicBlockName, std::pair<std::string, const BasicBlock&> basicBlockLinkInfo){
    for(const auto& basicBlock : _basicBlocks){
        if(basicBlock->GetName() == basicBlockName){
            basicBlock->AddSuccessor(basicBlockLinkInfo.first, basicBlockLinkInfo.second);
        }
    }
}

void Function::RemoveSuccessorBlock(const std::string & basicBlockName, const std::string& linkToRemove)
{
    for(const auto& basicBlock : _basicBlocks){
        if(basicBlock->GetName() == basicBlockName){
            basicBlock->RemoveSuccessor(linkToRemove);
        }
    }
}

void Function::AddBasicBlock(const std::string& basicBlockName){
    _basicBlocks.push_back(std::make_unique<BasicBlock>(basicBlockName));
}

void Function::RemoveBasicBlock(const std::string& basicBlockName){
    std::erase_if(_basicBlocks, [&](const auto& basicBlock) {
    return basicBlock->GetName() == basicBlockName;
    });
}
