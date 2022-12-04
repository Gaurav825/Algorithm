void dfs(int u, int p, int **memo, int *lev, int log, vector<int> *g)
{
    // Using recursion formula to calculate
    // the values of memo[][]
    memo[u][0] = p;
    for (int i = 1; i <= log; i++)
        memo[u][i] = memo[memo[u][i - 1]][i - 1];
    for (int v : g[u])
    {
        if (v != p)
        {
            lev[v] = lev[u] + 1;
            dfs(v, u, memo, lev, log, g);
        }
    }
}
int lca(int u, int v,int log,int *lev,int **memo)
{
    if(lev[u]<lev[v])
        swap(u,v);
    int up=lev[u]-lev[v];
    for(int i=0; i<=log; i++)
    {
        if(up &(1<<i))
            u=memo[u][i];


    }
    if(u==v)
        return u;
    for(int i=log; i>=0; i--)
    {

        if(memo[u][i] !=memo[v][i])
        {

            u=memo[u][i];
            v=memo[v][i];
        }
    }
    return memo[u][0];// return first lca


}

int main()
{int n = 9;

    // vector to store tree
    vector<int> g[n + 1];

    int log = (int)ceil(log2(n));
    int **memo = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        memo[i] = new int[log + 1];

    // Stores the level of each node
    int *lev = new int[n + 1];
    for(int i=1; i<=n; i++)
        lev[i]=0;

    // Initialising memo values with -1
    for (int i = 0; i <= n; i++)
        memset(memo[i], -1, sizeof memo[i]);

    // Add edges
    g[1].push_back(2);
    g[2].push_back(1);
    g[1].push_back(3);
    g[3].push_back(1);
    g[1].push_back(4);
    g[4].push_back(1);
    g[2].push_back(5);
    g[5].push_back(2);
    g[3].push_back(6);
    g[6].push_back(3);
    g[3].push_back(7);
    g[7].push_back(3);
    g[3].push_back(8);
    g[8].push_back(3);
    g[4].push_back(9);
    g[9].push_back(4);
    dfs(1, 1, memo, lev, log, g);
    for(int i=1; i<=n; i++)
        cout<<i<<" "<<lev[i]<<endl;
        dfs(1, 1, memo, lev, log, g);
    cout << "The LCA of 6 and 9 is " << lca(6, 9, log, lev, memo) << endl;
    cout << "The LCA of 5 and 9 is " << lca(5, 9, log, lev, memo) << endl;
    cout << "The LCA of 6 and 8 is " << lca(6, 8, log, lev, memo) << endl;
    cout << "The LCA of 6 and 1 is " << lca(6, 1, log, lev, memo) << endl;


    return 0;





}
