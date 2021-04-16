#include <iostream>
#include <thread>

using namespace std;

void func1(int x){
    while(x --> 0){
        cout << "Function 1 : " << x << endl;
    }
}

int main(){
    int x = INT8_MAX;
    thread t1(func1, x);        // Thread using Function Pointer

    while(x --> 0){
        cout << "Main : " << x << endl;
    }
    t1.join();

    return 0;
}
