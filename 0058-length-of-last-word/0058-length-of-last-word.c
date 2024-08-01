int lengthOfLastWord(char* s) {
    int len = 1;
    for(int i=1; s[i]; i++){
        if(s[i] == ' ') continue;
        if(s[i-1] == ' ') len = 0;
        len++;
    }
    return len;
}