#include "Account.h"

Account* Account::instance = nullptr;

bool Account::Init()
{
	if (m_UsingAccount)
	{
		cerr << "account already in use " << endl;
		return true;
	}
	

	while (!m_UsingAccount)
	{

	int choice;
	cout << "Do you want to \nLogin(1)\nRegister(2)\nGuest Account(3)" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		m_UsingAccount = Login();
		break;
	case 2:
		m_UsingAccount = Register();
		break;
	case 3:
		m_UsingAccount = GuestAccount();
	default:
		GuestAccount();
		break;
	}
	}
	m_UsingAccount = true;
}

string Account::takePasswdFromUser()
{
	// Stores the password
	string passwd = "";
	char charInput;
	char sp = '*';
	// Until condition is true
	while (true) {

		charInput = _getch();

		// if the ch_ipt
		if (charInput == IN::IN_RET) {
			cout << endl;
			return passwd;
		}
		else if (charInput == IN::IN_BACK
			&& passwd.length() != 0) {
			passwd.pop_back();

			// Cout statement is very
			// important as it will erase
			// previously printed character
			cout << "\b \b";

			continue;
		}

		// Without using this, program
		// will crash as \b can't be
		// print in beginning of line
		else if (charInput == IN::IN_BACK
			&& passwd.length() == 0) {
			continue;
		}

		passwd.push_back(charInput);
		cout << sp;
	}
}
void Account::InitUserData()
{
	m_storedData = nullptr;
}
bool Account::Login()
{
	string Name;
	string Password;
	cout << "Enter your name: " << endl;
	cin >> Name;
	cout << "What do you want to be called: " << endl;
	cin >> Password;
	string fileName = Name + ".csv";
	fstream file(fileName);
	string line = "";
	vector<string>dataList;
	if (!file.is_open())
	{
		remove(fileName.c_str());
		return false;
	}
	while (file.good())
	{
	getline(file, line, ',');
	dataList.push_back(line);

	}
	if (Password.compare(dataList[3]) == 0)
	{
		m_ID = stoi(dataList[0]);
		m_Name = dataList[1];
		m_ActiveName = dataList[2];
		m_Password = dataList[3];
		m_AssistantName = dataList[4];
		if (dataList[5] == "f")
		{
			m_Assistant = new Assistant(m_AssistantName, "f");
		}
		else
		{
			m_Assistant = new Assistant(m_AssistantName, "m");
		}
		return true;
	}
	remove(fileName.c_str());
	return false;
}

bool Account::Register()
{
	IDs++;
	char assistantGender;
	cout << "Enter your name: " << endl;
	cin >> m_Name;
	cout << "What do you want to be called: " << endl;
	cin >> m_ActiveName;
	cout << "Create a password " << endl;
	m_Password = takePasswdFromUser();
	cout << "What is Assistant Gender (M/F) " << endl;
	cin >> assistantGender;
	InitUserData();
	//Utilities::LowerCase(&assistantGender);
	switch (assistantGender)
	{
	case 'm':
		m_Assistant = new Assistant(m_AssistantName, "m");
		break;
	case 'f':
		m_Assistant = new Assistant(m_AssistantName, "f");
		break;
	default:
		m_Assistant = new Assistant(m_AssistantName, "f");
		break;
	}


	string fileName = m_Name + ".csv";
	fstream file(fileName);
	string dataFileName = m_Name + "Data.csv";
	fstream userDatafile(dataFileName);
	if (file.is_open())
	{
		cout << "File Exists";
		
		file.close();
		remove(fileName.c_str());
		return false;
	}
	else
	{
		cout << "Opening a new File" << endl;
	}

	if (userDatafile.is_open())
	{
		cout << "File Exists";
		userDatafile.close();
	}
	else
	{
		cout << "Opening a new File" << endl;
		userDatafile.open(dataFileName, ios::app);
		//userDatafile << "ID" << "," << "Name" << "," << "Password" << "," << "Assistance Gender" << endl;
		userDatafile.close();
	}
	UpdateAccount();
	return true;

}

void Account::UpdateAccount()
{
	string fileName = m_Name + ".csv";
	fstream file(fileName);
	string dataFileName = m_Name + "Data.csv";
	fstream userDatafile(dataFileName);

	char AssistanceGender = m_Assistant->GetGender() == 'm' ? 'm' : 'f';

	file.open(fileName);
	file << m_ID << "," << m_Name << "," << m_ActiveName << "," << m_Password << "," << m_AssistantName << "," << AssistanceGender << endl;
	file.close();

	userDatafile.open(dataFileName);
	//userDatafile << user->ID << user->Name << user->ActiveName << user->Password << user->personalAssistantVoice << endl;
	userDatafile.close();
}

void Account::UpdateUserData()
{
}

bool Account::GuestAccount()
{
	m_ID = 0;
	m_Name = "";
	m_ActiveName = "Master";
	m_AssistantName = "Amirah";
	m_Password = "";
	m_Assistant = new Assistant(m_AssistantName, "f");
	InitUserData();
	return true;
}

Account::~Account()
{
}