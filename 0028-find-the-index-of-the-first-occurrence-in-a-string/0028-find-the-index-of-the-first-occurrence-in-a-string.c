int strStr(char* haystack, char* needle) {
    int index = -1, curr = 0;
    // While haystack[i] != '\0' (single false)
    for(int i=0; haystack[i]; i++){
        if(needle[curr] == haystack[i]){
            // Save the index of the first occurrence
            if(index == -1) index = i; 
            curr++; 
            // If it's the end of needle
            if(!needle[curr]) return index; 
        }
        else {
            // Returns i to the location of the occurrence
            if(index != -1) i = index; 
            index = -1; // Reset index
            curr = 0; // Reset current
        }
    }
    return -1;
}