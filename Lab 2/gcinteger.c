#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b){
    int smaller = (a<b) ? a:b;
    int gcd = 1;
    for(int i = 2; i<= smaller; i++){
        if (a%i == 0 && b%i == 0){
            gcd = 1;
        }
    }
    return gcd;
}

int main(){
    int n1, n2;
    printf("Enter 2 numbers: ");
    scanf("%d","%d",&n1,&n2);
    printf("GCD of %d and %d is: ",n1,n2,gcd(n1,n2));
    return 0;
}