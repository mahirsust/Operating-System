#include <bits/stdc++.h>
using namespace std;
int n, m, arr[3], page[100];
int main()
{
    int i, j, k, t, p, cas=1;
    int flag=0;
    memset(arr, -1, sizeof(arr));
    memset(page, -1, sizeof(page));
    scanf("%d", &n);
    scanf("%d", &m);
    for( i=0; i<m; i++)
    {
        scanf("%d", &page[i]);
    }
    for( i=0; i<m; i++)
    {
        flag=0;
        for( j=0; j<n; j++)
        {
            if(arr[j]==page[i])
            {
                flag=1;
                break;
            }
            if(arr[j]==-1)
            {
                arr[j]=page[i];
                flag=1;
                break;
            }
        }
        int mini=1e9, idx;
        if(!flag)
        {
            for( j=0; j<n; j++)
            {
                for( k=i-1; k>=0; k--)
                {
                    if(page[k]==arr[j])
                    {
                        if(mini>k)
                        {
                            mini=k;
                            idx=j;
                        }
                        break;
                    }
                }
            }
            arr[idx]=page[i];
        }
        for( j=0; j<n; j++)
        {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
    return 0;
}
/*
3
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/

