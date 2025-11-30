#include <stdio.h>
#include <stdlib.h>

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    int pos = 0;
    while (pos < target) {
        for (int i = 0; i < positionSize; i++){
            if (position[i]<target){
                position[i] += speed[i];
            }
        }
    }
    
}

int main(){
    int target = 12, size = 5;
    int arr[5] = {10,8,0,5,3};
    int spe[5] = {2,4,1,1,3};

    printf("Number of car fleets: %d\n", carFleet(target, arr, size, spe, size));

    return  0;
}