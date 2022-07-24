//
// Created by yixin on 23/07/22.
//
#include <fstream>
#include <vector>
#include <queue>
#include <map>

#ifndef LEETCODE64_MINIMUM_PATH_SUM_DIJKSTRA_H
#define LEETCODE64_MINIMUM_PATH_SUM_DIJKSTRA_H

using namespace std;

class node {
public:
    int x;
    int y;
    int pathLength;
    node(int, int, int);

    bool operator<(const node& n) const;
    bool operator>(const node& n) const;
    bool operator==(const node& n) const;

};

class nodeQueue {
public:
    nodeQueue();
    ~nodeQueue();
    void push(node &newNode);
    node top();
    void pop();
    bool empty();
    void printQueue();

    vector<node> nodeContainer;
};

class dijkstra {
public:
    dijkstra();
    ~dijkstra();

    int minPathSum(vector<vector<int>> grid);
private:
    fstream logFile;
    void writeLog(int step, int x, int y, int pathLength, const nodeQueue& que);
};


#endif //LEETCODE64_MINIMUM_PATH_SUM_DIJKSTRA_H
