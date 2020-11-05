#include<stdio.h>
 int N;

/*void printN1(int Nint){     //for循环实现
    int i;
    for(i = 1;i <= N; i++){
        printf("%d、", i );
    }
    printf("\n");
}*/

void printN2(int N){    //递归实现
    if(N){
        printN2(N - 1);
        printf("%d、", N );
    }
}
int main(void){
    scanf("%d" , &N);
//    printN1( N );
    printN2( N );
}