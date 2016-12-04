#include "VectorMathLibrary.h"   

void main()
{
	//vectors and values in them
	Vector <double> A, B, C; 
	Vector <double> D, E;

	A.x = 5, A.y = 4, A.z = 7, A.alpha = 68;
	B.x = -2, B.y = 5, B.z = 6, B.alpha = 79;
	D.x = 7, D.y = 9, D.z = 4, D.alpha = 0;
	E.x = 8, E.y = 10, E.z = 2, E.alpha = 0;

	C = A + B;
	C.Print2D();
	cout << endl;

	C.Print3D();  
	cout << endl;

	C.Print4D();
	cout << endl;

	C = A - B;
	C.Print2D();
	cout << endl;

	C.Print3D(); 
	cout << endl;

	C.Print4D();
	cout << endl;

	cout << D.Magnitude() << endl;  
	cout << E.Magnitude() << endl;

	system("pause");
}