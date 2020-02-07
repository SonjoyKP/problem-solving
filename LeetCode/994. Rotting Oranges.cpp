#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int freshOrrangeCnt;
    int row;
    int col;

    int UpdateFreshOrangeCnt(vector<vector<int> > &grid)
    {
        freshOrrangeCnt = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
				printf("%d ", grid[i][j]);
                if (grid[i][j] == 1)
                    freshOrrangeCnt++;
            }
        }
        return freshOrrangeCnt;
    }

    int UpdateNewRotted(vector<vector<int> > &grid)
    {
        int newRotted = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == -2)
                {
                    grid[i][j] = 2;
                    newRotted++;
                    freshOrrangeCnt--;
                }
            }
        }
        return newRotted;
    }

    int orangesRotting(vector<vector<int> > &grid)
    {
        row = grid.size();
        col = grid[0].size();
        UpdateFreshOrangeCnt(grid);
        if (freshOrrangeCnt == 0)
            return 0;

        int minutes = 0;

        while (true)
        {
            int LastCount = freshOrrangeCnt;
			printf("LastCount= %d", LastCount);
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (grid[i][j] == 2)
                    {
                            int dirArrayX[] = {1, -1, 0, 0};
                            int dirArrayY[] = {0, 0, 1, -1};
                        for (int iDir = 0; iDir < 4; iDir++)
                        {
                            int dirIndexX = i + dirArrayX[iDir];
                            int dirIndexY = j + dirArrayY[iDir];
                            if (dirIndexX < row && dirIndexY < col && grid[dirIndexX][dirIndexY] == 1)
                            {
                                grid[dirIndexX][dirIndexY] = -2;
                            }
                        }
                    }
                }
            }
            int newRotted = UpdateNewRotted(grid);
            if (newRotted == 0)
            {
                return -1;
            }
            else if (newRotted > 0)
            {
                minutes++;
            }

            if (freshOrrangeCnt == 0)
            {
                return minutes;
            }
        }
    }
};

/* Driver program to check above functions */
int main()
{
	vector<int> a,b,c;
	a.push_back(2);
	a.push_back(1);
	a.push_back(1);
	b.push_back(1);
	b.push_back(1);
	b.push_back(0);
	c.push_back(0);
	c.push_back(1);
	c.push_back(1);
	// Let us search 3 in below array
	vector<vector<int> > grid;
	grid.push_back(a);
	grid.push_back(b);
	grid.push_back(c);

	Solution vSolution;

	// Function calling
	cout << "\nMinimum number of minutes : " << vSolution.orangesRotting(grid) << endl;

	return 0;
}