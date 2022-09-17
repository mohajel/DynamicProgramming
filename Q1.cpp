#include<bits/stdc++.h>
using namespace std;
 
string lcs(string &X, string &Y)
{
    int m = X.length();
    int n = Y.length();
    int L[m+1][n+1];
 
    /* Following steps build L[m+1][n+1] in bottom up fashion. 
    Note that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    // Following code is used to print LCS
    int index = L[m][n];
    string lcs(index+1, '\0');
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i-1] == Y[j-1])
        {
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    return lcs;
}

string longestPalSubseq(string &str)
{
    // Find reverse of str
    string rev = str;
    reverse(rev.begin(), rev.end());
    // Return LCS of str and its reverse
    return lcs(str, rev);
}

int main()
{
    string str = "helohola!";
    cout << longestPalSubseq(str);
    return 0;
}
