#include <iostream>
#include <vector>

using namespace std;

int _lines, _columns;
vector<int> _linesValues;

void readInput() {
    cin >> _lines; cin >> _columns;
    _linesValues.resize(_lines);

    for (int i=0; i<_lines; i++) cin >> _linesValues[i];
}

int evaluateInput() {
    int _totalBigSquares=0;

    for (int i=0; i<_lines-1; i++) {
        int _bigSquares = min(_linesValues[i], _linesValues[i+1]);
        _totalBigSquares += (_bigSquares!=0) ? _bigSquares-1 : 0;
    }

    // +1, all small squares;
    return _totalBigSquares + 1;
}

int main() {
    readInput();
    cout << evaluateInput() << endl;

    return 0;
}