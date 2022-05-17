#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod (1e9+7)

int found;

void bfs(queue<int> q, vector<vector<int> > t, int vis[], int k) {
    int f = q.front();
    q.pop();

    vis[f] = 1;
    if(f==k)
    {
        cout<< k <<" == "<<f<<" True"<<endl;
        cout<<"Element found!!\n\n";
        found = 1;
        return;
    }
    else {
        cout<< f <<" != "<< k <<endl;
    }
    
    for(int i = 0; i < t[f].size(); i++) {
        if (!vis[t[f][i]] && !found)
            q.push(t[f][i]);
    }
    bfs(q, t, vis, k);
}


void dfs(vector<vector<int> > t, int vis[], int s, int k) {
    vis[s] = 1;
    if(s==k)
    {
        cout << k <<" == "<< s << " True!"<<endl;
        cout<<"Element found!!\n\n";
        found = 1;
        return;
    }
    else {
        cout<< s <<" != "<< k <<endl;
    }

    for (int i = 0; i < t[s].size(); i++) {
        if(!vis[t[s][i]] && !found)
            dfs(t, vis, t[s][i], k);
    }
    if (found)
        return ;
}

void print(vector<vector<int> > t, int s)
{
    queue<int> q;
    q.push(s);
    int vis[1001]={0};
    while(!q.empty())
    {
        int k=q.size();
        for(int i=0;i<k;i++)
        {
            int x=q.front();
            q.pop();
            vis[x]=1;
            cout<<x<<" ";
            for(int i=0;i<t[x].size();i++)
            {
                if(vis[t[x][i]]==0)
                {
                    q.push(t[x][i]);
                }
            }
        }
        cout<<endl;
    }
}

int main()
{
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n, e, n1, n2, k, s;
    
    // cout << "\n #Nodes, #Edges : (n e)\n";
    cin >> n >> e;

    vector<vector<int> > t(n + 1);

    // cout << "\n Edges (u v) : \n";
    for (int i = 0; i < e; i++) {
        cin >> n1 >> n2;
        t[n1].push_back(n2);
        t[n2].push_back(n1);
    }
    // cout << "\nSource Node, Search Key (s, k) :\n";
    cin >> s >> k;

    cout << "\nTree : \n";
    print(t, s);
    
    queue<int> q;
    int vis[n+1] = {0};

    q.push(s);
    found = 0;
    
    cout << endl << "BFS Traversal : \n";
    bfs(q, t, vis, k);

    found = 0;
    memset(vis, 0, sizeof(vis));

    cout << endl << "DFS Traversal : \n";
    dfs(t, vis, 1, k);
}

/*
INPUT

5 4

1 2
1 3
2 4
2 5

1 4


OUTPUT

Tree : 
1 
2 3 
4 5 

BFS Traversal : 
1 != 4
2 != 4
3 != 4
4 == 4 True
Element found!!


DFS Traversal : 
1 != 4
2 != 4
4 == 4 True!
Element found!!

*/