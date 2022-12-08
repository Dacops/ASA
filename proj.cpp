#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

bool areAllZeros = true;
int combinations = 0;                      // total number of combinations.
vector<int> _linesValues;                   // vector to save free spaces per row;
vector<int> _occupiedColumns;               // vector to save occupied columns per row;
int lines, columns;
vector<vector<vector<int> > > paths;
int b = 0;

void readInput() {
    int input;                    // read number of lines and columns.
    cin >> lines;
    cin >> columns;                         // columns are not used but still need to be read.
    _linesValues.resize(lines);             // create vector that saves free spaces per row.
    _occupiedColumns.resize(lines);         // create vector that saves occupied columns per row.
    for (int i = 0; i < lines; i++) {
        cin >> input;
        if (input != 0)
            areAllZeros = false;
        _linesValues[i] = input;    
        _occupiedColumns[i] = 0;
    }
}

bool isOver(vector<int> values, vector<int> occupied) {

    for(int i = 0; i<values.size()-1; i++) {
        if(values[i] > 1) {
            if(i == 0)
                return false;   
            else {
                if((values[i-1] > 1 && occupied[i] < values[i-1]-1) || (values[i+1] > 1 && occupied[i] < values[i+1]+1))
                    return false;
            }
        }    
    }
    return true;
}

int freeSpace(int size, vector<int> values, vector<int> occupied) {

    int minimum = occupied[0];
    for(int i=0; i<(int)occupied.size(); i++) { if(occupied[i]<minimum) minimum=occupied[i]; }

    for(int i=0; i<=(int)values.size()-size; i++) {
        int space = (occupied[i]==minimum ? values[i] : 0);
        for(int n=1; n<size; n++) {
            if (occupied[i+n]!=minimum) { space=0; }    // 1st column of this row isn't free;
            space = min(space, values[i+n]);
        }
        if(space>=size) { return i; }
    }
    // error code no square of size "size" fits in this staircase.
    return -1;
}

void write_matrix(vector<int> arg, vector<int> arg1) {

    for(int l = 0; l<arg.size(); l++ ) {
        for(int j = 0; j<arg1[l];j++) {
            printf("x ");
        }
        for(int k =0; k<arg[l];k++) {
            printf("0 ");
        }
        for(int m =0; m<(columns-(arg[l]+arg1[l]));m++) {
            printf(". ");
        }
        printf("\n");
    }
    for(int b =0; b<(columns);b++) {
            printf("--");
        }
        printf("\n");
}

void getCombinations(vector<int> values, vector<int> occupied) {

    // vectors to be transformed by this iteration.
    vector<int> newValues;
    vector<int> newOccupied;

    // sizes of inputted vectors.
    int size = (int)values.size();
    newValues.resize(size);
    newOccupied.resize(size);

    // Remove lines with 1 or less free spots (creates new vectors).
    for(int i=0; i<size; i++) {
        if(values[i]>1) {
            newValues[i]=values[i];
            newOccupied[i]=occupied[i];
        }
        else {
            newValues[i]=0;
            newOccupied[i]=occupied[i]+1;
        }
    }

    // If only one line has free spots there's only 1 possible combination (all 1x1).
    if(isOver(newValues,newOccupied)) { combinations++; printf("----------------------ACABOU UM CAMINHO------------------------\n"); return; }

    // Implement dynamic coding. Check if inputted vector was already calculated.

    // Check if Squares of nxn size can fit in the free spots.
    for(int n=size; n>0; n--) {

        // 1st line where a square can be placed.
        int pos = freeSpace(n, newValues, newOccupied);

        // error code, no square of n size fits in the matrix.
        if(pos!=-1) {
            // new vectors need to be created, so they can be edited, newValues and newOccupied are being
            // used by all instances created in this generation.
            vector<int> newerValues;
            vector<int> newerOccupied;
            vector<vector<int> > path;
            newerValues.resize(size);
            newerOccupied.resize(size);
            for (int j = 0; j < size; j++) {
                newerValues[j] = newValues[j];
                newerOccupied[j] = newOccupied[j];
            }
            printf("takin out a %d by %d square\n",n,n);
            for (int j = 0; j < n; j++) {
                newerValues[j + pos] = newerValues[j + pos] - n;
                newerOccupied[j + pos] += n;
            }
            write_matrix(newerValues,newerOccupied);
            //for(int k = 0; k < newerValues.size();k++)
            //    printf("%d,",newerValues[k]);
            //printf("\n");
            getCombinations(newerValues, newerOccupied);
        }
    }
}


int main() {

    readInput();
    write_matrix(_linesValues,_occupiedColumns);
    if(areAllZeros) { cout << 0 << endl;
     return 0; }
    getCombinations(_linesValues, _occupiedColumns);
    cout << combinations << endl;

    return 0;
}