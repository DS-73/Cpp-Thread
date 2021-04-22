#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

int64_t sum1 = 0, sum2 = 0;

void oddSum(int64_t start, int64_t end){
    int64_t sum = 0;
    for(int i = start; i <= end; ++i){
        if(i & 1){
            sum += i;
        }
    }
    sum1 = sum;
}

void evenSum(int64_t start, int64_t end){
    int64_t sum = 0;
    for(int i = start; i <= end; ++i){
        if(!(i & 1)){
            sum += i;
        }
    }
    sum2 = sum;
}

int main(){
    int64_t start = 1, end = 1900000000;
    
    auto startTime = high_resolution_clock::now();
    
    // Function Calls
    thread t1(oddSum, start, end);
    thread t2(evenSum, start, end);

    t1.join();      t2.join();
    
    cout << "Total Odd Sum : " << sum1 << endl;
    cout << "Total Even Sum : " << sum2 << endl;  
    
    auto endTime = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(endTime - startTime);
    cout << "Total Time Taken : " << duration.count()/1000000 << " seconds";

    return 0;
}


/*
            ------ Output ------

        Total Odd Sum : 902500000000000000
        Total Even Sum : 902500000950000000
        Total Time Taken : 6 seconds

*/

