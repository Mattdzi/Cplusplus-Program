//===========================================
// Name        : Project1.cpp
// Author      : Matthew Dziewiecki
// SNHU Class  : CS210
// Description : 12 and 24 hour clock in C++
//===========================================

#include <iostream>
#include <windows.h>
using namespace std;


int hr = 12; //12 hour clock hours
int minute = 0; //minutes used for both 24 and 12 hr clock
int sec = 0; //seconds used for both 24 and 12 hr clock
int hr24 = 0; //tracking time in 24 hour format
//string amPm = "am"; ------->tried using a string to track am/pm. Used integer because couldn't implement with string
int menuInput; //variable for menu input
int startInput = 1; //variable for starting the program
bool exitChecker = true; //if 4 is chosen in menu this becomes false and exits the program
bool input = true; //used for while loop to create an infinte loop until the user pressed ESC
int i = 0; //I used to track if am or pm by comparing hrs24 to 12, changes to 1 if hrs24 >= 12

//prints time, used a long line to make easier to see what was being printed on what line.
void printTime() {
	cout << "***************************  ***************************" << endl;
	cout << "*       12-Hour Clock     *  *        24-Hour Clock    *" << endl;
	cout << "*       "; if (hr < 10) cout << "0"; cout << hr << ":"; if (minute < 10) cout << "0"; cout << minute << ":"; if (sec < 10) cout << "0"; cout << sec << " "; if (i == 0)cout << "AM"; else if (i == 1)cout << "PM"; cout << "       *  *        "; if (hr24 < 10) cout << "0"; cout << hr24 << ":"; if (minute < 10) cout << "0"; cout << minute << ":"; if (sec < 10) cout << "0"; cout << sec << "         *" << endl;
	cout << "***************************  ***************************" << endl;
}

//displays menu
void displayMenu() {

	cout << "***************************\n";
	cout << "* 1 - Add One Hour        *\n";
	cout << "* 2 - Add One Minute      *\n";
	cout << "* 3 - Add One Second      *\n";
	cout << "* 4 - Exit Program        *\n";
	cout << "***************************\n";
}

//tracks user input and takes appropriate course of action based on user input
void menuAction() {
	
	switch (menuInput) {
	case 1:
		hr24++;
		hr++;
		if (hr24 == 24) {
			hr24 = 0;
		}
		if (hr24 < 12) {
			i = 0;
		}
		if (hr == 13) {
			hr = 1;
		}
		if (hr24 >= 12) {
			i = 1;
		}
		break;
	case 2:
		minute++;
		if (minute == 60) {
			hr++;
			hr24++;
			minute = 0;
			if (hr24 < 12) {
				i = 0;
			}
			if (hr24 >= 12) {
				i = 1;
			}
			if (hr == 13) {
				hr = 1;
			}
			if (hr24 == 24) {
				hr24 = 0;
			}
		}
		break;
	case 3:
		sec++;
		if (sec == 60) {
			minute++;
			sec = 0;
			if (minute == 60) {
				hr++;
				hr24++;
				minute = 0;
				if (hr24 < 12) {
					i = 0;
				}
				if (hr == 13) {
					hr = 1;
				}
				if (hr24 >= 12) {
					i = 1;
				}
				if (hr24 == 24) {
					hr24 = 0;
				}
			}
		}

		break;
	case 4:
		cout << "Exiting Clock Program" << endl;
		exitChecker = false;
		input = false;
		break;
	default:
		cout << "Unexpected Input Received. Please Enter a Valid Menu Item. Returning to Main Screen" << endl;
		Sleep(3000);
		cin.clear();
		cin.ignore(10000, '\n');
		system("CLS");

	}

}
//prints time, displays menu, takes user input, changes time and displays clocks or exits program

void addSecond()
{
	sec++;
	if (sec == 60) {
		minute++;
		sec = 0;
		if (minute == 60) {
			hr++;
			hr24++;
			minute = 0;
			if (hr24 < 12) {
				i = 0;
			}
			if (hr == 13) {
				hr = 1;
			}
			if (hr24 >= 12) {
				i = 1;
			}
			if (hr24 == 24) {
				hr24 = 0;
			}
		}
	}
}

void startProgram() {
	system("CLS");
	switch (startInput) {
	case 1:
		printTime();
		displayMenu();
		cout << "Please enter the input: ";
		cin >> menuInput;
		menuAction();
		system("CLS");
		break;
	case 2:
		while (input) {
			if (GetAsyncKeyState(VK_ESCAPE))
			{
				break;
			}
			printTime();
			cout << "Press the ESC key if you would like to stop the clock";
			addSecond();
			Sleep(1000);
			system("CLS");
		}
	}
}
//This displays the menu and takes user input on adding time to the clock in case 1 or pressing the ESC key to stop the clock in case 2

void error() {
	cout << "Unexpected Input Received. Please Enter a Valid Menu Item. Returning to Main Screen";
	Sleep(3000);
	cin.clear();
	cin.ignore(10000, '\n');
	system("CLS");
}
//This is if the user inputs a non-integer as thier answer

int main() {
		while (exitChecker) {
			system("CLS");
			printTime();
			cout << "Would you like to add time to the Clock? \nPlease enter the input twice to confirm your choice. (1 = Yes, 2 = No): ";
			cin >> startInput;
			if (!(cin >> startInput))
			{
				error();
			}
			else {
				startProgram();
			}
		}
	return 0;
}
