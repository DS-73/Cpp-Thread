#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono;

void run(int x){
    while(x --> 0){
        cout << "RUN : " << x << endl;
    }this_thread::sleep_for(seconds(5));

}

int main(){
    thread t1(run, 10);
    cout << "Before thread" << endl;

    if(t1.joinable()){
        t1.detach();
    }

    cout << "After Thread";
	this_thread::sleep_for(seconds(5));
    return 0;
}
