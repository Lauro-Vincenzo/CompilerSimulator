#pragma once
#include <set>
#include <string>

#include "function.h"

class Module{
public:
    void AddFunction(const std::string& functionName);
    void RemoveFunction(const std::string& functionName);

    void AddBasicBlockToFunctionByName(const std::string& functionName, const std::string& entryBlockName);
    void RemoveBasicBlockToFunctionByName(const std::string& functionName, const std::string& entryBlockName);

    void AddSuccessorBlock(const std::string& functionName, const std::string& entryBlockName, const std::pair<std::string, const BasicBlock&>& basicBlockLinkInfo);
    void RemoveSuccessorBlock(const std::string& functionName, const std::string& entryBlockName, const std::string& linkToRemove);

    std::string RunFunctions() const;

    std::vector<std::weak_ptr<Function>> GetFunctions() const;

    std::string GetName() const;
private:
    std::string _name{"EntryModule"};
    std::set<std::unique_ptr<Function>> _functions{};
};