#include <string>

class BasicBlock{
private:
    std::string _name{};
public:
    BasicBlock(const std::string& name);
    std::string GetName() const;
};