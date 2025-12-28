#include <iostream>
#include <thread>
#include "singleton.hpp"


void ThreadFoo(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getSingleton(1);
    std::cout << singleton->getValue() << "\n";
}

void ThreadBar(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getSingleton(2);
    std::cout << singleton->getValue() << "\n";
}


int main()
{
    std::cout <<"This implementation is not thread safe, so if values are different two instances were created\n\n" <<
                "RESULT:\n";   
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}