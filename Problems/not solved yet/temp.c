#include<stdio.h>

int mySqrt(int x) {
    int comp, i = -1;
    while (comp <= x){
        i++;    
        int comp = i * i;
        if (comp == x){
            return i;
        } else if (comp > x){
            return i - 1;
        }
    }
}


int main() {
    printf("Power: %d\n", mySqrt(8));
    
    return 0;
}