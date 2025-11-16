#include<iostream>
using namespace std;

class AddToSum {

private:
    int initialSum;

public:

    // constructor to initialize member variable  
    AddToSum(int sum) {
        initialSum = sum;
    }

    // overload function call operator
    int operator()(int num) {
        initialSum += num;
        return initialSum;
    }

};

int main() {

    // create object of Add_To_Sum class
    // initialize member variable of object with value 100
    AddToSum add = AddToSum(100);

    // call the add object with 78 as argument
    int finalSum = add(78);

    cout << "100 + 78 = " << finalSum;

    finalSum = add(2);

    cout << "178 + 2 = " << finalSum;

    return 0;
}