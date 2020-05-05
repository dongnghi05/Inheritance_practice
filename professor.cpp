/*
 * Title:	    Professor Class Method Definition
 * Purpose:		Impletation of all Professor class methods
 * Author:		Nghi Vo
 * Date:		April 16, 2020
 */

#include "date.h"
#include "person.h"
#include "professor.h"
#include <sstream>
#include <string>

using namespace std;

/*
 * Basic Professor constructor with name and birthday, major with rank ASSISTANT and open salary
 */
Professor::Professor(const string &name, const Date& birthday, string& department)
            : Person(name, birthday), _department(department), _hireDate(Date::Now()), _rank(ASSISTANT_PROFESSOR), _salary(60000.00){
}

/*
 * Basic Professor constructor with name and birthday, major
 * Rank is based on how long professor has worked
 * More than 10 year is professor with start salary is 75000
 * Less than 5 years is assistant with start salary is 60000
 * From 5 to 10 years is associate with start salary is 70000
 */
Professor::Professor(const string &name, const Date& birthday, const string& department, const Date& hireDate)
            : Person(name, birthday), _department(department), _hireDate(hireDate) {
    if (hireDate.Difference(Date::Now()) < 1825){
        _rank = ASSISTANT_PROFESSOR;
        _salary = 60000.00;
    }
    else if (hireDate.Difference(Date::Now()) >= 1825 && hireDate.Difference(Date::Now()) < 3650){
        _rank = ASSOCIATE_PROFESSOR;
        _salary = 70000.00;
    }
    else {
        _rank = PROFESSOR;
        _salary = 75000.00;
    }
}
/*
 * Basic Professor constructor with name, birthday, major, hire-date, rank and salary
 */
Professor::Professor(const string &name, const Date& birthday, const string& department, const Date& hireDate, Rank rank, float salary)
            : Person(name, birthday), _department(department), _hireDate(hireDate), _rank(rank), _salary(salary){
}
/*
 * Deconstructor
 */
Professor::~Professor() {

}
/*
 * To String: create a string representation of professor with name and birthday major hire date rank and salary
 * Return a string information of professor
 */
string Professor::ToString() const {
    stringstream ss;
    ss << "{Person: " << Person::ToString() << " ,department: " << _department
       << " ,rank: " << _rank << " ,hire-date: " << _hireDate.ToString() << " ,salary: " << _salary << "}";
    return ss.str();
}

/*
 * Load professor to file
 */
void Professor::Read(istream &input) {
    string name;
    Date birthday;
    Date temp(0, 0, 0);
    string deparment;
    Date hireDate;
    size_t rank;
    float salary;


    input >> name;
    if (input.fail()){
        name = " ";
        birthday = temp;
        deparment = " ";
        hireDate = temp;
        rank = 0;
        salary = 0.0;
    }

    input >> birthday;
    if(input.fail()){
        name = " ";
        birthday = temp;
        deparment = " ";
        hireDate = temp;
        rank = 0;
        salary = 0.0;
    }

    input >> deparment;
    if (input.fail()){
        name = " ";
        birthday = temp;
        deparment = " ";
        hireDate = temp;
        rank = 0;
        salary = 0.0;
    }

    input >> hireDate;
    if (input.fail()){
        name = " ";
        birthday = temp;
        deparment = " ";
        hireDate = temp;
        rank = 0;
        salary = 0.0;
    }

    input >> rank;
    if (input.fail()){
        name = " ";
        birthday = temp;
        deparment = " ";
        hireDate = temp;
        rank = 0;
        salary = 0.0;
    }

    input >> salary;
    if (input.fail()){
        name = " ";
        birthday = temp;
        deparment = " ";
        hireDate = temp;
        rank = 0;
        salary = 0.0;
    }

    _name = name;
    _birthday = birthday;
    _department = deparment;
    _hireDate = hireDate;
    _rank = static_cast<Rank>(rank);
    _salary = salary;
}

/*
 * Write professor to file
 */
void Professor::Write(ostream &output)const {
    output << "R" << " " << _name << " " << _birthday << " " << _department << " " << _hireDate << " " << _rank;
}

/*
 * Raise professor salary based on percentage
 */
void Professor::Raise(float percentage) {
    _salary = _salary*percentage/100 + _salary;
}

/*
 * Promote professor to next rank based on old rank.
 */
void Professor::Promote() {
    if(_rank == ASSISTANT_PROFESSOR){
        _rank = ASSOCIATE_PROFESSOR;
    }
    else {
        _rank = PROFESSOR;
    }
}

/*
 * Rank accessor
 */
Rank Professor::GetRank() const {
    return _rank;
}

/*
 * Salary accessor
 */
float Professor::GetSalary() const {
    return _salary;
}









