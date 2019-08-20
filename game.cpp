#include <bits/stdc++.h>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
int r,c;
bool draw = false;
void display_board()
{   
	system("cls");
    cout<<"\n\nTICK TAC TOE GAME"<<endl;
	cout<<"\tPlayer1 [X] \n \tPlayer2 [O]\n";
    cout<<endl<<endl;
	cout<<"\t\t\t     |     |     \n";
	cout<<"\t\t \t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
	cout<<"\t\t\t_____|_____|_____\n";
	cout<<"\t\t\t     |     |     \n";
	cout<<"\t\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
	cout<<"\t\t\t_____|_____|_____\n";
	cout<<"\t\t\t     |     |     \n";
	cout<<"\t\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
	cout<<"\t\t\t     |     |     \n";

}
void player_turn()
{   

	int choice;
    if(turn =='X')
		cout<<"\n\tPlayer1 [X] turn:";
	else if(turn =='O')
		cout<<"\n\tPlayer2 [O] turn:";
	cin>>choice;

	switch(choice){
	  case 1: r=0;c=0;break;
	  case 2: r=0;c=1;break;
	  case 3: r=0;c=2;break;
	  case 4: r=1;c=0;break;
	  case 5: r=1;c=1;break;
	  case 6: r=1;c=2;break;
	  case 7: r=2;c=0;break;
	  case 8: r=2;c=1;break;
	  case 9: r=2;c=2;break;
	  default:
	  cout<<"Invalid Choice"<<endl;
	  break;}

	  if(turn=='X' && board[r][c]!='X' && board[r][c]!='O')
	  {
	  	board[r][c]='X';
	  	turn='O';
	  }
	  else if(turn=='O' && board[r][c]!='O' && board[r][c]!='X')
	  {
	  	board[r][c]='O';
	  	turn='X';
	  }
	  else
	  {
	  	cout<<"Box already filled!\n Please Try Again.\n\n";
	  	player_turn();
	  }
	display_board();
}
bool gameover()
{   //to check win
	for(int i=0;i<3;i++)
    if((board[i][0]== board[i][1] && board[i][0]== board[i][2]) || (board[0][i]== board[1][i] && board[0][i]== board[2][i]))
    return false;

   // diagonal win
    
   if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0])
   	return false;


   // to check draw
   for(int i=0;i<3;i++)
   	for(int j=0;j<3;j++)
   	if(board[i][j]!='X' && board[i][j]!='O')
   	return true;
   //for draw
   draw  = true;
   return false;
}
int main()
{    
   while(gameover() && draw == false)
   {
    display_board();
    player_turn();
    gameover();
  }

  if(turn =='X' && draw == false)
  	cout<<"Player1 [O] Wins!! Congratulations \n";
  else if(turn == 'O' && draw == false)
  	cout<<"Player1 [X] Wins!! Congratulations\n";
  else
  	cout<<"Game Draw !! \n\n";
   
return 0;
} 