#include "module.h"

std::string Module::GetName() const {
    return _name;
}

void Module::AddFunction(const std::string& functionName){
    _functions.insert(std::make_unique<Function>(functionName));
}

void Module::RemoveFunction(const std::string& functionName){
    std::erase_if(_functions, [&](const auto& function) {
    return function->GetName() == functionName;
    });
}

void Module::AddEntryBlockToFunctionByName(const std::string& functionName, const std::string& entryBlockName){
    for(const auto& function : _functions){
        if(function->GetName() == functionName){
            function->AddBasicBlock(entryBlockName);
        }
    }
}

void Module::RemoveEntryBlockToFunctionByName(const std::string& functionName, const std::string& entryBlockName){
    for(const auto& function : _functions){
        if(function->GetName() == functionName){
            function->RemoveBasicBlock(entryBlockName);
        }
    }
}

void Module::RunFunctions() const{
    for(const auto& function : _functions){
        function->Run();
    }
}