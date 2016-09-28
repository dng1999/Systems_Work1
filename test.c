#include <stdio.h>
#include <stdlib.h>

char strLen(char *s){
  int i = 0;
  while (s[i]){
    i++;
  }
  return i;
}

char *strnCpy(char *dest, char *src, int n){
  int i = 0;
  while (src[i] || i < n){
    dest[i] = src[i];
    i++;
  }
  return src;
}

char *strCat(char *dest, char *src){
  int i = strLen(dest);
  while (*src){
    dest[i] = *src;
    src++;
    i++;
  }
  return dest;
}

char strCmp(char *s1, char *s2){
  while (*s1 && (*s1 == *s2)){
    s1++;
    s2++;
  }
  return *s1-*s2;
}

char strChr(char *str, char c){
  char i = 0;
  while (*str){
    if (*str == c) return i;
    str++;
    i++;
  }
  return NULL;
}

int main(){
  char s1[] = "Hello";
  char s2[20];
  
  printf("Before applying functions:\n");
  printf("s1 = %s, length = %d\n", s1, strLen(s1));
  printf("s2 = %s, length = %d\n", s2, strLen(s2));
  
  printf("\nTesting regular functions:\n");
  strnCpy(s2,s1,3);
  printf("Copy s1 to s2 (first three): s2 = %s, length = %d\n", s2, strLen(s2));
  strCat(s2, "Man");
  printf("Cat 'Man' to s2: s2 = %s, length = %d\n", s2, strLen(s2));
  printf("s1 = %s, length = %d\n", s1, strLen(s1));

  printf("\nTesting strcmp:\n");
  printf("compare ab to abc: %d\n", strCmp("ab","abc"));
  printf("compare abc to ab: %d\n", strCmp("abc","ab"));
  printf("compare abc to abc: %d\n", strCmp("abc","abc"));

  printf("\nTesting strchr:\n");
  printf("Looking for 1 in Hello123: [%d]\n", strChr("Hello123",'1'));
  printf("Looking for 0 in Hello123: [%d]\n", strChr("Hello123",'0'));

  return 0;
}
