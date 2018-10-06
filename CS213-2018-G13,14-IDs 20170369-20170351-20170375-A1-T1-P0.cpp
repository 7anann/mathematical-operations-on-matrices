/**
Course:  CS213 - Programming II  - 2018
Title:   Assignment I - Task 1 - Problem 0
Program: CS213-2018-A1-T1-P0
Purpose: Mathematics operations on Matrices
Authors: 1- Name :- Nada Nasser Al-Said El-Azab .................. ID :- 20170369
         2- Name :- Hanan Mohamed Abd-El-Rahim  .................. ID :- 20170375
         3- Name :- Farah Mohamed Osama Mostafa .................. ID :- 20170351
Date:    6 October 2018
Version: 1.0
*/
//________________________________________________________________________
#include <iostream>
#include <iomanip>
#include <system_error>
#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  int** data;       // Pointer to 2-D array that will simulate matrix
  int row, col;
};

// Already implemented
void createMatrix (int row , int col , int num[] , matrix& mat);
///---------------------------------------------------------------------------------------
// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1 , matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1 , matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1 , matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1 , int scalar);  // Add a scalar
matrix operator-  (matrix mat1 , int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1 , int scalar);  // Multiple by scalar
///--------------------------------------------------------------------------------------
// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1 , matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1 , matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat , int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat , int scalar);   // change mat & return new matrix
matrix   operator++ (matrix& mat);   	/// Add 1 to each element ++mat
matrix   operator-- (matrix& mat);    	/// Sub 1 from each element --mat

matrix   operator++ (matrix& mat , int no);    	/// Sub 1 from each element --mat

matrix   operator++ (matrix& mat , int no);    	/// Sub 1 from each element --mat


istream& operator>> (istream& in , matrix& mat);
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

///---------------------------------------------------------------------------------------
//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out , matrix mat);
       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	       // and return ostream to cascade printing	9	12    123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

void drowLine();
///---------------------------------------------------------------------------------------

int main()
{
    cout << left << boolalpha;
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int data4 [] = {1,2,3
                   ,4,5,6
                   ,7,8,9} ;

    int data5 [] = {1,0,0,
                    0,1,0,
                    0,0,1};
/*
    matrix mat1, mat2, mat3 , mat4 , mat5 , mat6;
    createMatrix (4, 2, data1, mat1);
    createMatrix (2, 3, data2, mat2);
    createMatrix (4, 2, data3, mat3);
    createMatrix (3, 3, data4, mat4);
    createMatrix (3, 3, data5, mat5);

    cout << mat1 + mat2 << endl ;
    cout << mat4 + mat5 << endl ;
*/
/*
    cout << "Is this matrix a square matrix ? " << isSquare(mat4)   << endl;
    cout << "Is this matrix Symmetric ? "       << isSymetric(mat2) << endl;
    cout << "Is this matrix Identity ? "        << isIdentity(mat5) << endl;


    cin >> mat4;

    cout <<endl << mat4 << endl;

    cout << transpose(mat4) << endl;
    cout << mat1 << endl;
    cout << mat2 << endl;
    cout << mat3 << endl;
    mat1 += mat3;
    cout << mat1 <<endl;
    mat1 -= mat3;
    cout << mat1 <<endl;

    cout << (mat1 + mat3) << endl ;
    cout << (mat3 + mat3) << endl ;
    cout << (mat1 - mat3) << endl ;
    cout << (mat3 - mat3) << endl ;


    ++mat1;
    cout << mat1 << endl;

    mat1+= mat3 += mat3;
    cout << mat1 << endl;
    cout << mat2 << endl;
    cout << mat3 << endl;

*/
    return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat)
{
  mat.row = row;
  mat.col = col;
  mat.data = new int* [row];

  for (int i = 0; i < row; i++)
    mat.data[i] = new int [col];

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      mat.data[i][j] = num[i * col + j];
}

