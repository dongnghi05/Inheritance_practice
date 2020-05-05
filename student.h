/*
 * Title:	    Student Class Method Definition
 * Purpose:		A Class represent a simple student
 * Author:		Nghi Vo
 * Date:		April 16, 2020
 */

#ifndef SCHOOL_INHERITANCE_STUDENT_H
#define SCHOOL_INHERITANCE_STUDENT_H

#include "date.h"
#include "person.h"
class Student : public Person{

    string _major;
    size_t _credits;
    float _gpa;

public:
    Student(const string& , const Date& );
    Student(const string& , const Date& , const string& );

    virtual ~Student();
    virtual string ToString()const;
    virtual void Read(istream& input);
    virtual void Write(ostream& output)const;

    void AddGrade(float grade, size_t credits);
    float GetGPA()const;
    size_t GetCredits()const;

};

#endif
