bool wordPattern(char* pattern, char* s) {
    char a[300][300];
    int f=0,j=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]==' '){
            strncpy(a[j],s+f,i-f);
            a[j][i-f]='\0';
            f=i+1;
            j++;
        }
    }
    strncpy(a[j],s+f,strlen(s)-f);
    a[j][strlen(s)-f]='\0';
    if(j+1!=strlen(pattern))return false;
    for(int i=0;i<strlen(pattern);i++){
        if(pattern[i]!=' '){
            for(int k=i+1;k<strlen(pattern);k++){
                if(pattern[i]==pattern[k]){
                    pattern[k]=' ';
                    if(strcmp(a[i],a[k]))return false;
                }else{
                    if(!strcmp(a[i],a[k]))return false;
                }
            }
        }
    }
    return true;
}