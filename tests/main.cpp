#include <iostream>
#include <set>
#include <array>
#include <list>
#include "FriendFunctionTest.h"
using namespace std;


void Increment(int &a);
long long Factorial(long n);

int main() {
    std::cout << "Hello, World!" << std::endl;


    int idk[] = {1,2,3,6,5,6,7,8,9,0};

    cout << idk[3]<<endl;
    cout << 3[idk] <<endl;
    cout << *(idk)+3 <<endl;
    cout << *(idk+3) <<endl;

    FriendFunctionTest ff("yoo",123);
    FriendFunction(ff);

    set<int> naturallyOrderedList;

    naturallyOrderedList.insert(1);
    naturallyOrderedList.insert(2);
    naturallyOrderedList.insert(3);
    naturallyOrderedList.insert(5);
    naturallyOrderedList.insert(4);
    naturallyOrderedList.insert(0);



    for (int s: naturallyOrderedList) {
        cout << s << endl;
    }

    int x = 4;
    int *pX = &x;

    int **p = &pX;

    cout << "if i do just px i get " << pX << endl;
    cout << "if i do just *px i get " << *pX << endl;
    cout << "if i do just &px i get " << &pX << endl;

    cout << "The value at the new px is " << &p << endl;
    cout << "The value at the new px is " << *p;

    cout << endl;
    cout << endl;
    Increment(*pX);
    cout << *pX << endl;

    int arr[4][5] = {
            1,2,4,4,5,
            6,7,8,9,10,
            11,12,13,14,15,
            16,17,18,19,20
    };
    int (*pArr)[5] = arr;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout <<*(*pArr + j) + i  << " ";
        }
        cout << endl;
    }




    return 0;
}

void Increment(int &a){
    a += 1;
}

long long Factorial(long n){
    if(n <= 1) return n;
    return n * Factorial(n - 1);
}


