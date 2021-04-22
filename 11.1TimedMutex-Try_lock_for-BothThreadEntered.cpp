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
     *  In this case both will enter because we have increased waiting time and 
     *  decreased execution time for the thread which was able to enter first.
     * 
    */
    if(m.try_lock_for(seconds(2))){
        ++counter;
        this_thread::sleep_for(seconds(1));
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
    Thread 1 : 1
    Thread 2 : 2    
    
*/