///----------------------------------------------------------------------------
/// Student one codes :-
///-----------------------
matrix operator+  (matrix mat1, matrix mat2) // Add if same dimensions
{
    if (mat1.col == mat2.col && mat1.row == mat2.row)
    {
        //to check of they have the same dimensions
        matrix mat3;
        int *data = new int[mat1.col * mat2.row];
        createMatrix(mat1.row, mat1.col, data, mat3);

        for (int i = 0; i < mat1.row; i++)
        {
            for (int j = 0; j < mat1.col; j++)
            {
                mat3.data[i][j] = mat1.data[i][j] + mat2.data[i][j];//adds elements in the matrices
            }
        }
        return mat3;
    }
    else{
        cout << "these matrices don't have the same dimensions\n";//if not the same dimensions
    }
}
//_____________________________________________________________________________
matrix operator-  (matrix mat1, matrix mat2) // Sub if same dimensions
{
    if (mat1.col == mat2.col && mat1.row == mat2.row)
    {
        //to check of they have the same dimensions
        matrix mat3;
        int *data = new int[mat1.col*mat2.row];
        createMatrix(mat1.row, mat1.col, data, mat3);

        for (int i = 0; i < mat1.row; i++)
        {
            for (int j = 0; j < mat1.col; j++)
            {
                mat3.data[i][j] = mat1.data[i][j] - mat2.data[i][j];//subtracts elements in the matrices
            }
        }
        return mat3;
    }
    else
        cout << "these matrices dont have the same dimension\n";//if not the same dimensions
}
//_____________________________________________________________________________
matrix operator*  (matrix mat1, matrix mat2) // Multi if col1 == row2
{
    if (mat1.col == mat2.row) //to check if they are the right dimensions (nxm&mxk)
    {
        matrix mat3;
        int *data = new int[mat1.row * mat2.col];

        for (int i = 0; i<mat1.row*mat2.col; i++)
        {
            data[i] = 0;    // Initialize all elements to zero.
        }
        for (int i = 0; i < mat1.row; i++)
        {
            for (int j = 0; j < mat1.col; j++)
            {
                for (int h = 0; h < mat2.col; h++)
                {
                    data[i * mat2.col + h] += mat1.data[i][j] * mat2.data[j][h];//we created an array that
                }//stores the multiplied elements of the new matrix
            }
        }

        createMatrix(mat1.row, mat2.col, data, mat3);//we'll then use the array we made in the createMatrix function.
    }
    else
        cout << "these matrices dont have the right dimensions\n";//if the dimensions were not right

}
//_____________________________________________________________________________
matrix operator+  (matrix mat1, int scalar)  // Add a scalar
{
    matrix mat2;
    int *data = new int[mat1.col*mat1.row];
    for (int i = 0; i < mat1.row; i++)
    {
        for (int j = 0; j < mat1.col; j++)
        {
            data[i * mat1.col + j] = mat1.data[i][j] + scalar;//we created an array that stores the matrix which
        }//we added the scaler to
    }
    createMatrix(mat1.row, mat1.col, data, mat2);//then we use the array to create the new matrix
    return mat2;
}
//_____________________________________________________________________________
matrix operator-  (matrix mat1, int scalar)  // Subtract a scalar
{
    matrix mat2;
    int *data = new int[mat1.col*mat1.row];
    for (int i = 0 ; i < mat1.row ; i++)
    {
        for (int j = 0 ; j < mat1.col ; j++)
        {
            data[i * mat1.col + j] = mat1.data[i][j] - scalar;//we created an array that stores the matrix which
        }//we subtracted the scaler from
    }
    createMatrix(mat1.row, mat1.col, data, mat2);//then we use the array to create the new matrix
    return mat2;
}
//_____________________________________________________________________________
matrix operator*  (matrix mat1, int scalar)  // Multiple by scalar
{
    matrix mat2;
    int *data = new int[mat1.col * mat1.row];
    for (int i = 0 ; i < mat1.row ; i++)
    {
        for (int j = 0 ; j < mat1.col ; j++)
        {
            data[i * mat1.col + j] = mat1.data[i][j] * scalar;//we created an array that stores the matrix which
        }//we multiply the scaler to
    }
    createMatrix(mat1.row, mat1.col, data, mat2);//then we use the array to create the new matrix
    return mat2;
}

