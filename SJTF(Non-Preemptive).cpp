#include <bits/stdc++.h>
using namespace std;
struct SJTF
{
    int pid, at, bt, st, ft, rt, wt, tt;
};
SJTF arr[100];
int n, m;
double rt_a, wt_a, tt_a;
bool comp(SJTF a, SJTF b)
{
    if(a.at==b.at)
    {
        return a.bt<b.bt;
    }
    else return a.at<b.at;
}
bool comp1(SJTF a, SJTF b)
{
    if(a.at<=m && b.at<=m)
    {
        if(a.bt<b.bt) return true;
        else if(a.bt==b.bt)
        {
            if(a.at<b.at) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}
int main()
{
    int i, j, k, t, p, cas=1;
    scanf("%d", &n);
    for( i=0; i<n; i++)
    {
        scanf("%d %d %d", &arr[i].pid, &arr[i].at, &arr[i].bt);
    }
    sort(arr, arr+n, comp);
    for(int i=0; i<n; i++)
    {
        cout << arr[i].pid << " " << arr[i].at << " " << arr[i].bt << "\n";
    }
    arr[0].st=arr[0].at;
    arr[0].ft=arr[0].st+arr[0].bt;
    arr[0].rt=arr[0].st-arr[0].at;
    arr[0].tt=arr[0].ft-arr[0].at;
    arr[0].wt=arr[0].tt-arr[0].bt;
    rt_a+=(double)arr[0].rt;
    wt_a+=(double)arr[0].wt;
    tt_a+=(double)arr[0].tt;
    for( i=1; i<n; i++)
    {
        m=arr[i-1].ft;
        sort(arr+i, arr+n, comp1);
//        for( j=i; j<n; j++)
//        {
//            printf("P%d %d %d\n", arr[j].pid, arr[j].at, arr[j].bt);
//        }
        if(arr[i].at<=m)
        {
            arr[i].st=arr[i-1].ft;
            arr[i].ft=arr[i].st+arr[i].bt;
            arr[i].rt=arr[i].st-arr[i].at;
            arr[i].tt=arr[i].ft-arr[i].at;
            arr[i].wt=arr[i].tt-arr[i].bt;
        }
        else
        {
            arr[i].st=arr[i].at;
            arr[i].ft=arr[i].st+arr[i].bt;
            arr[i].rt=arr[i].st-arr[i].at;
            arr[i].tt=arr[i].ft-arr[i].at;
            arr[i].wt=arr[i].tt-arr[i].bt;
        }
        rt_a+=(double)arr[i].rt;
        wt_a+=(double)arr[i].wt;
        tt_a+=(double)arr[i].tt;
    }
    for( i=0; i<n; i++)
    {
        printf("P%d %d %d %d %d %d\n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].rt, arr[i].wt, arr[i].tt);
    }
    cout << round(rt_a/n) << " " << round(wt_a/n) << " " << round(tt_a/n) << "\n";
    return 0;
}
/*
5
1 4 2
2 1 3
3 2 1
4 0 1
5 9 5
5
1 4 1
2 1 3
3 2 2
4 0 1
5 9 5
*/
