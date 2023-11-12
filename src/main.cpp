#include <memory>
#include <iostream>

#include "module.h"

int main(){
    std::cout << "Start\n";

    auto firstModule = std::make_unique<Module>();
    auto bFunctionAdded = firstModule->AddFunction("FirstFunction");
    std::cout << "Function Adding " << (bFunctionAdded ? "Success" : "Failure") << std::endl;
    
    bFunctionAdded = firstModule->AddFunction("SecondFunction");
    std::cout << "Function Adding " << (bFunctionAdded ? "Success" : "Failure") << std::endl;

    bFunctionAdded = firstModule->AddFunction("SecondFunction");
    std::cout << "Function Adding " << (bFunctionAdded ? "Success" : "Failure") << std::endl;

    std::cout << "End\n";
    return 0;
}