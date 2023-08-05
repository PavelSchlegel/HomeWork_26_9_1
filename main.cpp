#include <iostream>
#include "homework.hpp"

int main() {
    
    HomeWork work(20, 3);
    std::cout << work.get_result() << std::endl;
    
    HomeWork job(30, 5);
    std::cout << job.get_result() << std::endl;
    
    HomeWork make(10, 6);
    std::cout << make.get_result() << std::endl;
    return 0;
}