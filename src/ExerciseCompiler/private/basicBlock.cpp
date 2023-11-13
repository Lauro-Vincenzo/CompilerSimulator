#include "basicBlock.h"

BasicBlock::BasicBlock(const std::string& name) : _name{name}{

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
