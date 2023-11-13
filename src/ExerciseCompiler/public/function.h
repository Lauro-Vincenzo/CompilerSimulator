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
    void Run() const;
    std::string GetName() const;

    void AddSuccessorBlock(const std::string &basicBlockName, std::pair<std::string, const BasicBlock &> basicBlockLinkInfo);
    void RemoveSuccessorBlock(const std::string &basicBlockName, const std::string &linkToRemove);

    void AddBasicBlock(const std::string &basicBlockName);
    void RemoveBasicBlock(const std::string &basicBlockName);
};