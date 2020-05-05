/*
 * Title:	    Student Class Method Definition
 * Purpose:		Implemenation if all Student class methods
 * Author:		Nghi Vo
 * Date:		April 16, 2020
 */

#include <sstream>
#include "date.h"
#include "person.h"
#include "student.h"

using namespace std;
/*
 * Basic Student constructor with name and birthday with undecided major, _gpa and _credit is 0
 */
Student::Student(const string &name, const Date &birthday)
        : Person(name, birthday), _major("Undecided"),_credits(0), _gpa(0.0){

}

/*
 * Student constructor with all the data members of the student
 */
Student::Student(const string &name, const Date& birthday, const string& major)
        : Person(name, birthday), _major(major), _credits(0), _gpa(0.0){

}

/*
 * Destructor of student
 */
Student::~Student() {

}

/*
 * To String: create a string representation of student with inheritance class person with name and birthday
 * also append Major and GPA
 */
string Student::ToString() const {
    stringstream ss;
    ss << "{Person: " << Person::ToString() << " , major: " << _major << " credits: " << _credits << " ,gpa: " << _gpa << "}";
    return ss.str();
}
/*
 * Load student from file
 */
void Student::Read(istream &input) {
    string name;
    Date birthday;
    Date temp(0, 0, 0);
    string major;
    size_t credit;
    float gpa;

    input >> name;
    if (input.fail()){
        name = " ";
        birthday = temp;
        major = " ";
        credit = 0;
        gpa = 0.0;
        exit(0);
    }

    input >> birthday;
    if(input.fail()){
        name = " ";
        birthday = temp;
        major = " ";
        credit = 0;
        gpa = 0.0;
        exit(0);

    }

    input >> major;
    if (input.fail()){
        name = " ";
        birthday = temp;
        major = " ";
        credit = 0;
        gpa = 0.0;
        exit(0);
    }

    input >> credit;
    if (input.fail()){
        name = " ";
        birthday = temp;
        major = " ";
        credit = 0;
        gpa = 0.0;
        exit(0);
    }

    input >> gpa;
    if (input.fail()){
        name = " ";
        birthday = temp;
        major = " ";
        credit = 0;
        gpa = 0.0;
        exit(0);
    }

    _name = name;
    _birthday = birthday;
    _major = major;
    _credits = credit;
    _gpa = gpa;
}
/*
 * Write student to file
 */
void Student::Write(ostream &output) const {
    output << "S" << " " << _name << " " << _birthday << " " << _major << " " << _gpa << " " << _credits;
}

/*
 * Adds grade with number of credits and update GPA
 */
void Student::AddGrade(float grade, size_t credits) {
    float _curGPA = grade * credits;
    float _oldGPA = _gpa * _credits;
    _credits +=credits;
    _gpa = (_oldGPA + _curGPA)/_credits;
}

/*
 * GPA Accessor
 * Return GPA of student
 */
float Student::GetGPA() const {
    return _gpa;
}

/*
 * Credits Accessor
 * Return the number of credits of student
 */
size_t Student::GetCredits() const {
    return _credits;
}








