//Q2 answer
//Given an array A, maximize value of expression (A[s] - A[r] + A[q] - A[p]), where p, q, r, and s are indices of the array and s > r > q > p
//The idea is to create four lookup tables, first[], second[], third[], and fourth[], where:
//first[] stores the maximum value of A[s].
//second[] stores the maximum value of A[s] - A[r].
//third[] stores the maximum value of A[s] - A[r] + A[q].
//fourth[] stores the maximum value of A[s] - A[r] + A[q] - A[p].
//time complexity:  O(n)
//space complexity:  O(n)

#include<bits/stdc++.h>
using namespace std;
 
int maximizeExpression(vector<int> const &A)
{
    int n = A.size();
    // create 4 lookup tables and initialize them to `INT_MIN`
    int first[n + 1], second[n], third[n - 1], fourth[n - 2];
    
    for (int i = 0; i <= n - 3; i++) 
        first[i] = second[i] = third[i] = fourth[i] = INT_MIN;
    first[n - 2] = second[n - 2] = third[n - 2] = INT_MIN;
    first[n - 1] = second[n - 1] = first[n] = INT_MIN;
 
    // `first[]` stores the maximum value of `A[l]`
    for (int i = n - 1; i >= 0; i--)
        first[i] = max(first[i + 1], A[i]);
    
    // `second[]` stores the maximum value of `A[l] - A[k]`
    for (int i = n - 2; i >= 0; i--) 
        second[i] = max(second[i + 1], first[i + 1] - A[i]);
 
    // `third[]` stores the maximum value of `A[l] - A[k] + A[j]`
    for (int i = n - 3; i >= 0; i--) 
        third[i] = max(third[i + 1], second[i + 1] + A[i]);
 
    // `fourth[]` stores the maximum value of `A[l] - A[k] + A[j] - A[i]`
    for (int i = n - 4; i >= 0; i--) 
        fourth[i] = max(fourth[i + 1], third[i + 1] - A[i]);
 
    // maximum value would be present at `fourth[0]`
    return fourth[0];
}
int main()
{
    vector<int> A = { 3, 9, 10, 1, 30, 40 };
    cout << maximizeExpression(A);
    return 0;
}
