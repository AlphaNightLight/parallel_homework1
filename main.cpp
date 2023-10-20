#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <chrono>

using namespace std;

void array_addition();
void matrix_copy();

int main()
{
    srand(time(NULL));
    //array_addition();
    matrix_copy();
    return 0;
}

void array_addition()
{
    int i;
    int n;
    cout << "Size of the arrays: " << endl;
    cin >> n;
    cout << endl;

    //float A[n], B[n], C[n];
    // Note: I first tried with static allocation, but it gives runtime errors when n > 100_000.
    float *A, *B, *C;
    A = new float[n];
    B = new float[n];
    C = new float[n];

    for (i=0;i<n;++i){
        A[i] = (float)rand() / (float)rand();
        B[i] = (float)rand() / (float)rand();
    }

    /* Debug *
    cout << fixed << setprecision(5);

    cout << "A[" << n << "]:";
    for (i=0;i<n;++i){
        cout << " " << A[i];
    }
    cout << endl << endl;

    cout << "B[" << n << "]:";
    for (i=0;i<n;++i){
        cout << " " << B[i];
    }
    cout << endl << endl;
    /**/

    cout << "For loop start" << endl;
    auto start_time = chrono::high_resolution_clock::now();

    for (i=0;i<n;++i){
        C[i] = A[i] + B[i];
        //for (int j=0;j<1000;++j); // Make execution time longer, for debug purposes
    }

    auto end_time = chrono::high_resolution_clock::now();
    cout << "For loop end" << endl << endl;

    /* Debug *
    cout << "C[" << n << "]:";
    for (i=0;i<n;++i){
        cout << " " << C[i];
    }
    cout << endl << endl;
    /**/

    delete[] A;
    delete[] B;
    delete[] C;

    auto difference_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    float execution_time = difference_time.count() * 1e-6;
    cout << fixed << setprecision(6);
    cout << "Execution time: " << execution_time << " s" << endl;

    return;
}

void matrix_copy()
{
    int i, j, ib, jb;
    int n, b, a;
    cout << "Size of the matrix n: ";
    cin >> n;
    cout << "Size of the block b: ";
    cin >> b;

    if (b > n){
        cout << "Error, b > n." << endl;
        return;
    } else if ((n%b) != 0){
        cout << "Error, n not divisible by b." << endl;
        return;
    } else {
        a = n / b; // Matrix M is decomposed in a by a blocks, each one of size b by b
        // So, a can be viewed as the row/column size in term of blocks
        cout << "Hence, a = " << a << endl << endl;
    }

    float **M, **O;
    M = new float*[n];
    for (i=0;i<n;++i){
        M[i] = new float[n];
    }
    O = new float*[n];
    for (i=0;i<n;++i){
        O[i] = new float[n];
    }

    for (i=0;i<n;++i){
        for (j=0;j<n;++j){
            M[i][j] = (float)rand() / (float)rand();
        }
    }

    /* Debug *
    cout << fixed << setprecision(5);

    cout << "Initial matrix M:" << endl;
    for (i=0;i<n;++i){
        for (j=0;j<n;++j){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    /**/

    cout << "For loop start" << endl;
    auto start_time = chrono::high_resolution_clock::now();

    /* Debug *
    for (i=0;i<a;++i){ // for each block
        for (j=0;j<a;++j){
            cout << "Block i=" << i << " j=" << j << ":" << endl;
            for (ib=0;ib<b;++ib){ // for each element of the block
                for (jb=0;jb<b;++jb){
                    cout << M[i*b+ib][j*b+jb] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    /**/

    for (i=0;i<a;++i){ // for each block
        for (j=0;j<a;++j){
            for (ib=0;ib<b;++ib){ // for each element of the block
                for (jb=0;jb<b;++jb){
                    O[(a-1-i)*b+ib][(a-1-j)*b+jb] = M[i*b+ib][j*b+jb];
                }
            }
        }
    }

    auto end_time = chrono::high_resolution_clock::now();
    cout << "For loop end" << endl << endl;

    /* Debug *
    cout << "Reverse matrix O:" << endl;
    for (i=0;i<n;++i){
        for (j=0;j<n;++j){
            cout << O[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    /**/

    for (i=0;i<n;++i){
        delete[] M[i];
    }
    delete[] M;
    for (i=0;i<n;++i){
        delete[] O[i];
    }
    delete[] O;

    auto difference_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    float execution_time = difference_time.count() * 1e-6;
    cout << fixed << setprecision(6);
    cout << "Execution time: " << execution_time << " s" << endl;

    return;
}
