#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

int64_t oddSum(int64_t start, int64_t end){
    int64_t sum = 0;
    for(int i = start; i <= end; ++i){
        if(i & 1){
            sum += i;
        }
    }
    return sum;
}

int64_t evenSum(int64_t start, int64_t end){
    int64_t sum = 0;
    for(int i = start; i <= end; ++i){
        if(!(i & 1)){
            sum += i;
        }
    }
    return sum;
}

int main(){
    int64_t start = 1, end = 1900000000;
    
    auto startTime = high_resolution_clock::now();
    
    // Function Calls
    int64_t sum1 = oddSum(start, end);
    int64_t sum2 = evenSum(start, end);
    
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
        Total Time Taken : 12 seconds

*/

