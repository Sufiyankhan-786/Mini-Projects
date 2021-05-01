#include<bits/stdc++.h>
using namespace std;
char arr[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
bool draw = false;
int turn = 'X';
void display_board()
{
    system("cls");
    cout<<"\t\t  T I C   T A C "<<endl;
    cout<<endl<<endl;;
    cout<<"\t      |      |      \n";
    cout<<"\t  "<<arr[0][0]<<"   |  "<<arr[0][1]<<"   |  "<<arr[0][2]<<"    \n";
    cout<<"\t______|______|______\n";
    cout<<"\t      |      |      \n";
    cout<<"\t  "<<arr[1][0]<<"   |  "<<arr[1][1]<<"   |  "<<arr[1][2]<<"    \n";
    cout<<"\t______|______|______\n";
    cout<<"\t      |      |      \n";
    cout<<"\t  "<<arr[2][0]<<"   |  "<<arr[2][1]<<"   |  "<<arr[2][2]<<"    \n";
    cout<<"\t      |      |      \n";

}
bool check()
{
    if ((arr[0][0]==arr[0][1] && arr[0][1]==arr[0][2]) || (arr[1][0]==arr[1][1] && arr[1][1]==arr[1][2]) || (arr[2][0]==arr[2][1] && arr[2][1]==arr[2][2]) ||
        (arr[0][0]==arr[1][0] && arr[1][0]==arr[2][0]) || (arr[0][1]==arr[1][1] && arr[1][1]==arr[2][1]) || (arr[0][2]==arr[1][2] && arr[1][2]==arr[2][2]) ||
        (arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2]) || (arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0]))
    {
        return false;
    }
  
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != 'X' && arr[i][j] !='O')
            {
                return true;
            }
        }
    }
    draw = true;
    return false;
}
void player_turn()
{
    
    int row;
    int column;
    if (turn == 'X')
    {
        cout<<"player 1 [X]";
    }
    else if (turn == 'O')
    {
        cout<<"player 2 [O]";
    }
    
    char choice;
    cin>>choice;
    switch (choice)
    {
        case '1': row = 0; column = 0;break; 
        case '2': row = 0; column = 1;break;
        case '3': row = 0; column = 2;break;
        case '4': row = 1; column = 0;break;
        case '5': row = 1; column = 1;break;
        case '6': row = 1; column = 2;break;
        case '7': row = 2; column = 0;break;
        case '8': row = 2; column = 1;break;
        case '9': row = 2; column = 2;break;
        
        default:
        cout<<"invalid choice\n";
        break;
    }
    if (turn == 'X' && arr[row][column]!='X' && arr[row][column]!='O')
    {
        arr[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O'&& arr[row][column]!='X' && arr[row][column]!='O')
    {
        arr[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout<<"BOX is already filled\nPlease try again\n!";
        player_turn();
    }
}
int main()
{
    display_board();
    while (check())
    {
        check();
        player_turn();
        display_board();
    }
    if (draw)
    {
        cout<<"\tMATCH IS DRAW !!!\n\tBETTER LUCK NEXT TIME!";
    }
    else if (turn == 'O')
    {
        cout<<"CONGRATULATION PLAYER 1 : WIN THE MATCH";
    }
    else if (turn == 'X')
    {
        cout<<"CONGRATULATION PLAYER 2 : WIN THE MATCH";
    }
    return 0;
}