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