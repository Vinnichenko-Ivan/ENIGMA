#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <time.h> 
#include <unistd.h>
#include <vector>

using namespace std;
#include "myAngleRotate.hpp"
#include "loger.hpp"
#include "memoryCordinate.hpp"
#include "area.hpp"
#include "WallAround.hpp"
#include "cell.hpp"
#include "cordinate.hpp"

area field(10,10);
memoryCordinate memory;
loger actions;
WallAround wallNear;
vector<cell> fieldInMemory;
cell bufferCell;
constexpr auto orange="\x1B[1;33;40m";
constexpr auto blue="\x1B[0;34;40m";
constexpr auto white="\x1B[0;0;40m";	
constexpr auto red="\x1B[0;31;40m";	
constexpr auto green="\x1B[1;32;40m";

WallAround checkWall()
{
	WallAround wallAroundIn;
	wallAroundIn.wallLeft=field.checkWallLeft();
	wallAroundIn.wallBack=field.checkWallBack();
	wallAroundIn.wallRight=field.checkWallRight();
	wallAroundIn.wallForward=field.checkWallForward();
	return wallAroundIn;
}

void display(WallAround wallAroundIn)
{
	cout<<endl<<orange;
	cout<<"╔═════════════════════════════════════╗"<<endl;
	cout<<"║wallLeft: "<<wallAroundIn.wallLeft<<"                          ║"<<endl;
	cout<<"║wallBack: "<<wallAroundIn.wallBack<<"                          ║"<<endl;
	cout<<"║wallRight: "<<wallAroundIn.wallRight<<"                         ║"<<endl;
	cout<<"║wallForward: "<<wallAroundIn.wallForward<<"                       ║"<<endl;
	cout<<"║angel: ";
	if(memory.angle.getAngle()==1)
	{
		cout<<"↑";
	}
	else if(memory.angle.getAngle()==2)
	{
		cout<<"→";
	}
	else if(memory.angle.getAngle()==3)
	{
		cout<<"↓";
	}
	else if(memory.angle.getAngle()==4)
	{
		cout<<"←";
	}		
	cout<<"                             ║"<<endl;
	cout<<"║my cordinate: ";
	string x=to_string(memory.myCordinateX),y=to_string(memory.myCordinateY);
	cout<<x<<" : "<<y;
	for(int i=x.length()+y.length();i<20;i++)
	{
		cout<<" ";
	}
	cout<<"║"<<endl;
	cout<<"╚═════════════════════════════════════╝"<<endl;
	cout<<endl<<white;
}

void turnLeft()
{
	field.turnLeft();
	memory.turnLeft();
	actions.addElement('L');
}

void turnRight()
{
	field.turnRight();
	memory.turnRight();
	actions.addElement('R');
}

void goForward()
{
	field.goForward();
	memory.goForward();
	actions.addElement('F');
	wallNear=checkWall();
	bufferCell=newCell(wallNear,memory);
	addCell(fieldInMemory,bufferCell);
}

void goBack()
{
	field.goBack();
	memory.goBack();
	actions.addElement('B');
	wallNear=checkWall();
	bufferCell=newCell(wallNear,memory);
	addCell(fieldInMemory,bufferCell);
}

int main()
{

	wallNear=checkWall();
	bufferCell=newCell(wallNear,memory);
	addCell(fieldInMemory,bufferCell);

	while(1)
	{
		wallNear=checkWall();
		if(wallNear.wallForward==0&&memory.iStayInForwardCordinate()==0)
		{
			goForward();
		}
		else
		{
			turnLeft();
		}
		field.draw();
		display(wallNear);
		usleep(100000);
	}

	// xrobot=rand()%x;
	// yrobot=rand()%y;
	// generate();
	// //test();
	// algorithm();
	//cout<<rand()%2<<"\x1B[0;2;40m"<<endl<<algorithmLogfile<<endl;
    return 0;
}
