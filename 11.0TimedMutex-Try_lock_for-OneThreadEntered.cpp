#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using namespace std::chrono;

int counter = 0;
timed_mutex m;

void increment(int i){
    /*
     *
     *  Thread that will be unable to enter will print its output first as 
     *  other thread will be busy in execution 
     *
    */
    if(m.try_lock_for(seconds(1))){
        ++counter;
        this_thread::sleep_for(seconds(2));
        cout << "Thread " << i << " : " << counter << endl;
        m.unlock();
    }
    else{
        cout << "Thread " << i << " : Unable to enter " << endl;
    }
}

int main(){
    thread t1(increment, 1);
    thread t2(increment, 2);
    
    t1.join();
    t2.join();

    return 0;
}


/*
        --- Output ---
    Thread 2 : Unable to enter 
    Thread 1 : 1
    
*/
