/*
 * Title:		Nghi Vo
 * Purpose:		Implementation of all Person class methods
 * Description: Represent a person with name and and object birthday
 *              Represent a person with name and and birthday (yyyy, mm, dd)
 * Author:		Nghi Vo
 * Date:		April 16, 2020
 */

#include "person.h"
#include "date.h"
#include <string>
#include <sstream>

using namespace std;

/*
 * Basic Person Constructor with name and object Date Birthday
 * Set name name of person
 * Set birthday birthday of person
 */
Person::Person(const string& name, const Date &birthday)
        : _name(name), _birthday(birthday) {
}

/* This Person Constructor with name and birthday */
Person::Person(const string& name, size_t year, size_t month, size_t day)
        : _name(name), _birthday(Date(year, month, day)) {
}

/* Destructor of Person class */
Person::~Person(){

}
/*
 * To String: create a string representation of person with name and birthday
 * Return a string information of person
 */
string Person::ToString() const {
    stringstream ss;
    ss << "{name: " << _name << " ,Birthday: " << _birthday.ToString() << "}";
    return ss.str();
}
/*
 * Name Accessor
 * Return Name of person
 */
string Person::GetName() const {
    return _name;
}

/*
 *  Age Accessor
 *  Return Age of person
 */
size_t Person::GetAge() const {
    return _birthday.Difference(Date::Now()) / 365;
}

/*
 * Read person from input
 */
void Person::Read(istream &input) {
    string name;
    Date birthday;
    Date temp(0, 0, 0);

    input >> name;
    if (input.fail()){
         _name = " ";
        _birthday = temp;
        exit(0);
    }

    input >> birthday;
    if(input.fail()){
        _name = " ";
        _birthday = temp;
        exit(0);
    }
    _name = name;
    _birthday = birthday;
}

/*
 * Writes person data to output
 */
void Person::Write(ostream &output) const {
    output << "P" << " " << _name << " " << _birthday;
}

