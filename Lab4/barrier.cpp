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
  std::cout << "Thread is at barrier and waiting" << std::endl;
  if(count == n){
    barrierB->Wait();//lock second barrier
    barrierA->Signal();//open first barrier
  }
  mutex->Signal();
  
  barrierA->Wait();//lock first barrier
  barrierA->Signal();//open first barrier

  mutex->Wait();
  count--;
  if(count == 0){
    std::cout << "Threads finished" << std::endl; 
    barrierA->Wait();//lock first barrier
    barrierB->Signal();//open second barrier
  }
  mutex->Signal();
  
  barrierB->Wait();//lock second barrier
  barrierB->Signal();//open first barrier
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



