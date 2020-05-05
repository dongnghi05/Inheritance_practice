/*
 * Title:	    Person Class Method Definition
 * Purpose:		A Class represent a simple person
 * Author:		Nghi Vo
 * Date:		April 16, 2020
 */

#ifndef SCHOOL_INHERITANCE_PERSON_H
#define SCHOOL_INHERITANCE_PERSON_H

#include "date.h"

class Person {
protected:
    string _name;
    Date _birthday;

public:
    Person(const string& name, const Date& birthday);
    Person(const string& name, size_t year, size_t month, size_t day);

    virtual ~Person();
    virtual string ToString()const;
    virtual void Read(istream& input);
    virtual void Write(ostream& output)const;

    string GetName()const;
    size_t GetAge()const;
};


#endif
