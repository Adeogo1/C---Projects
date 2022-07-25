
#ifndef TESTS_FRIENDFUNCTIONTEST_H
#define TESTS_FRIENDFUNCTIONTEST_H

#include <iostream>
using namespace std;



class FriendFunctionTest {
public:
    FriendFunctionTest(string _word, int _num);
    int publicNumber;
    string publicWord;
private:
    int number;
    string word;

    friend void FriendFunction(FriendFunctionTest &ff);
};


#endif //TESTS_FRIENDFUNCTIONTEST_H
