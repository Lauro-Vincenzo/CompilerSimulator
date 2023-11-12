#include "module.h"

std::string Module::GetName() const {
    return _name;
}

bool Module::AddFunction(const std::string& functionName){
    auto bSuccess{false};

    const auto functionNum = _functions.size();
    _functions.emplace(std::make_unique<Function>(functionName));
    bSuccess = _functions.size() == functionNum + 1;

    return bSuccess;
}

bool Module::RemoveFunction(const std::string& functionName){
    auto bSuccess{false};
    return bSuccess;
}

bool Module::AddEntryBlockToFunctionByName(const std::string& functionName){
    auto bSuccess{false};
    return bSuccess;
}

bool Module::RemoveEntryBlockToFunctionByName(const std::string& functionName){
    auto bSuccess{false};
    return bSuccess;
}