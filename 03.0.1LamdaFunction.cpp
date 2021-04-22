#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // 1. Lambda function without auto 
    std::function<void(int)> lambda1 = [](int x){ cout << "Hello from lambda 1 \nValue :" << x << endl;};
    /*
     *  [] = Capture 
     *  () = Arguments Passed
     * 
     *  Lambda Function also known as anaonymus function
     * 
    */

   // Problem Statement 1
   //   Take a vector as input using find if function print first value greater than 5 
   //

    vector<int> v{1,2,4,5,6,72,2};
    auto it = std::find_if(v.begin(), v.end(), [](int x){if(x > 5){return true;} return false;});
    cout << "First value greater than 5 : " << *it << endl;

    lambda1(11);

    
}


