#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <chrono>

using namespace std;

int main()
{
    srand(time(NULL));

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

    /* Debug
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
    */

    cout << "For loop start" << endl;
    auto start_time = chrono::high_resolution_clock::now();

    for (i=0;i<n;++i){
        C[i] = A[i] + B[i];
        //for (int j=0;j<1000;++j); // Make execution time longer, for debug purposes
    }

    auto end_time = chrono::high_resolution_clock::now();
    cout << "For loop end" << endl;

    /* Debug
    cout << "C[" << n << "]:";
    for (i=0;i<n;++i){
        cout << " " << C[i];
    }
    cout << endl << endl;
    */

    delete[] A;
    delete[] B;
    delete[] C;

    auto difference_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    float execution_time = difference_time.count() * 1e-6;
    cout << fixed << setprecision(6);
    cout << "Execution time: " << execution_time << " s" << endl;

    return 0;
}
