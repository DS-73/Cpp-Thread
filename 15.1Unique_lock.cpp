#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

using namespace std;
using namespace std::chrono;

int counter = 0;
mutex m;

void increment(const char* desc){

    std::unique_lock<mutex> lock(m, std::defer_lock);   
                // Our thread own the mutex but it is not locked yet    
    cout << "----- Mutex Locked for Thread " << desc << " -----" << endl;            
    for(int i = 0; i < 5; ++i){
        ++counter;
        cout << "Thread " << desc << " : " << counter << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }
        
    cout << "----- Mutex released by Thread " << desc << " -----" << endl;    
    // m.unlock() is not required as it will unlock itself 
    // when the destructor of unique lock will be called   

}

int main(){
    thread t1(increment, "1");
    thread t2(increment, "2");

    t1.join();
    t2.join();

    return 0;
}

