#include "input.c"
#include "out.c"
#include "processing.c"

FILE *openFile(char *filename);
int getGridLength(char *filename);
int getSubgridLength(char *filename, int n);
int **getSudoku(char *filename);

void *verifyRows(void *arg);
void *verifyColumns(void *arg);
void *verifySubgrid(void *arg);
int verifyVeracity(int subgrid_length, int grid_length, int **grid);

void create_output_file(int message);