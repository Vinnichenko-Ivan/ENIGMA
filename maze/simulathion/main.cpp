#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <time.h> 
#include <unistd.h>
#include <vector>

using namespace std;
#include "cordinate.hpp"
#include "myAngleRotate.hpp"
#include "loger.hpp"
#include "memoryCordinate.hpp"
#include "area.hpp"
#include "WallAround.hpp"
#include "cell.hpp"

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
	//wallNear=checkWall();
	//bufferCell=newCell(wallNear,memory);
	//addCell(fieldInMemory,bufferCell);
}

void goBack()
{
	field.goBack();
	memory.goBack();
	actions.addElement('B');
	//wallNear=checkWall();
	//bufferCell=newCell(wallNear,memory);
	//addCell(fieldInMemory,bufferCell);
}

int main()
{

	wallNear=checkWall();
	bufferCell=newCell(wallNear,memory);
	addCell(fieldInMemory,bufferCell);
	cout<<(int)(memory.iStayInLeftCordinate()||wallNear.wallLeft)<<(int)(memory.iStayInForwardCordinate()||wallNear.wallForward)<<(int)(memory.iStayInRightCordinate()||wallNear.wallRight)<<(int)(memory.iStayInBackCordinate()||wallNear.wallBack)<<endl;
	
	//while(1){}
	while(1)
	{
		wallNear=checkWall();
		actions.display();
		if(wallNear.wallForward==0&&memory.iStayInForwardCordinate()==0)
		{
			if(memory.iStayInLeftCordinate()==0&&wallNear.wallLeft==0)
			{
				memory.targetLeft();
			}

			if(memory.iStayInRightCordinate()==0&&wallNear.wallRight==0)
			{
				memory.targetRight();
			}

			if(memory.iStayInBackCordinate()==0&&wallNear.wallBack==0)
			{
				memory.targetBack();
			}

			goForward();
		}

		else if(((int)(memory.iStayInLeftCordinate()||wallNear.wallLeft)+(int)(memory.iStayInForwardCordinate()||wallNear.wallForward)+(int)(memory.iStayInRightCordinate()||wallNear.wallRight)+(int)(memory.iStayInBackCordinate()||wallNear.wallBack))==4)
		{
			//cordinate target=memory.getNearTarget();
			//cout<<target.x<<" : "<<target.y<<endl;
			char a=actions.getElement();
			actions.deleteElement();
			if(a=='F')
			{
				goBack();
				actions.deleteElement();
			}
			else if(a=='R')
			{
				turnLeft();
				actions.deleteElement();
			}
			else if(a=='L')
			{
				turnRight();
				actions.deleteElement();
			}
			else if(a=='B')
			{
				goForward();
				actions.deleteElement();
			}
			if(memory.myCordinateX==0&&memory.myCordinateY==0)
			{
				field.draw();
				return 0;
			}

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
