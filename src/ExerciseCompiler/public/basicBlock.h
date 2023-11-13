#include <string>

class BasicBlock{
private:
    std::string _name{};
public:
    BasicBlock(const std::string& name);
    void Run() const;
    std::string GetName() const;
};