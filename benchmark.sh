./array_addition_autovectorized.exe
mv report_array_addition.csv report_array_addition_autovectorized.csv
./array_addition.exe
./array_addition_AVX.exe

./matrix_copy_autovectorized.exe
./matrix_copy_prefetch_autovectorized.exe
mv report_matrix_copy.csv report_matrix_copy_autovectorized.csv
mv report_matrix_copy_prefetch.csv report_matrix_copy_prefetch_autovectorized.csv
./matrix_copy.exe
./matrix_copy_prefetch.exe
./matrix_copy_prefetch_reversed.exe
