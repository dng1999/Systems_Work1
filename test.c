#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myLen(char *s){
  int i = 0;
  while (s[i]){
    i++;
  }
  return i;
}

char *mynCpy(char *dest, char *src, int n){
  int i = 0;
  while (src[i] && i < n){
    dest[i] = src[i];
    i++;
  }
  return src;
}

char *myCat(char *dest, char *src){
  int i = myLen(dest);
  while (*src){
    dest[i] = *src;
    src++;
    i++;
  }
  return dest;
}

int myCmp(char *s1, char *s2){
  while (*s1 && (*s1 == *s2)){
    s1++;
    s2++;
  }
  return *s1-*s2;
}

char *myChr(char *s, char c){
  while (*s){
    if (*s == c) return s;
    s++;
  }
  return NULL;
}

char *myStr(char *s, char *c){
  char *sPos = s;
  char *cPos = c;
  while (*s){
    while (*c && *s && *s == *c){
      s++;
      c++;
    }
    if (!*c){
      return sPos;
    }
    sPos++;
    s = sPos;
    c = cPos;
  } 
  return NULL;
}

int main(){
  char Ys1[] = "Hello";
  char Ys2[20] = "";

  char Cs1[] = "Hello";
  char Cs2[20] = "";
  /////////////////////////////////////////////////////////////////////
  
  printf("Before applying functions:\n");
  printf("\tY|Ys1 = %s, length = %d\n", Ys1, myLen(Ys1));
  printf("\tC|Cs1 = %s, length = %zu\n\n", Cs1, strlen(Cs1));
  
  printf("\tY|Ys2 = %s, length = %d\n", Ys2, myLen(Ys2));
  printf("\tC|Cs2 = %s, length = %zu\n\n", Cs2, strlen(Cs2));
  
  printf("\nTesting regular functions:\n");
  mynCpy(Ys2,Ys1,3);
  printf("\tmynCpy(Ys2,Ys1,3): Ys2 = %s, length = %d\n", Ys2, myLen(Ys2));
  strncpy(Cs2,Cs1,3);
  printf("\tstrncpy(Cs2,Cs1,3): Cs2 = %s, length = %zu\n\n", Cs2, strlen(Cs2));

  myCat(Ys2, "Man");
  printf("\tmyCat(Ys2, 'Man): Ys2 = %s, length = %d\n", Ys2, myLen(Ys2));
  strcat(Cs2, "Man");
  printf("\tstrcat(Cs2, 'Man): Cs2 = %s, length = %zu\n\n", Cs2, strlen(Cs2));
  
  printf("\tYs1 = %s, length = %d\n", Ys1, myLen(Ys1));
  printf("\tCs1 = %s, length = %zu\n\n", Cs1, strlen(Cs1));

  printf("\nTesting myCmp:\n");
  printf("\tmyCmp('ab','abc'): %d\n", myCmp("ab","abc"));
  printf("\tstrcmp('ab','abc'): %d\n\n", strcmp("ab","abc"));

  printf("\tmyCmp('abc','ab'): %d\n", myCmp("abc","ab"));
  printf("\tstrcmp('abc','ab'): %d\n\n", strcmp("abc","ab"));
  
  printf("\tmyCmp('abc','abc'): %d\n", myCmp("abc","abc"));
  printf("\tstrcmp('abc','abc'): %d\n\n", strcmp("abc","abc"));
  
  printf("\tmyCmp('abc','abd'): %d\n", myCmp("abc","abd"));
  printf("\tstrcmp('abc','abd'): %d\n\n", strcmp("abc","abd"));
  
  printf("\nTesting myChr:\n");
  printf("\tmyChr('Hello123','1'): [%s]\n", myChr("Hello123",'1'));
  printf("\tstrchr('Hello123','1'): [%s]\n\n", strchr("Hello123",'1'));

  printf("\tmyChr('Hello123','0'): [%s]\n", myChr("Hello123",'0'));
  printf("\tstrchr('Hello123','0'): [%s]\n\n", strchr("Hello123",'0'));
  
  printf("\nTesting myStr:\n");
  printf("\tmyStr('Hello123','lo'): [%s]\n", myStr("Hello123","lo"));
  printf("\tstrstr('Hello123','lo'): [%s]\n\n", strstr("Hello123","lo"));

  printf("\tmyStr('Hello123','H20'): [%s]\n", myStr("Hello123","H20"));
  printf("\tstrstr('Hello123','H20'): [%s]\n\n", strstr("Hello123","H20"));
  
  return 0;
}
