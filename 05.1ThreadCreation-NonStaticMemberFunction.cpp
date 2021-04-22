#include <iostream>
#include <thread>

using namespace std;

class myClass{
    /*
     *   Here the member function must be public so we can access it 
     *   ouside the class using member function.
    */
    public:
    // Non static method 
        void solve(int x){
            while(x ++< 10){
                cout << x << ", ";
            }cout << endl;
        }
};

int main(){
    myClass obj;
    // Used non static method for creating threads
    /*
     *  Here in this case we need an object of class so as to call the fucntion 
     *  As non static functions are associated with object only.
     * 
     *  So we cannot eliminate object in this case
     * 
    */
    thread t1(&myClass::solve, &obj, 0);
    t1.join();

    return 0;
}