///----------------------------------------------------------------------------
/// Student two codes :-
///-----------------------
matrix operator += (matrix& mat1 , matrix mat2) // mat1 changes & return
{
    //assert((mat1.row == mat2.row) && (mat1.col == mat2.col));

    if(mat1.row == mat2.row && mat1.col == mat2.col)
    {
        for (int i = 0 ; i < mat1.row ; i++)
        {
            for(int j = 0; j < mat1.col ; j++)
            {
                mat1.data[i][j] += mat2.data[i][j];
            }
        }
        return mat1;
    }
}
//___________________________________________________________________________________
matrix operator -= (matrix& mat1 , matrix mat2) // mat1 changes & return
{

    if(mat1.row == mat2.row && mat1.col == mat2.col)
    {
        for (int i = 0 ; i < mat1.row ; i++)
        {
            for(int j = 0 ; j < mat1.col ; j++)
            {
                mat1.data[i][j] -= mat2.data[i][j];
            }
        }
        return mat1;

    }
}
//____________________________________________________________________________________
matrix operator += (matrix& mat, int scalar)   // change mat & return new matrix
{
    for (int i = 0 ; i < mat.row ; i++)
    {
        for(int j = 0 ; j < mat.col ; j++)
            mat.data[i][j] += scalar; // add the number given to each entry in the matrix
    }
    return mat;
}
//____________________________________________________________________________________
matrix operator -= (matrix& mat , int scalar)   // change mat & return new matrix
{
    for (int i = 0 ; i < mat.row ; i++)
    {
        for(int j=0; j < mat.col; j++)
            mat.data[i][j]-=scalar;  // subtract the number given from each entry in the matrix
    }
    return mat;
}
//_____________________________________________________________________________________
matrix operator++ (matrix& mat)   	// Add 1 to each element ++mat
{
    for (int i = 0 ; i < mat.row ; i++)
    {
        for(int j = 0 ; j < mat.col ; j++)
            ++ mat.data[i][j];
    }
    return mat;
}
//__________________________________________________________________________________
matrix   operator-- (matrix& mat)    	// Sub 1 from each element --mat
{
    for (int i = 0; i < mat.row; i++)
    {
        for(int j = 0; j < mat.col; j++)
            -- mat.data[i][j];

    }
    return mat;
}
//_______________________________________________________________________________
istream& operator>> (istream& in , matrix& mat)
{
    cout << "Enter number of rows    : ";
    cin  >> mat.row;
    cout << "Enter number of columns : ";
    cin  >> mat.col;
    int  num[] = {mat.row * mat.col}; //an empty array with size of rows multiplied by columns
    createMatrix (mat.row , mat.col , num , mat);

    cout<<"Enter the elements of the matrix: "<<endl;
    for(int i = 0 ; i < mat.row ; i++)
    {
        for(int j = 0 ; j < mat.col ; j++)
            in >> mat.data[i][j] ; //enter the elements of the array

    }
    return in;
}

