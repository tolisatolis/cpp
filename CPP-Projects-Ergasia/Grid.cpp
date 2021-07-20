#include <iostream>
#include "Classes.h"
using namespace std;

////////////////////////////////////////////
////////////////////////////////////////////Grid
////////////////////////////////////////////

Grid::Grid()
{
	for(int i=0; i<6; i++)
		for(int j=0; j<10; j++)
			grid[i][j] = 'O';
		
	grid[0][0] = 'X';
	grid[0][2] = 'U';
	grid[0][6] = 'M';
	grid[0][9] = 'U';
	grid[1][2] = 'M';
	grid[1][5] = 'U';
	grid[1][7] = 'U';
	grid[2][0] = 'U';
	grid[2][1] = 'M';
	grid[2][2] = 'U';
	grid[2][8] = 'U';
	grid[3][5] = 'U';
	grid[3][7] = 'U';
	grid[4][1] = 'U';
	grid[4][3] = 'M';
	grid[4][7] = 'M';
	grid[5][3] = 'U';
	grid[5][7] = 'U';
	
	x=0;
	y=0;
	previous = 'O';
}
	
Grid::~Grid()
{}

void Grid::displayMap()
{
	cout<<"Map:"<<endl;
	
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<10; j++)
			cout<<grid[i][j]<<" ";
		cout<<endl;
	}
}
		
char Grid::Move(char c)
{
	
	char temp;
	
	switch(c)
	{
		case 'W':
		case 'w':
			if(x==0 || grid[x-1][y] == 'U')
			{
				cout<<"You can't go there (Out of Map)"<<endl;
				return 'U';
			}
			else
			{
				temp = grid[x-1][y];
				grid[x-1][y] = 'X';
				grid[x][y] = previous;
				x--;
				previous = temp;
				return previous;
			}
		case 'A':
		case 'a':
			if(y==0 || grid[x][y]-1 == 'U')
			{
				cout<<"You can't go there (Out of Map)"<<endl;
				return 'U';
			}
			else
			{	
				temp = grid[x][y-1];
				grid[x][y-1] = 'X';
				grid[x][y] = previous;
				y--;
				previous = temp;
				return previous;
			}
		case 'S':
		case 's':
			if(x==5 || grid[x+1][y] == 'U')
			{
				cout<<"You can't go there (Out of Map)"<<endl;
				return 'U';
			}
			else
			{
				temp = grid[x+1][y];
				grid[x+1][y] = 'X';
				grid[x][y] = previous;
				previous = temp;
				x++;
				return previous;
			}
		case 'D':
		case 'd':
			if(y==9 || grid[x][y+1] == 'U')
			{
				cout<<"You can't go there (Out of Map)"<<endl;
				return 'U';
			}
			else
			{
				temp = grid[x][y+1];
				grid[x][y+1] = 'X';
				grid[x][y] = previous;
				previous = temp;
				y++;
				return previous;
			}				
		default:
			return c;
	}
}

