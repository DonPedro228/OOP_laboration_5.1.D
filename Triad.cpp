#include "Triad.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

Triad::Triad()
{
	date[0] = 1;
	date[1] = 1;
	date[2] = 1;
}

Triad::Triad(int day, int month, int year)
{
	date[0] = day;
	date[1] = month;
	date[2] = year;
}

int Triad::getDay() const {
	return date[0];
}

int Triad::getMonth() const {
	return date[1];
}

int Triad::getYear() const {
	return date[2];
}

void Triad::setDay(int day) {
	date[0] = day;
}

void Triad::setMonth(int month) {
	date[1] = month;
}

void Triad::setYear(int year) {
	date[2] = year;
}

void Triad::Init(int day, int month, int year) {
	setDay(day);
	setMonth(month);
	setYear(year);
}

void Triad::Display() const {
	cout << endl;
	cout << "Date: " << date[0] << "/" << date[1] << "/" << date[2] << endl;
}

void Triad::Read() {
	int day, month, year;
	cout << "Input date: ";
	cin >> day >> month >> year;

	Init(day, month, year);
}

Triad::operator string()const
{
	stringstream ss;
	ss << endl;
	ss << "Date: " << date[0] << "/" << date[1] << "/" << date[2] << endl;
	return ss.str();
}

ostream& operator << (ostream& out, const Triad& m)
{
	out << string(m);
	return out;
}

istream& operator >> (istream& input, Triad& vec)
{
	int day, month, year;
	cout << "Enter day: ";
	input >> day;
	if (day <= 0) {
		throw VectorException("Invalid input: day must be a positive number.");
	}

	cout << "Enter month: ";
	input >> month;
	if (month <= 0) {
		throw VectorException("Invalid input: month must be a positive number.");
	}

	cout << "Enter year: ";
	input >> year;
	if (year <= 0) {
		throw VectorException("Invalid input: year must be a positive number.");
	}

	vec.Init(day, month, year);
	return input;
}


bool operator>(const Triad& t1, const Triad& t2) {
	if (t1.date[0] > t2.date[0])
		return true;
	else if (t1.date[0] == t2.date[0]) {
		if (t1.date[1] > t2.date[1])
			return true;
		else if (t1.date[1] == t2.date[1]) {
			if (t1.date[2] > t2.date[2])
				return true;
		}
	}
	return false;
}

bool operator==(const Triad& t1, const Triad& t2) {
	return t1.date[0] == t2.date[0] && t1.date[1] == t2.date[1] && t1.date[2] == t2.date[2];
}


bool operator!=(const Triad& t1, const Triad& t2) {
	return !(t1 == t2);
}


bool operator>=(const Triad& t1, const Triad& t2) {
	return (t1 > t2) || (t1 == t2);
}

bool operator<(const Triad& t1, const Triad& t2) {
	return !(t1 >= t2);
}

bool operator<=(const Triad& t1, const Triad& t2) {
	return !(t1 > t2);
}

Triad::~Triad() {}