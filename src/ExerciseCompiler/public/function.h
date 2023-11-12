#include <vector>
#include <string>
#include <memory>

#include "basicBlock.h"

class Function{
private:
    std::string _name{};
    std::vector<std::unique_ptr<BasicBlock>> _basicBlocks{};
public:
    Function(const std::string& name);
    std::string GetName() const;
};