//MD Abir A. Choudhury
//CIS 3100 - Exam 2
//041418
//FedEx

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//prototypes	
void createNewMail(string state[], double cost[], int &num, fstream &fileInput);
void displayMenu();
void displayReport(string state[], double cost[], int& num, fstream &fileInput);
void searchMailCost(string state[], double cost[], int& num);
void searchMailState(string state[], double cost[], int& num);

int main() {
	//variable defintions
	const int SIZE = 1000;
	string state[SIZE];
	double cost[SIZE];

	int num = 0;
	int choice = 0;

	//create io stream
	fstream fileInput("ioFile.txt");
	if (!fileInput) {
		cout << "Error loading file for writing data!\n";
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

	//do loop as long as user does not exit
	do {
		//display menu
		displayMenu();
		cin >> choice;

		//choice 1
		if (choice == 1) {
			createNewMail(state, cost, num, fileInput);
		}
		//choice 2
		else if (choice == 2) {
			searchMailState(state, cost, num);
		}
		//choice 3
		else if (choice == 3) {
			searchMailCost(state, cost, num);
		}
		//choice 4
		else if (choice == 4) {
			displayReport(state, cost, num, fileInput);
		}
	} while (choice != 0);

	fileInput.close();
	cout << "Thank you for using out service!\n";
	system("PAUSE");
	return 0;
}

//Function Definitions - create a new mail
void createNewMail(string state[], double cost[], int &num, fstream &fileInput) {
	char choice = 'Y';
	bool cont = true;
	while (cont) {
		cout << "Destination State (Two Letters, no space): ";
		cin >> state[num];
		fileInput << state[num] << " ";
		cout << "Cost of this delivery (No $ sign): ";
		cin >> cost[num];
		fileInput << cost[num] << "\n";
		num++;

		cout << "Would you like to input another mail? (Y or N): ";
		cin >> choice;
		if (toupper(choice) == 'Y') {
			cont = true;
		}
		else {
			cont = false;
		}
	}
}
//displays the menu in the do loop
void displayMenu() {
	cout  << "++++++++++++++++++++++++++++++++++++++++++++++++\n"
		<< "+++Welcome to FedEx in the middle of nowhere++++\n"
		<< "+This tool will help you keep track of packages+\n"
		<< "++++++++++++++++++++++++++++++++++++++++++++++++\n"
		<< "\n"
		<< "1 - Create New Mail\n"
		<< "2 - Search Mail (by State)\n"
		<< "3 - Search Mail (by Cost)\n"
		<< "4 - Grand Report\n"
		<< "0 - Exit\n"
		<< "What is your choice? ";
}
//displays the report
void displayReport(string state[], double cost[], int& num, fstream &fileInput) {
	//for saving to file
	cout << "Here are all the packages for today: \n";
	/*for (int i = 0; i < num; i++) {
		cout << "Package to " << state[i] << " for $" << cost[i] << endl;
	}*/
	string x;
	while (fileInput >> x) {
		cout << x << endl;
	}
}
//search the mail according to the cost
void searchMailCost(string state[], double cost[], int& num) {
	double input;
	cout << "Enter minimum package price: ";
	cin >> input;
	cout << "Here are the packages that are larger in value than: " << input << endl;
	for (int i = 0; i < num; i++) {
		if (cost[i] > input) {
			cout << "Package to " << state[i] << " for $" << cost[i] << endl;
		}
	}
}
//search the mail according to the state
void searchMailState(string state[], double cost[], int& num) {
	string choice;
	cout << "Enter state you want to see: ";
	cin >> choice;
	cout << "Here are the packages going to " << choice << endl;
	for (int i = 0; i < num; i++) {
		if (choice == state[i]) {
			cout << "Package to " << choice << " for $" << cost[i] << endl;
		}
	}
}