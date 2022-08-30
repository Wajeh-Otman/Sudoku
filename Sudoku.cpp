// Sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;


#define N 9


bool checkBox(int table[N][N], int& row, int& col, int& num)
{
    int RowStart = (row / 3)*3, colStart = (col / 3)*3;
    int RowEnd = (RowStart+1)*3, colEnd = (colStart + 1) * 3;
    for (int r = RowStart; r < RowEnd; r++)
    {
        for (int c = colStart; c < colEnd; c++)
        {
            if (table[RowStart][colStart]==num)
            {
                return false;
            }

        }
    }
    return true;
}


bool checkCol(int table[N][N], int& col, int& num)
{
    for (size_t i = 0; i < N; i++)
    {
        if (table[i][col] == num)
        {
            return false;
        }
    }
    return true;
}


bool checkRow(int table[N][N], int& row,int& num)
{
    for (size_t i = 0; i < N; i++)
    {
        if (table[row][i]==num)
        {
            return false;
        }
    }
    return true;
}


void printResult(int table[N][N])
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            cout << table[r][c] << " ";
            
        }
        cout << endl;
    }
}

bool EmptyLocation(int table[N][N], int& row, int& col)
{
    if (table[row][col] == 0)
    {
        return true;
    }
    return false;
}
bool EmptyTable(int table[N][N]) {
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            if (table[r][c]==0)
            {
                return true;
            }
        }    
    }
    return false;
}

void SolveSudoku(int table[N][N])
{
    int err = 0, row, col, num;
    
   
    while (err < 3 && EmptyTable(table))
    {
        printResult(table);
        cout << "Mistakes " << err << "/3" << endl;
        cout << "Enter row, col, number: ";
        cin >> row >> col >> num;
        row--;
        col--;


        if (EmptyLocation(table, row, col))
        {
            if (checkRow(table, row, num) && checkCol(table, col, num) && checkBox(table, row, col, num))
            {
                table[row][col] = num;
            }
            else
            {
                err++;
                cout << "ERROR!" << ", row or col or box contain " << num << endl;
            }
        }
        else
        {
            err++;
            cout << "ERROR!" << ", location not empty" << endl;
        }
 
    }
    if (err==3)
    {
        cout << "Mistakes " << err << "/3" << endl;
        cout << "Gmae Over!!" << endl;
    }
    else
        cout << "You win!!" << endl;

}

int main()
{
    int table[N][N] = { {8, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 3, 0, 8, 5},
                      {0, 0, 1, 0, 2, 0, 0, 0, 0},
                      {0, 0, 0, 5, 0, 7, 0, 0, 0},
                      {0, 0, 4, 0, 0, 0, 1, 0, 0},
                      {0, 9, 0, 0, 0, 0, 0, 0, 0},
                      {5, 0, 0, 0, 0, 0, 0, 7, 3},
                      {0, 0, 2, 0, 1, 0, 0, 0, 0},
                      {0, 0, 0, 0, 4, 0, 0, 0, 9} };
    
    SolveSudoku(table);
}


