#include "Matrix.h"

int main()
{
	Matrix <double> M1, M2, M3, M4;
// input, output and operator[] check
	cout << "Enter M1:\n";
	cin >> M1;
	cout << "M1[2][2]:\n" << M1[1][1] << '\n';
	cout << "M1:\n" << M1;

// track check
	cout << "\nTrack of M1:\n" << M1.track() << '\n';
// transpose check
	M2 = M1.transp();
	cout << "\nM1(transposed):\n" << M2;
// sum check
	M1 += M2;
	cout << "\nM1 + M1(transposed):\n" << M1;

	M3 = M1 + M2;
	cout << "\nM1 + previous result:\n" << M3;
// multiplying check
	int num;
	cout << "\nEnter the number: ";
	cin >> num;

	M1 *= num;
	cout << "\nM1 * (your number):\n" << M1;

	cout << "\nPrevious result * (your number):\n" << M1 * num;

	cout << "\nEnter the matrix for multiplying (with correct size):\n";
	cin >> M2;
	cout << "\nM1 * (your matrix):\n" << M1 * M2;
// Gauss check
	M2 = M1.gauss();
	cout << "\nHere is the triangle form of M1:\n" << M2;
// determinant check
	int d = M1.det();
	cout << "\nHere is the determinant of M1: " << d << "\n";
// swap raws check
	M1.swapRaws(0, 1);
	cout << "\nHere is M1 with 1st and 2nd swaped raws:\n" << M1;
// swap columns check
	M1.swapColumns(0, 1);
	cout << "\nHere is M1 with 1st and 2nd swaped columns:\n" << M1;
// subtraction check
	cout << "\nEnter your matrix for subtraction from M1:\n";
	cin >> M2;
	cout << "\nHere is M1 - (your matrix):\n" << M1 - M2;
// diagonal matrix check
	cout << "Enter your matrix which needs to be diagonalized:\n";
	cin >> M1;
	cout << "Here is your matrix in diagonal form:\n";
	cout << M1.diagonal();

// inversion check
	cout << "Enter your matrix which needs to be inversed:\n";
	cin >> M1;
	cout << "Here is your inverted matrix:\n";
	cout << M1.invertMatrix(); // !!! if det = 0, prints 0-matrix (same size, all elements are equal 0)

	system("PAUSE");

	return 0;
}