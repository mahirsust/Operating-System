#include <bits/stdc++.h>
using namespace std;
int n, m, arr[3], ind[3];
int main()
{
    int i, j, k, t, p, cas=1;
    int flag=0;
    memset(arr, -1, sizeof(arr));
    memset(ind, -1, sizeof(ind));
    scanf("%d", &n);
    scanf("%d", &m);
    for( i=0; i<m; i++)
    {
        scanf("%d", &p);
        flag=0;
        for( j=0; j<n; j++)
        {
            if(arr[j]==p)
            {
                flag=1;
                break;
            }
            if(arr[j]==-1)
            {
                arr[j]=p;
                flag=1;
                ind[j]=i;
                break;
            }
        }
        if(!flag)
        {
            int mini=1e9, idx;
            for( j=0; j<n; j++)
            {
                if(mini>ind[j])
                {
                    mini=ind[j];
                    idx=j;
                }
            }
            arr[idx]=p;
            ind[idx]=i;
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
