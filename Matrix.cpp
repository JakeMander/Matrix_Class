#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix()
{
	// Initialise All Values To 0 To Ensure Array Is Initalised With Valid Values.
	SetMatrixElement(0, 0, 0);
	SetMatrixElement(0, 1, 0);
	SetMatrixElement(1, 0, 0);
	SetMatrixElement(1, 1, 0);
}

Matrix::Matrix(float x0y0, float x0y1, float x1y0, float x1y1)
{
	SetMatrixElement(0, 0, x0y0);
	SetMatrixElement(0, 1, x0y1);
	SetMatrixElement(1, 0, x1y0);
	SetMatrixElement(1, 1, x1y1);

	cout << "\nArray Values: " << endl;
	cout << "\n\t" << GetMatrixElement(0, 0) << " || " << GetMatrixElement(0, 1) << endl;
	cout << "\n\t" << GetMatrixElement(1, 0) << " || " << GetMatrixElement(1, 1) << endl;
}

//	const At Start Of Function Implementation: The Return Value Is Changed, But The Address Which This Value Is Stored To Remains Constant.
//	const Inside Brackets: The Referenced Parameter Value Cannot Be Changed.
//	const At End Of Function: The Function Cannot Change Any Member Data Values Within The Class
Matrix::Matrix(const Matrix& other)
{
	copy(other);
}

float Matrix::GetMatrixElement(const int row, const int column) const
{
	return _matrixArray[row][column];
}

void Matrix::SetMatrixElement(const int row, const int column, const float value)
{
	_matrixArray[row][column] = value;
}

Matrix& Matrix::operator=(const Matrix &rhs)
{
	if (&rhs == this)
	{
		return *this;
		cout << "\nCOPY HAS BEEN PERFORMED" << endl;
	}
	copy(rhs);
	return *this;
}

Matrix& Matrix::operator=(Matrix &&rhs)
{
	//No Destructor Required: rhs Should Go Out Of Scope By Itself. Simply Move The Values Over.
	if (&rhs == this)
	{
		return *this;
		cout << "\nMOVE HAS BEEN PERFORMED" << endl;
	}
	copy(rhs);
	return *this;
}

//	Iterate Through Each Matrix Element. Compare Across Both Matrices. If Any Element Pair Do Not Match, The Matrices Can Be Considered Unequal And The Function Returns False
//	
bool Matrix::operator==(const Matrix &other)const
{
	for ( int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (GetMatrixElement(i, j) != other.GetMatrixElement(i,j))
			{
				return false;
			}
		}
	}
	return true;
}

const Matrix Matrix::operator*(const Matrix &other) const
{
	Matrix resultMatrix;
	float cumulativeSum;

	// For Each Row...
	for (int i = 0; i < ROWS; i++)
	{
		//	...Increment Through The Columns.
		for (int j = 0; j < COLUMNS; j++)
		{
			//	Reset The Cumulative Total Before We Move On To The Next Set of Calculations...
			cumulativeSum = 0;
			for (int k = 0; k < 2; k++)
			{
				//	Then Calculate The Value For Each Element In The Product Matrix By Multiplying Every Row Element (First Matrix) By Every Column Element In The Second Matrix.
				//	To Do This, Use A Third Value K, To Synchronise The Multiplication (I.e. First Element In Row 0 In Matrix 1, Multiplied By The First Column Elmenet In Matrix 2)
				cumulativeSum += (GetMatrixElement(i, k) * other.GetMatrixElement(k, j));
			}
			resultMatrix.SetMatrixElement(i, j, cumulativeSum);
		}
	}
	return resultMatrix;
}

const Vertex Matrix::operator*(const Vertex &other) const
{
	Vertex productResult;

	productResult.SetX((GetMatrixElement(0, 0) * other.GetX()) + (GetMatrixElement(0,1) * other.GetY()));
	productResult.SetY((GetMatrixElement(1, 0) * other.GetX()) + (GetMatrixElement(1, 1) * other.GetY()));

	return productResult;
}

//	Remove Need For Repeated Code By Representing The Process Of Cycling Through A Matrix And Setting It's Values As A Single Function.
void Matrix::copy(const Matrix & matrixIn)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			SetMatrixElement(i, j, matrixIn.GetMatrixElement(i, j));
		}
	}
}

