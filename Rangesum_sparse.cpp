int main()
{
	long long int n,q;
	cin>>n>>q;
    long long int arr[n];
	for(int i=0; i<n; i++)
        cin>>arr[i];
	int log=17;
	long long int sparse[n+1][log+1];
    for(int i=0; i<n; i++)
	sparse[i][0]=arr[i];
	for(long long int i=1; i<log; i++)
    {
        for(long long int j=0; j+(1<<i)<=n; j++)
        {
            sparse[j][i]=sparse[j][i-1]+sparse[j+(1<<(i-1))][i-1];
        }
    }
    while(q--)
    {
        long long int ans=0;
        int l,r;
        cin>>l>>r;
         l--;
         r--;
        for(int i=log; i>=0; i--)
        {
            if(l+(1<<i)-1<=r)
            {

                ans+=sparse[l][i];
                l=l+(1<<i);
            }
        }
        cout<<ans<<endl;

    }

}
