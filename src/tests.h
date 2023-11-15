#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <functional>
#include <module.h>

namespace tests
{

    class Test{
        std::string _name{};
        std::function<bool()> _testFunctor = [this]()->bool{return false;};
    public:
        Test(std::string name, const std::function<bool()>& testFunction){
            _name = name;
            _testFunctor = testFunction;
        }
        std::string Run(){
            const bool bSuccess = _testFunctor();
            return "Test with Name " + _name + (bSuccess ? "Succeded" : "Failed");
        };
    };

    class ModuleTestSuite{
        std::vector<std::unique_ptr<Test>> _tests{};
        std::unique_ptr<Module> _module;
        public:

        ModuleTestSuite(std::unique_ptr<Module> module) : _module{std::move(module)}{
        }

        void AddTest(std::string name, const std::function<bool()>& testFunction){
            _tests.push_back(std::make_unique<Test>(name, testFunction));
        };

        void RunTests() const{
            for(const auto& test : _tests){
                std::cout << test->Run() << std::endl;
            }
        };        
        
    };
    
} // namespace tests

