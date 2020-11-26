#include <bits/stdc++.h>
using namespace std;
struct Bankers
{
    int pid, allocation[3], max_resource[3], need[3];
};
Bankers arr[100];
int n, m, available[3];
vector<int> v;
int main()
{
    int i, j, k, t, p, cas=1;
    v.clear();
    scanf("%d", &n);
    for( i=0; i<n; i++)
    {
        scanf("%d", &arr[i].pid);
        for( j=0; j<3; j++)
        {
            scanf("%d", &arr[i].allocation[j]);
        }
        for( j=0; j<3; j++)
        {
            scanf("%d", &arr[i].max_resource[j]);
        }
        for( j=0; j<3; j++)
        {
            arr[i].need[j]=arr[i].max_resource[j]-arr[i].allocation[j];
        }
    }
    scanf("%d %d %d", &available[0], &available[1], &available[2]);
//    for( i=0; i<n; i++)
//    {
//        printf("%d ", arr[i].pid);
//        for( j=0; j<3; j++)
//        {
//            printf("%d ", arr[i].allocation[j]);
//        }
//        for( j=0; j<3; j++)
//        {
//            printf("%d ", arr[i].max_resource[j]);
//        }
//        for( j=0; j<3; j++)
//        {
//            printf("%d ", arr[i].need[j]);
//        }
//        printf("\n");
//    }
//    printf("%d %d %d\n", available[0], available[1], available[2]);
    while(1)
    {
        int flag=0, flag1=0;
        for( i=0; i<n; i++)
        {
            flag1=0;
            for( j=0; j<3; j++)
            {
                if(arr[i].allocation[j]!=-1 && available[j]>=arr[i].need[j])
                {
                    continue;
                }
                else
                {
                    flag1=1;
                    break;
                }
            }
            if(!flag1)
            {
                flag=1;
                v.push_back(arr[i].pid);
                for( j=0; j<3; j++)
                {
                    available[j]+=arr[i].allocation[j];
                    arr[i].allocation[j]=-1;
                    printf("%d ", available[j]);
                }
                printf("\n");
            }
        }
        if(!flag) break;
    }
    if(v.size()==n)
    {
        printf("Processes are in Safe State\nSafe Sequence\n");
        for(auto a:v)
        {
            cout << "P" << a << ", ";
        }
        cout << "\n";
    }
    else printf("There is no Safe Sequence\n");
    return 0;
}
/*
5
1 0 1 0 7 5 3
2 2 0 0 3 2 2
3 0 0 2 4 3 3
4 2 1 1 2 2 2
5 3 0 2 9 0 2
3 3 2
*/
