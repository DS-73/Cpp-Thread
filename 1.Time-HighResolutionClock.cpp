#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

int main(){
    auto startTime = high_resolution_clock ::now();
    int t = 0;
    for(int i = 0; i < INT_MAX; ++i){
        t = 1;
    }    

    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);

    cout << "Total Time Taken : " << (duration.count()/1000000) << " seconds ";

    return 0;
}

