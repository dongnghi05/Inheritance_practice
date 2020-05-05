/*
 * Title:	    Person Class Method Definition
 * Purpose:		Main class run all the function.
 * Author:		Nghi Vo
 * Date:		April 16, 2020
 */

#include "date.h"
#include "person.h"
#include "student.h"
#include "professor.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::vector;
using std::fstream;

using namespace std;

size_t Menu();
void DeletePeople(vector<Person*>& person);

int main(int argc, char* argv[]) {
	vector<Person*> people; // This is the only vector you need, remember to release the memory
	int userOption;
	while ( (userOption = Menu()) != 15){
		if (userOption == 1){			// Add Person
		    string name;
		    Date birthDay;
		    string major;

            cout << "Name: ";
            cin >> name;

            cout << "Birth date yyyy mm dd: ";
            cin >> birthDay;
            Date tempBirthday(birthDay.GetYear(), birthDay.GetMonth(), birthDay.GetDay());
            while (tempBirthday.IsInvalidDate()){
                cout << "Invalid Date!" << endl;
                cout << "Birth date yyyy mm dd: ";
                cin >> tempBirthday;
            }
            people.push_back(new Person(name, tempBirthday));
            cout << "Person inserted in position: " << people.size() - 1 << endl;

		}else if (userOption == 2){		// Add Student
		    string name;
		    Date birthDay;
		    string major;

		    cout << "Name: ";
		    cin >> name;

            cout << "Birth date yyyy mm dd: ";
            cin >> birthDay;
            Date tempBirthday(birthDay.GetYear(), birthDay.GetMonth(), birthDay.GetDay());
            while (tempBirthday.IsInvalidDate()){
                cout << "Invalid Date!" << endl;
                cout << "Birth date yyyy mm dd: ";
                cin >> tempBirthday;
            }

            cout << "Major: ";
            cin >> major;
            people.push_back(new Student(name, tempBirthday, major));
            cout << "Student inserted in position: " << people.size() - 1  << endl;

        }else if (userOption == 3){		// Add Professor
            string name;
            Date birthDay;
            string department;
            Date hireDate;

            cout << "Name: ";
            cin >> name;

            cout << "Birth date yyyy mm dd: ";
            cin >> birthDay;
            Date tempBirthday(birthDay.GetYear(), birthDay.GetMonth(), birthDay.GetDay());
            while (tempBirthday.IsInvalidDate()){
                cout << "Invalid Date!" << endl;
                cout << "Birth date yyyy mm dd: ";
                cin >> tempBirthday;
            }
            cout << "Department: ";
            cin >> department;

            cout << "Hire date yyyy mm dd: ";
            cin >> hireDate;
            Date tempHireDate(hireDate.GetYear(), hireDate.GetMonth(), hireDate.GetDay());
            while (tempHireDate.IsInvalidDate()){
                cout << "Invalid Date!" << endl;
                cout << "Hire date yyyy mm dd: ";
                cin >> tempHireDate;
            }

            people.push_back(new Professor(name, tempBirthday, department, tempHireDate));
            cout << "Professor inserted in position: " << (people.size() - 1) << endl;

		}else if (userOption == 4){		// List All People
            for (Person* person: people){
                cout << person->ToString() << endl;
            }

		}else if (userOption == 5){		// Show Students Report
		    for (Person* person: people){
		        if (dynamic_cast<Student*>(person) != nullptr){
		            cout << person->ToString() << endl;
		        }
		    }

		}else if (userOption == 6){		// Show Professor Report
            for (Person* person: people){
                if (dynamic_cast<Professor*>(person) != nullptr){
                    cout << person->ToString() << endl;
                }
            }

		}else if (userOption == 7){		// Show !Professor !Student
            for (Person* person: people){
                if (dynamic_cast<Professor*>(person) == nullptr && dynamic_cast<Student*>(person) == nullptr){
                    cout << person->ToString() << endl;
                }
            }

		}else if (userOption == 8){		// Calculate Average GPA
		    float avgGPA = 0.0;
		    float count = 0.0;
            for (Person* person: people){
                if (dynamic_cast<Student*>(person) != nullptr){
                    count++;
                    Student* student = dynamic_cast<Student*>(person);
                    avgGPA = (avgGPA + student->GetGPA())/count;
                }
            }
            cout << "The average GPA of all students is: " << avgGPA << endl;

		}else if (userOption == 9){		// Calculate Average Salary
            float avgSalary = 0.0;
            float count = 0.0;
            for (Person* person: people){
                if (dynamic_cast<Professor*>(person) != nullptr){
                    count++;
                    Professor* professor = dynamic_cast<Professor*>(person);
                    avgSalary += professor->GetSalary()/count;
                }
            }
            cout << "The average salary of all professors is: " << avgSalary << endl;

		}else if (userOption == 10){	// Input Grades to Student
		    // Show all the students report
		    if (people.size() == 0){
		        cout << "The list is empry! Please adding people." << endl;
		    }
		    else {
		        int check = 0;
                int count = 0;
                for (Person *person: people) {
                    if (dynamic_cast<Student *>(person) != nullptr) {
                        cout << count << " " << person->ToString() << endl;
                        check++;
                    }
                    count++;
                }
                if (check == 0){
                    cout << "There is no student." << endl;
                }
                else {
                    // Choose student to input grade
                    size_t choice;
                    cout << "Number of student to input grades to: ";
                    cin >> choice;
                    while (cin.fail() || choice >= people.size() ||
                           (dynamic_cast<Student *>(people[choice])) == nullptr) {
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(255, '\n');
                            cout << "Incorrect input!" << endl;
                            cout << "Number of student to input grades to: ";
                        } else if (choice >= people.size()) {
                            cout << "Position out of range!" << endl;
                            cout << "Number of student to input grades to: ";
                        } else {
                            cout << people[choice]->ToString() << " is not a student" << endl;
                            cout << "Number of student to input grades to: ";
                        }
                        cin >> choice;
                    }
                    // Adding grade for student
                    float grade;
                    cout << "Grade of the student [0.0 to 4.0 scale]: ";
                    cin >> grade;
                    while (cin.fail() || (grade > 4.0 || grade < 0.0)) {
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(255, '\n');
                            cout << "Incorrect input!" << endl;
                            cout << "Grade of the student [0.0 to 4.0 scale]: ";
                        } else if (grade > 4.0 || grade < 0.0) {
                            cout << "Invalid grade value, make sure [0.0, 4.0]: " << endl;
                            cout << "Grade of the student [0.0 to 4.0 scale]: ";
                        }
                        cin >> grade;
                    }

                    size_t credit;
                    cout << "Credits {1, 2, 3, 4, 5}: ";
                    cin >> credit;
                    while (cin.fail() || credit > 6 || grade < 1) {
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(255, '\n');
                            cout << "Incorrect input!" << endl;
                            cout << "Credits {1, 2, 3, 4, 5}: ";
                        } else if (credit > 6 || grade < 1) {
                            cout << "Invalid grade value, make sure Credits {1, 2, 3, 4, 5}: " << endl;
                        }
                        cin >> credit;
                    }
                    dynamic_cast<Student *>(people[choice])->AddGrade(grade, credit);
                }
            }
        }else if (userOption == 11) {    // Promote Professor
            // No element in list
            if (people.size() == 0) {
                cout << "The list is empry! Please adding people.";
            }
            else {
                // Show all the professor report
                int check = 0;
                int count = 0;
                for (Person *person: people) {
                    if (dynamic_cast<Professor *>(person) != nullptr) {
                        cout << count << " " << person->ToString() << endl;
                        check++;
                    }
                    count++;
                }
                if (check == 0){
                    cout << "There is no professor in the list." << endl;
                }
                else {
                    // Choose professor to input promote
                    size_t choice;
                    cout << "Number of student to input grades to: ";
                    cin >> choice;
                    while (cin.fail() || choice >= people.size() ||
                           (dynamic_cast<Professor *>(people[choice])) == nullptr) {
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(255, '\n');
                            cout << "Incorrect input!" << endl;
                            cout << "Number of professor to promote: ";
                        } else if (choice >= people.size()) {
                            cout << "Position out of range!" << endl;
                            cout << "Number of professor to promote: ";
                        } else {
                            cout << people[choice]->ToString() << " is not a professor" << endl;
                            cout << "Number of professor to promote: ";
                        }
                        cin >> choice;
                    }
                    dynamic_cast<Professor *>(people[choice])->Promote();
                }
            }
        }else if (userOption == 12){	// Give Raise to Professor
            // Show all the professor report
            if (people.size() == 0){
                cout << "The list is empry! Please adding people." << endl;
            }
            else {
                int count = 0;
                int check = 0;
                for (Person *person: people) {
                    if (dynamic_cast<Professor *>(person) != nullptr) {
                        cout << count << " " << person->ToString() << endl;
                        check++;
                    }
                    count++;
                }
                if (check == 0){
                    cout << "There is no professor. " << endl;
                }
                else {
                    // Choose professor to input promote
                    size_t choice;
                    cout << "Number of professor to promote: ";
                    cin >> choice;
                    while (cin.fail() || choice >= people.size() ||
                           (dynamic_cast<Professor *>(people[choice])) == nullptr) {
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(255, '\n');
                            cout << "Incorrect input!" << endl;
                            cout << "Number of professor to promote: ";
                        } else if (choice >= people.size()) {
                            cout << "Position out of range!" << endl;
                            cout << "Number of professor to promote: ";
                        } else {
                            cout << people[choice]->ToString() << " is not a professor" << endl;
                            cout << "Number of professor to promote: ";
                        }
                        cin >> choice;
                    }
                    // Adding raise for professor
                    float raise;
                    cout << "Raise to the professor [0.0, 50.0]: ";
                    cin >> raise;
                    while (cin.fail() || (raise > 50.0 || raise < 0.0)) {
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(255, '\n');
                            cout << "Incorrect input!" << endl;
                            cout << "Raise to the professor [0.0, 50.0]: ";
                        } else if (raise > 50.0 || raise < 0.0) {
                            cout << "Raise out of range!" << endl;
                            cout << "Raise to the professor [0.0, 50.0]: ";
                        }
                        cin >> raise;
                    }
                    dynamic_cast<Professor *>(people[choice])->Raise(raise);
                }
            }
		}else if (userOption == 13){	// Load from File
            string fileName;
            string line;
            cout << "Input Filename: ";
            cin >> fileName;

            string name = "unknown";
            Date tempBirthday;
            string department = "unknown";

            ifstream Inmyfile(fileName);
            if (Inmyfile){
               while (getline(Inmyfile,line)){
                   char character;
                   Inmyfile >> character;
                   Person* person = new Person(name, tempBirthday);
                   Person* student = new Student(name, tempBirthday);
                   Person* professor = new Professor(name, tempBirthday, department);
                   if (character == 'P'){
                        person->Read(Inmyfile);
                       people.push_back(person);
                       delete student;
                       delete professor;
                    }
                   else if (character == 'S'){
                        student->Read(Inmyfile);
                       people.push_back(student);
                       delete person;
                       delete professor;
                   }
                   else if (character == 'R'){
                        professor->Read(Inmyfile);
                       people.push_back(professor);
                       delete person;
                       delete student;
                   }
               }
                Inmyfile.close();
            }
            else {
                cout << "Can not open file " << fileName << endl;
            }

        }else if (userOption == 14){	// Write to File
            ofstream myfile;
            // Get name from user
            cout << "Output filename: ";
            string fileName;
            cin >> fileName;
            myfile.open(fileName);
            for (Person* person: people){
                person->Write(myfile);
                myfile << endl;
            }
            myfile.close();
		}
	}
	DeletePeople(people);
	return 0;
}

