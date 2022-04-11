#include <iostream>
#include <cmath>
using namespace std;

#define n 100
int arr[n][2];

void initialization(){
    for(int i = 0; i<n;i++){
        for(int j = 0; j<2; j++){
            arr[i][j]=0;
        }
    }
}

void set(int value, int timeStamp){
    int i = 0;
    while(arr[i][0]!=0){
        i++;
    }
    arr[i][0] = value;
    arr[i][1] = timeStamp;
}

int get(int key, int timeStamp){
    for(int i = 0; i<n; i++){
        if(arr[i][1]==timeStamp) return arr[i][0];
        else if(timeStamp >0) get(key, timeStamp-1);
        else return -1;
    }
}

int main(){
    int key = 2;
    set(3,6);
    set(17,15);
    set(13,15);
    set(6,12);
    set(9,1);
    set(2,7);
    set(10,19);
    cout<<get(2,1)<<"\n"<<get(2,16);
}