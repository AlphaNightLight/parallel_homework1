#include <iostream>
#include <fstream>
#include <iomanip>

#include <stdlib.h>
#include <time.h>

#include <chrono>

#define MIN_SIZE 4
#define MAX_SIZE 22
// They mean n can vary from 2^MIN_SIZE to 2^MAX_SIZE

using namespace std;

float array_addition(int);
float routine1(float*, float*, float*, int);

int main()
{
	srand(time(NULL));
	ofstream report_file("report_array_addition_routine1.txt");
	
	int i;
	int n = 1; // 2^0
	for (i=0;i<MIN_SIZE-1;++i) n *= 2;

	report_file << fixed << setprecision(6);
	for (i=MIN_SIZE;i<=MAX_SIZE;++i){
		n *= 2;
		report_file << "size: " << setw(7) << n << ", time: " << array_addition(n) << " s" << endl;
	}

	report_file.close();
	return 0;
}

float array_addition(int n)
{
	int i;
	float execution_time;

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

	execution_time = routine1(A, B, C, n);

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

	/* Debug *
	cout << fixed << setprecision(6);
	cout << "Execution time: " << execution_time << " s" << endl;
	/**/

	return execution_time;
}

float routine1 (float* A, float* B, float* C, int n)
{
	int i;
	float execution_time;

	//cout << "For loop start" << endl; // Debug
	auto start_time = chrono::high_resolution_clock::now();

	for (i=0;i<n;++i){
		C[i] = A[i] + B[i];
	}

	auto end_time = chrono::high_resolution_clock::now();
	//cout << "For loop end" << endl << endl; // Debug

	auto difference_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
	execution_time = difference_time.count() * 1e-6;

	return execution_time;
}
