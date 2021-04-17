/*
 *  Problem Statement -
 *  Given to integer vectors of same size add elements of of both the vector 
 *  and print result. 
 *  
 *  Test Case
 *      Input -
 *          v1 = {1, 2, 3, 4, 5}        v2 = {6, 7, 8, 9 ,10}
 *      Output -
 *          7, 9, 11, 13, 15
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(){
    auto startTime = high_resolution_clock::now();
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{6, 7, 8, 9, 10};
    
    // Initial Vector
    cout << "---- Initial Vector ---- " << endl;
    cout << " > Vector 1 : " ;
    for(int val : v1){
        cout << val << ", ";
    }cout << endl;

    cout << " > Vector 2 : " ;
    for(int val : v2){
        cout << val << ", ";
    }cout << endl;

    // Using Tranform to solve question in one line of code
    std::transform(v1.begin(), v1.end(), v2.begin(), v2.begin(), plus<int>());
    cout << "---- Final Vector ---- "<< endl;
    cout << " > Vector : ";

    // Using For each and lambda function
    for_each(v2.begin(), v2.end(), [](int x){cout << x << ", ";});
    
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);

    cout << endl << endl << "Time : " << duration.count() << " microseconds";

    return 0;
}


