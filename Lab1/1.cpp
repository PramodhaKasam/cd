#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    bool in_multiline_comment = false;

   
    ifstream infile("original.cpp"); 
    if (!infile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    
    ofstream outfile("cleaned.cpp");  
    if (!outfile) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    while (getline(infile, line)) {
        string result = "";
        size_t i = 0;

        while (i < line.length()) {
            if (!in_multiline_comment) {
                if (i + 1 < line.length() && line[i] == '/' && line[i + 1] == '/') {
                    break; 
                }
                else if (i + 1 < line.length() && line[i] == '/' && line[i + 1] == '*') {
                    in_multiline_comment = true;
                    i += 2;
                }
                else {
                    result += line[i++];
                }
            } else {
                if (i + 1 < line.length() && line[i] == '*' && line[i + 1] == '/') {
                    in_multiline_comment = false;
                    i += 2;
                } else {
                    i++;
                }
            }
        }

        if (!result.empty() && !in_multiline_comment)
            outfile << result << endl;
    }

    infile.close();
    outfile.close();

    cout << "Comments removed and written to cleaned.cpp" << endl;
    return 0;
}
