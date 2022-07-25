#include "bits-stdc++.h"
#include <sapi.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <winsock.h>
#include "Account.h"
using namespace std;


int main()
{
    Account* User = Account::Instance();
    
    while (User->Init())
    {
        User->GetAssistant()->clock();
        User->GetAssistant()->greeting();
        User->GetAssistant()->repeat();
    }

    return 0;
}










