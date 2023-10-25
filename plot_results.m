report_array_addition = dlmread('report_array_addition.csv', ',', 1, 0);
report_array_addition_autovectorized =...
dlmread('report_array_addition_autovectorized.csv', ',', 1, 0);
report_array_addition_AVX =...
dlmread('report_array_addition_AVX.csv', ',', 1, 0);

report_matrix_copy = dlmread('report_matrix_copy.csv', ',', 1, 0);
report_matrix_copy_autovectorized =...
dlmread('report_matrix_copy_autovectorized.csv', ',', 1, 0);
report_matrix_copy_prefetch =...
dlmread('report_matrix_copy_prefetch.csv', ',', 1, 0);
report_matrix_copy_prefetch_autovectorized =...
dlmread('report_matrix_copy_prefetch_autovectorized.csv', ',', 1, 0);
report_matrix_copy_prefetch_reversed =...
dlmread('report_matrix_copy_prefetch_reversed.csv', ',', 1, 0);

#array_addition_size = report_array_addition(:,1);
array_addition_time = [report_array_addition(:,2),...
report_array_addition_autovectorized(:,2),report_array_addition_AVX(:,2)];

matrix_copy_block = report_matrix_copy(:,2);
matrix_copy_time = [report_matrix_copy(:,3),...
report_matrix_copy_autovectorized(:,3), report_matrix_copy_prefetch(:,3),...
report_matrix_copy_prefetch_autovectorized(:,3),...
report_matrix_copy_prefetch_reversed(:,3)];

# plot_array_addition

set(0, 'defaulttextfontsize', 15);
set(0, 'defaultaxesfontsize', 12);
plot(4:22,array_addition_time,...
'linewidth',2,'marker','.','markersize',30);

xticks(4:22);
xticklabels(4:22);
yticks(0:0.001:0.05);
yticklabels(0:0.001:0.05);
grid on;
set(gca,'XMinorTick','Off');
set (gca, 'xminorgrid', 'off');
set(gca,'YMinorTick','Off');
set (gca, 'yminorgrid', 'off');

title('Array Addition');
ylabel('time [s]');
xlabel('size [log_2n]');
legend('Sequential', 'Autovectorized', 'AVX', 'location', 'northwest');
print('plot_array_addition.png','-dpng');

### plot_log_array_addition

for (i = 4:22)
  for (j = 1:3)
    if (array_addition_time(i-3,j) == 0.0)
      array_addition_time(i-3,j) = 1e-6;
    endif
  endfor
endfor

semilogy(4:22,array_addition_time,...
'linewidth',2,'marker','.','markersize',30);

xticks(4:22);
xticklabels(4:22);
grid on;
set(gca,'XMinorTick','Off');
set (gca, 'xminorgrid', 'off');

title('Array Addition');
ylabel('time [s]');
xlabel('size [log_2n]');
legend('Sequential', 'Autovectorized', 'AVX', 'location', 'northwest');
print('plot_log_array_addition.png','-dpng');

### plot_matrix_copy_wrong_cached

semilogx(matrix_copy_block,matrix_copy_time,...
'linewidth',2,'marker','.','markersize',30);

xticks(matrix_copy_block);
xticklabels(matrix_copy_block);
yticks(0:0.1:1);
yticklabels(0:0.1:1);
grid on;
set(gca,'XMinorTick','Off');
set (gca, 'xminorgrid', 'off');
set(gca,'YMinorTick','Off');
set (gca, 'yminorgrid', 'off');

title('Matrix Copy');
ylabel('time [s]');
xlabel('size [b]');
legend('Sequential', 'Autovectorized', 'Prefetch',...
'Prefetch Autovectorized', 'Wrong Caching', 'location', 'west');
print('plot_matrix_copy_wrong_cached.png','-dpng');

# plot_matrix_copy

matrix_copy_time = matrix_copy_time(:,1:4);
semilogx(matrix_copy_block,matrix_copy_time,...
'linewidth',2,'marker','.','markersize',30);

xticks(matrix_copy_block);
xticklabels(matrix_copy_block);
yticks(0:0.02:0.4);
yticklabels(0:0.02:0.4);
grid on;
set(gca,'XMinorTick','Off');
set (gca, 'xminorgrid', 'off');
set(gca,'YMinorTick','Off');
set (gca, 'yminorgrid', 'off');

title('Matrix Copy');
ylabel('time [s]');
xlabel('size [b]');
legend('Sequential', 'Autovectorized', 'Prefetch',...
'Prefetch Autovectorized', 'location', 'west');
print('plot_matrix_copy.png','-dpng');
