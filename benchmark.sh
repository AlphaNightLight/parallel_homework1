./array_addition_autovectorized.exe
mv report_array_addition.txt report_array_addition_autovectorized.txt
./array_addition.exe
./array_addition_AVX.exe

./matrix_copy_autovectorized.exe
./matrix_copy_prefetch_autovectorized.exe
mv report_matrix_copy.txt report_matrix_copy_autovectorized.txt
mv report_matrix_copy_prefetch.txt report_matrix_copy_prefetch_autovectorized.txt
./matrix_copy.exe
./matrix_copy_prefetch.exe
./matrix_copy_prefetch_reversed.exe
