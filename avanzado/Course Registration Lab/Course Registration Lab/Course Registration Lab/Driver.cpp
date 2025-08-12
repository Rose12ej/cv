// Course Registration Program -  program that stores and adds course information
// Rosalia Nunez
// April 21,2023
// CSCN 112-002


//libraries
#include <iostream>
#include <cctype>
#include <string>
#include <exception>
#include <iomanip>
#include "Date.h"
#include "Course.h"

using namespace std;

//	*	*	* FUNCTION PROTOTYPES
// -- GETS INFO
void getCourse(string& nme, int& cp); // prompts for course name and capacity
char printMenu(); // prints menu and prompts for selection
void getPersonalInfo(string& id, string& fN, string& lN, Date& bD); // gets and stores basic personal info 
	// sets employee info
void getEmployeeInfo(Date& bD, string& fN, string& lN, string& id, string& rnk, string& t, double& sal, Date& dX, char selec);
	// sets academic info
void getAcademicInfo(Date& bD, string& fN, string& lN, string& id, string& lvl, string& mj, double& gpa, Date& dX, char selec);
// -- ERROR CHECKS 
void errorCheckForSalAndGPA(double& z, istream& cin, char menuSelection); // error check gpa for student and salary for instructor
string studentLevel(string level); // error checks for a correct level
void errorCheckDate(int& dd, int& mm, int& yyyy); // error checks for positive number in dates
	

int main()
{
	//variables
	 string Cname; // course name
	 string id, fN, lN; // basic info (id, first name, last name)
	 string t, rnk, mj, lvl; // Instructor's title & rank; Student's major & level
	 Date bD; // birth date
	 Date dX; // any type of date
	 char selection = 0, c =0; // menu selection, and c character for the '/' in the Dates
	 int cap = 0; // course's max student capacity
	 int d = 0, m = 0, yyyy = 0;  // date, month, year
	 double gpa =0, sal = 0; // student's gpa and instructor's salary 
	

	//main logic
	 cout << setw(30) << "-COURSE REGISTRATION-" << endl << endl;
	 //	*	*	*	* SETS BASIC COURSE INFO
	 getCourse(Cname, cap); // prompts for course name and capacity
	 Course a(cap, Cname); // saves it
	 //	*	*	*	* MENU
	 while (selection != 'Q') { //stops when user selects quit
		 selection = printMenu(); // displays menu, & prompts and stores selection
		 switch (selection)
		 {
		 case 'I':
			 if (!a.isThereInstructor()) { // if there is no instructor assigned in course

				 //		*	*	*	* CREATES FACULTY RECORD
				 cout << setw(28) << "Create Faculty Member" << endl; // title
				 getPersonalInfo(id, fN, lN, bD); // gets and stores in variables basic info of faculty
				 cin.ignore(); // fixes cin for getlines
				 // --  gets and stores in variables employee info of faculty
				 getEmployeeInfo(bD, fN, lN, id, rnk, t, sal, dX, selection);
				 //		*	*	*	* STORES FACULTY RECORD IN COURSE
				 a.setFaculty(bD, fN, lN, id, rnk, t, sal, dX);
			 }else { // does not allow more than one instructor to be enrolled 
				 cout << "An instructor has already been set for this course! " << endl << endl;
			 }
			 break;
		case 'S':
			//		*	*	*	* CREATES STUDENT RECORD
				 cout << setw(23) << "Create Student" << endl; // title
				 getPersonalInfo(id, fN, lN, bD); // gets and stores in variables basic info of student
				 cin.ignore(); // fixes cin for getlines
				  // --  gets and stores in variables academic info of student
				 getAcademicInfo(bD, fN, lN, id, lvl, mj, gpa, dX,selection);
			//		*	*	*	* STORES STUDENT RECORD IN COURSE
				 try { a.addStudent(bD, fN, lN, id, lvl, mj, gpa, dX);
						cout << endl << "Student succesfully added!" << endl << endl;
				 }
				 catch (exception e) // outputs error if class is full
				 {
					 cout << "The class is full. Student could'not be added. No more students can be added!" << endl << endl;
				 }
				 
			 break;
		 case 'L': // list all course's info
			 a.listCourseInfo();
			 break;
			 cout << endl;
		 case 'Q': // quits switch statement
			 cout << "Quitting Program..." ;
			 break;
		 default: // error check for invalid selection
			 cout << "You entered an invalid character!" << endl;
			 cin.clear(); // clearing cin
			 cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignoring incorrect values
			 break;
		 }
	 }

	 //closing statements
	system("pause");
	return 0;
}


