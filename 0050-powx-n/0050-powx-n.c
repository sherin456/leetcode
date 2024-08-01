long double myPow(long double x, long int n)
{
    long double prod=1;
    if(n==0 || x==1 || (x==-1 && n%2==0))
    return 1;
    else if(x==-1)
    return -1;
    else if(n>=2147483647 || n<=-2147483648)
    return 0;
    else if(n>0)
    {
        for(long int i=0;i<n;i++)
        {
            prod*=x;
        }
    }
    else
    {
      for(long int i=0;i<-n;i++)
        {
            prod/=x;
        }  
    }
    return prod;

}
