#include <iostream>
#include <thread>

using namespace std;

class myFunctor{
    public:
        void operator()(int x){
            while(x ++< 20){
                cout << x << ", ";
            }cout << endl;
        }
};

int main(){
    cout << "---- Functors ----" << endl;
    cout << "Output : " ;
    thread t1(myFunctor(), 0);
    t1.join();

    return 0;
}

