#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
//written by Tran Duy Khanh
int is_integer(char a[100]){
    if (a==NULL){
        return -1;
    }
    for (int i=0; i<strlen(a)-1; i++){
        if (isdigit(a[i])){
            continue;
        }else{
            return 2;
        }
    }
    if (atoi(a)>=100){
        return 3;
    }
    if ((strlen(a)-1)>8){
        return 4;
    }
    return 1;
}

int is_triangle(int a, int b, int c){
    if (a+b>c&&b+c>a&&c+a>b){
        return 1;
    } else {
        return -1;
    }
}
int is_equilateral_triangle(int a, int b, int c){
    if (a==b&& b==c){
        return 1;
    } else{
        return 2;
    }
}
int is_right_triangle(int a, int b, int c){
    if ((a*a)+(b*b)==(c*c)||(b*b)+(c*c)==(a*a)||(c*c)+(a*a)==(b*b)){
        return 1;
    } else{
        return 2;
    }
}
int is_isosceles_triangle(int a, int b, int c){
    if (a==b||b==c||c==a){
        return 1;
    } else {
        return 2;
    }
}
int main(void){
    char a[100]="";
    char b[100]="";
    char c[100]="";
    //side a
    printf("Input three sides:> ");
    printf("\na:");
    fgets(a, sizeof a, stdin);
    if (is_integer(a)==-1||is_integer(a)==2||is_integer(a)==3||is_integer(a)==4){
        printf("[ERROR], the side must be integer from equal 1 to less than 100");
        return 0;
    }
    //side b
    printf("\nb:");
    fgets(b, sizeof b, stdin);
    if (is_integer(b)==-1||is_integer(b)==2||is_integer(b)==3||is_integer(a)==4){
        printf("[ERROR], the side must be integer from equal 1 to less than 100");
        return 0;
    }
    //side c
    printf("\nc:");
    fgets(c, sizeof c, stdin);
    if (is_integer(c)==-1||is_integer(c)==2||is_integer(c)==3||is_integer(a)==4){
        printf("[ERROR], the side must be integer from equal 1 to less than 100");
        return 0;
    }
    
    //check is_triangle
    is_triangle(atoi(a), atoi(b), atoi(c));
    if (is_triangle(atoi(a), atoi(b), atoi(c))==-1){
        printf("[ERROR], this is not triangle");
        return 0;
    }
    
    // check equilateral triangle
    if (is_equilateral_triangle(atoi(a), atoi(b), atoi(c))==1){
        printf("This is equilateral triangle");
        return 0;
    }
    
    // check right triangle
    if (is_right_triangle(atoi(a), atoi(b), atoi(c))==1){
        printf("This is right triangle");
        return 0;
    }
    
    //check isosceles triangle
    
    if (is_isosceles_triangle(atoi(a), atoi(b), atoi(c))==1){
        printf("This is isosceles triangle");
        return 0;
    }
    printf("This is scalene triangle");
    return 0;
}