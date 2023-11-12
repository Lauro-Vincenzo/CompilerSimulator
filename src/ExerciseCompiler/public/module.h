#include <set>
#include <string>

#include "function.h"

class Module{
public:
    bool AddFunction(const std::string& functionName);
    bool RemoveFunction(const std::string& functionName);
    bool AddEntryBlockToFunctionByName(const std::string& functionName);
    bool RemoveEntryBlockToFunctionByName(const std::string& functionName);

    std::string GetName() const;
private:
    std::string _name{};
    std::set<std::unique_ptr<Function>> _functions{};
};