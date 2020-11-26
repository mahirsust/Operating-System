#include <bits/stdc++.h>
using namespace std;
struct Priority
{
    int pid, at, bt, bt_d, pr, st, ft, rt, wt, tt;
};
Priority arr[100];
int n, m;
bool visited[100];
bool comp(Priority a, Priority b)
{
    if(a.at==b.at)
    {
        return a.pr<b.pr;
    }
    else return a.at<b.at;
}
bool comp1(Priority a, Priority b)
{
    return a.pid<b.pid;
}
int main()
{
    int i, j, k, t, p, cas=1;
    memset(visited, false, sizeof(visited));
    scanf("%d", &n);
    for( i=0; i<n; i++)
    {
        scanf("%d %d %d %d", &arr[i].pid, &arr[i].at, &arr[i].bt, &arr[i].pr);
        arr[i].bt_d=arr[i].bt;
    }
    for( i=0; i<n; i++)
    {
        printf("%d %d %d %d\n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].pr);
    }
    sort(arr, arr+n, comp);
    int complete=0, ft_cnt=arr[0].at;
    while(complete<n)
    {
        int mini=INT_MAX, idx;
        for( i=0; i<n; i++)
        {
            if(arr[i].bt_d!=0 && arr[i].at<=ft_cnt && arr[i].pr<mini)
            {
                mini=arr[i].pr;
                idx=i;
            }
        }
        if(mini==INT_MAX)
        {
            ft_cnt++;
            continue;
        }
        if(visited[idx]==false)
        {
            cout << arr[idx].pid << " " << ft_cnt << "\n";
            visited[idx]=true;
            arr[idx].st=ft_cnt;
        }
        arr[idx].bt_d--;
        ft_cnt++;
        if(arr[idx].bt_d==0)
        {
            complete++;
            arr[idx].ft=ft_cnt;
            arr[idx].rt=arr[idx].st-arr[idx].at;
            arr[idx].tt=arr[idx].ft-arr[idx].at;
            arr[idx].wt=arr[idx].tt-arr[idx].bt;
        }
    }
    sort( arr, arr+n, comp1);
    double rt_a=0.0, wt_a=0.0, tt_a=0.0;
    for( i=0; i<n; i++)
    {
        printf("P%d %d %d %d %d\n", arr[i].pid, arr[i].rt, arr[i].wt, arr[i].tt, arr[i].ft);
        rt_a+=arr[i].rt;
        wt_a+=arr[i].wt;
        tt_a+=arr[i].tt;
    }
    cout << round(rt_a/n) << " " << round(wt_a/n) << " " << round(tt_a/n) << "\n";
    return 0;
}
/*
5
1 0 2 12
2 1 4 4
3 0 6 10
4 2 1 3
5 3 5 6
5
1 4 2 2
2 1 3 6
3 2 1 1
4 0 1 5
5 9 5 10
*/
