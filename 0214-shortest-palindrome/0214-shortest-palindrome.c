int palindrome(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len/2; i++) {
        if (s[i] != s[len-i-1]) return 0;
    }
    return 1;
}

int partial_palindrome(char* s, int end) {
    for (int i = 0; i < (end+1)/2; i++) {
        if (s[i] != s[end-i]) return 0;
    }
    return 1;
}

void makenewstring(char* dst, char* src, int len, int add_len) {
    for (int i = add_len; i > 0; i--) {
        dst[add_len - i] = src[len - add_len + i -1];

    }
    
    for (int i = 0; i < len; i++){
        dst[i+add_len] = src[i];
    }
    dst[len+add_len] = '\0';
}

char* shortestPalindrome(char* s) {
    if (palindrome(s)) return s;
    int len = strlen(s);
    int end = 0;
    int i;
    for (i = len-2; i > 0; i--) {
        if (partial_palindrome(s, i)) {
            end = i;
            break;
        }   
    }
    
    int add = len - end -1;
    char* new_s = (char*)malloc(sizeof(char) * (len+1+add));
    for (i = add; i > 0; i--) {
        new_s[add - i] = s[len - add + i -1];
    }
    
    for (i = 0; i < len; i++){
        new_s[i+add] = s[i];
    }
    
    new_s[len+add] = '\0';
    return new_s;
}