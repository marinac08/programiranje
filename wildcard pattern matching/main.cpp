#include <bits/stdc++.h>
using namespace std;

bool isMatch(string word, string pattern, int n, int m, auto &lookup)
{
    if (m < 0 && n < 0) {
        return true;
    }
    else if (m < 0) {
        return false;
    }
    else if (n < 0)
    {
        for (int i = 0; i <= m; i++)
        {
            if (pattern[i] != '*') {
                return false;
            }
        }

        return true;
    }
    if (!lookup[m][n])
    {
        if (pattern[m] == '*')
        {
            lookup[m][n] = isMatch(word, pattern, n - 1, m, lookup) ||
                        isMatch(word, pattern, n, m - 1, lookup);
        }
        else {
            if (pattern[m] != '?' && pattern[m] != word[n]) {
                lookup[m][n] = 0;
            }
            else {
                lookup[m][n] = isMatch(word, pattern, n - 1, m - 1, lookup);
            }
        }
    }

    return lookup[m][n];
}
int main()
{
    string word;
    string pattern;
    cin >> word >> pattern;
    int n = word.length();
    int m = pattern.length();
    vector<vector<bool>> lookup(m + 1, vector<bool>(n + 1, false));

    if (isMatch(word, pattern, n - 1, m - 1, lookup)) {
        cout << "Match";
    }
    else {
        cout << "No Match";
    }

    return 0;
}
