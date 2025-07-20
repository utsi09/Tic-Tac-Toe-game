#include <stdio.h>
#include <iostream>
using namespace std;

int board[3][3] = {0};

// 놓을 수 있는 자리를 표시
void select_board(int n=0){
    int select=1;
    for(int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if(board[i][j]==1){
                cout<<"A ";
                continue;
            }
            else if(board[i][j]==2){
                cout<<"B ";
                continue;
            }
            else if(board[i][j]==0){
                if(n!=0 && select==n){
                    board[i][j] = 1;
                    return;
                }   
                else{
                    cout<<select<<" ";
                    select++;
                    continue;
                }
            }
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout << "---------\n";
    
}

void print_board(){
    for(int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (board[i][j] == 1){
                //플레이어면 
                cout <<"A ";
            }
            else if (board[i][j] == 2){
                //봇이면 
                cout <<"B ";
            }
            else{
                cout<<"O ";
            }
        }
        cout<<"\n";
    }
    cout << "---------\n";

}

int end_game(){
    // 가로
    for (int i=0; i<3; i++){
        if (board[i][0] != 0 &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            if (board[i][0] == 1) printf("player Horizontal bingo!\n");
            else printf("bot Horizontal bingo!\n");
            return 1;
        }
    }

    // 세로
    for (int i=0; i<3; i++){
        if (board[0][i] != 0 &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i]) {
            if (board[0][i] == 1) printf("player Vertical bingo!\n");
            else printf("bot Vertical bingo!\n");
            return 1;
        }
    }

    // 대각선
    if (board[0][0] != 0 &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        if (board[0][0] == 1) printf("player Diagonal bingo!\n");
        else printf("bot Diagonal bingo!\n");
        return 1;
    }

    if (board[0][2] != 0 &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        if (board[0][2] == 1) printf("player Diagonal bingo!\n");
        else printf("bot Diagonal bingo!\n");
        return 1;
    }

    return 0;
}


void play_bot(){
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++){
            if(board[i][j]==0){
                board[i][j]=2;
                return;
            }
        }
    }
}

void play_game(){
    do{
        //플레이어는 A 봇은 B 선택은 숫자 // 출력이 아닌 저장은 1 , 2
        int select=1;
        print_board();
        printf("where do you want to put?\n");
        select_board(); //선택 영역 확인
        cin>>select;
        select_board(select); //선택 영역 적용
        play_bot();
    }while(end_game() != 1);

    cout<<"game is end"<<"\n";
}


int main(){
    play_game();

}