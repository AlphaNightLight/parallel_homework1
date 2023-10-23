#include <iostream>
#include <fstream>
#include <iomanip>

#include <stdlib.h>
#include <time.h>

#include <chrono>

#define N_TRIALS 4
// To reduce spikes, each b will be retested N_TRIALS times, and an averege will be performed

#define SIZE 12
// It means n = 2^SIZE

#define MIN_BLOCK 2
#define MAX_BLOCK 8
// They mean b can vary from 2^MIN_BLOCK to 2^MAX_BLOCK

using namespace std;

float matrix_copy(int, int);
float routine2(float**, float**, int, int);

int main()
{
	srand(time(NULL));
	ofstream report_file("report_matrix_copy_prefetch.csv");
	float execution_time;

	int i, j;
	int n = 1; // 2^0
	for (i=0;i<SIZE;++i) n *= 2;

	int b = 1;
	for (i=0;i<MIN_BLOCK-1;++i) b *= 2;

	report_file << fixed << setprecision(6);
	report_file << "size,block,time" << endl;
	for (i=MIN_BLOCK;i<=MAX_BLOCK;++i){
		b *= 2;
		execution_time = 0;
		for (j=0;j<N_TRIALS;++j) execution_time += matrix_copy(n, b) * (1.0 / N_TRIALS);
		//report_file << "size: " << n << ", block: " << setw(3) << b << ", time: " << execution_time << " s" << endl;
		report_file << n << "," << b << "," << execution_time << endl;
	}

	report_file.close();
	return 0;
}

float matrix_copy(int n, int b)
{
	int i, j;
	float execution_time;

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

	execution_time = routine2(M, O, n, b);

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

	/* Debug *
	cout << fixed << setprecision(6);
	cout << "Execution time: " << execution_time << " s" << endl;
	/**/

	return execution_time;
}

float routine2(float** M, float** O, int n, int b)
{
	int i, j, ib, jb;
	float execution_time;
	int a = n / b;

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

	//cout << "For loop start" << endl; // Debug
	auto start_time = chrono::high_resolution_clock::now();

	for (i=0;i<a;++i){ // for each row
		for (ib=0;ib<b;++ib){
			for (j=0;j<a;++j){ // for each element of the row
				for (jb=0;jb<b;++jb){
					O[(a-1-i)*b+ib][(a-1-j)*b+jb] = M[i*b+ib][j*b+jb];
				}
			}
		}
	}

	auto end_time = chrono::high_resolution_clock::now();
	//cout << "For loop end" << endl << endl; // Debug

	auto difference_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
	execution_time = difference_time.count() * 1e-6;
	
	return execution_time;
}