//	*	*	* FUNCTION IMPLEMENTATION 	*	*	*
void getCourse(string& nme, int& cp) // prompts for course name and capacity
{
	cout << "Enter a name for your Course: "; // prompts for course name
	getline(cin,nme);
	cout << endl;
	cout << "What is the maximum capacity for your course: "; // prompts for course's student max. capacity
	cin >> cp;
	cout << endl;
	
	// error check for capacity
	while (cin.fail()||cp<0)
	{
		cin.clear(); // clearing cin
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignoring incorrect values
		// re-prompts for capacity
		cout << "You entered an invalid or negative value. \n What is the maximum capacity for your course: "; 
		cin >> cp;
		cout << endl;
	}
}
char printMenu() // prints menu and prompts for selection
{
	char selec; // selection
	cout << setw(20) << "Main Menu" << endl;
	cout << setw(22) << "I -- Add Instructor" << endl;
	cout << setw(19) << "S -- Add Student" << endl;
	cout << setw(31) << "L -- List Course Information" << endl;
	cout << setw(12) << "Q -- Quit" << endl << endl;
	cout << setw(14) << "Selection: ";
	cin >> selec;
 	cout << endl;
	return toupper(selec); // returns selection in uppercase
}
void getPersonalInfo(string& id, string& fN, string& lN, Date& bD) // gets and stores basic personal info 
{
	char c; // character var for '/' in the dates
	int d = 0, m = 0, yyyy = 0;  // date , month, and year variables

	cin.ignore(); // fixes cin for getlines
	cout << "ID: ";		//	ID
	getline(cin, id);
	cout << endl;
	cout << "First Name: "; 	//	FIRST NAME
	getline(cin, fN);
	cout << endl;
	cout << "Last Name: ";		//	LAST NAME
	getline(cin, lN);
	cout << endl;
	cout << "Birthdate (mm/dd/yyyy): ";			//	BIRTH DATE
	cin >> m >> c >> d >> c >> yyyy; cout << endl;
	// error check for birthday
	errorCheckDate(d, m, yyyy);
	bD.setDate(d,m,yyyy);
}
void errorCheckForSalAndGPA(double& z, istream& cin, char menuSelection) // error check gpa for student and salary for instructor
{
	double x = z; // represents the salary or gpa
	Course f; // fake course
	Date y(0, 0, 0000); // empty fake date

		if (cin.fail()) { // check if in fail state
			cin.clear();  //clearing cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignoring incorrect values
			cout << "You entered an invalid character. Please re-enter value:" << endl;
			cin >> x;
			errorCheckForSalAndGPA(x, cin, menuSelection);
		}
		else if (menuSelection == 'I') // checks for salary
		{
			try {
				f.setFaculty(y,"","","","","",x,y);
			}
			catch (exception a) { // catches negative salary exception
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignoring incorrect values
				cerr << a.what();
				cout << "Please re-enter value : " << endl;
				cin >> x;
				errorCheckForSalAndGPA(x, cin, menuSelection); // repeats function
			}
		}
		else if (menuSelection == 'S') {  // checks for gpa
			try {
				f.setCapacity(1); 
				f.addStudent(y, "a", "a", "a", "a", "a", x, y);
			}
			catch (exception a) { // catches negative gpa  or more than 4.00 exception
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignoring incorrect values
				cerr << a.what();
				cout << "Please re-enter value : " << endl;
				cin >> x;
				errorCheckForSalAndGPA(x, cin, menuSelection); // repeats function
			}
		}
		z = x; // returns correct salary or gpa
}

string studentLevel(string l) // error checks for a correct level
{
	string temp = l; // temporal string 
	for (int i = 0; i <= temp.size(); ++i) // turns level into upper case
	{ if(temp[i] == tolower(temp[i]))
		temp[i] = toupper(temp[i]);
	}
	l = temp;
	if (l != "FRESHMAN") { // checks if the string does not have a correct level, and if it does re-prompts
		if (l != "SOPHOMORE") {
			if (l != "JUNIOR") {
				if (l != "SENIOR") {
					cout << "you entered an invalid level." << endl;
					cout << "re-enter level: ";
					cin >> l;
					studentLevel(l); // repeats function
			}    }
		}
	}

	for (int i = 0; i <= temp.size(); ++i) // turns level into lower case for aesthetic :)
	{
		temp[i] = tolower(temp[i]);
	}
	l = temp;
	
	return l; // returns corrected level
}
void errorCheckDate(int& dd, int& mm , int& yyyy) // error checks for positive number in dates
{
	char c = 0; // c character for the '/' in the dates
	// error check for date
	while (cin.fail() || mm < 0 || dd < 0 || yyyy < 0)
	{
		cin.clear(); // clearing cin
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignoring incorrect values
		cout << "An incorrect value was entered for date! Please re-enter date!" << endl;
		cout << "Date (mm/dd/yyyy): ";
		cin >> dd>> c >> mm >> c >> yyyy; cout << endl;
	}
	
}
// gets faculty's employee info
void getEmployeeInfo(Date& bD, string& fN, string& lN, string& id,string& rnk,string& t,double& sal,Date& dX, char selec )
{
	char c; // character var for '/' in the dates
	int d = 0, m = 0, yyyy = 0;  // date , month, and year variables

	cout << "Title: "; getline(cin, t); cout << endl;
	cout << "Rank: "; getline(cin, rnk); cout << endl;
	cout << "Salary: "; cin >> sal; cout << endl;
	errorCheckForSalAndGPA(sal, cin, selec); // error check for the salary
	cout << "Date of Hire (mm/dd/yyyy): " ; cin >> m >> c >> d >> c >> yyyy; cout << endl;
	errorCheckDate(d, m, yyyy); // error check for date
	dX.setDate(d, m, yyyy);  // stores date hired in variable
}
// gets student's academic info
void getAcademicInfo(Date& bD, string& fN, string& lN, string& id, string& lvl, string& mj, double& gpa, Date& dX, char selec)
{
	char c; // character var for '/' in the dates
	int d = 0, m = 0, yyyy = 0;  // date , month, and year variables

	cout << "Major: "; getline(cin, mj); cout << endl;
	cout << "Level (Freshman, Sophomore, Junior, Senior): "; cin >> lvl; cout << endl;
	lvl = studentLevel(lvl); // error checks and stores correct level
	cout << "GPA: "; cin >> gpa; cout << endl;
	errorCheckForSalAndGPA(gpa, cin, selec); // error checks gpa
	cout << "Date of Enrollment (mm/dd/yyyy): "; cin >> m >> c >> d >> c >> yyyy; cout << endl;
	errorCheckDate(d, m, yyyy); // error checks date
	dX.setDate(d, m, yyyy); //saves date
}