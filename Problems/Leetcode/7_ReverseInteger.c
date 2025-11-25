#include<stdio.h>

int reverse(int x){
    int num = x, rem;
    int result = 0;
    while (num != 0 ){
        rem = num % 10;
        num /= 10;

        if (result > 214748364 || (result == 214748364 && rem > 7)) return 0;
        if (result < -214748364 || (result == -214748364 && rem < -8)) return 0;

        result = (result * 10) + rem;
    }
    return result;
}

int main() {
    printf("%d", reverse(2434));

    return 0;
}