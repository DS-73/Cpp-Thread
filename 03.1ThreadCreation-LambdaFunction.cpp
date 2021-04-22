#include <iostream>
#include <thread>

using namespace std;

int main(){

    // 1. Creating lambda function and then using
    auto func = [](int x){
        while(x --> 0){
            cout << x << endl;
        }
    };

    thread t1(func, 20);
    t1.join();    

    // 2. Directly putting the content in thread
    thread t2([](int x){
        while(x --> 0){
            cout << x << endl;
        }
    },12);
    t2.join();
    
    return 0;
}
