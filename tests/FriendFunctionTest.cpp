//
// Created by adeog on 28/06/2022.
//

#include "FriendFunctionTest.h"

FriendFunctionTest::FriendFunctionTest(string _word, int _num) {

    number = _num;
    word = _word;
    cout << word << " " << number << endl;
}

void FriendFunction(FriendFunctionTest &ff) {

    cout << "Hey I'm the friend " << endl;

}
