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