#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool IsLoggedIn()
{
	string username, password, user, passW;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	ifstream read(username + ".txt");
	getline(read, user);
	getline(read, passW);

	if (user == username && passW == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int choice;

	cout << "1: Register\n2: Login\nYour choice: ";
	cin >> choice;

	if (choice == 1)
	{
		string username, password;

		cout << "Select a username: ";
		cin >> username;
		cout << "Select a password: ";
		cin >> password;

		ofstream file;
		file.open( username + ".txt");
		file << username << endl << password;
		file.close();
		
		main();
	}
	else if (choice == 2)
	{
		bool status = IsLoggedIn();
		
		if (!status)
		{
			cout << "Incorrect Login" << endl;
			system("PAUSE");
			return 0;
		}
		else
		{
			cout << "Successfully logged in" << endl;
			system("PAUSE");
			return 0;
		}
	}
}