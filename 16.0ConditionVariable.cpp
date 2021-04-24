#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

using namespace std;

mutex m;
condition_variable cv;
int balance = 0;

void addBalance(int money){
    cout << "> Inside Add_Balance  " << endl;
    cout << "--------------------------------" << endl;
    std::lock_guard<mutex> lg(m);
    balance += money;
    cout << "Amount Added successfully ! ! !" << endl;
    cout << "> Current balance : " << balance << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cv.notify_one();
        // Notifying condition variable to check condition again
}

void withdraw_money(int withdraw_amount){
    cout << "> Inside Withdraw_Amount " << endl;
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, [](){return (balance != 0) ? true : false;});
            // Waiting for condition to be true so as to start further execution
    if(balance < withdraw_amount){
        cout << "Error : Insufficient Amount " << endl;
    }
    else{
        cout << endl << "Transaction Successful ! ! !" << endl;
        cout << "> Deducted amount : " << withdraw_amount << endl;
        balance -= withdraw_amount;
        cout << "> Balance : " << balance << endl;
    }
    cout << "--------------------------------" << endl;
    this_thread::sleep_for(chrono::seconds(2));
}

int main(){
    
    thread t1(withdraw_money, 100);
    /*
     *  Even though withdraw_moeny get time first to execute but it will wait for
     *  addBalance() function first to complete.
     *  Because we have condition variable wait in withdraw_amount() function 
     *  that will wait till balance is added to out account.
    */
    this_thread::sleep_for(chrono::seconds(1));
    thread t2(addBalance, 500);

    t1.join();
    t2.join();

    return 0;
}
