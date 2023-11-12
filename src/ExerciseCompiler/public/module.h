#include <set>
#include <string>

#include "function.h"

class Module{
public:
    void AddFunction(const std::string& functionName);
    void RemoveFunction(const std::string& functionName);
    void AddEntryBlockToFunctionByName(const std::string& functionName);
    void RemoveEntryBlockToFunctionByName(const std::string& functionName);

    std::string GetName() const;
private:
    std::string _name{};
    std::set<std::unique_ptr<Function>> _functions{};
};