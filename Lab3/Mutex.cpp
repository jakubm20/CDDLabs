#include "Semaphore.h"
#include <iostream>
#include <thread>

int value = 0;

void task(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << value << std::endl;
  theSemaphore->Wait();
  
  value++;
  theSemaphore->Signal();
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem(new Semaphore(1));
  /**< Launch the threads  */
  threadOne=std::thread(task, sem);
  threadTwo=std::thread(task, sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
