#include <iostream>
#include <thread>

using namespace std;

void addtion(int a, int b){
    cout << "Sum : " << a + b;
}

void subtraction(int a, int b){
    cout << "Difference : " << a - b;
}

void multiplication(int a, int b){
    cout << "Product : " << a * b;
}

void function(int x, float y){
    cout << "----- Function Call ------ " << endl;
    cout << "Integer : " << x << endl;
    cout << "Float : " << y << endl;
}

int main(){
    /*
     *  void - Return type of function
     *  () around name of pointer otherwise it will be function declaration 
     *     that return a void pointer  
     *
     *  (int, float) - Datatype of arguments passed in the function
     *  
    */
    // Type 1
    void (*func_ptr1)(int, float) = &function;

    // Type 2
    void (*func_ptr2)(int, float);
    func_ptr2 = function;       // No need of & symbol with function name
                                // As function name carry address with itself
    func_ptr2 = &function;      // We can use & symbol as well 

    // ---- Calling pointer ----
    cout << endl << "> Call Type 1" << endl;
    (*func_ptr1)(12, 12.0012);
    cout << endl << "> Call Type 2" << endl;
    func_ptr1(12, 12.0012);
    cout << endl << "> Call Type 3 " << endl;
    (func_ptr1)(12, 12.0012);
    

    // Array of Function pointer
    //      - Can be used in place of switch
    /*
     *  Problem Statement - 
     *  On user input call addition, subtraction, multiplication function
     *
    */
    getchar();
    system("cls");

    void (*func_ptr[])(int, int) = {addtion, subtraction, multiplication};
    cout << endl << endl << "---- Main Menu ----" ;
    cout << endl << "1. Addition";
    cout << endl << "2. Subtraction";
    cout << endl << "3. Multiplication" << endl;
    
    cout << endl << "Enter your choice : ";
    int choice;         cin >> choice;

    cout << endl << "Enter X & Y : ";
    int x, y;       cin >> x >> y;

    func_ptr[choice - 1](x, y);

    return 0;
}


