#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <fstream>
#include <iostream>

class Student
{
    long ID;
    double GPA;
    char grade;
    std::string name;
public:
    // Constructor
    Student() :name(), ID(), GPA(), grade() {} //Default Constructor
    // Accessors
    long get_ID() const { return ID; }
    double get_GPA() const { return GPA; }
    char get_grade() const { return grade; }
    std::string get_name() const { return name; }

    //Files

    void read(std::istream& in) // reads input from file
    {
        using namespace std;
        while (in.peek() == '#') // looks for a '#'
        {
            in.ignore(INT_MAX, '\n'); //skips to next line if found(comment)
            in >> ws;
        }
        getline(in, name); // Reads  name till newline
        // Finds position of first # (start of comment)
        size_t pos = name.find('#'); 
        
        if (pos != std::string::npos)
        {
        name.erase(pos); //erases starting from # sign
        }

        while (in.peek() == '#')
        {
            in.ignore(INT_MAX, ('\n'));
            in >> ws;
        }
        in >> ID >> ws; // reads ID
        while (in.peek() == '#')
        {
            in.ignore(INT_MAX, '\n');
            in >> ws;
        }
        in >> GPA >> ws; // reads GPA
        while (in.peek() == '#')
        {
            in.ignore(INT_MAX, '\n');
            in >> ws;
        }
        in >> grade >> ws; // reads grade
    }

    void write(std::ostream& out) // writes data to file
    {
        using namespace std;
        out << name << endl << ID << endl << GPA << endl << grade << endl << endl;
    }

    // Mutators
    void set_ID(const long i_ID) { ID = i_ID; }
    void set_GPA(const double i_GPA) { GPA = i_GPA; }
    void set_grade(const char i_grade) { grade = i_grade; }
    void set_name(const std::string i_name) { name = i_name; }

};

#endif /* STUDENT_H */


