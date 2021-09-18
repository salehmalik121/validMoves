
#include <iostream>
using namespace std;
void table() {
    cout << "staring from edge values then block by block move to next edge once at edge enter value out of table " << endl;
    cout << " for eg: you start from (0,0) and move to (2,3) then enter (2,4)[value out of table] it will end and show" << endl;
    cout << "number of moves you made" <<endl;
    cout << " |   0,0    |   0,1     |     0,2    |    0,3    | " << endl;
    cout << "_|__________|___________|____________|___________|_" << endl;
    cout << " |   1,0    |   1,1     |     1,2    |    1,3    | " << endl;
    cout << "_|__________|___________|____________|___________|_" << endl;
    cout << " |   2,0    |   2,1     |     2,2    |    2,3    | " << endl;
    cout << "_|__________|___________|____________|___________|_" << endl;
    cout << " |   3,0    |   3,1     |     3,2    |    3,3    | " << endl;
    cout << "_|__________|___________|____________|___________|_" << endl;
    cout << " |          |           |            |           | " << endl;

}
bool check(int row, int col) {
    if (row == 0 || col == 0 || row == 3 || col == 3) {
        
        return true;
    }
    else{
        cout << "invalid move, you dumb how can one start in middle of table, always start from start." << endl;
        return false;
    }
}
bool possiblemoveValidity(int prerow, int precol, int newrow, int newcol) {
    if (newrow == prerow + 1 && newcol == precol) {
        return true;
    } else if (newrow == prerow -1  && newcol == precol) {
        return true;
    }
    else if (newrow == prerow && newcol == precol-1) {
        return true;
    }
    else if (newrow == prerow  && newcol == precol +1) {
        return true;
    }
    else if (newrow == prerow-1 && newcol == precol - 1) {
        return true;
    }
    else if (newrow == prerow+1 && newcol == precol + 1) {
        return true;
    }
    else if (newrow == prerow+1 && newcol == precol - 1) {
        return true;
    }
    else if (newrow == prerow-1 && newcol == precol + 1) {
        return true;
    }
    else {
        cout << "duh!!!!! This program is not human who can jump so plz,walk block by block.retry! " << endl;
        return false;
    }
}
bool greaterThenlimit(int row, int col) {
    if (row > 3 || row < 0 || col>3 || col < 0) {
        return true;
    }
    else {
        return false;
    }
}

void nextMoves(int preRow, int preCol , int arr[3][3]) {
    for (int i = 0; i <= 15; i++) {
        cout << "make your " << i + 2 << "nd move" << endl;
        bool movevaild = false;
        int newrow;
        int newcol;
        while (movevaild == false) {

            cout << "enter row:";
            cin >> newrow;
            cout << "enter col:";
            cin >> newcol;
            if (newrow == preCol && newcol == preCol) {
                cout << "cant have previous position" << endl;
            }
            else {
                movevaild = possiblemoveValidity(preRow, preCol, newrow, newcol);
            }
        }
        if (movevaild == true) {
            arr[newrow][newcol] = 1;
            cout << "valid move" << endl;
        }
        if (greaterThenlimit(newrow , newcol )) {
            cout << "congrats you are out of table by making " << i + 2 << " moves" << endl;
            break;
        }
        preRow = newrow;
        preCol = newcol;

    }
    
}
void startvalue(int arr[3][3]) {
    cout << "enter position to start NOTE: Start position can only be positions on boundaries" << endl;
    int row;
    int col;
    bool valid = false;
    while (valid == false) {
        
        cout << " enter ROW:";
        cin >> row;
        cout << "enter Columns:";
        cin >> col;
         valid = check(row, col);
    }
    if (check(row,col) == true) {
        cout << "valid move " << endl;
        arr[row][col] = 1;
        nextMoves(row, col, arr);
    }
    

}


int  main()
{
    table();
    int tablearr[3][3] = {0};
    startvalue(tablearr);
    return 0;
}
