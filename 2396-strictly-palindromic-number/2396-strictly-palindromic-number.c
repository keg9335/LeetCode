bool isStrictlyPalindromic(int n) {
    int n_tmp = n;
    int temp;
    for (int b = 2; b < n - 1; b++) {
        temp = 0;
        n_tmp = n;
        while (n_tmp) {
            temp = temp * b + n_tmp % b;
            n_tmp /= b;
        }
        if (temp != n) return 0;
    }
    return 1;    
}