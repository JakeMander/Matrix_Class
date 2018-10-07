#pragma once
#include "Vertex.h"

const int ROWS = 2;
const int COLUMNS = 2;

class Matrix
{
	public:
		
		//	Default Constructor, Constructor And The Copy Constructor Allow For The Creation Of An Empty Matrix, a 2x2 Matrix 
		//	And Provide The Capacity To Initalise An Object By Copying Another Instance Of The Matrix Class.
		Matrix();
		Matrix(float x0y0, float x0y1, float x1y0, float x1y1);
		Matrix(const Matrix& other);
		
		//	Accessor And Mutator For Encapsulation Of Class. Allow Only Members Of The Class Access To The Private Variables.
		float GetMatrixElement(const int row, const int column) const;
		void SetMatrixElement(const int row, const int column, const float value);

		//	Operator Overloads To Define The Copying, Moving, Eqivalence And Multiplication Of Matrices. 
		Matrix& operator= (const Matrix &rhs);
		Matrix& operator= (Matrix &&rhs);
		
		// Equality Check: Is Matrix x Equal To Matrix Y?
		bool operator==(const Matrix&other) const;
		
		// Multiplication Operators: Calculate The Product of 2, 2x2 Matrices OR The Product of A Vertex And A Matrix.
		const Matrix operator*(const Matrix &other) const;
		const Vertex operator*(const Vertex &other) const;

		//	copy Function To Reduce Repeated Code When Checking Each Element Of A Matrix.
		void copy(const Matrix& matrixIn);

		//	Private Access Specifier: Variables That Are Only Accessible To Members Of The Same Class.
	private:
		float _matrixArray[ROWS][COLUMNS];
};
