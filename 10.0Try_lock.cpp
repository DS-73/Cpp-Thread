#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using namespace std::chrono;

int x = 0, y = 0;
mutex m1, m2;

void doSomeWorkForSeconds(int second){this_thread::sleep_for(seconds(second));}

void incrementXY(int& XorY, mutex& m, const char* desc){
    for(int i = 0; i < 5; ++i){
        m.lock();
        ++XorY;
        cout << desc << " : " << XorY << endl;
        m.unlock();
        doSomeWorkForSeconds(1);
    }
}

void consumeXY(){
    int userCount = 5;
    int XplusY = 0;
    while(1){
        int lockResult = std::try_lock(m1, m2);
        if(lockResult != -1){
            if(x != 0 && y != 0){
                --userCount;
                XplusY += x + y;
                x = 0;
                y = 0;
                cout << "XplusY : " << XplusY << endl;
            }
            m1.unlock();
            m2.unlock();
        }
        if(userCount == 0){
            break;
        }
    }
}

int main(){
    thread t1(incrementXY, std::ref(x), std::ref(m1), "X ");
    thread t2(incrementXY, std::ref(y), std::ref(m2), "Y ");
    
    thread t3(consumeXY);
    
    t1.join();
    t2.join();
    t3.join();

    return 0;
}

/*
        --- Output ---
    X  : XplusY : 2
    Y  : 0
    0
    X  : 0
    Y  : 0
    XplusY : 4
    Y  : 0
    XplusY : 6
    X  : 0
    Y  : 0
    X  : 0
    XplusY : 8
    Y  : 0
    XplusY : 10
    X  : 0

*/