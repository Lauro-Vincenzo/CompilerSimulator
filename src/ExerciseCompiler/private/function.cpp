#include <cassert>
#include "function.h"

Function::Function(const std::string& name) : _name{name}{
    _basicBlocks.push_back(std::make_unique<BasicBlock>("EntryBasicBlock"));
    assert(_basicBlocks.size() == 1);
}

std::string Function::GetName() const{
    return _name;
}
