// 这道题有两个思路，一个是进行强转成字符型，用指针从中间开始往两边遍历，一直到结束都相同则是回文数。

bool isPalindrome(int x) {
    if(x < 0 || x > 0 && x % 10 == 0) {
        return false;
    }
    int rev = 0;
    while(rev < x /10) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev == x || rev == x / 10;
}

bool isPalindromes(int x) {
    if(x < 0) return false;

    char str[20];
    sprintf(str, "%d", x);      //将X中每个字符都转为独个字符
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right]) return false;
        left++;
        right--;
    }
    return true;
}