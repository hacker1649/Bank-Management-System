// Group Members Name:
//20k-1726,20k-1649,20k-0333.zip

#include <iostream>//header files
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
using namespace std;


void colorit(int col)
{//font colour
	HANDLE hstdout;
	hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	//12=red, 15=white---------------->this.colorit(12);  this.colorit(15);
	SetConsoleTextAttribute(hstdout, col);
}
void gotoxy(int x, int y)
{//to move coordinates in X,and Y
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(int milisec)// function for delaying screen time
{
	clock_t start_time = clock();
	while (clock() < start_time + milisec);
}

void introscreen()
{//showing animations from loop
	const char* txt = "  FAST BANK  ";
	int  x = 68;
	for (int j = 0; j < x - 40; j++) {
		gotoxy(x - j, 22);
		printf("%c", 178);
		gotoxy(x + j, 22);
		printf("%c", 178);
		delay(30);
	}

	for (int i = 0; i <= 9; i++) {

		for (int j = 0; j < x - 40; j++) {
			gotoxy(x - j, 21 - i);
			printf("%c", 178);
			gotoxy(x + j, 21 - i);
			printf("%c", 178);
			gotoxy(x - j, 21 + i);
			printf("%c", 178);
			gotoxy(x + j, 21 + i);
			printf("%c", 178);
		}
		delay(30);
		for (int k = 0; k < x - 40; k++) {
			gotoxy(x - k, 21 - i);
			printf(" ");
			gotoxy(x + k, 21 - i);
			printf(" ");
			gotoxy(x - k, 21 + i);
			printf(" ");
			gotoxy(x + k, 21 + i);
			printf(" ");
		}

	}

	for (int l = 0; l < x - 29; l++) {
		gotoxy(x - l, 12);
		printf("%c", 178);
		gotoxy(x + l, 12);
		printf("%c", 178);
		gotoxy(x - l, 29);
		printf("%c", 178);
		gotoxy(x + l, 29);
		printf("%c", 178);

	}
	for (int i = 0; i < x - 40; i++) {

		for (int j = 0; j < 8; j++) {
			gotoxy(x - i, 21 - j);
			printf("%c", 178);
			gotoxy(x + i, 21 - j);
			printf("%c", 178);
			gotoxy(x - i, 21 + j);
			printf("%c", 178);
			gotoxy(x + i, 21 + j);
			printf("%c", 178);
		}
		delay(25);
		for (int k = 0; k < 8; k++) {
			gotoxy(x - i, 21 - k);
			printf(" ");
			gotoxy(68 - i, 20);
			printf("%c", txt[6 - i]);
			gotoxy(x + i, 21 - k);
			printf(" ");
			gotoxy(x - i, 21 + k);
			printf(" ");
			if (i < 8) {
				gotoxy(68 + i, 20);
				printf("%c", txt[6 + i]);
			}
			gotoxy(x + i, 21 + k);
			printf(" ");
		}

	}

	for (int l = 0; l < 9; l++) {
		gotoxy(30, 21 - l);
		printf("%c", 178);
		gotoxy(106, 21 - l);
		printf("%c", 178);
		gotoxy(30, 21 + l);
		printf("%c", 178);
		gotoxy(106, 21 + l);
		printf("%c", 178);
	}

	gotoxy(39, 31);
	printf("PRESS ANY KEY TO CONTINUE...");
	getch();
}
void showmenu();//function declare
class Fast_Bank {//base class 
private:
	int bankcode;
	string bankaddress;
	string bankstate;
public:
	Fast_Bank() {
		bankcode = 0;//initialize
	}
	//setter and getters
	void setbankdata() {
		cout << "\n\n\t\t\t\t\t\t\t Enter the FAST Bank Details:\n\n" << endl;
		cout << "Enter the FAST Bank Code:";
		cin >> bankcode;
		cout << "Enter the Bank Address:";
		fflush(stdin);
		getline(cin, bankaddress);
		cout << "Enter the Bank State:";
		fflush(stdin);
		getline(cin, bankstate);
	}
	int getbankcode() {
		return bankcode;
	}
	string getbankaddress() {
		return bankaddress;
	}
	string getbankstate() {
		return bankstate;
	}
	friend class Manager;
};


class Person :public Fast_Bank {//inheritance
private:
	string persname, persaddress;
public:
	Person() {}//default constructor
	void setpersname() {
		cout << "Enter the Person Name Who Is Using:";
		fflush(stdin);
		getline(cin, persname);
	}
	string getpersname() {
		return persname;
	}
	void setpersaddress() {
		cout << "Enter the Person Address Who Is Using:";
		fflush(stdin);
		getline(cin, persaddress);
	}
	string getpersaddress() {
		return persaddress;
	}
	friend class Manager;
};

void login(); //declaration
class Account;
class Customer :public 	Person {
private:
	string cus_username, cus_password, newname, newemail, newaddress, fathername, newphone, cnic;
	int date, month, year;
	double newaccno, newbalance;
public:
	int choice;
	Customer() {//constructor
		date, month, year, newaccno, newbalance = 0;
	}
	//setters and getters bcz private
	void set_newname() {
		getline(cin, newname);
	}
	string get_newname() {
		return newname;
	}
	void set_newemail() {
		getline(cin, newemail);
	}
	string get_newemail() {
		return newemail;
	}
	void set_fathername() {
		getline(cin, fathername);
	}
	string get_fathername() {
		return fathername;
	}
	void set_newaddress() {
		getline(cin, newaddress);
	}
	string get_newaddress() {
		return newaddress;
	}
	void set_newphone() {
		getline(cin,newphone);
	}
	string get_newphone() {
		return newphone;
	}
	void set_newaccno() {
		cin >> newaccno;
	}
	double get_newaccno() {
		return newaccno;
	}
	void set_newbalance() {
		cin >> newbalance;
	}
	double get_newbalance() {
		return newbalance;
	}
	void set_cnic() {
		getline(cin,cnic);
	}
	string get_cnic() {
		return cnic;
	}
	void set_date() {
		cin >> date;
	}
	int get_date() {
		return date;
	}
	void set_month() {
		cin >> month;
	}
	int get_month() {
		return month;
	}
	void set_year() {
		cin >> year;
	}
	int get_year() {
		return year;
	}
	//member functions
	void Show_Cus_Choice() {
		cout << "\n\n\t\t\t\t\t\t\t Welcome To The Customer of FAST BANK\n\n";
		cout << "1) Old Customer" << endl;
		cout << "2) New Customer" << endl;
		cout << "3) Back to Main Menu" << endl;
		cout << "Enter the Choice:";
		cin >> choice;
		switch (choice) {
		case 1:
			oldaccount();
			break;
		case 2:
			createaccount();
			break;
		case 3:
			showmenu();
			break;
		default:
			cout << "\nInvalid Input!!\n";
			break;
		}
	}
	void oldaccount() {
		system("cls");
		cout << "\n\n\t\t\t\t\t\t\t Welcome To The Old Customer of FAST BANK\n\n";
		login();
		showoldCustomerdata();
	}
	void showoldCustomerdata() {
		ifstream fin;
		string temp;
		fin.open("olduser.txt");
		temp = fin.get();
		while (!fin.eof()) {
			cout << temp;
			temp = fin.get();
		}
		fin.close();
		cout << "\n\n\t\t\t\tYou Wanted Any Step To Perform?\n\n";
		cout << "1) Withdraw Amount" << endl;
		cout << "2) Deposit Amount" << endl;
		cout << "3) Back to Main Menu" << endl;
		cout << "Enter the Choice:";
		int account_choice;
		cin >> account_choice;
		double withamount, demount;
		switch (account_choice) {
		case 1:
			cout << "\n\nEnter The Amount To Withdraw From Your Account:";
			cin >> withamount;
			cout << "\n\nYour Total Account Balance After Withdraw is:" << 25000 -
				withamount << " Rupees\n\n";
			break;
		case 2:
			cout << "\n\nEnter The Amount To Deposit In Your Account:";
			cin >> demount;
			cout << "\n\nYour Total Account Balance After Deposited is:" << 25000 + demount
				<< " Rupees\n\n";
			break;
		case 3:
			showmenu();
			break;
		default:
			cout << "\nInvalid Input!!\n";
			break;
		}
	}

	void createaccount() {
		cout << "\n\n\t\t\t\t\t\t\t Welcome To The New Customer of FAST BANK\n\n";
		cout << "Enter the Full Name Of Account Customer:";
		fflush(stdin);
		getline(cin, newname);
		cout << "Enter the Father name:";
		fflush(stdin);
		getline(cin, fathername);
		cout << "Enter the Date/Month/Year Of Birth:";
		cin >> date >> month >> year;
		cout << "Enter the CNIC:";
		cin >> cnic;
		cout << "Enter the Contact Number:";
		cin >> newphone;
		cout << "Enter the Address :";
		fflush(stdin);
		getline(cin, newaddress);
		cout << "Enter the Email:";
		fflush(stdin);
		getline(cin, newemail);
		cout << "Enter the Account Number:";
		cin >> newaccno;
		cout << "Enter the Initial Account Balance which must be greater than 500:";
		cin >> newbalance;
		if (newbalance >= 500) {
			writeaccountinfile();
			system("cls");
			cout << "\nAll Required Data is taken\n";
			cout << "\n\n\t\t\t\t\t\t\t Congratulations Your Account Has Been Created\n";
			cout << "\nYou can Select Following Choice\n";
			cout << "1) Show Account Data" << endl;
			cout << "2) Deposit Amount" << endl;
			cout << "3) Withdraw Amount" << endl;
			cout << "3) Back To Main Menu" << endl;
			cout << "Enter the Choice:";
			int selection;
			cin >> selection;
			switch (selection) {
			case 1:
				showaccountinfo();
				break;
			case 2:
				createdeposit();
				break;
			case 3:
				createwithdraw();
				break;
			case 4:
				showmenu();
				break;
			default:
				cout << "\nInvalid Input!\n";
				break;
			}
		}
		else {
			cout << "\n\n\t\tAccount Not Created Due to less Balance Amount!!\n\n";
			createaccount();
		}
	}
	void writeaccountinfile() {
		ofstream fcout;
		cout << "\n\nPlease Enter Your File Name to Save:";
		string writefilename;
		fflush(stdin);
		getline(cin, writefilename);
		fcout.open(writefilename.c_str());//create account file= newnewuser1.txt; add account= newuser2.txt
		fcout << "\n\n\t\t\t\t\t\t\t Welcome To The New Customer of FAST BANK\n\n" << endl;
		fcout << "\n\n\n\n\t\t\t\t\tBANK DETAILS:\n\n\n";
		fcout << "The Bank Code:";
		fcout << getbankcode() << endl;
		fcout << "The Bank location:";
		fcout << getbankaddress() << endl;
		fcout << "The Bank State:";
		fcout << getbankstate() << endl;
		fcout << "\n\n\t\t\t\t\t\t\t CUSTOMER ACCOUNT DETAILS:\n\n\n";
		fcout << "The Customer Account Name:";
		fcout << get_newname() << endl;
		fcout << "The Father name:";
		fcout << get_fathername() << endl;
		fcout << "The Date Of Birth:";
		fcout << get_date() << " /" << get_month() << " /" << get_year() << endl;
		fcout << "The CNIC:";
		fcout << get_year() << endl;
		fcout << "The Contact Number:";
		fcout << get_newphone() << endl;
		fcout << "The Address :";
		fcout << get_newaddress() << endl;
		fcout << "The Email :";
		fcout << get_newemail() << endl;
		fcout << "The Account Number:";
		fcout << get_newaccno() << endl;
		fcout << "The Account Balance:";
		fcout << get_newbalance() << endl;
		fcout.close();
	}
	void showaccountinfo() {
		string filename;
		cout << "\n\nPlease Enter Your File Name To Show Information:";
		fflush(stdin);
		getline(cin, filename);
		string line;
		ifstream myfile(filename.c_str());//create account file= newnewuser1.txt; add account= newuser2.txt
		if (myfile.is_open()) {//(myfie)
			while (getline(myfile, line)) {
				cout << line << '\n';
			}
			myfile.close();
			getch();
		}
		else cout << "Unable to open file";
	}
	void createdeposit() {
		double createdeposit;
		cout << "\n\nEnter the Deposit Amount To Add In Your Account:";
		cin >> createdeposit;
		cout << "\n\n\nThe Total Balance In Your Account Is:" << get_newbalance() +
			createdeposit << endl;
	}
	void createwithdraw() {
		double createwithdraw;
		cout << "\n\nEnter the Withdrawal Amount from Your Account:";
		cin >> createwithdraw;
		cout << "\n\n\nThe Total Balance In Your Account Is:" << get_newbalance() -
			createwithdraw << endl;
	}
	void searchAccount(double account_number)
	{
		showaccountinfo();
	}
	friend class Manager;
};


class Account :public Customer {
public:
	void accountshowchoice() {
		cout << "\n\n\t\t\tYou Can Also Perform These Options:\n\n";
		cout << "1) Add Account" << endl;
		cout << "2) Edit Account" << endl;
		cout << "3) Delete Account" << endl;
		cout << "4) Back to Main Menu" << endl;
		cout << "Enter the account Choice:";
		int accountchoice;
		cin >> accountchoice;
		switch (accountchoice) {
		case 1:
			system("cls");
			addaccount();
			break;
		case 2:
			system("cls");
			cout << "\n\n\n\t\t\tYou are on Account Edit Mode\n\n";
			editaccount();
			break;
		case 3:
			system("cls");
			deleteaccount();
			break;
		case 4:
			system("cls");
			showmenu();
			break;
		default:
			cout << "\n\n Invalid Input\n\n";
			break;
		}
	}
	void addaccount() {
		cout << "\n\n\t\t\t\t\t\t\t Welcome To The New Customer of FAST BANK\n\n";
		cout << "Enter the Full Name Of Account Customer:";
		fflush(stdin);
		set_newname();
		cout << "Enter the Father name:";
		fflush(stdin);
		set_fathername();
		cout << "Enter the Date/Month/Year Of Birth:";
		set_date();
		set_month();
		set_year();
		cout << "Enter the CNIC:";
		set_cnic();
		cout << "Enter the Contact Number:";
		set_newphone();
		cout << "Enter the Address :";
		fflush(stdin);
		set_newaddress();
		cout << "Enter the Email:";
		fflush(stdin);
		set_newemail();
		cout << "Enter the Account Number:";
		set_newaccno();
		cout << "Enter the Initial Account Balance which must be greater than 500:";
		set_newbalance();
		if (get_newbalance() >= 500) {
			writeaccountinfile();
			system("cls");
			cout << "\nAll Required Data is taken\n";
			cout << "\n\n\n\n\t\t\t\t\tCongratulations Your Account Has Been Created\n";
			cout << "\nYou can Select Following Choice\n";
			cout << "1) Show Account Data" << endl;
			cout << "2) Deposit Amount" << endl;
			cout << "3) Withdraw Amount" << endl;
			cout << "4) Back To Main Menu" << endl;
			cout << "Enter the Choice:";
			int selection;
			cin >> selection;
			switch (selection) {
			case 1:
				showaccountinfo();
				break;
			case 2:
				depositamount();
				break;
			case 3:
				withdrawamount();
				break;
			case 4:
				showmenu();
				break;
			default:
				cout << "\nInvalid Input!\n";
				break;
			}
		}
		else {
			cout << "\n\n\t\tAccount Not Created Due to less Balance Amount!!\n\n";
			createaccount();
		}
	}
	void editaccount() {
		double checkaccno;
		string checkfullname, file_name;
		cout << "\n\nPlease Enter Your File Name To Edit:";
		fflush(stdin);
		getline(cin, file_name);
		ifstream myfile("file_name");
		cout << "Enter the Account Number:";
		cin >> checkaccno;
		cout << "Enter the Full Name:";
		fflush(stdin);
		getline(cin, checkfullname);
		if ((checkaccno == get_newaccno() && checkfullname == get_newname())
			|| (checkaccno == 123 && checkfullname == "Anas Hassan")) {
			cout << "\n\n\t\t What You Want To Edit?\n\n";
			cout << "1) Your Full Name" << endl;
			cout << "2) Father Name" << endl;
			cout << "3) CNIC Number" << endl;
			cout << "4) Contact Number" << endl;
			cout << "5) Address" << endl;
			cout << "6)Email Address" << endl;
			cout << "7) Account Balance" << endl;
			cout << "Enter the Edit Choice:";
			int editchoice;
			cin >> editchoice;
			switch (editchoice) {
			case 1:
				cout << "Enter the Full Name to edit:";
				fflush(stdin);
				set_newname();
				cout << "\n Editing Successfully!\n";
				writeaccountinfile();

				break;
			case 2:
				cout << "Enter the Father Name to edit:";
				fflush(stdin);
				set_fathername();
				cout << "\n Editing Successfully!\n";
				writeaccountinfile();

				break;
			case 3:
				cout << "Enter the CNIC Number to edit:";
				set_cnic();
				cout << "\n Editing Successfully!\n";
				writeaccountinfile();

				break;
			case 4:
				cout << "Enter the Contact Number to edit:";
				set_newphone();
				cout << "\n Editing Successfully!\n";
				writeaccountinfile();

				break;
			case 5:
				cout << "Enter the Full Address to edit:";
				fflush(stdin);
				set_newaddress();
				cout << "\n Editing Successfully!\n";
				writeaccountinfile();

				break;
			case 6:
				cout << "Enter the Email Address to edit:";
				fflush(stdin);
				set_newemail();
				cout << "\n Editing Successfully!\n";
				writeaccountinfile();

				break;
			case 7:
				cout << "Enter the Account Balance to edit Must Be greater than 500:";
				set_newbalance();
				if (get_newbalance() < 500) {
					cout << "Enter the Account Balance to edit:";
					set_newbalance();
				}
				else {
					cout << "\n\n\n\n\t\t\t\t\tCongratulations Your Account Has Been Edited\n";
					writeaccountinfile();
				}
				break;
			default:
				cout << "\n\nInvalid Input!!\n\n";
				break;
			}
		}
		else {
			cout << "The Account Number or Full Name is wrong!";
			accountshowchoice();
		}
	}
	void depositamount() {
		double depositamount;
		cout << "\n\nEnter the Deposit Amount To Add In Your Account:";
		cin >> depositamount;
		cout << "\n\n\nThe Total Balance In Your Account Is:" << get_newbalance() +
			depositamount << endl;
	}
	void withdrawamount() {
		double withdrawamount;
		cout << "\n\nEnter the Withdraw Amount To Add In Your Account:";
		cin >> withdrawamount;
		cout << "\n\n\nThe Total Balance In Your Account Is:" << get_newbalance() -
			withdrawamount << endl;
	}
	void deleteaccount() {
		double checkaccno;
		string checkfullname, deletefilename;
		cout << "\n\nPlease Enter Your File Name To Delete Information:";
		fflush(stdin);
		getline(cin, deletefilename);
		ifstream myfile(deletefilename.c_str());
		cout << "\n\n\n\t\t\tYou are on Account Delete Mode\n\n";
		cout << "Enter the Account Number:";
		cin >> checkaccno;
		cout << "Enter the Full Name:";
		fflush(stdin);
		getline(cin, checkfullname);
		if (checkaccno == get_newaccno() && checkfullname == get_newname()) {
			ofstream o;
			o.open(deletefilename.c_str());
			o.close();
			cout << "\t\t\t\n\n\nAccount Deleted Successfully!";
		}
		else {
			cout << "The Account Number or Full Name is wrong!";
			accountshowchoice();
		}
	}

	friend class Manager;
};

class employee :public Person {
private://for hiding data
	// Variables for employee details
	char name[30];
	char id[5];
	char designation[10];
	int age;
	int ctc;
	int experience;

	// Functions to perform desired actions
	void listEmployees() { //To list total employees with Name, Id and Designation
		system("cls");
		FILE* file;
		file = fopen("employee.txt", "r");
		cout << "\n\n\t\t\t\t\t\t\t List of Employees\n";
		cout << "\n----------------------------------------------";
		cout << "\n NAME        |     ID     |     DESIGNATION\n";
		cout << "----------------------------------------------";
		while (fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0], &designation[0],
			&age, &ctc, &experience) != EOF)
			cout << "\n" << name << "\t\t" << id << "\t\t" << designation;
		fclose(file);
		getch();
	}

	void showDetails(void) { //Displays all details according to Employee's id
		system("cls");
		FILE* file;
		char checkId[5];
		cout << "\n\nEnter Employee ID: ";
		cin >> checkId;
		file = fopen("employee.txt", "r");
		while (fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0], &designation[0],
			&age, &ctc, &experience) != EOF)
			if (strcmp(checkId, id) == 0) {
				cout << "\n---------------------";
				cout << "\nName: " << name;
				cout << "\n---------------------";
				cout << "\nId: " << id;
				cout << "\n---------------------";
				cout << "\nDesignation: " << designation;
				cout << "\n---------------------";
				cout << "\nAge: " << age;
				cout << "\n---------------------";
				cout << "\nCTC: " << ctc;
				cout << "\n---------------------";
				cout << "\nExperience: " << experience;
				cout << "\n---------------------";
			}
		fclose(file);
		getch();
	}

	void editExisting(void) { //edits Designation and CTC of an employee
		system("cls");
		char checkId[5];
		cout << "\nEnter employee id: ";
		cin >> checkId;
		char newDesignation[10];
		cout << "\n-----------------------------";
		cout << "\nEnter new designation: ";
		fflush(stdin);
		cin >> newDesignation;
		int newCtc;
		cout << "------------------------------";
		cout << "\nEnter new CTC: ";
		cin >> newCtc;
		FILE* file, * tempfile;
		file = fopen("employee.txt", "r");
		tempfile = fopen("temp.txt", "w");
		while (fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0], &designation[0],
			&age, &ctc, &experience) != EOF) {
			if (strcmp(checkId, id) == 0)
				fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, newDesignation, age, newCtc,
					experience);
			else
				fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc,
					experience);
		}
		fclose(file);
		fclose(tempfile);
		int isRemoved = remove("employee.txt");
		int isRenamed = rename("temp.txt", "employee.txt");
		getch();
	}

	void addNewEmployee() { //adding records
		system("cls");
		cout << "\n----------------------------------------";
		cout << "\n Enter First Name of Employee: ";
		fflush(stdin);
		cin >> name;
		cout << "\n----------------------------------------";
		cout << "\n Enter Employee ID [max 4 digits]: ";
		cin >> id;
		cout << "\n----------------------------------------";
		cout << "\n Enter Designation: ";
		fflush(stdin);
		cin >> designation;
		cout << "\n----------------------------------------";
		cout << "\n Enter Employee Age: ";
		cin >> age;
		cout << "\n----------------------------------------";
		cout << "\n Enter Employee CTC: ";
		cin >> ctc;
		cout << "\n----------------------------------------";
		cout << "\n Enter Employee Experience: ";
		fflush(stdin);
		cin >> experience;
		cout << "\n----------------------------------------";

		char ch;
		cout << "\nEnter 'y' to save above information\n";
		cin >> ch;
		if (ch == 'y') {
			FILE* file;
			file = fopen("employee.txt", "a");
			fprintf(file, "%s %s %s %d %d %d \n", name, id, designation, age, ctc,
				experience);
			fclose(file);
			cout << "\nNew Employee has been added\n";
		}
		else
			addNewEmployee();
		getch();
	}

	void deleteEmployeeDetails() { //removing records
		system("cls");
		char checkId[5];
		cout << "\n----------------------------------";
		cout << "\nEnter Employee Id To Remove: ";
		cin >> checkId;
		char ch;
		cout << "----------------------------------";
		cout << "\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
		cin >> ch;
		if (ch == 'y') {
			FILE* file, * tempfile;
			file = fopen("employee.txt", "r");
			tempfile = fopen("temp.txt", "w");
			while (fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0], &designation[0],
				&age, &ctc, &experience) != EOF)
				if (strcmp(checkId, id) != 0)
					fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc,
						experience);
			fclose(file);
			fclose(tempfile);
			int isRemoved = remove("employee.txt");
			int isRenamed = rename("temp.txt", "employee.txt");
			cout << "\nRemoved Successfully\n";
			getch();
		}
		else
			deleteEmployeeDetails();
	}


