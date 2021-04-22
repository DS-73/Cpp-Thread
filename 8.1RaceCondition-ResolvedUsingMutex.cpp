#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int counter = 0;
std::mutex m;

void update(){
    
    m.lock();
    cout << "Locked Inside thread " << this_thread::get_id << " !!!" << endl;
    this_thread::sleep_for(chrono::seconds(5));
    ++counter;
    cout << "Unlocked Thread " << this_thread::get_id << " finished !!!" << endl; 
    m.unlock();
}

int main(){
    thread t1(update);
    thread t2(update);

    this_thread::sleep_for(chrono::seconds(12));
    cout << "Counter Updated : " << counter << endl;        // Ideally it should be 2
    t1.detach();
    t2.detach();
    return 0;
}

