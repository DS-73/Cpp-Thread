#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>

using namespace std;

int counter = 0;
mutex m;

void increment(const char *desc){
    std::lock_guard<mutex> loc(m);
    for(int i = 0; i < 5; ++i){
        ++counter;
        cout << "Thread " << desc << " : " << counter << endl;
        std::this_thread::sleep_for(chrono::seconds(1));
    }
}

int main(){
    thread t1(increment, "1");
    thread t2(increment, "2");
    
    t2.join();
    t1.join();

    return 0;
}

 