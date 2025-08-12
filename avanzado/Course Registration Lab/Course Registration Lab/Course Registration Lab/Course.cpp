// Course class header file - is a class that stores course's information 

//libraries
#include "Course.h"
#include "Faculty.h"
#include "Student.h"
#include "Date.h"
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

Course::Course(int cap, string nme)  // default constructor
{
	setCapacity(cap);
	setCourseName(nme);
}
Course::~Course()  // default destructor
{}
void Course::setCourseName(string nme)  // sets the course name
{
	cName = nme;
}
void Course::setCapacity(int cp) // sets the max. student capacity
{
	if (cp >= 0)
		capacity = cp;
	else  // error checks for negative number
		throw invalid_argument("Capacity cannot be a negative integer!");
}
void Course::addStudent(Date bd,string fn,string ln,string id,string lvl, string mjr, double gpa,Date de) // enrolls students
{
	if (studentIC.size() < capacity) {
		Student x(bd, fn, ln, id); // sets personal info
		// sets academic info
		x.setLevel(lvl);
		x.setMajor(mjr);
		x.setGPA(gpa);
		x.setDateEnrolled(de);
		studentIC.push_back(x); // stores in vector
	}
	else { // error check for maximum capacity
		throw exception("maximum capacity has been reached!");
	}
}
void Course::setFaculty(Date bd,string fn, string ln,string id,string rnk,string t, double sal,Date dH) // assigns instructor
{
	Faculty x(bd, fn, ln, id); // sets personal info
	// sets employee info
	if (!isThereInstructor()) { // if there is no instructor assigned in course

		x.setRank(rnk);
		x.setSalary(sal);
		x.setTitle(t);
		x.setDateHired(dH);
		facultyIC = x;
	}
	else { // does not allow more than one instructor to be enrolled 
		throw exception("An instructor has already been set for this course! ");
	}
}

string Course::getCourseName() const // retrieves name of course
{
	return cName;
}
int Course::getCapacity() const // retrieves max. student capacity
{
	return capacity;
}
void Course::getStudents() // retrieves and sorts students info
{
	sortStudents(); // sorts students
	for (int i = 0; i < studentIC.size(); ++i) // outputting sorted students
	{
		cout << studentIC.at(i) << endl;
	}
}
void Course::getFaculty() // retrieves instructor info
{
	cout << facultyIC << endl;
}
bool Course::isThereInstructor() // checks if there is an instructor for the course
{
	bool isThereI = false; // is there an instructor in this course bool initialization
	if (facultyIC.getFirstName() == "") { // checks if there is no name stored in the faculty object
		isThereI = false;
	}
	else { // if there is a name returns there is an instructor
		isThereI = true;
	}
	return isThereI;
}
bool Course::isThereStudents() // checks if there are students enrolled
{
	bool isThereStudents = false;// is there students in this course bool initialization
	if (studentIC.size() == 0) { // check if student vector's size is 0
		isThereStudents = false;
	}
	else { // returns true if size is not 0
		isThereStudents = true;
	}
	return isThereStudents;
}
void Course::listCourseInfo() //lists all course's info (name, capacity, instructor, students)
{
	cout << "Information for Course " << getCourseName() << endl; // displays title and course name 
	cout << "Student Capacity: " << getCapacity() << endl << endl; // displays course capacity
	if (!isThereInstructor()) // if there is no instructor, displays message below
	{
		cout << "No Instructor is enrolled in this course!" << endl << endl;
	}else { // if there is instructor, formats and displays all info of faculty
		getFaculty();
	}
	if (!isThereStudents()) // if there is no students, displays message below
	{
		cout << "No Students are enrolled in this course!" << endl << endl;
	}else{ // if there is students, formats and displays all info of faculty
		cout << "These are the Students enrolled in the " << getCourseName() << " course:" << endl;
		getStudents();
	}
}
void Course::sortStudents() // sorts students
{
	sort(studentIC.begin(), studentIC.end()); // sorting from least to highest id
}