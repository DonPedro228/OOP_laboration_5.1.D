#pragma once
#include "Triad.h"
#include <iostream>
using namespace std;

class Vector3D : public Triad
{
public:
	Vector3D() : Triad() {}
	Vector3D(double x, double y, double z) : Triad(x, y, z) {};
	Vector3D(const char* str) : Triad(str) {};

	Vector3D& operator =(const Vector3D& other);

	operator string() const;
	friend Vector3D operator*(double scalar, const Vector3D& vec);

	friend bool operator==(const Vector3D& vec1, const Vector3D& vec2);
	friend bool operator ^ (const Vector3D& vec1, const Vector3D& vec2);
	friend bool operator!=(const Vector3D& vec1, const Vector3D& vec2);

	Vector3D& operator ++();
	Vector3D& operator --();
	Vector3D operator ++(int);
	Vector3D operator --(int);

	double operator()() const;
}; 
