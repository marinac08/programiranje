#include <iostream>
#include <vector>
using namespace std;

int N;
int solutionCount = 0;

// Check if placing queen at (row, col) is safe
bool isSafe(vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        // Same column
        if (board[i] == col)
            return false;

        // Diagonals
        if (abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

// Brute force recursive function
void solve(vector<int>& board, int row) {
    if (row == N) {
        solutionCount++;
        cout << "\nSolution " << solutionCount << ":\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solve(board, row + 1);
        }
    }
}

int main() {
    cout << "Enter value of N: ";
    cin >> N;

    vector<int> board(N, -1);

    solve(board, 0);

    if (solutionCount == 0)
        cout << "No solutions found.\n";
    else
        cout << "\nTotal solutions: " << solutionCount << endl;

    return 0;
}
