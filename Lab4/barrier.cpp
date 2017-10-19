//Jakub Michalec
#include "Semaphore.h"
#include <iostream>
#include <thread>

//Creating a reusable barrier

int count = 0; //thread count
int n = 3; //number of threads

void task(std::shared_ptr<Semaphore> mutex, std::shared_ptr<Semaphore> barrierA, std::shared_ptr<Semaphore> barrierB){
  mutex->Wait();
  count++;
  std::cout << count << std::endl; 
  if(count == n){
    barrierB->Wait();
    barrierA->Signal();
  }
  mutex->Signal();
  
  barrierA->Wait();
  barrierA->Signal();

  mutex->Wait();
  count--;
  if(count == 0){
    barrierA->Wait();
    barrierB->Signal();
  }
  mutex->Signal();
  
  barrierB->Wait();
  barrierB->Signal();
}

int main(){
  std::thread threadOne, threadTwo, threadThree;
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  std::shared_ptr<Semaphore> barrierA( new Semaphore());
  std::shared_ptr<Semaphore> barrierB( new Semaphore(1));
  /**< Launch the threads  */
  threadOne=std::thread(task, mutex, barrierA, barrierB);
  threadTwo=std::thread(task, mutex, barrierA, barrierB);
  threadThree=std::thread(task, mutex, barrierA, barrierB);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  return 0;
}



