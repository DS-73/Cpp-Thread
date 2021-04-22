#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

using namespace std;
using namespace std::chrono;

int counter = 0;
mutex m;

void update(int x){

    while(x --> 0){
        m.lock();
        counter++;
        m.unlock();
    }
}

int main(){
    thread t1(update, 1000000);
    thread t2(update, 1000000);

    if(t1.joinable()){
        t1.detach();      // Here both the threads are updating same value
    }
    if(t2.joinable()){
        t2.detach();      // This give rise to race condition
    }

    std::this_thread::sleep_for(chrono::seconds(10));
    cout << "Counter Updated : " << counter << endl;        // Ideally it should be 2
    return 0;
}

/*

    --- Output --- 
    > Counter Updated : 2000000

*/

