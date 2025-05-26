#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include <limits> // Needed for paue
#include <cstdlib> // for clear console


using namespace std;

int number_of_user = 5;
string confirmpassword;

int admin_acc = 5;

struct user
{
	string name;
	unsigned long long phn;
	long long pin;														// USER STURCTURE
	string password;
	unsigned long long balance;


};    

user U[100];

struct Admin_data
{
	string name;										//ADMIN STUCTURE
	long pin;
};

Admin_data admin[10];

void Account_initialize()
{
	U[1].name = "samer awais";
	U[1].phn = 1234567890;
	U[1].pin = 1234;
	U[1].password = "samer123";
	U[1].balance = 100000;

	U[2].name = "jawad";
	U[2].phn = 3225326245;
	U[2].pin = 5678;
	U[2].password = "jawad890";
	U[2].balance = 100000;													// ACOUNTS INITIALIZATION

	U[3].name = "alia khan";
	U[3].phn = 3154456677;
	U[3].pin = 4321;
	U[3].password = "alia321";
	U[3].balance = 100000;

	U[4].name = "hassan raza";
	U[4].phn = 3009988776;
	U[4].pin = 8765;
	U[4].password = "hassan98";
	U[4].balance = 100000;

}

int Digit(unsigned long long  n)
{
	int count = 0;
	if (n == 0)
		return 1;

	while (n != 0)									// FUNCTION TO CHECK PHONE NUMBER HAS 10 DIGITS
	{
		n = n / 10;
		count++;
	}
	return count;
}

void Account_registration()
{
	number_of_user++;

	cout << "Enter name : ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer so that it does not skip the line
	getline(cin, U[number_of_user].name);							// NAME SET


	cout << endl;

	int store = 10;
	do
	{
		if (store != 10)
			cout << "\n INVALID number !!!!" << endl;
		cout << "Enter Phone number (format 32011223344) : ";
		cin >> U[number_of_user].phn;								// PHONE SET
		unsigned long long phn_clone = U[number_of_user].phn;
		store = Digit(phn_clone);

	} while (store != 10);

	cout << endl;

	cout << endl;

	
	cout << "Enter Password : ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer
	getline(cin, U[number_of_user].password);						// PASSWORD SET

	bool a;
	do
	{
		cout << "\n Confirm your password : ";
		getline(cin, confirmpassword);

		if (confirmpassword == U[number_of_user].password)
		{

			cout << " Account Succesfully Registered" << endl;		// PASSWORD CONFIRM 
			a = 1;
		}
		else
		{
			cout << "Invalid Password " << endl;
			a = 0;
		}

	} while (a == 0);

	U[number_of_user].balance = 0;
	system("pause");      // Waits for user to press Enter
	system("cls"); // For Windows
}

int Account_login(unsigned long long a, string b)
{
	for (int i = 1; i < number_of_user; i++)
	{
		if (U[i].phn == a)
		{
			if (U[i].password == b)
			{

				return i;											// USER LOGIN FUNCTION 

			}
			else
			{
				cout << "\n Incorrect password : ";
				return 0;
				system("pause");      // Waits for user to press Enter
				system("cls"); // For Windows
			}
		}
	}
}

void Account()
{
	system("cls"); // For Windows
	cout << "***REGISTERED ACCOUNTS***" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "|" << setw(30) << "NAME" << "|" << setw(10) << "PHONE NUMBER" << endl;

	cout << "--------------------------------------------------------" << endl;					// SHOWS ACCOUNT'S PHONE AND NAME DETAILS
	for (int i = 1; i < number_of_user; i++)
	{
		cout << "|" << setw(30) << U[i].name;
		cout << "|" << setw(30) << U[i].phn;
		cout << endl;
	}
	cout << "--------------------------------------------------------" << endl;
}

int Admin_login()
{
	admin[0].name = "admin";
	admin[0].pin = 1357;

	admin[1].name = "admin2";
	admin[1].pin = 246;
																// ADMIN LOGIN FUNCTION
	system("cls"); // For Windows

	string dumy_name;
	long dumy_pin;
	int flag = 1;
	cout << "**** ADMIN LOGIN ****" << endl;
	cout << "\n Name : ";
	cin >> dumy_name;
	cout << "\n Pin : ";
	cin >> dumy_pin;
	for (int i = 0; i < admin_acc; i++)
	{
		if (admin[i].name == dumy_name)						// COMPARES NAME 
		{
			if (admin[i].pin == dumy_pin)					// COMPARES PIN 
			{
				return 1;
				flag = 0;
			}
			else
			{
				cout << "\n Invalid Password";
				return 0;

			}
		}

	}
	if (flag == 1)
	{
		cout << "\nAccess Denied!!!!";
		system("pause");      // Waits for user to press Enter
		system("cls"); // For Windows
	}
}

