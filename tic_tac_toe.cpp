#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cstdlib>
using namespace std;
class game
{
    int i,choice,player;
    char position[9];
public:
    game()
    {
        for(i=0;i<9;i++)
         position[i]=49+i;
        player=1;
    }
    board()
    {
        fflush(stdin);
        cout<<"\n      |   |  "<<endl;
        cout<<"    "<<char(position[0])<<" | "<<position[1]<<" | "<<position[2]<<endl;
        cout<<"  ____|___|____";
        cout<<"\n      |   |  "<<endl;
        cout<<"    "<<position[3]<<" | "<<position[4]<<" | "<<position[5]<<endl;
        cout<<"  ____|___|____";
        cout<<"\n      |   |  "<<endl;
          cout<<"    "<<position[6]<<" | "<<position[7]<<" | "<<position[8]<<endl;
    }
    choices(int choice)
    {
        choice--;
        if(position[choice]!='X'&&position[choice]!='O')
        {
        if(player%2==1)
        {
            position[choice]='X';
        }
        else
        {
            position[choice]='O';
        }
        player++;
        }
        else
        {
            cout<<"already taken";
            getch();
        }
    }
    win()
    {
        if(position[0]==position[1]&&position[1]==position[2])
            return 0;
        else if(position[3]==position[4]&&position[4]==position[5])
            return 0;
        else if(position[6]==position[7]&&position[7]==position[8])
            return 0;
        else if(position[0]==position[3]&&position[3]==position[6])
            return 0;
        else if(position[1]==position[4]&&position[4]==position[7])
            return 0;
        else if(position[2]==position[5]&&position[5]==position[8])
            return 0;
        else if(position[0]==position[4]&&position[4]==position[8])
            return 0;
        else if(position[2]==position[4]&&position[4]==position[6])
            return 0;
        else
            return 1;
    }
    result()
    {
        if(win()==0)
           {
               if(player%2==0)
                cout<<"Player 1 has won";
               else
                cout<<"Player 2 has won";
               return 0;
           }
         return 1;
    }
};
int main()
{
    int choice;
    cout<<"\n   player 1 is X and player 2 is O\n";
    game p;
    p.board();
    while(p.result()){
    cout<<"\nEnter your choice: \n";
    cin>>choice;
    p.choices(choice);
    system("cls");
    p.board();
    }
    getch();
}
