#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> theSemaphore, int *count){
  theSemaphore->Wait();
  ++*count;
  theSemaphore->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> theSemaphore, int *count){
  theSemaphore->Wait();
  ++*count;
  theSemaphore->Signal();
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> mutex(new Semaphore(1));
  int count = 0;
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo, mutex, &count);
  threadTwo=std::thread(taskOne,mutex, &count);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();

  std::cout << count << std::endl;
  return 0;
}
