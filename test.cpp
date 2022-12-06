#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

int combinations = 0;
vector<int> _linesValues;

void readInput() {
    int lines, columns;                         // read number of lines and columns;
    cin >> lines;
    cin >> columns;
    _linesValues.resize(lines);                 // create vector that saves width of each line.
    for (int i = 0; i < lines; i++) {
        cin >> _linesValues[i];
    }
}

int freeSpace(int size, vector<int> values) {

    int index = 0;
    for(int i=0; i<=(int)values.size()-size; i++) {

        int space = values[i];
        for(int n=1; n<size; n++) {
            space = min(space, values[i+n]);
        }

        if(space>=size) { index=i; break; }
    }
    return index;
}

void getCombinations(vector<int> values) {

    // vector to be transformed by this iteration.
    vector<int> newValues;

    // size of inputted vector.
    int size = (int)values.size();

    // Get number of lines with 1 or less free spots (can be removed).
    int remove = 0;
    for(int i=0; i<size; i++) { if(values[i]<=1) remove++; }
    newValues.resize(size-remove);

    // size of vector created by this iteration.
    int newSize = (int)newValues.size();

    // Remove lines with 1 or less free spots (creates new vector).
    for(int i=0, j=0; i<size; i++) { if(values[i]>1) { newValues[j]=values[i]; j++; } }

    // If only one line as free spots there's only 1 possible combination (all 1x1).
    if(newSize<=1) { combinations++; return;}

    // Implement dynamic coding. Check if inputted vector was already calculatted.

    // Check if Squares of nxn size can fit in the free spots.
    for(int n=newSize; n>0; n--) {

        // 1st line where a square can be placed.
        int pos = freeSpace(n, newValues);

        // new vector needs to be created, so it can be edited, newValues is being used by all instances created
        // in this generation.
        vector<int> newerValues;
        newerValues.resize(newSize);
        for(int j=0; j<newSize; j++) { newerValues[j]=newValues[j]; }

        // k equals line to place the square, i equals offset, j equals remaining lines for example a 2x2 square
        // takes spots in 2 lines.
        for(int j=0; j<n; j++) { newerValues[j+pos]=newerValues[j+pos]-n; }

        getCombinations(newerValues);
    }
}


int main() {
    readInput();
    getCombinations(_linesValues);
    cout << combinations << endl;

    return 0;
}