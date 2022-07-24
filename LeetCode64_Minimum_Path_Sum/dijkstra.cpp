//
// Created by yixin on 23/07/22.
//

#include <iostream>
#include "dijkstra.h"
#include <queue>
#include <cassert>
#include <map>
#include <algorithm>

using namespace std;

node::node(int x, int y, int pathLength) : x(x), y(y), pathLength(pathLength) {
}

bool node::operator<(const node& n) const {
    return pathLength < n.pathLength;
}

bool node::operator>(const node& n) const {
    return pathLength > n.pathLength;
}

bool node::operator==(const node &n) const{
    return n.x == x && n.y == y;
}

nodeQueue::nodeQueue()= default;

nodeQueue::~nodeQueue() = default;

void nodeQueue::push(node &newNode){
    for(auto it = nodeContainer.begin(); it != nodeContainer.end(); ++it) {
        if (*it == newNode) {
            if (it->pathLength > newNode.pathLength) {
                nodeContainer.erase(it);
                nodeContainer.emplace_back(newNode);
                sort(nodeContainer.begin(), nodeContainer.end());
            }
            return;
        }
    }
    nodeContainer.emplace_back(newNode);
    sort(nodeContainer.begin(), nodeContainer.end());
}

node nodeQueue::top(){
    return *(nodeContainer.begin());
}

void nodeQueue::pop(){
    if(!nodeContainer.empty()) {
        nodeContainer.erase(nodeContainer.begin());
    }
}

bool nodeQueue::empty(){
    return nodeContainer.empty();
}

void nodeQueue::printQueue() {
    cout << "nodeQueue: " << endl;
    for(auto e: nodeContainer) {
        cout << "x=" << e.x << ", y=" << e.y << ", pathLength=" << e.pathLength << endl;
    }
}

dijkstra::dijkstra() {
    logFile.open("../Outputs/log.txt");
    assert(logFile.is_open());
}

dijkstra::~dijkstra() {
    logFile.close();
}

int dijkstra::minPathSum(vector<vector<int>> grid) {
    nodeQueue que;
    int m = grid.size();
    int n = grid[0].size();

    node myNode(0,0,grid[0][0]);

    que.push(myNode);

    int step = 1;

    while(!que.empty()) {
        node curNode = que.top();
        que.pop();

        // goal checking
        if(curNode.x == m - 1 && curNode.y == n - 1) {
            writeLog(step++, curNode.x, curNode.y, curNode.pathLength, que);
            return curNode.pathLength;
        }

        // explore node on the bottom
        if(curNode.x < m - 1) {
            node newNode(curNode.x + 1, curNode.y, curNode.pathLength + grid[curNode.x + 1][curNode.y]);
            que.push(newNode);
        }

        // explore node on the right
        if(curNode.y < n - 1) {
            node newNode(curNode.x, curNode.y + 1, curNode.pathLength + grid[curNode.x][curNode.y + 1]);
            que.push(newNode);
        }

        writeLog(step++, curNode.x, curNode.y, curNode.pathLength, que);
    }

    return 0;
}

void dijkstra::writeLog(int step, int x, int y, int pathLength, const nodeQueue& que) {
    logFile << "Step: " << step << ", x=" << x << ", y=" << y << ", pathLength=" << pathLength ;
    logFile << ", NodeQueue: ";
    for(auto e: que.nodeContainer) {
        logFile << "(" << e.x << ", " << e.y << ", " << e.pathLength << ") ";
    }
    logFile << endl;
}