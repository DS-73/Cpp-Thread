#include <iostream>
#include <thread>

using namespace std;

class myClass{
    /*
     *   Here the member function must be public so we can access it 
     *   ouside the class using class name.
    */
    public:
        static void solve(int x){
            while(x ++ < 10){
                cout << x << ", ";
            }cout << endl;
        }
};

int main(){
    /*
     *   Creating thead without using object of the class.
     *   As the function that we are calling is a static function we can call it with base name.
     *   
    */
    thread t(&myClass::solve, 0);
    t.join();

    return 0;
}