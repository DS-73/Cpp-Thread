/*
 *
 *  Recursive Mutex 
 *  - This is a demonstration of recursive mutex using for loop
 *      In this program we have shown we can lock single mutex multiple times 
 *      with same thread.
 *      Till we do not unlock mutex for each time we locked it.
 *      
 * 
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using namespace std::chrono;

int val = 0;
recursive_mutex m ;

void increment(const char* desc){
    // Checking for mutex availability 
    while(!m.try_lock()){
        cout << "Thread " << desc << " : " << "Unable to lock " << endl;
        this_thread::sleep_for(seconds(2));
    }

    // Got mutex here
    cout << "--- Thread T" << desc << " Locked --- " << endl;
    for(int i = 0; i < 5; ++i){
        m.lock();
        ++val;
        cout << "Thread " << desc << " : " << val << endl; 
        this_thread::sleep_for(seconds(1));
    }

    for(int i = 0; i < 5; ++i){
        ++val;
        cout << "Thread " << desc << " : " << val << endl; 
        this_thread::sleep_for(seconds(1));
        m.unlock();
    }
    // Unlocked mutex and returing back form here
    m.unlock();
}

int main(){
    // Locked mutex for main thread
    for(int i = 0; i < 5; ++i){
        m.lock();
        ++val;
        cout << "Main Thread  : " << val << endl;
        this_thread::sleep_for(seconds(1));
    }

    // Started Thread 
    //  Unable get mutex for this thread so it will be waiting
    cout << "--- Thread T1 Started --- " << endl;
    thread t1(increment, "1");

    // Loop for unlocking mutex 
    for(int i = 0; i < 5; ++i){
        this_thread::sleep_for(seconds(1));
        ++val;
        cout << "Main Thread  : " << val << endl; 
        m.unlock();
    }

    // Joined thread 
    t1.join();
    this_thread::sleep_for(seconds(1));

    return 0;
}