public:
	// Function to serve as end point
	void options(void) { //menu
		login();//login screen
		while (true) {
			system("cls");
			cout << "\n\t\t\t------------------------------------------------\n\n";
			cout << "\n\t\t\t1: To View List of Employees";
			cout << "\n\t\t\t2: To View Employee Details";
			cout << "\n\t\t\t3: To Modify Existing Employee Details";
			cout << "\n\t\t\t4: To Add New Employee Details";
			cout << "\n\t\t\t5: To Remove an Employee Details";
			cout << "\n\t\t\t0: To Exit     ";
			cout << "\n\t\t\t------------------------------------------------";
			cout << "\n\n\t\t\t   Please Enter Your Choice: ";
			// Taking the action input
			int choice;
			cin >> choice;
			// Calling relevant function as per choice
			switch (choice) {
			case 0:
				system("CLS");
				showmenu();
				break;
			case 1:
				listEmployees();
				break;
			case 2:
				showDetails();
				break;
			case 3:
				editExisting();
				break;
			case 4:
				addNewEmployee();
				break;
			case 5:
				deleteEmployeeDetails();
				break;
			default:
				cout << "\n Invalid Input! \n";
				break;
			}
		}
	}
	friend class Manager;
};

class employeetype :public employee {
public:
	void showemployeetype() {

		cout << "\n\n\n\t\t\t\t\t Type Of Employee:\n\n\n";
		cout << "\n\n 1) Permanent employee\n";
		cout << "\n\n 2) Temporary employee\n";
		int choice;
		cout << "\nEnter the choice:";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "\n\nDetails Of Permanent Employee:\n\n";
			break;
		case 2:
			cout << "\n\nDetails Of Temporary Employee:\n\n";
			break;
		}
	}
	friend class manager;
};
void login()  //login procedure
{
	string pass = "";
	char ch;
	cout << "\n\n\t\t\t\t\t\t\tEnter Your Password :";
	ch = _getch();
	while (ch != 13) { //character 13 is enter
		pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	cout << "\n\n\n\t\t\t\t\t\t\t\tVerifying";
	for (int a = 1; a < 8; a++) { // Change 'a<?' to how many * you want
		Sleep(500);
		cout << "...";
	}
	if (pass == "pass") {
		cout << "\n\n\n\t\t\t\t\tCorrect Password Access Granted!! \n\n\n";
		system("PAUSE");
		system("CLS");
	}
	else {
		cout << "\n\n\n\t\t\t\t\t Wrong Password Access Aborted...\n";
		login();
	}
}

class Manager
{
private:
	// Variables for storing manager details
	string man_username, man_password, man_employeeid;
	double loan;
public:
	Manager()
	{
		loan = 0.0;
		man_username = "NULL";
		man_password = "NULL";
		man_employeeid = "NULL";
	}
	// Functions to perform desired actions
	void check_managervalidation(Person obj)
	{
		cout << "\n\n\t\t\t\t\t\t\t Welcome To The Manager of FAST BANK:\n";
		cout << "\t\t\t\t================================================================================\n\n";
		obj.setbankdata();
		obj.setpersname();
		obj.setpersaddress();
		system("cls");
		cout << "\n\n\n\n\t\t\t\t Provide Correct Details To Access Credential Data\n\n\n\n";
		cout << " Enter the Manager User Name:";
		fflush(stdin);
		getline(cin, man_username);
		cout << endl;
		cout << " Enter the Manager Password:";
		fflush(stdin);
		getline(cin, man_password);
		cout << endl;
		cout << " Enter the Manager Employee ID :";
		fflush(stdin);
		getline(cin, man_employeeid);
		string manusername = "anas";//hardcoded username, password  and employee id
		string manuserpass = "anas123";
		string manuserid = "12345";
		if (man_username == manusername && man_password == manuserpass
			&& man_employeeid == manuserid) {
			showmanagerdata(obj);
			choiceinput();
		}
		else {
			cout << "\nInvalid Information for Manager Login!\n";
			check_managervalidation(obj);
		}
	}
	void showmanagerdata(Person obj)
	{
		system("cls");
		cout << "\nAll Required Data is taken for the validation of bank manager.\n";
		cout << endl << endl << endl << endl << endl;
		system("pause");
		system("cls");
		cout << endl << endl;
		cout << "\n\t\t\t\t\t\t\t FAST BANK MANAGER DETAILS :" << endl;
		cout << "\t\t\t\t=======================================================================================" << endl << endl;
		cout << "\n Bank Code:" << obj.getbankcode() << endl;
		cout << "\n Bank Location:" << obj.getbankaddress() << endl;
		cout << "\n Bank State:" << obj.getbankstate() << endl;
		cout << "\n Manager Name:" << obj.getpersname() << endl;
		cout << "\n Manager Residential Adddress:" << obj.getpersaddress() << endl;
	}
	// functions for the user to choose an action
    void choiceinput()
	{
		cout << endl << endl;
		cout << "\n\n\t\t\tYou can Select one of the Following Choice :\n";
		cout << setw(10) << "\t\t\t1) Search Account Information of specific Person" << endl;
		cout << setw(10) << "\t\t\t2) Show Bank Future Policy Information" << endl;
		cout << setw(10) << "\t\t\t3) Grant Loan Availiblity" << endl;
		cout << setw(10) << "\t\t\t4) Back to Main Menu" << endl;
		cout << "\t\t\tEnter the Choice:";
		int selection;
		cin >> selection;
		// Calling relevant function as per choice
		switch(selection)
		{
			case 1:
				{
					cout << endl << endl << endl << endl << endl;
					system("pause");
					system("cls");
					SearchCustomerAccount();
			        break;
				}
			case 2:
				{
					cout << endl << endl << endl << endl << endl;
					system("pause");
					system("cls");
					ShowFuturePolicy();
					break;
				}
			case 3:
				{
					cout << endl << endl << endl << endl << endl;
					system("pause");
					system("cls");
					Account obj;
					GrantLoan(obj);
					break;
				}
			case 4:
				{
					showmenu();
					break;
				}
			default:
				{
					cout << "Wrong Input !!!!!" << endl;
					break;
				}
		}
	}
	void SearchCustomerAccount()
	{
		Customer c;
	    double account=0.0;
		cout << endl << endl;
		cout << "  SEARCHING SPECIFIC ACCOUNT :" << endl;
		cout << "................................" << endl << endl;
		cout << " Enter the Person Account Number :";
		cin >> account;
		c.searchAccount(account);
	}
	void ShowFuturePolicy()
	{
		cout << endl << endl;
		cout << "\n\t\t\t FUTURE POLICY OF FAST BANK :" << endl;
		cout << "\t\t\t ===============================" << endl << endl;
		cout << " Endowment Plan is a unique saving and protection scheme through which the policy holder can get a particular amount of money at a specific time speculated on the basis of his/her future requirements." << endl;
		cout << " Endowment plan is most suitable for people who are far sighted and want to fulfill their future needs." << endl;
		cout << " Behind every success, there is a woman. We stand with you, no matter what role you play. Be it entrepreneur, a mother or a daughter, we understand your needs. With" << endl <<
			" that in mind we present Rahat Savings and Protection Plan – designed exclusively for you with Jubilee Life Insurance Company Limited. This is an insurance plan that is" << endl <<
			" tailored to meet your needs. The plan allows you to invest for yourself or your loved ones and secure a bright future no matter what comes." << endl;
		cout << " Life rewards those who carefully and wisely plan their future. Whether its planning to reside in a comfortable home or to get your children an education that they" << endl << " deserve, it includes making important decisions with ones wealth." << endl;
		cout << " That why the Mukammal Savings and Insurance Plan offers you the chance to secure your familys happiness by making sure that your hard-earned savings receive the" << endl <<
			" optimized returns needed to aid you and your loved ones when the time comes." << endl;
		cout << endl;
		cout << " Fast Bank Limited in partnership with Jubilee Life Insurance Company Limited offers Rahat Savings and Protection Plan." << endl;
		cout << " Fast Bank Limited in partnership with State Life Insurance Limited offers Endowment Plan." << endl;
		cout << " Fast Bank Limited in partnership with Jubilee Life Insurance Company Limited offers Mukammal Savings and Insurance Plan." << endl;

		cout << endl << endl << endl;
		cout << "\n\t FEATURES AND BENEFITS :" << endl;
		cout << "\t --------------------------" << endl << endl;
		cout << " 1) All your invested premiums are completely secure. This means at the time of maturity of the plan you get the entire cash value accumulated during the term of the" << endl << "    plan." << endl;
		cout << " 2) It is a flexible plan which gives you the ability to select the sum assured of your choice." << endl;
		cout << " 3) If the life assured expires during the term of the plan, his beneficiaries will be entitled to the sum assured or the cash value, whichever is higher. You can" << endl <<
			"    determine the sum assured by multiplying your annualized basic premium amount by the selected cover multiple (offered from 5 to 254)* depending on your savings and     insurance needs. For example, if your annual basic premium contribution is PKR 100,000 and you have selected a cover multiple of 10, your total sum assured would be    100,000 x 10 = 1,000,000." << endl;
		cout << " 4) The range of cover multiples available to the policy holder varies with the age at the time of entry of the life assured." << endl;
		cout << " 5) Your contributions will be invested in the fund(s) of your choice (Meesaq, Managed, Capital Growth or Yaqeen Growth Fund) which are managed by expert investment" << endl <<
			"    managers and backed by premium financial securities, in order to ensure optimized returns with manageable risk exposure." << endl;
		cout << " 6) In spouse coverage; if selected, additional amount equal to one time of the sum assured (of the policy will be paid) in case of his accidental death." << endl;
		cout << " 7) If the life assured expires during the term of the plan, his beneficiaries will be entitled to the sum assured plus accrued bonuses up till that point in time." << endl;
	}
	void GrantLoan(Account a)
	{
		cout << "\n\n\t\t\t\t\t\t\t  APPLICATION FOR GRANT LOAN :" << endl;
		cout << "\t\t\t =================================================" << endl << endl;
		a.setpersname();
		cout << endl;
		a.setpersaddress();
		cout << endl;
		cout << " Enter your CNIC number :";
		a.set_cnic();
		cout << endl;
		cout << " Enter the Customer Account Name :";
		fflush(stdin);
		a.set_newname();
		cout << endl;
		cout << " Enter the Customer Account Number :";
		a.set_newaccno();
		cout << endl;
		cout << " Enter the Current Account balance :";
		fflush(stdin);
		a.set_newbalance();
		cout << endl;
		cout << " Enter your desired Amount for Granting Loan :";
		cin >> loan;
		cout << endl << endl << endl << endl;
		cout << fixed << setprecision(2);
		cout << "Hence , you received Rs." << loan << " loan from the FAST BANK." << endl;
	}
	//setters and getters of all the attributes of manager class
	void set_managerusername(const string a)
	{
		man_username = a;
	}
	string get_managerusername() const
	{
		return man_username;
	}
	void set_managerpassword(const string b)
	{
		man_password = b;
	}
	string get_managerpassword() const
	{
		return man_password;
	}
	void set_manageremployeeid(const string c)
	{
		man_employeeid = c;
	}
	string get_manageremployeeid() const
	{
		return man_employeeid;
	}
	void set_loan(const double x)
	{
		loan = x;
	}
	double get_loan() const
	{
		return loan;
	}
};



void showmenu()
{
	system("color 02");
	Account a1;
	int index = 1;
	int key = 0;
	system("cls");
	while (key != 13) {
		gotoxy(9, 3);
		colorit(15);
		gotoxy(45, 3); //cordinate(x,y)
		colorit(15);   ////12=red, 15=white---------------->this.colorit(12);  this.colorit(15);///
		printf("\t\t\t\t\tFAST BANK");
		gotoxy(45, 4);
		printf("\t\t\t\t     ===============");
		gotoxy(45, 7);
		colorit(15);
		if (index == 1) {
			colorit(12);
		}
		printf("\t\t\t\t\tCUSTOMER");
		gotoxy(45, 10);
		colorit(15);
		if (index == 2) {
			colorit(12);
		}
		printf("\t\t\t\t\tEMPLOYEE");
		gotoxy(45, 13);
		colorit(15);
		if (index == 3) {
			colorit(12);
		}
		printf("\t\t\t\t\tMANAGER");
		gotoxy(45, 16);
		colorit(15);
		if (index == 4) {
			colorit(12);
		}
		printf("\t\t\t\t\tEXIT");
		//UP=224/72 Down=224/80 Enter=13 ascii code
		key = getch();
		if (key == 80) {
			index++;
		}
		else if (key == 72) {
			index--;
		}
		if (index == 5) {
			index = 1;
		}
		if (index == 0) {
			index = 4;
		}
	}
	if (index == 1) {
		system("cls");
		system("color 02");
		a1.setbankdata();
		a1.setpersname();
		a1.Show_Cus_Choice();
		a1.accountshowchoice();
		printf("\n\n\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
		getch();
		showmenu();
	}
	else if (index == 2) {
		system("cls");
		system("color 02");
		cout << "\n\n\n\t\t\t\t\t\t\t>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<\n\n";
		employeetype e1;
		e1.setbankdata();
		e1.setpersname();
		e1.showemployeetype();
		e1.options();
		printf("\n\n\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
		getch();
		showmenu();
	}
	else if (index == 3) {
		system("cls");
		system("color 02");
		Manager m1;
		Person obj;
		m1.check_managervalidation(obj);
		printf("\n\n\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
		getch();
		showmenu();
	}
	else if (index == 4) {
		system("taskkill/IM Console.exe");
	}
}

int main()
{
	system("color 02");
	introscreen();
	system("color 02");
	showmenu();
}

