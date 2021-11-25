#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
        int numIslands(vector<vector<char> > &grid)
        {
            int result = 0; // number of island

            if(grid.size() == 0) return result;

            int numberOfRows = grid.size();
            int numberOfColumns = grid[0].size();

            vector<pair<int,int> > neighboorCoor = {{0,1},{1,0},{0,-1},{-1,0}};
            
            for(int i = 0; i < numberOfRows; i++)
            {
                for(int j = 0; j < numberOfColumns; j++)
                {
                    if(grid[i][j] == '1')
                    {
                        result++; //increment number of island
                        queue<pair<int,int> >que;
                        que.push({i,j});
                        grid[i][j] = '0';

                        while(!que.empty())
                        {
                            auto p = que.front();
                            que.pop();
                            //Check the neighboorhood cordinates
                            for(unsigned int k = 0; k < neighboorCoor.size(); k++)
                            {
                                
                                int x = p.first + neighboorCoor[k].first;
                                int y = p.second + neighboorCoor[k].second;
                                // We check the boundary conditions
                                if(x >= 0 && x < numberOfRows && y >= 0 && y < numberOfColumns)
                                {
                                    if(grid[x][y] == '1')
                                    {
                                        grid[x][y] = '0';
                                        que.push({x,y});
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return result;
        }
};


int main()
{
    vector<vector<char> > grid = {
         {'1','1','1','1','0'},
         {'1','1','0','1','0'},
         {'1','1','0','0','0'},
         {'0','0','0','0','0'}
    
    };
    Solution s;
    cout<<s.numIslands(grid)<<endl;

    return 0;
}