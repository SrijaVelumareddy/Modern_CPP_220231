#include<stdio.h>

union performance {
    char grade;
    float percent;
};

int main(){
    union performance u1;
    u1.grade = 'A'; //percent part is undefined behaviour, don't access

    printf("%c\n" , u1.grade);

    u1.percent = 91.f; //grade part is undefined behaviour, don't access

    printf("%.3f", u1.percent);
}