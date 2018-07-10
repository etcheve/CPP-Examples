#include <iostream>
#include <thread>
#include <mutex>

static int counter = 0;
static std::mutex myMutex;

void increment() {
  //Use RAII to keap lock
  std::lock_guard<std::mutex> guard(myMutex);
  counter = counter + 1;
}

int main(){
  increment();
  std::cout << counter;
}
