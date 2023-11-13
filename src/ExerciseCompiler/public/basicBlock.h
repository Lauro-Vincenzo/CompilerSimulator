#include <string>
#include <memory>
#include <map>

class BasicBlock{
private:
    std::string _name{};
    std::map<std::string,std::shared_ptr<BasicBlock>> _successorsBlocks{};
public:
    BasicBlock(const std::string& name);
    void Run() const;
    std::string GetName() const;
    void AddSuccessor(const std::string& tag, const BasicBlock& successor);
    void RemoveSuccessor(const std::string& tag);
};