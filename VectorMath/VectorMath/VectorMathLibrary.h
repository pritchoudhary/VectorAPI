#pragma once
#include <iostream>  
#include <cmath>      
#include <string>

using namespace std;

//templated vector class
template<typename T> 
class Vector
{
public:
	//variables
	T x = 0;
	T y = 0;  
	T z = 0;
	T alpha = 0;

	//used to print 3D vecs
	void Print3D() 
	{
		cout << x << " " << y << " " << z << endl;
	}

	//used to print 2D vecs
	void Print2D() 
	{
		cout << x << " " << y << endl;
	}

	//used to print 4D vecs
	void Print4D() 
	{
		cout << x << " " << y << " " << z << " " << alpha << endl;
	}

	Vector()
	{
		//default constructor
		x = 0;
		y = 0; 
		z = 0;
		alpha = 0;
	}

	//2D constructor
	Vector(T a, T b)
	{
		x = a;  
		y = b;
	}

	//3D constructor
	Vector(T a, T b, T c)
	{
		x = a; 
		y = b;
		z = c;
	}

	//4D constructor
	Vector(T a, T b, T c, T d)
	{
		x = a;
		y = b; 
		z = c;
		alpha = d;
	}

	//addition
	Vector operator+(Vector other) 
	{
		Vector temp(0, 0);
		temp.x = x + other.x;
		temp.y = y + other.y;
		temp.z = z + other.z;
		return temp;
	}

	//subtraction
	Vector operator-(Vector other) 
	{
		Vector temp(0, 0);
		temp.x = x - other.x;
		temp.y = y - other.y;
		temp.z = z - other.z;
		return temp;
	}

	//finds magnitude of vecs
	double Magnitude() 
	{
		int tempx = x * x;
		int tempy = y * y;
		int tempz = z * z;
		double sr = sqrt(tempx + tempy + tempz);

		return sr;
	}

	//normalizes vecs
	Vector Normalize() 
	{
		double div;
		if (x >= y && x >= z)
		{
			div = x;
		}

		else if (y >= x && y >= z)
		{
			div = y;
		}

		else
		{
			div = z;
		}
		double newx = x / div;
		double newy = y / div;
		double newz = z / div;

		Vector temp(newx, newy, newz);
		return temp;
	}

	//Dot Product
	double operator*(Vector other) 
	{
		Vector temp(0, 0);
		temp.x = x * other.x;
		temp.y = y * other.y;
		temp.z = z * other.z;
		double dot = temp.x + temp.y + temp.z;

		return dot;
	}

	//Cross Product
	Vector operator/(Vector other)
	{
		double crossx, crossy, crossz;
		crossx = (y * other.z) - (other.y * z);
		crossy = (z * other.x) - (other.z * x);
		crossz = (x * other.y) - (other.x * y);

		Vector cross(crossx, crossy, crossz);
		return cross;
	}

	//Angle between two vectors.
	double Angle(Vector b)
	{
		double base, opp, hyp;
		opp = this->Magnitude();
		base = b.Magnitude();
		hyp = sqrt((base * base) + (opp * opp));

		Vector tri(base, opp, hyp);
		tri = tri.Nomalize();

		double angle = acos(base / hyp);

		angle = (angle / 3.14) * 180;

		return angle;
	}

	//LinearInterpolation
	double LinearInterpolation(float a, float b, float perc)
	{
		return (a + (b - a)) * perc;
	}

	//Degrees to Radians
	float DtoR(int d)
	{
		return (d / 180)*3.14;
	}

	//Radians to degrees
	float RtoD(int r)
	{
		return (r / 3.14) * 180;
	}

	//hex color conversion
	Vector<int> HexColor(unsigned int HexColor) 
	{
		unsigned int Hexred = HexColor >> 24;
		unsigned int Hexgreen = (HexColor >> 16) & 0x00FF;
		unsigned int Hexblue = (HexColor >> 8) & 0x0000FF;
		unsigned int Hexalpha = HexColor & 0x000000FF;
		Vector<int> hex(Hexred, Hexgreen, Hexblue, Hexalpha);

		return hex;
	}

	
};