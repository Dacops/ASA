#include <iostream>
#include <vector>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"


using namespace std;

int _lines, _columns;
vector<int> _linesValues;
vector<vector<int>> _freeSpaces;


void readInput() {
    cin >> _lines; cin >> _columns;         // read number of lines and columns.
    _linesValues.resize(_lines*sizeof(int));// create vector that saves width of each line.
    for (int i=0; i<_lines; i++) {
        cin >> _linesValues[i];
    }


    _freeSpaces.resize(_lines*sizeof(int)); // create matrix to save free spaces on the board.
    for (int i=0; i<_lines; i++) {
        _freeSpaces[i].resize(_columns*sizeof(int));
        for (int j=_columns; j>=_linesValues[i]; j--) { _freeSpaces[i][j]=1; }
    }
}

void showFreeSpaces() {
    for (int i=0; i<_lines; i++) {
        for (int j=0; j<_columns; j++) {
            if (_freeSpaces[i][j]) { printf(ANSI_COLOR_GREEN); cout << "0 "; }
            else { printf(ANSI_COLOR_RED); cout << "0 "; }
            printf(ANSI_COLOR_RESET);
        }
        cout << endl;
    }
    cout << endl;
}

void addSquare(int line, int size) {
    int column=0;

    while (_freeSpaces[line][column]) { column++; }
    printf("Adding square on position (%d, %d) of size %dx%d\n", line, column, size, size);

    for (int i=line; i<line+size; i++) {
        for (int j=column; j<column+size; j++) {
            _freeSpaces[i][j]=1;
            _linesValues[i]--;
        }
    }

    showFreeSpaces();
    cout << "-----------------------------\n" << endl;
}

int isFree(int size) {
    for (int i=0; i<=_lines-size; i++) {

        int _freeSpace = _linesValues[i];
        if (_freeSpace>=size) {
            for (int j = i; j < (size + i - 1); j++) {
                _freeSpace = min(_freeSpace, _linesValues[j + 1]);
            }

            if (_freeSpace >= size) {
                addSquare(i, size);
                return 1;
            }
        }
    }
    return 0;
}

void getSolution() {
    for (int n=_lines; n>0; n--) {           // is it possible to insert a square
        if (isFree(n)) n++;             // with nxn size?
    }
}

int main() {
    readInput();
    showFreeSpaces();
    getSolution();
    return 0;
}