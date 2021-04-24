#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
using namespace std::chrono;

recursive_mutex m;
int val  = 0;

void recursion(int ForLoop, const char * desc){
    if(ForLoop <= 0){
        return;
    }
    m.lock();
    ++val;
    cout << "Thread " << desc << " : " << val << endl;
    this_thread::sleep_for(seconds(1));
    recursion(ForLoop - 1, desc);
    m.unlock();

}

int main(){
    thread t1(recursion, 10, "1");
    thread t2(recursion, 10, "2");

    t1.join();
    t2.join();

    return 0;
}

