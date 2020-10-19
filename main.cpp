#include <iostream>
#include <string>
using namespace std;

const int N = 50;
int vectorMulti(int A[], int B[], int n1, int n2)
{
    int result;
    string err = "error";
    try {
        if(n1 != n2) throw err;
        for(int i = 0; i < n1; ++i) {
            result += A[i]*B[i];
        }
    }catch(string err) { cout << err << endl;}
}
void vectorMatrixMulti(int A[], int B[][N], int C[], int c1, int r2, int c2)
{
    int result = 0;
    string err = "error";
    try {
        if(c1 != r2 || c1 != c2) throw err;
        for(int i = 0; i < c1; ++i) {
            for(int j = 0; j < c2; ++j)
            {
                result += A[i]*B[i][j];
            }
            C[i] = result;
        }
    }catch(string err) { cout << err << endl;}
}

int main()
{

    int A[2] = {1, 0};
    int B[2] = {0, 1};
    int Cr[3] = {1, 0 ,1};
    int result[3];
    int K[][N] = { {1, 0, 1}, {0, 1, 1}, {1, 1, 1}};
    cout << vectorMulti(A, B, 2, 2) << endl;
    vectorMatrixMulti(Cr, K, result, 3 ,3 ,3);
    for(int k = 0; k < 3; k++) {
        cout << result[k] << endl;
    }
    int r1, c, c2,a[100][100], b[100][100], sum[100][100], multi[100][100], i, j;

    cout << "Enter number of rows of the first column(between 1 and 100): ";
    cin >> r1 ;

    cout << "Enter number of columns/rows (equal for both matrix)(between 1 and 100): ";
    cin >> c;
    //c1 = r2
    cout << "Enter number of columns of the second matrix(between 1 and 100): ";
    cin >> c2;

    cout << endl << "Enter elements of 1st matrix: " << endl;

    // Storing elements of first matrix entered by user.
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           cout << "Enter element a" << i + 1 << j + 1 << " : ";
           cin >> a[i][j];
       }

    // Storing elements of second matrix entered by user.
    cout << endl << "Enter elements of 2nd matrix: " << endl;
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           cout << "Enter element b" << i + 1 << j + 1 << " : ";
           cin >> b[i][j];
       }

    // Adding Two matrices
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
            sum[i][j] = a[i][j] + b[i][j];

    // Displaying the resultant sum matrix.
    cout << endl << "Sum of two matrix is: " << endl;
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            cout << sum[i][j] << "  ";
            if(j == c - 1)
                cout << endl;
        }
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
            multi[i][j] = a[i][j] * b[i][j];
    // Displaying the result of multipl of two matrics
    cout << endl << "The multiplication of two matrix is: " << endl;
    for(i = 0; i < r; ++i) {
        for(j = 0; j < c; ++j)
        {
            cout << multi[i][j] << "  ";
            if(j == c - 1) cout << endl;
        }
    }
    return 0;
}
