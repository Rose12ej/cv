// Course class header file - is a class that stores course's information 
#pragma once

//libraries
#include "Faculty.h"
#include "Student.h"
#include <vector>

class Course
{
public:
	Course( int cap = 0, std::string nme = ""); // default constructor
	~Course(); // default destructor
	void setCourseName(std::string nme); // sets the course name
	void setCapacity(int cp); // sets the max. student capacity
	void addStudent(Date bd, std::string fn, std::string ln, 
		std::string id,std::string lvl, std::string mjr, double gpa, Date de); // enrolls students
	void setFaculty(Date bd, std::string fn, std::string ln,
		std::string id, std::string rnk,std::string t, double sal, Date dH); // assigns instructor
	std::string getCourseName() const; // retrieves name of course
	int getCapacity() const; // retrieves max. student capacity
	void getStudents(); // retrieves and sorts students info
	void getFaculty() ; // retrieves instructor info
	bool isThereInstructor(); // checks if there is an instructor for the course
	bool isThereStudents();  // checks if there are students enrolled
	void listCourseInfo(); //lists all course's info (name, capacity, instructor, students)
	void sortStudents(); 
private:
	std::string cName; //course name
	int capacity; // max. capacity of students in course
	Faculty facultyIC; //faculty in course
	std::vector<Student> studentIC; // students  in course 
};