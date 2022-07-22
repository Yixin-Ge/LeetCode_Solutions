#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <unistd.h>
#include <vector>

#include "solution.h"

using namespace std;

int main() {
    // get current working directory
    char path[255];
    getcwd(path, 255);
//    std::cout << path << std::endl;

    // read input arguments from input.txt
    ifstream infile;
    infile.open("../Inputs/input.txt");
//    infile.open("/home/yixin/Softwares/CPP/LeetCode_76_Minimum_Window_Substring/input.txt");
    assert(infile.is_open());
    cout << "Read input.txt" << endl;

    int numArgs = 2;
    int numCases = 3;

    vector<string> inputs;
    vector<string> outputs;
    string s;

    while(infile >> s) {
        inputs.push_back(s);
    }

    infile.close();

    // test cases
    for(int caseNum = 0, inputNum = 0; caseNum < numCases; ++caseNum, inputNum += numArgs) {
        cout << "test case " << caseNum << endl;
        cout << "inputs: " << inputs[inputNum] << endl;

        Solution solution;
        string outputStr = solution.minWindow(inputs[inputNum], inputs[inputNum + 1]);
        cout << "outputs: " << outputStr << endl;
        cout << endl;
        outputs.push_back(outputStr);
    }

    // write result to output.txt
    ofstream outfile;
    outfile.open("../Outputs/output.txt");
    assert(outfile.is_open());
    cout << "Writing output.txt" << endl;
    for(string outStr: outputs) {
        outfile << '"' << outStr << '"' << endl;
    }
    cout << "Writing complete!" << endl;

    return 0;
}
