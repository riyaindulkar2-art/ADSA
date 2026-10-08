#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int LCS_LENGTH(string X, string Y,
               vector<vector<int>>& dp)
{
    int m = X.length();
    int n = Y.length();

    dp.assign(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] =
                    max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}


string BUILD_LCS(string X, string Y,
                 vector<vector<int>>& dp)
{
    int i = X.length();
    int j = Y.length();

    string result = "";

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            result = X[i - 1] + result;

            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return result;
}

int main()
{
    string X, Y;

    cout << "Enter first string: ";
    cin >> X;

    cout << "Enter second string: ";
    cin >> Y;

    vector<vector<int>> dp;

    int length = LCS_LENGTH(X, Y, dp);

    string result = BUILD_LCS(X, Y, dp);

    cout << "\nLength of LCS: " << length;

    cout << "\nLCS: " << result;

    return 0;
}