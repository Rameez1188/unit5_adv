#include <iostream>
#include <vector>

using namespace std;

pair<vector<vector<int>>, string> longestCommonSubstring(const string& str1, const string& str2) {
    int len_str1 = str1.length();
    int len_str2 = str2.length();

    // Initialize a 2D table to store the lengths of common substrings
    vector<vector<int>> lookupTable(len_str1 + 1, vector<int>(len_str2 + 1, 0));

    // Variables to keep track of the maximum length and its ending position
    int max_length = 0;
    int end_position = 0;

    // Populate the table and find the maximum length and its ending position
    for (int i = 1; i <= len_str1; ++i) {
        for (int j = 1; j <= len_str2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                lookupTable[i][j] = lookupTable[i - 1][j - 1] + 1;
                if (lookupTable[i][j] > max_length) {
                    max_length = lookupTable[i][j];
                    end_position = i - 1;  // or j - 1, as they are equal in this case
                }
            } else {
                lookupTable[i][j] = 0;
            }
        }
    }

    // Retrieve the common substring based on the ending position and length
    string common_substring = str1.substr(end_position - max_length + 1, max_length);

    return {lookupTable, common_substring};
}

int main() {
    // Input two strings
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    // Find the longest common substring
    auto result = longestCommonSubstring(str1, str2);
    vector<vector<int>> lookupTable = result.first;
    string lcs = result.second;

    // Print lookup table
    for (const auto& row : lookupTable) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    // Print one of the longest common substrings
    cout << "Longest Common Substring: " << lcs << endl;

    return 0;
}
