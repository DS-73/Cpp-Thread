#include <iostream>
#include <thread>

using namespace std;

int counter = 0;

void update(){
    ++counter;
    cout << "Thread " << this_thread::get_id << " finished !!!" << endl; 
}

int main(){
    thread t1(update);
    thread t2(update);

    if(t1.joinable()){
        t1.detach();      // Here both the threads are updating same value
    }
    if(t2.joinable()){
        t2.detach();      // This give rise to race condition
    }

    cout << "Counter Updated : " << counter << endl;        // Ideally it should be 2

    

    return 0;
}

/*
    --- Outputs ---
        PS C:\Users\DS\Desktop\Workspace\C++ Thread\Cpp-Thread> g++ -std=c++14 -pthread -oa .\8.0RaceConditon.cpp
        PS C:\Users\DS\Desktop\Workspace\C++ Thread\Cpp-Thread> ./a.exe
        Counter Updated : 2
        n.cpp
        PS C:\Users\DS\Desktop\Workspace\C++ Thread\Cpp-Thread> ./a.exe
        Counter Updated : Thread 1 finished !!!
        2
        PS C:\Users\DS\Desktop\Workspace\C++ Thread\Cpp-Thread> g++ -std=c++14 -pthread -oa .\8.0RaceConditon.cpp
        PS C:\Users\DS\Desktop\Workspace\C++ Thread\Cpp-Thread> ./a.exe
        Counter Updated : Thread 1 finished !!!Thread 1 finished !!!

        2

*/