#include <memory>
#include <iostream>

#include "module.h"

int main(){
    std::cout << "Start\n";

    auto firstModule = std::make_unique<Module>();
    firstModule->AddFunction("FirstFunction");
    

    std::cout << "End\n";
    return 0;
}

std::vector<std::unique_ptr<Module>> CreateModules(){
    std::vector<std::unique_ptr<Module>> modules;
    auto entryModule = std::make_unique<Module>();
    auto secondModule = std::make_unique<Module>();

    entryModule->AddFunction("FirstFunction");
    entryModule->AddFunction("SecondFunction");
    secondModule->AddFunction("FirstFunction");

    modules.push_back(std::move(entryModule));
    modules.push_back(std::move(secondModule));

    return modules;
}