void Admin_operation()
{
	int choice2;
	char choice;
	unsigned long long dumy_phn;;
	int option;

	do
	{
		system("cls"); // For Windows

		Account();
		cout << "WHat Do You want to change" << endl;
		cout << "1.Add\t\t2.Remove\t\t3.Update\t\t4.SHow Table\t\t5. Exit" << endl;
		cin >> option;
		system("cls"); // For Windows

		if (option == 1)																// ADMIN ADD OPERATION
		{
			cout << "****ADD Account Manually****" << endl;
			cout << "--------------------------------------------------------" << endl;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer so that it does noot skip the line

			cout << "Name : ";
			getline(cin, U[number_of_user].name);
			cout << "\nPhone : ";
			cin >> U[number_of_user].phn;
			cout << "\nPIN : ";
			cin >> U[number_of_user].pin;
			cout << "\nPassword : ";
			cin >> U[number_of_user].password;
			U[number_of_user].balance = 0;

			cout << "--------------------------------------------------------" << endl;
			cout << "Changes made Succesfully**" << endl;
			number_of_user++;
			system("pause");      // Waits for user to press Enter
			system("cls"); // For Windows



		}
		else if (option == 2)														// ADMIN REMOVE OPERATION
		{
			Account();
			cout << "****REMOVE Account Manually****" << endl;

			cout << "Enter Phone Number Of Account To Remove : ";
			cin >> dumy_phn;
			int checker = 0;
			for (int i = 1; i < number_of_user; i++)
			{
				if (U[i].phn == dumy_phn)
				{
					checker = i;
				}
			}
			if (checker == 0)
			{
				cout << "INVALID Phone Number!! " << endl;
				system("pause");      // Waits for user to press Enter
				system("cls"); // For Windows

			}
			else
			{
				U[checker].name = " - ";
				U[checker].phn = 0;
				U[checker].password = " - ";
				U[checker].pin = 0;


				string temp_name, temp_password;
				unsigned long long temp_phn;
				long temp_pin;
				int acc_value = checker;
				for (int i = checker; i < number_of_user; i++)
				{
					acc_value++;
					if (acc_value > number_of_user)
					{
						number_of_user--;
					}
					else
					{

						temp_name = U[i].name;
						temp_phn = U[i].phn;
						temp_password = U[i].password;
						temp_pin = U[i].pin;
																				// REMOVES EMPTY SAPCE
						U[i].name = U[acc_value].name;
						U[i].phn = U[acc_value].phn;
						U[i].password = U[acc_value].password;
						U[i].pin = U[acc_value].pin;

						U[acc_value].name = temp_name;
						U[acc_value].phn = temp_phn;
						U[acc_value].password = temp_password;
						U[acc_value].pin = temp_pin;

					}
				}
				number_of_user--;
				cout << "\n Cjanges Made Successfuly !!!!" << endl;

			}


		}
		else if (option == 3)													// ADMIN UPDATE DATA OPERATION
		{
			int flag;
			do
			{
				flag = 1;
				if (flag == 0)
				{
					cout << "Retry Phone Number " << endl;
					system("pause");      // Waits for user to press Enter
					system("cls"); // For Windows

				}

				cout << "*UPDATE" << endl;
				cout << "Enter Phone Number Of ACC To Update : ";
				cin >> dumy_phn;
				int checker = 0;
				for (int i = 1; i < number_of_user; i++)
				{
					if (U[i].phn == dumy_phn)							// CHECK'S PHONE NUMBER
					{
						checker = i;
					}
				}
				if (checker == 0)
				{
					cout << "INVALID Phone Number!! " << endl;
					flag = 0;
				}
				else
				{

					cout << ": Select A Choice To Update : \n1. Name\t\t2. Phone Number\n3. Pin\t\t4. Password\n5. Exit\t\t 6. Show Account \n CHOICE :";
					cin >> choice2;
					if (choice2 == 1)
					{
						cout << "Enter new Name : ";
						cin >> U[checker].name;

						cout << endl;
					}
					else if (choice2 == 2)
					{
						cout << "Enter new PHONE NUMBER : ";
						cin >> U[checker].phn;
						cout << endl;
					}
					else if (choice2 == 3)
					{
						cout << "Enter new PIN : ";
						cin >> U[checker].pin;
						cout << endl;
					}
					else if (choice2 == 4)
					{
						cout << "Enter new Password : ";
						cin >> U[checker].password;
						cout << endl;
					}
					else if (choice2 == 5)
					{
						continue;
					}
					else
					{
						cout << " Invalid Choice!!!" << endl;
						flag = 0;
					}

				}
			} while (flag == 0);
			cout << "Changes Made Successfully " << endl;
			system("pause");      // Waits for user to press Enter
			system("cls"); // For Windows
		}
		else if (option == 4)
		{																// SHOWS ACCOUNT'S
			Account();
			cout << endl;
		}
		else if (option == 5)
		{
			choice = 'n';
		}

		else
		{
			cout << "\t DO You Want To Perform Another Option ' Y ' : ";
			cin >> choice;
			}
		

	} while (choice == 'y' || choice == 'Y');



}
	