size_t Menu(){
	int option = 0;
	while(true){
		cout << "-------------------------------------------" << endl;
		cout << "1. Add a Person" << endl;
		cout << "2. Add a Student" << endl;
		cout << "3. Add a Professor" << endl;
		cout << "4. List all People" << endl;
		cout << "5. Show Students Report" << endl;
		cout << "6. Show Professors Report" << endl;
		cout << "7. Show People (not Professors or Students)" << endl;
		cout << "8. Calculate all Students Average GPA" << endl;
		cout << "9. Calculate all Professors Average Salary" << endl;
		cout << "10. Input Grades to Student" << endl;
		cout << "11. Promote Professor" << endl;
		cout << "12. Give Raise to Professor" << endl;
		cout << "13. Load Data from File" << endl;
		cout << "14. Write Data to File" << endl;
		cout << "15. Exit" << endl;

		cin >> option;
		if (cin.fail()){
			cin.clear();
			cin.ignore(255, '\n');
			cerr << "Incorrect input!" << endl;
			continue;
		}
		if (option < 1 || option > 15){
			cerr << "Incorrect menu option!" << endl;
			continue;
		}
		break;
	}
	cout << endl;
	return static_cast<size_t>(option);
}

void DeletePeople(vector<Person*>& person){
    for (Person* people : person){
        delete people;
    }
}