///----------------------------------------------------------------------------
/// Student three codes :-
///-----------------------
ostream& operator << (ostream& out, matrix mat)
{
    out << "\nThe Matrix is : " << endl;
    for(int i = 0 ; i < mat.row ; i++)
    {
        for(int j = 0 ; j < mat.col ; j++)
            out << setw(5)  << mat.data[i][j] ;
        out << endl;
    }
    drowLine(); // just to separate between matrices printed .

    return out;// return ostream to be able to print the matrix using the same (cout) Ex : cout << mat1 << mat2 << ...;
}
//________________________________________________________________________________________________
bool operator == (matrix mat1, matrix mat2)	// True if identical (same dimension and same data)
{
    if(mat1.row != mat2.row && mat1.col != mat2.col) // if same dimension or not
        return (0);
    for(int i = 0 ; i < mat1.row ; i++)
    {
        for(int j = 0 ; j < mat1.col ; j++)
        {
            if(mat1.data[i][j] != mat2.data[i][j])  // if same element or not
            {
                return (0);
            }
        }
    }
    return (1);
}
//________________________________________________________________________________________________
bool   operator != (matrix mat1, matrix mat2) 	// True if not same dimension or not same data
{
    if(mat1.row != mat2.row || mat1.col != mat2.col) // if same dimension or not
        return 1;
    bool diff = false;
    for(int i = 0 ; i < mat1.row ; i++)
    {
        for(int j = 0 ; j < mat1.col ; j++)
        {
            if( mat1.data[i][j] != mat2.data[i][j] )  // if same element or not
            {
                diff = true;
            }
        }
    }
    return diff;
}
//________________________________________________________________________________________________
bool   isSquare   (matrix mat)  // True if square matrix (number of rows = number of columns)
{
    return ( mat.row == mat.col ? 1 : 0 );
}
//________________________________________________________________________________________________
bool isSymetric (matrix mat)  // True if square and symmetric .
{
    if(isSquare(mat))
    {
        for(int i = 0 ; i < mat.row ; i++)
        {
            for(int j = 0 ; j < mat.col ; j++)
            {
                // data[i][j] is the corresponding element of data[j][i].
                if(mat.data[i][j] != mat.data[j][i])
                    return 0;
            }
        }
    }
    else
    {
        return 0;
    }
    return 1;
}
//________________________________________________________________________________________________
bool isIdentity (matrix mat) // True if square and identity.
{
    if(isSquare(mat))
    {
        for(int i = 0 ; i < mat.row ; i++)
        {
            for(int j = 0 ; j < mat.col ; j++)
                // The elements in the main diagonal (row = column (i = j)) should not = 1 .
                // and the other elements (row != column (i != j)) should not = 0 .
                if( (i != j && mat.data[i][j] != 0 )  || (i == j && mat.data[i][j] != 1))
                    return 0;
        }

    }
    else
        return 0;

    return 1;
}
//________________________________________________________________________________________________
matrix transpose (matrix mat) // Return new matrix with the transpose
{
    // create a new matrix to save the transpose in it :-
    int data[(mat.col) * (mat.row)];
    matrix t_mat;
    createMatrix(mat.row, mat.col, data, t_mat);

    for(int i = 0 ; i < mat.row ; i++)
    {
        for(int j = 0 ; j < mat.col ; j++)
        {
            t_mat.data[i][j] = mat.data[j][i]; // the row in real matrix = the column in the transpose.
        }
    }

    return t_mat;
}
///--------------------------------------------------------------------
void drowLine()
{
    cout <<"----------------------------------";
}
///--------------------------------------------------------------------

matrix   operator++ (matrix& mat , int no)    	// Add 1 to each element mat++
{
    matrix mat2;
    int *data = new int [mat.row * mat.col];
    for(int i = 0; i < mat.row ; i++){
        for(int j = 0 ; j<mat.col ; j++){
            data[i * mat.col + j] = mat.data[i][j];
        }
    }
    createMatrix(mat.row , mat.col , data , mat2);

    for(int i = 0 ; i < mat.row ; i++ ){
        for(int j = 0 ; j < mat.col ; j++){
            mat.data[i][j]++;
        }
    }
    return mat2;
}

matrix   operator-- (matrix& mat , int no)    	/// Sub 1 from each element mat--
{
    matrix mat2;
    int *data = new int [mat.row * mat.col];
    for(int i = 0; i < mat.row ; i++){
        for(int j = 0 ; j<mat.col ; j++){
            data[i * mat.col + j] = mat.data[i][j];
        }
    }
    createMatrix(mat.row , mat.col , data , mat2);

    for(int i = 0 ; i < mat.row ; i++ ){
        for(int j = 0 ; j < mat.col ; j++){
            mat.data[i][j]--;
        }
    }
    return mat2;
}