int User_operation(int acc, int operation)										// FUNCTIONS USER CAN PERFORM
{
	int n;
	switch (operation)
	{
	case 1:
		cout << "\n**** BALANCE INQUERY ****" << endl << U[acc].balance;
		break;
	case 2:
		cout << "\n**** Deposit ****" << endl;
		cout << "\n Amount : ";
		cin >> n;
		U[acc].balance = U[acc].balance + n;
		cout << "\n Cash Deposited SUCESSFULLY !!!!" << endl;
		break;
	case 3:
		cout << "\n **** WITHDRAW ****" << endl;
		cout << "\n Amount : ";
		cin >> n;
		U[acc].balance = U[acc].balance - n;
		cout << "\n Cash Withdraw SUCESSFULLY !!!!" << endl;
		break;
	case 4:
		return 1;
		break;
	default:
		return 0;



	}

}

int main()
{
	Account_initialize();
	int op, flag = 1, menu, acc_number, flag2;
	char op2, exit;
	string login_password;
	unsigned long long login_phone;
	do
	{
		do
		{
			system("cls"); // For Windows
			if (flag == 0)
			{
				cout << "\n *** Retry ***" << endl;
			}
			cout << "1. Login 2. Signup 3. Admin Access \n....";
			cin >> op;

			if (op == 2)														// SIGN UP CALL
			{
				system("pause");											 // Waits for user to press Enter
				system("cls");												// For Windows
				cout << "\n **** SIGN UP ****"<<endl;
				Account_registration();
				system("pause");										// Waits for user to press Enter
				system("cls");											// For Windows
				cout << "**** LOGIN ****" << endl;						// LOGIN FUNCTION CALL AFTER SIGN UP
				cout << "Enter Phone Number : ";
				cin >> login_phone;
				cout << "\n Enter Password : ";
				cin >> login_password;
				acc_number = Account_login(login_phone, login_password);
				cout << "\n--- Login Sucessful ---" << endl;
				char ch;
				do
				{
					system("pause");      // Waits for user to press Enter
					system("cls"); // For Windows
					if (flag == 0)
					{
						cout << "\n RETRY ";
					}
					cout << "MAIN MENU" << endl;
					cout << "1. Balance Check\t\t2. Deposit\t\t3.Withdraw\t\t4. EXIT" << endl << ".... : ";
					cin >> menu;
					int flag = User_operation(acc_number, menu);
					if (flag != 0)
					{
						cout << "\n DO YOU WANT TO PERFORM OTHER OPERATION !!!!  'Y' .......... ";
						cin >> ch;
					}

				} while (flag == 0 || ch == 'y' || ch == 'Y');

			}
			else if (op == 3)
			{																		// ADMIN LOGIN FUNCTION CALL
				int validate = Admin_login();
				if (validate == 1)
				{
					Admin_operation();											// ADMIN OPERATION'S FUNCTION CALL
				}
				else
					flag = 0;

			}
			else if (op == 1)
			{																		// LOGIN FUNCTION CALL
				do
				{
					system("pause");      // Waits for user to press Enter
					system("cls"); // For Windows
					cout << "**** LOGIN ****" << endl;
					cout << "Enter Phone Number : ";
					cin >> login_phone;
					cout << "\n Enter Password : ";
					cin >> login_password;
					acc_number = Account_login(login_phone, login_password);

					if (acc_number == 0)
					{
						cout << "\nDo you want to Signup ' Y ' : ";
						cin >> op2;
						if (op2 == 'Y' || op2 == 'y')
						{
							Account_registration();
						}

					}

				} while (acc_number == 0);
				cout << "\n--- Login Sucessful ---" << endl;
				char ch;
				do
				{
					system("pause");      // Waits for user to press Enter
					system("cls"); // For Windows
					if (flag == 0)
					{
						cout << "\n RETRY ";
					}
					cout << "MAIN MENU" << endl;
					cout << "1. Balance Check\t\t2. Deposit\t\t3.Withdraw\t\t4. EXIT" << endl << ".... : ";
					cin >> menu;
					int flag = User_operation(acc_number, menu);
					if (flag != 0)
					{
						cout << "\n DO YOU WANT TO PERFORM OTHER OPERATION !!!!  'Y' .......... ";
						cin >> ch;
					}

				} while (flag == 0 || ch == 'y' || ch == 'Y');

			}
			else
				cout << "INVALID choice!!!!" << endl;
		} while (flag == 0);

		system("pause");      // Waits for user to press Enter
		system("cls"); // For Windows
		cout << "\n REPEAT THE PROJECT 'Y' : ";
		cin >> exit;
	} while (exit == 'Y' || exit == 'y');


}