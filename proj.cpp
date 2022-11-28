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

int evaluateInput(int n) {
    int _totalBigSquares=0;

    for (int i=0; i<=_lines-n; i++) {

        int _bigSquares = _linesValues[i];
        for (int j=i; j<(n+i-1); j++) {
            _bigSquares = min(_bigSquares, _linesValues[j + 1]);
        }

        _totalBigSquares += (_bigSquares >= n) ? 1+(_bigSquares-n) : 0;
    }

    return _totalBigSquares;
}

int main() {
    readInput();
    for (int i=_lines; i>0; i--) {
        cout << printf("%d %dx%d squares in this board.",evaluateInput(i),i,i) << endl;
    }

    return 0;
}