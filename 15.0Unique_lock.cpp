#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

using namespace std;
using namespace std::chrono;

int counter = 0;
mutex m;

void increment(const char* desc){

    std::unique_lock<mutex> lock(m);    // Since locking strategy is not specified
                                        // it will automatically lock the mutex     
    cout << "----- Mutex Locked for Thread " << desc << " -----" << endl;            
    for(int i = 0; i < 5; ++i){
        ++counter;
        cout << "Thread " << desc << " : " << counter << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }
        
    cout << "----- Mutex released by Thread " << desc << " -----" << endl;       
    // No unlocking required
    // Unlocking is based on scope as scope run out it will automatically unlock mutex
    // Destructor of the obeject will be called at that moment.
    // And that destructor will unlock it/

}

int main(){
    thread t1(increment, "1");
    thread t2(increment, "2");

    t1.join();
    t2.join();

    return 0;
}

