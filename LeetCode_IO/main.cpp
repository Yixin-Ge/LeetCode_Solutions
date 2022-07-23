#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void cin_single_variable() {
    cout << "Enter an int variable t:" << endl;
    int t;
    cin >> t;
    cout << "t = " << t << endl;
}

void cin_single_string() {
    cout << "Enter a string s:" << endl;
    string s;
    getline(cin, s);
    cout << "s = " << s << endl;
}

void enter_1D_array_with_length() {
    cout << "Enter a 1-D array nums, given length n:" << endl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    for(auto num: nums) {
        cout << num << " ";
    }
    cout << endl;
}

void enter_1D_array() {
    cout << "Enter a 1-D array nums2:" << endl;
    vector<int> nums2;
    int val;
    while(cin >> val) {
        nums2.push_back(val);
        if(getchar() == '\n') break;
    }

    for(auto num: nums2) {
        cout << num << " ";
    }
    cout << endl;
}

void enter_1D_array_with_delimiter() {
    cout << "Enter a 1-D array of strings with delimiter ',':" << endl;
    string input;
    getline(cin, input);
    vector<string> strs;
    string s3;

    stringstream ss(input);

    while(getline(ss, s3, ',')) {
        strs.push_back(s3);
    }

    for(const auto& str: strs) {
        cout << str << " ";
    }
    cout << endl;
}

void enter_2D_array_with_size_and_delimiter() {
    cout << "Enter a 2-D array with row size n, separated by symbol ',':" << endl;
    int n, m;
    cin >> n >> m;
    string s4;
    stringstream ss;
    // we need to change line here!
    getline(cin, s4);
    vector<vector<int>> nums5(n, vector<int>(m));

    for(int i = 0; i < n; ++i) {
        getline(cin, s4);
        replace(s4.begin(), s4.end(), ',', ' ');

        ss.clear();
        ss.str(s4);
        int tmp;
        for(int j = 0; j < m; ++j) {
            ss >> tmp;
            nums5[i][j] = tmp;
        }
    }

    for(auto row: nums5) {
        for(int element: row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
//    // Enter a variable
//    cin_single_variable();
//
//    // Enter a string
//    cin_single_string();
//
//    // Enter an 1-D array given length n
//    enter_1D_array_with_length();
//
//    // Enter an 1-D array for arbitrary n
//    enter_1D_array();
//
//    // Enter a 1-D array of strings with delimiter ','
//    enter_1D_array_with_delimiter();

    // Enter a 2-D array with row size n, separated by symbol ','
    enter_2D_array_with_size_and_delimiter();

    return 0;
}
