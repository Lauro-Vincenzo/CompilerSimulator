#include <memory>
#include <iostream>

#include "module.h"

void TestFunction();

int main(){
    std::cout << "Start\n";

    TestFunction();

    std::cout << "End\n";
    return 0;
}

void TestFunction(){
    auto entryModule = std::make_unique<Module>();

    entryModule->AddFunction("FirstFunction");
    entryModule->AddBasicBlockToFunctionByName("FirstFunction", "SecondEntryBlock");

    auto sharedBasic = std::make_shared<BasicBlock>("BasicSuccessor 1");
    auto sharedBasic2 = std::make_shared<BasicBlock>("BasicSuccessor 2");
    sharedBasic->AddSuccessor("link0", *sharedBasic2);
    entryModule->AddSuccessorBlock("FirstFunction", "EntryBasicBlock", std::pair<std::string, const BasicBlock&>{"link1", *sharedBasic});
    entryModule->AddSuccessorBlock("FirstFunction", "BasicSuccessor 1", std::pair<std::string, const BasicBlock&>{"link2", *sharedBasic2});

    std::cout<<std::endl;

    entryModule->RunFunctions();

}