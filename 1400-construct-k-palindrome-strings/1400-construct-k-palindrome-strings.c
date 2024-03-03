bool canConstruct(char* s, int k) {
    if (strlen(s) < k) return 0;
    int cnt[26] = {0,};
    int odd = 0;

    for (int i = 0; i < strlen(s); i++) {
        cnt[s[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2) odd++;
    }
    
    return odd <= k;
}