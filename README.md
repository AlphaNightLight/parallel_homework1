# Parallel Computing Homework 1

## Files in this repository
In this repository you will find the following files:

- array_addition.cpp: the serial solution for the first problem. It can be compiled without flags or with flags to enable vectorization
- array_addition_AVX.cpp: a modified verson of array_addition.cpp that uses explicit AVX intrinsics to accomplish vectorization.
- matrix_copy.cpp: the serial solution for the second problem. As array_addition.cpp it can be compiled with or without flgs.
- matrix_copy_prefetch.cpp: solves the second problem with a better access pattern compared to matrix_copy.cpp, to better exploit the cache.
- matrix_copy_prefetch_reversed.cpp: solves the second problem, but with a bad access pattern. It's purpose is just for comparison.
- compile.sh: a bash script that compiles all the previous C++ sources, some of them are compiled multiple times with different flags.
- benchmark.sh: a bash script that executes all the C++ programs compiled before. Each program will produce a .csv file with its execution times.
- clean.sh: a bash script that cancel all the executable and .csv files generated by the previous scripts.
- plot_results.m: a GNU octave script that reads the .csv files to produces four plots of the data.
- alex_pegoraro_227642_homework_1.pdf: the report of the work. It also contains much more details about all the other fils.

## How to run the experiment

Run this experiment is very simple thanks to the scripts that automante most of the passages.

1. Run the script compile.sh, it will produce all the executable files you will nedd in the next steps.
2. Run the script benchmark.sh, it will execute all the programs causing the cretion of many .csv files. 
It will also change names to some of them, to avoid conflicts.
3. On a machine with installed GNU octave, you can run plot_results.m to create the plots. Alternativley, you can use any plot tool you want. In that
case read alex_pegoraro_227642_homework_1.pdf to understand the structure of the .csv files and be able to read them.
4. If you want to clean your workspace run clean.sh, it will delete all the executables and the .csv (but not the plots).

Note: this is the way to test all the programs one shot. If you want to benchmrk only a specific one, read alex_pegoraro_227642_homework_1.pdf to understand
the peculiarity and the logic of each program.
