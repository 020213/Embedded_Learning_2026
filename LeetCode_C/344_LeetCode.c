void reverseString(char* s, int sSize) {
    for(int left = 0,right = sSize -1; left < right; left++,right--){
         char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
    }
}

/* 
    这是单指针写法
 */
void reverseString(char* s, int sSize) {
    for(int left = 0; left < sSize-left-1; left++){
         char tmp = s[left];
        s[left] = s[sSize-left-1];
        s[sSize-left-1] = tmp;
    }
}