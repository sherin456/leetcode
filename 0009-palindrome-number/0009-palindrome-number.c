bool isPalindrome(int x) {
    int rev=0;
    if(x<0||x!=0&&x%10==0)
    return false;
    while(x>rev)
    {
        int digit=x%10;
        rev=rev*10+digit;
        x/=10;
    }
    return (x==rev||x==rev/10);
}