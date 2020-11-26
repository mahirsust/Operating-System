#include<bits/stdc++.h>
using namespace std;
struct Process
{
    int pid, at, bt, rt, wt, tt, st, ft;
};
Process arr[100];
int n, m, rt_a, wt_a, tt_a;
bool comp(Process a, Process b)
{
    return a.at<b.at;
}
bool comp1(Process a, Process b)
{
    return a.pid<b.pid;
}
int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d", &arr[i].pid, &arr[i].at, &arr[i].bt);
    }
    sort(arr, arr+n, comp);
    for(int i=0; i<n; i++)
    {
        cout << arr[i].pid << " " << arr[i].at << " " << arr[i].bt << "\n";
    }
    arr[0].rt=0;
    arr[0].wt=arr[0].rt;
    arr[0].tt=arr[0].bt;
    arr[0].ft=arr[0].at+arr[0].bt;
    arr[0].st=arr[0].at;
    rt_a+=arr[0].rt;
    wt_a+=arr[0].wt;
    tt_a+=arr[0].tt;
    for(int i=1; i<n; i++)
    {
        if(arr[i].at<=arr[i-1].ft)
        {
            arr[i].st=arr[i-1].ft;
            arr[i].ft=arr[i].st+arr[i].bt;
            arr[i].rt=arr[i].st-arr[i].at;
            arr[i].tt=arr[i].ft-arr[i].at;
            arr[i].wt=arr[i].tt-arr[i].bt;
            rt_a+=arr[i].rt;
            wt_a+=arr[i].wt;
            tt_a+=arr[i].tt;
        }
        else
        {
            arr[i].st=arr[i].at;
            arr[i].ft=arr[i].st+arr[i].bt;
            arr[i].rt=arr[i].st-arr[i].at;
            arr[i].tt=arr[i].ft-arr[i].at;
            arr[i].wt=arr[i].tt-arr[i].bt;
            rt_a+=arr[i].rt;
            wt_a+=arr[i].wt;
            tt_a+=arr[i].tt;
        }
    }
    rt_a=round((double)rt_a/n);
    wt_a=round((double)wt_a/n);
    tt_a=round((double)tt_a/n);
    sort(arr, arr+n, comp1);
    //printf("Proces   AT   BT    RT    WT    TT\n");
    for(int i=0; i<n; i++)
    {
        //printf("P%d       %d     %d     %d     %d     %d\n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].rt, arr[i].wt, arr[i].tt);
        printf("P%d %d %d %d %d\n", arr[i].pid, arr[i].rt, arr[i].wt, arr[i].tt, arr[i].ft);
    }
    cout << rt_a << " " << wt_a << " " << tt_a << "\n";
    return 0;
}
//1----5(BT)------20 = 19s(TT) er moddhe 5s execute = 19-5 = 14
/*
5
1 1 4
2 0 2
3 3 1
4 5 6
5 4 9
5
1 0 4
2 0 2
3 0 1
4 0 6
5 0 9
6
1 1 4
2 0 2
3 3 1
4 5 6
5 4 9
6 23 4
*/
