#pragma once
#include <iostream>
#include <exception>
#include <sstream>
#include <string>
using namespace std;

class VectorException : public exception {

public:
    VectorException(const char* msg) : exception(msg) {
        throw invalid_argument("Incorrect value");
    }
};

class Triad
{
private:
    int date[3];
public:
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    Triad();
    Triad(int day, int month, int year);
    Triad(const char* str) {
        istringstream iss(str);
        char slash;
        if (!(iss >> date[0] >> slash >> date[1] >> slash >> date[2]))
            throw VectorException("Incorerect value!");
    }

    void Init(int day, int month, int year);
    void Display() const;
    void Read();

    operator string () const;
    friend ostream& operator << (ostream& out, const Triad& m);
    friend istream& operator >> (istream& in, Triad& m);
    friend bool operator>(const Triad& t1, const Triad& t2);
    friend bool operator==(const Triad& t1, const Triad& t2);
    friend bool operator!=(const Triad& t1, const Triad& t2);
    friend bool operator>=(const Triad& t1, const Triad& t2);
    friend bool operator<(const Triad& t1, const Triad& t2);
    friend bool operator<=(const Triad& t1, const Triad& t2);


    ~Triad(void);
};