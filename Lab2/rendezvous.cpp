#include "Semaphore.h"
#include <iostream>
#include <thread>
//Task: B1 always print before A1, and A2 always print before B2. 

void taskOne(std::shared_ptr<Semaphore> sem1,std::shared_ptr<Semaphore> sem2){
  std::cout << "A1"<<std::endl;
  sem1->Signal();
  sem2->Wait();
  std::cout << "A2"<<std::endl;
}
void taskTwo(std::shared_ptr<Semaphore> sem1,std::shared_ptr<Semaphore> sem2){
  std::cout << "B1"<<std::endl;
  sem2->Signal();
  sem1->Wait();
  std::cout << "B2"<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskOne, sem1, sem2);
  threadTwo=std::thread(taskTwo, sem1, sem2);

  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
