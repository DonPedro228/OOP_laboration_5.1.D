#include "Vector3D.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

Vector3D& Vector3D::operator = (const Vector3D& other)
{
    if (this != &other) {
        Triad::operator=(other);
    }
    return *this;
}

Vector3D::operator string() const
{
    stringstream sout;
    sout << "( " << getDay() << ", " << getMonth() << ", " << getYear() << ")";
    return sout.str();
}

Vector3D operator*(double scalar, const Vector3D& vec) {
    if (scalar == 0) {
        throw invalid_argument("Scalar can not be 0!");
    }
    return Vector3D(scalar * vec.getDay(), scalar * vec.getMonth(), scalar * vec.getYear());
}

bool operator!=(const Vector3D& vec1, const Vector3D& vec2) {
    return !(vec1 == vec2);
}

double Vector3D::operator()() const {
    return sqrt(getDay() * getDay() + getMonth() * getMonth() + getYear() * getYear());
}

bool operator==(const Vector3D& vec1, const Vector3D& vec2) {
    return vec1.getDay() == vec2.getDay() && vec1.getMonth() == vec2.getMonth() && vec1.getYear() == vec2.getYear();
}

bool operator ^ (const Vector3D& vec1, const Vector3D& vec2)
{
    return vec1() == vec2();
}

Vector3D& Vector3D::operator++() {
    setDay(getDay() + 1);
    setMonth(getMonth() + 1);
    setYear(getYear() + 1);
    return *this;
}

Vector3D& Vector3D::operator--() {
    setDay(getDay() - 1);
    setMonth(getMonth() - 1);
    setYear(getYear() - 1);
    return *this;
}

Vector3D Vector3D::operator++(int) {
    Vector3D temp(*this);
    ++(*this);
    return temp;
}

Vector3D Vector3D::operator--(int) {
    Vector3D temp(*this);
    --(*this);
    return temp;
}
