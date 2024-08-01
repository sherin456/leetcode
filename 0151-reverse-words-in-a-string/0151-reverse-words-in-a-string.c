

// Function to reverse a portion of the string
void reverse(char* begin, char* end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

// Function to reverse words in the string
char* reverseWords(char* s) {
    // Remove leading and trailing spaces
    while (*s == ' ') {
        s++;
    }
    int len = strlen(s);
    while (len > 0 && s[len - 1] == ' ') {
        s[--len] = '\0';
    }

    // Reverse individual words
    char* word_begin = s;
    char* temp = s;
    while (*temp) {
        temp++;
        if (*temp == ' ' || *temp == '\0') {
            reverse(word_begin, temp - 1);
            //It ensures that we correctly update the starting position for the next word after reversing the current word.
            word_begin = temp + 1;
        }
    }

    // Reverse the entire string
    reverse(s, temp - 1);

    // Remove extra spaces between words
    char* dest = s;
    temp = s;
    while (*temp) {
        if (*temp != ' ' || (*(temp + 1) != ' ' && *(temp + 1) != '\0')) {
            *dest++ = *temp;
        }
        temp++;
    }
    *dest = '\0';

    return s;
}

