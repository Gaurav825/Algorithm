 int bin_log[100005];
int main()
{
     int n,q;
    cin>>n>>q;
    int arr[n];
   for(int i=0; i<n; i++)
    cin>>arr[i];
     int log=17;//10^5
    bin_log[1]=0;
    for(int i=2; i<=n; i++)
        bin_log[i]=bin_log[i/2]+1;
   int sparse[n+1][log+1];
    for(int i=0; i<n; i++)
    sparse[i][0]=arr[i];
    for(int i=1; (1<<i)<=n; i++){
        for(int j=0; j+(1<<i)-1<n; j++)
        {
            sparse[j][i]=min(sparse[j][i-1],sparse[j+(1<<(i-1))][i-1]);


        }
    }

    while(q--)
    {

       int l,r;
        cin>>l>>r;
        l-=1;
        r-=1;
         int len=r-l+1;
        int k=bin_log[len];
        int ans= min(sparse[l][k],sparse[r-(1<<k)+1][k]);
        cout<<ans<<endl;


    }



}

