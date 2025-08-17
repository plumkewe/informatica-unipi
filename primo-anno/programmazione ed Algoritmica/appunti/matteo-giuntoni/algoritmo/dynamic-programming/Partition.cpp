#include <iostream>

using namespace std;

int partition(int A[], int n, int s)
{
    bool P[n + 1][s + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            P[i][j] = false;
        }
    }
    P[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (P[i - 1][j])
                P[i][j] = true;
            if (j >= A[i - 1] && P[i - 1][j - A[i - 1]])
                P[i][j] = true;
        }
    }
    return P[n][s];
}

int main()
{
    int A[7] = {10, 4, 5, 5, 3, 2, 1};
    cout << partition(A, 7, 7);
}