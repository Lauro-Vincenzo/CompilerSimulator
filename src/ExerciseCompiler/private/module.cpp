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

void Module::AddBasicBlockToFunctionByName(const std::string& functionName, const std::string& entryBlockName){
    for(const auto& function : _functions){
        if(function->GetName() == functionName){
            function->AddBasicBlock(entryBlockName);
        }
    }
}

void Module::RemoveBasicBlockToFunctionByName(const std::string& functionName, const std::string& entryBlockName){
    for(const auto& function : _functions){
        if(function->GetName() == functionName){
            function->RemoveBasicBlock(entryBlockName);
        }
    }
}

void Module::RemoveSuccessorBlock(const std::string &functionName, const std::string &entryBlockName, const std::string& linkToRemove)
{
    for(const auto& function : _functions){
        if(function->GetName() == functionName){
            function->RemoveSuccessorBlock(entryBlockName,linkToRemove);
        }
    }
}

void Module::AddSuccessorBlock(const std::string &functionName, const std::string &entryBlockName, const std::pair<std::string, const BasicBlock&>& basicBlockLinkInfo)
{
    for(const auto& function : _functions){
        if(function->GetName() == functionName){
            function->AddSuccessorBlock(entryBlockName,basicBlockLinkInfo);
        }
    }
}

void Module::RunFunctions() const{
    for(const auto& function : _functions){
        function->Run();
    }
}