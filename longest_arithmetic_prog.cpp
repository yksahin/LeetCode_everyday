#include <iostream>

using namespace std;

int longestAP(int arr[], int n)
{
    // Boudnary condition
    if(n <= 2) return n;

    //Table creation
    int table[n][n];
    // max length is something that we are going to return
    int maxLength = 2;

    //prefiling the last column of the array  with 2.
    for(int i = 0; i < n; i++)
    {
        table[i][n-1] = 2;
    }
    // This is where we start j with last second last element 
    // Taking it back till j is equal to 1
    for(int j = n -2; j>= 1; j--)
    {
        int i = j-1, k = j + 1;
        
        while(i > = 0 && k <= n -1)
        {
            //Three conditions that we follow.
            if(arr[i] + arr[k] < 2 * arr[j]) k++;
            else if(arr[i] + arr[k] > 2 * arr[j]) table[i][j] = 2;i--;
            else
            {
                // Third condition when both sides are equal
                
                table[i][j] = table[j][k] + 1;
                maxLength = max(maxLength, table[i][j]);
                i--;k++;
            }
        }
        while(i >= 0)
        {
            table[i][j] = 2;
            i--;
        }
    }
    return maxLength;
}