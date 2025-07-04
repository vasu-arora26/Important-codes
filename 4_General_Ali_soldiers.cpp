/*
General Ali has devised a strategic game to reduce
an enemy army of N soldiers to just 1 soldier using a
minimal number of moves.
The game allows the following three types of
moves:
1. Reduce the enemy army by 1 soldier.
2. Reduce the enemy army by half of its current
soldiers, rounding down to the nearest integer.
3. Reduce the enemy army by two-thirds of its
current soldiers, rounding down to the nearest
integer.
Each move must ensure that the resulting number
of soldiers is an integer.
Find the minimum number of moves required to
reduce enemy army to just 1 soldier.
Case 1
Input:
5
Output:
3
Explanation:
Given N = 5.
Move 1: Reduce by 1 soldier (5 -> 4)
Move 2: Reduce by half (4 -> 2)
Move 3: Reduce by half (2 -> 1)
Hence, the answer for this case is equal to 3.
Case 2
Input:
1
Output:
0
Explanation:
Given N = 1.
There is only 1 soldier already, so no moves are
required to reduce the enemy soldiers to 1.
Therefore, the minimum number of moves needed
is 0.
Case 3
Input:
6
Output:
2
Explanation:
Given N = 6.
Move 1: Reduce by half (6 -> 3)
Move 2: Reduce by half (3 -> 1)
Hence, the answer for this case is equal to 2.

*/

#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int fun(int n)
{
    if(n==1)return 0;
    queue<pair<int,int>>q;
    unordered_set<int>vis;
    q.push({n,0});
    vis.insert(n);
    while(!q.empty())
    {
        int current=q.front().first;
        int steps=q.front().second;
        q.pop();
        if(current==1)return steps;
        if(vis.find(current-1)==vis.end())
        {
            q.push({current-1,steps+1});
            vis.insert(current-1);
        }
        if(vis.find(current/2)==vis.end())
        {
            q.push({current/2,steps+1});
            vis.insert(current/2);
        }
        if(vis.find(current/3)==vis.end())
        {
            q.push({current/3,steps+1});
            vis.insert(current/3);
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    cout<<fun(n);
    return 0;
}
