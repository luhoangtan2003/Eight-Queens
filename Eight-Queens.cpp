#include<bits/stdc++.h>
using namespace std;

#define SIZE 8

int Queens[SIZE];

int Can_Put_Queens(int Rows, int Cols){
    for(int i=0;i<Rows;i++){
        if(Queens[i] == Cols || abs(i-Rows) == abs(Queens[i]-Cols)){
            return 0;
        }
    }
    return 1;
}
void Show_Queens(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(Queens[i] == j){
                printf("Q ");
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("Bạn có muốn xem tiếp không?(1 to comtinue or any to exit):\n");
    int A;
    scanf("%d",&A);
    if(A != 1){
        exit(1);
    }
}

void Put_Queens(int Rows){
    for(int Cols=0;Cols<SIZE;Cols++){
        if(Can_Put_Queens(Rows,Cols)){
            Queens[Rows] = Cols;
            if(Rows == SIZE-1){
                Show_Queens();
            }else{
                Put_Queens(Rows+1);
            }
            Queens[Rows] = 0;
        }
    }
}

int main(int argc, char const *argv[]){
    Put_Queens(0);
}