#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int counter = 0;
mutex m;

void increment(){
    for(int i = 0; i < 1000000; ++i){
        if(m.try_lock()){
            ++counter;
            m.unlock();
        }
    }
}

int main(){
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << "Counter : " << counter << endl;

    return 0;
}


/*

    --- Output ---
    > Counter : 938202
    > Counter : 808153
    > Counter : 614706

*/