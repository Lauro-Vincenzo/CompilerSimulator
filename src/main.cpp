#include <memory>
#include <iostream>
#include <fstream>

#include "module.h"

std::unique_ptr<Module> CreateModule();
void Serialize(const Module& module);

int main(){
    std::cout << "Start\n";

    auto module = CreateModule();
    Serialize(*std::move(module));

    std::cout << "End\n";
    return 0;
}

std::unique_ptr<Module> CreateModule(){
    auto entryModule = std::make_unique<Module>();

    entryModule->AddFunction("FirstFunction");

    entryModule->AddBasicBlockToFunctionByName("FirstFunction", "SecondEntryBlock");

    auto sharedBasic = std::make_shared<BasicBlock>("BasicSuccessor1");
    auto sharedBasic2 = std::make_shared<BasicBlock>("BasicSuccessor2");
    sharedBasic->AddSuccessor("link0", *sharedBasic2);
    entryModule->AddSuccessorBlock("FirstFunction", "EntryBasicBlock", std::pair<std::string, const BasicBlock&>{"link1", *sharedBasic});
    entryModule->AddSuccessorBlock("FirstFunction", "BasicSuccessor1", std::pair<std::string, const BasicBlock&>{"link2", *sharedBasic2});

    return std::move(entryModule);
}

void Serialize(const Module& module){
    std::ofstream outputFile("controlFlow.dot");

    if (!outputFile.is_open()) {
        return;
    }

    outputFile << "digraph ControlFlowGraph {" << std::endl;
    outputFile << module.RunFunctions();
    outputFile << "}" << std::endl;

    outputFile.close();
}