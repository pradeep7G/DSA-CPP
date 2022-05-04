#include <bits/stdc++.h>
using namespace std;
bool isValidSudoku(vector<vector<int> > &sudoku)
{
  //Time O(n^2) + O(n^2) + O(n* sqrt n * sqrt n) ~= O (n^2); Space O(n) size of the sudoku i.e bit array
  //check row constraints
  for (int i = 0; i < sudoku.size(); i++)
  {
    if (HasDuplicate(sudoku, i, i + 1, 0, sudoku.size()))
    {
      return false;
    }
  }

  //column constraints
  for (int i = 0; i < sudoku.size(); i++)
  {
    if (HasDuplicate(sudoku, 0, sudoku.size(), i, i + 1))
    {
      return false;
    }
  }

  //check sqrt n * sqrt n region contraints
  int regionSize = sqrt(sudoku.size());
  for (int i = 0; i < regionSize; i++)
  {
    for (int j = 0; j < regionSize; j++)
    {
      if (HasDuplicate(sudoku, regionSize * i, regionSize * (i + 1), regionSize * j, regionSize * (j + 1)))
      {
        return false;
      }
    }
  }
}
bool HasDuplicate(vector<vector<int> > &sudoku, int rowStart, int rowEnd, int columnStart, int columnEnd)
{
  deque<bool> isPresent(sudoku.size() + 1, false);
  for (int i = rowStart; i < rowEnd; i++)
  {
    for (int j = columnStart; j < columnEnd; j++)
    {
      if (sudoku[i][j] != 0 && isPresent[sudoku[i][j]])
      {
        return true;
      }
      isPresent[sudoku[i][j]] = true;
    }
  }
  return false;
}
int main()
{
}