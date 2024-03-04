char* largestPalindromic(char* num) {
    int len = strlen(num);
    int freq[10] = {0, };
    int valid_num = 0;
    int left = len / 2 - 1, mid = len / 2, right = len / 2;
    
    for (int i = 0; i < len; i++) {
        freq[num[i]-'0']++;
    }
    
    for (int i = 0; i < 10; i++) {
        if (freq[i]) valid_num++;
    }
    
    if (valid_num == 1 && freq[0]) return "0";
    
    char* new_num = (char*) malloc(sizeof(char) * (len+1));
    for (int i = 9; i >= 0; i--) {
        if (freq[i] % 2) {
            new_num[mid] = i + '0';
            freq[i]--;
            right++;
            break;
        }
    }
    
    for (int i = 0; i < 10; i++) {
        while (freq[i] > 1) {
            new_num[left--] = i + '0';
            new_num[right++] = i + '0';
            freq[i] -= 2;
        }
    }
    
    while (new_num[left+1] == '0') {
        left++; right--;
    }
    
    new_num[right] = '\0';
    return new_num+left+1;    
}