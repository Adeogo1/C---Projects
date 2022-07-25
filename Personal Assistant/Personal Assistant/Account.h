#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <conio.h>
#include "assistant.h"
#include "Utilities.h"
#include "MaleVoice.h"
#include "FemaleVoice.h"

using namespace std;


static long int IDs = 0;
const string ALLACOUNTSFILE = "AllAccounts.csv";


	enum IN {

		// 13 is ASCII for carriage
		// return
		IN_BACK = 8,
		IN_RET = 13

	};

	struct UserData {//Stores info about user

	};


	template<typename Base, typename T>
	inline bool instanceof(const T* ptr) {
		return dynamic_cast<const Base*>(ptr) != nullptr;
	}

	class Assistant;
class Account
{

private:
	Account()
	{
		m_UsingAccount = false;
	}
	unsigned int m_ID;
	string m_Name;
	string m_ActiveName;
	string m_Password;
	string m_AssistantName;
	UserData* m_storedData;
	Assistant *m_Assistant;
	bool m_UsingAccount;
	
	static Account* instance;
	string takePasswdFromUser();
	void InitUserData();
	bool Login();
	bool GuestAccount();
	bool Register();

public:
	static Account* Instance() {
		if (!instance)
			instance = new Account;
		return instance;
	}
	
	bool Init();
	inline string GetName() {return m_Name;}
	inline string GetActiveName() {return m_ActiveName;}
	inline string GetAssistantName() {return m_AssistantName;}
	Assistant* GetAssistant() { return m_Assistant; }
	void UpdateAccount();
	void UpdateUserData();
	void ChangeAssistantName();
	void ChangeAssistantVoice();
	void ChangeActiveName();
	void ChangePassword();

	
	~Account();

};



