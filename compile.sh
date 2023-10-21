g++ -o array_addition array_addition.cpp
g++ -O3 -mavx -o array_addition_autovectorized array_addition.cpp
g++ -mavx -o array_addition_AVX array_addition_AVX.cpp

g++ -o matrix_copy matrix_copy.cpp
g++ -o matrix_copy_prefetch matrix_copy_prefetch.cpp
g++ -o matrix_copy_prefetch_reversed matrix_copy_prefetch_reversed.cpp

g++ -O3 -mavx -o matrix_copy_autovectorized matrix_copy.cpp
g++ -O3 -mavx -o matrix_copy_prefetch_autovectorized matrix_copy_prefetch.cpp
