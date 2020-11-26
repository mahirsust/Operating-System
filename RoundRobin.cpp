#include <bits/stdc++.h>
using namespace std;
struct RR
{
    int pid, at, bt, bt_c, st, ft, rt, wt, tt;
};
int n, m, f_t, completed, visited[100];
queue<int> q;
bool comp(RR a, RR b)
{
    if(a.at<b.at) return true;
    else return false;
}
bool comp1(RR a, RR b)
{
    return a.pid<b.pid;
};
int main()
{
    RR arr[100];
    int i, j, k, t, p, cas=1;
    memset(visited, 0, sizeof(visited));
    scanf("%d %d", &n, &m);
    for( i=0; i<n; i++)
    {
        scanf("%d %d %d", &arr[i].pid, &arr[i].at, &arr[i].bt);
        arr[i].bt_c=arr[i].bt;
    }
    sort(arr, arr+n, comp);
    for( i=0; i<n; i++)
    {
        printf("%d %d %d\n", arr[i].pid, arr[i].at, arr[i].bt);
    }
    q.push(0);
    f_t=arr[0].at, completed=0;
    //cout << f_t << "\n";
    while(completed<n)
    {
        if(q.size()==0)
        {
            f_t++;
            for( i=0; i<n; i++)
            {
                if(arr[i].at<=f_t && visited[i]==0)
                {
                    q.push(i);
                    visited[i]=1;
                }
            }
            continue;
        }
        int ind=q.front();
        q.pop();
        //cout << "P" << arr[ind].pid << " ";
        if(visited[ind]==0)
        {
            arr[ind].st=f_t;
            visited[ind]=1;
        }
        if(arr[ind].bt_c>=m)
        {
            arr[ind].bt_c-=m;
            f_t+=m;
        }
        else if(arr[ind].bt_c<m)
        {
            f_t+=arr[ind].bt_c;
            arr[ind].bt_c=0;
        }
        if(arr[ind].bt_c==0)
        {
            completed++;
            //cout << "Completed " << completed << " " << arr[ind].pid << "\n";
            arr[ind].rt=arr[ind].st-arr[ind].at;
            //cout << f_t << " ";
            arr[ind].ft=f_t;
            cout << arr[ind].st << " P" << arr[ind].pid << "\n";
            arr[ind].tt=arr[ind].ft-arr[ind].at;
            arr[ind].wt=arr[ind].tt-arr[ind].bt;
        }
        for( i=0; i<n; i++)
        {
            if(arr[i].at<=f_t && visited[i]==0)
            {
                q.push(i);
                visited[i]=1;
            }
        }
        if(arr[ind].bt_c!=0) q.push(ind);
        //cout << f_t << " ";
    }
    cout << "\n";
    sort( arr, arr+n, comp1);
    for( i=0; i<n; i++)
    {
        printf("%d %d %d ------- %d %d\n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].st, arr[i].ft);
    }
    for( i=0; i<n; i++)
    {
        printf("%d %d %d %d %d %d %d %d\n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].st, arr[i].ft, arr[i].rt,
                arr[i].wt, arr[i].tt);
    }
    return 0;
}
/*
6 2
1 3 6
2 6 8
3 3 1
4 0 9
5 7 3
6 4 12
*/
