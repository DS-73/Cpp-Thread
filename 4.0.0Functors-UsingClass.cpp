#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class myStructFunctor{
    private:
        int _incrementalValue;
    public:
        myStructFunctor(int x) {
            _incrementalValue = x;
        }
        int operator()(int val) const{
            return val + _incrementalValue;
        }
};

int main(){
    vector<int> v{1, 2, 3, 4, 5};
    cout << "---- Initial Vector ----" << endl;
    for(auto val : v){
        cout << val << ", ";
    }cout << endl;

    cout << endl << "Enter Incremental Value : ";
    int incrementalValue;       cin >>  incrementalValue;

    // Transforming vector
    transform(v.begin(), v.end(), v.begin(), myStructFunctor(incrementalValue));
    cout << "---- Incremented Vector ----" << endl;
    for(auto val : v){
        cout << val << ", ";
    }cout << endl;

    return 0;
}



