bool isPowerOfThree(int n) {
    if(n<=0){return false;}
    if(n==1){return true;}
    int pow_of_three=1;
    for(int i=0;i<19;i++){
        pow_of_three *= 3;
        if(pow_of_three==n)
        return true;
    }
    return false;
}