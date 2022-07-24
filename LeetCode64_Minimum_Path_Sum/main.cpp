#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>

#include "dijkstra.h"

using namespace std;

vector<vector<int>> read_input_from_file(string path, bool visualize) {
    int n,m;

    // read input arguments from input.txt
    ifstream infile;
    infile.open(path);
    assert(infile.is_open());

    string currentLine;
    stringstream ss;

    // read the first line
    getline(infile, currentLine);
    ss.clear();
    ss.str(currentLine);
    ss >> n >> m;


    // initialize grid
    vector<vector<int>> grid(n, vector<int>(m));

    // read grid values
    for(int i = 0; i < n; ++i) {
        getline(infile, currentLine);
//        cout << currentLine << endl;
        replace(currentLine.begin(), currentLine.end(), ',',' ');

        ss.clear();
        ss.str(currentLine);
        for(int j = 0; j < m; ++j) {
            ss >> grid[i][j];
        }
    }

    if(visualize) {
        cout << "n: " << n << "  m: " << m << endl;
        // output grid values
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    return grid;
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for(int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        int kMax = min(m, n);

        for(int k = 1; k < kMax; ++k) {
            for(int i = k; i < m; ++i) {
                dp[i][k] = min(dp[i - 1][k], dp[i][k - 1]) + grid[i][k];
            }
            for(int j = k + 1; j < n; ++j) {
                dp[k][j] = min(dp[k - 1][j], dp[k][j - 1]) + grid[k][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    int numArgs = 1;
    int numCases = 1;

    vector<vector<int>> grid = read_input_from_file("../Inputs/input.txt", false);

    dijkstra dijkstraSolver;
    int result = dijkstraSolver.minPathSum(grid);

//    Solution solver;
//    int result = solver.minPathSum(grid);

    cout << result << endl;

    return 0;
}
