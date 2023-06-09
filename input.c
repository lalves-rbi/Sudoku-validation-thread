#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define GRID_LINES 100
#define MAX_INPUT 10
#define MAX_LENGTH 1001000

FILE *openFile(char *filename)
{
    FILE *file_ptr;
    file_ptr = fopen(filename, "r");
    if (file_ptr == NULL)
    {
        printf("Error to read file\n");
        exit(1);
    }

    return file_ptr;
}

int getGridLength(char *filename)
{
    FILE *file_ptr = openFile(filename);
    char inputfile_first_line[MAX_INPUT];
    fscanf(file_ptr, "%9s", inputfile_first_line);
    int n = 0;
    int n1 = 0;
    sscanf(inputfile_first_line, "%dx%d", &n, &n1);
    if (n == 0)
    {
        printf("File out of format\n");
        exit(1);
    }
    if (n == n1)
    {
        return n;
    }
    else
    {
        printf("File out of format\n");
        exit(1);
    }
}

void getSubgridLength(char *filename, int n)
{
    FILE *file_ptr = openFile(filename);

    char inputfile_second_line[MAX_INPUT];
    fscanf(file_ptr, "%9s", inputfile_second_line);
    fscanf(file_ptr, "%9s", inputfile_second_line);
    int a = 0;
    int b = 0;
    sscanf(inputfile_second_line, "%dx%d", &a, &b);
    if (a * b == n)
    {
        subgrid_row = a;
        subgrid_column = b;
    }
    else
    {
        printf("File out of format\n");
        exit(1);
    }
}

int **getSudoku(char *filename)
{
    FILE *file_ptr = openFile(filename);

    // Read and discard the first two lines
    char buffer[GRID_LINES];
    fgets(buffer, GRID_LINES, file_ptr);
    fgets(buffer, GRID_LINES, file_ptr);

    int n = getGridLength(filename);
    int **grid = (int **)malloc(n * sizeof(int *));
    char temp_grid[MAX_LENGTH];
    int i = 0;
    while (fgets(temp_grid, MAX_LENGTH, file_ptr) != NULL)
    {
        grid[i] = (int *)malloc(n * sizeof(int));
        int j = 0;
        char *c;

        c = strtok(temp_grid, " ");
        while (c != NULL && j < n)
        {
            int k = atoi(c);
            if (k > n || k == 0)
            {
                printf("File out of format");
                exit(1);
            }
            grid[i][j] = k;
            c = strtok(NULL, " ");
            j++;
            if (j == n && c != NULL)
            {
                printf("File out of format");
                exit(1);
            }
        }
        i++;
    }
    for (int k = 0; k < i; k++)
    {
        for (int z = 0; z < i; z++)
        {
            if (z < i - 1 && grid[k][z] != 0 && grid[k][z + 1] != 0)
            {
                printf("File out of format");
                exit(1);
            }
        }
    }
    if (i != n)
    {
        printf("File out of format");
        exit(1);
    }
    return grid;
}
