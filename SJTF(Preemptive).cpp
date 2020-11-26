#include <bits/stdc++.h>
using namespace std;
struct SJTF_P
{
    int pid, at, bt, bt_d, st, ft, rt, wt, tt;
};
SJTF_P arr[100];
bool visited[100];
int n, m;
bool comp(SJTF_P a, SJTF_P b)
{
    if(a.at==b.at)
    {
        return a.bt<b.bt;
    }
    else return a.at<b.at;
}
bool comp1(SJTF_P a, SJTF_P b)
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
        scanf("%d %d %d", &arr[i].pid, &arr[i].at, &arr[i].bt);
        arr[i].bt_d=arr[i].bt;
    }
    sort(arr, arr+n, comp);
    int complete=0, ft_cnt=arr[0].at;
    while(complete<n)
    {
        int mini=INT_MAX, idx, flag=false;
        for( i=0; i<n; i++)
        {
            if(arr[i].bt_d!=0 && arr[i].at<=ft_cnt && arr[i].bt_d<mini)
            {
                mini=arr[i].bt_d;
                idx=i;
                flag=true;
            }
        }
        if(flag==false)
        {
            ft_cnt++;
            continue;
        }
        if(visited[arr[idx].pid]==false)
        {
            arr[idx].st=ft_cnt;
            visited[arr[idx].pid]=true;
        }
        arr[idx].bt_d--;
        ft_cnt++;
        cout << ft_cnt << " " << arr[idx].pid << "\n";
        if(arr[idx].bt_d==0)
        {
            complete++;
            arr[idx].ft=ft_cnt;
            arr[idx].rt=arr[idx].st-arr[idx].at;
            arr[idx].tt=arr[idx].ft-arr[idx].at;
            arr[idx].wt=arr[idx].tt-arr[idx].bt;
        }
    }
    double rt_a=0.0, wt_a=0.0, tt_a=0.0;
    for( i=0; i<n; i++)
    {
        rt_a+=(double)arr[i].rt;
        wt_a+=(double)arr[i].wt;
        tt_a+=(double)arr[i].tt;
    }
    sort(arr, arr+n, comp1);
    for( i=0; i<n; i++)
    {
        //printf("P%d  %d  %d  %d  %d  %d\n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].rt, arr[i].wt, arr[i].tt);
        printf("P%d  %d  %d  %d  %d\n", arr[i].pid, arr[i].rt, arr[i].wt, arr[i].tt, arr[i].ft);
    }
    cout << round(rt_a/n) << " " << round(wt_a/n) << " " << round(tt_a/n) << "\n";
    return 0;
}
/*
5
1 0 2
2 1 4
3 0 6
4 2 1
5 3 5
5
1 4 2
2 1 3
3 2 1
4 0 1
5 9 5
*/
