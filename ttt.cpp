// preprocessors
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//board variable
char board[9]={
			   '-','-','-',
			   '-','-','-',
			   '-','-','-'
			  };
			  
//reset board		  
void resetBoard()
{
	for(int i=0;i<9;i++)
	{
		board[i]='-';
	}
}



//display board
void displayBoard()
{
	int i;
	for (i=0;i<9;i++)
	{
		if(i==1 || i==4 || i==7)
			cout<<"| "<<board[i]<<" |";
		else
			cout<<" "<<board[i]<<" ";
		if(i==2 || i==5 || i==8)
			cout<<endl;
	}
	
}
//display available positions
void availablePos()
{
	cout<<"Available positions: [";
	for (int i=0;i<9;i++)
	{
		if(board[i]=='-')
		{
			cout<<i+1<<", ";
		}
	}
	cout<<"]"<<endl;
}
//check if entered position is availabe
bool checkPos(int p)
{
	if(board[p]=='-')
		return true;
	
	return false;
}
//ask another position
void notAvailable()
{
	cout<<endl<<"Position Invalid!!! "<<endl;
	availablePos();
	
}

//check row
char checkRow()
{
	
	if(board[0]==board[1] && board[1]==board[2] && board[0]!='-')
		return board[2];	
	else if(board[3]==board[4] && board[4]==board[5] && board[3]!='-')
		return board[5];	
	else if(board[6]==board[7] && board[7]==board[8] && board[6]!='-')	
		return board[8];	
	else
		return 'a';	
}
//check winner column
char checkCol()
{
	
	if(board[0]==board[3] && board[3]==board[6] && board[0]!='-')
		return board[0];	
	else if(board[1]==board[4] && board[4]==board[7] && board[1]!='-')
		return board[1];	
	else if(board[2]==board[5] && board[5]==board[8] && board[2]!='-')	
		return board[2];	
	else
		return 'a';	
}
//check diagonal winner
char checkDia()
{
	
	if(board[0]==board[4] && board[4]==board[8] && board[0]!='-')
		return board[0];	
	else if(board[2]==board[4] && board[4]==board[6] && board[2]!='-')
		return board[2];		
	else
		return 'a';	
}
//check tie
char checkTie()
{
	int i,c=0;
	for(i=0;i<9;i++)
	{
		if(board[i]!='-')
			c++;
	}
	if(c==9)//if 9 board is full
		return 'N';
	else 
		return 'a';
}
//check winner function
char checkWin()
{
	//row
	char rw=checkRow();
	if(rw!='a')
		return checkRow();
		//col
	char cw=checkCol();
	if(cw!='a')
		return checkCol();
	//diagonal
	char dw=checkDia();
	if(dw!='a')
		return checkDia();
	//if no winner check tie
	char ct=checkTie();
	if(ct!='a')
		return checkTie();
}
//flip player
char flipPlayer(char cp)
{
	if(cp=='X')
		return 'O';
	else if(cp=='O')
		return 'X';
}



//main function
int main()
{
	char ch;
	do
	{
		system("cls");
		int xScore=0,oScore=0;
		int gameNo=1,gameCount=0;
		bool bo3Winner=false; //bo3 not finished
		char ultimateWinner;
		char cPlayer;
		cout<<"-----------------------ALU CROSS----------------------"<<endl<<endl;
		cout<<"-------------------BEST OF 3 !!!!---------------------"<<endl;
		//get starting player
		char sPlayer;
		cout<<"Who goes first?[X/O] : ";
		cin>>sPlayer;
		//current Player
		if(sPlayer=='x' || sPlayer=='X')
			cPlayer='X';
		else
			cPlayer='O';
		cout<<"         player X: "<<xScore<<"      player O: "<<oScore<<endl;
		// b03 loop
		do
		{
			
			
			
			resetBoard();
			int pos;
			
			bool avail=true;
			char winner;
			cout<<endl;
			cout<<"   GAME "<<gameNo<<endl<<endl;
			displayBoard();
			
			bool gameOn = true;
	
			
			while (gameOn)
			{
				cout<<endl;
				cout<<"Player "<<cPlayer<<"'s turn:"<<endl;
				//display available positions
				availablePos();
				//ask position
				cout<<"position[1-9]: ";
				cin>>pos;
				pos--;
				// check if place available
				avail=checkPos(pos);
				while(1)
				{
					if(avail==false)
					{
						//display not available and display available positions
						notAvailable();
						//ask another position
						cout<<"position[1-9]: ";
						cin>>pos;
						pos--;
						avail=checkPos(pos);
					}
					else if(avail==true)
					{
						break;
					}
				}
				//place mark
				board[pos]=cPlayer;
				//display updated board
				displayBoard();
				//check if game over by checking winner
				winner = checkWin();
				if(winner=='X' || winner=='O' || winner=='N')
				{	
					gameOn=false;
					break;
				}
				//flip player
				cPlayer=flipPlayer(cPlayer);	
			}
			//outside gameOn loop i.e gameOn-false
			//if win or tie check
			cout<<endl;
			if(winner=='N')
				cout<<"--------------------- (GAME "<<gameNo<<") It's a tie!!! --------------------------"<<endl;	
			else
				cout<<"---------------- Winner (GAME "<<gameNo<<") is: player "<<winner<<"!!! -------------------"<<endl;
			
			//update player score
			if(winner=='X')
				xScore++;
			else if(winner=='O')
				oScore++;
			//disply score
			cout<<"                  player X: "<<xScore<<"      player O: "<<oScore<<endl;
			//increase game no.
			gameNo++;
			//check best of 3 ends
			if(xScore==2 || oScore==2)
				bo3Winner=true;//bo3 finished
				
			
		// end do loop
		} while(gameCount<4 && bo3Winner==false);
		//display ultimate winner
		if(bo3Winner==true)
		{
			if(xScore==2)
				ultimateWinner = 'X';
			else
				ultimateWinner = 'O';
		}
		cout<<endl<<"------------------ Ultimate winner: player "<<ultimateWinner<<"--------------------------"<<endl;
		cout<<endl;
		cout<<"**************************************************************************************************"<<endl;
		cout<<endl;
		//ask to play more
		cout<<endl;
		cout<<"Do you want to play again? [y/n]: ";
		cin>>ch;
		cout<<endl;
	//end of bo3
	}while(ch=='y');
	

	
	return 0;
}

