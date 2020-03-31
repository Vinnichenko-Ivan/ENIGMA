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
#include "cell.hpp"

area fild(10,10);
cell bufferCell;
memoryCordinate memory;
loger actions;
bool wallLeft,wallRight,wallBack,wallForward;
string orange="\x1B[1;33;40m";
string blue="\x1B[0;34;40m";
string white="\x1B[0;0;40m";	
string red="\x1B[0;31;40m";	
string green="\x1B[1;32;40m";
vector<cell> fildInMemory;

void checkWall()
{
	wallLeft=fild.checkWallLeft();
	wallBack=fild.checkWallBack();
	wallRight=fild.checkWallRight();
	wallForward=fild.checkWallForward();
}

void display()
{
	cout<<endl<<orange;
	cout<<"╔═════════════════════════════════════╗"<<endl;
	cout<<"║wallLeft: "<<wallLeft<<"                          ║"<<endl;
	cout<<"║wallBack: "<<wallBack<<"                          ║"<<endl;
	cout<<"║wallRight: "<<wallRight<<"                         ║"<<endl;
	cout<<"║wallForward: "<<wallForward<<"                       ║"<<endl;
	cout<<"║angel: ";
	if(memory.angle.getAngle()==1)
	{
		cout<<"↑";
	}
	if(memory.angle.getAngle()==2)
	{
		cout<<"→";
	}
	if(memory.angle.getAngle()==3)
	{
		cout<<"↓";
	}
	if(memory.angle.getAngle()==4)
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
	fild.turnLeft();
	memory.turnLeft();
	actions.addElement('L');
}

void turnRight()
{
	fild.turnRight();
	memory.turnRight();
	actions.addElement('R');
}

void goForward()
{
	fild.goForward();
	memory.goForward();
	actions.addElement('F');
}

void goBack()
{
	fild.goBack();
	memory.goBack();
	actions.addElement('B');
}

void newCell()
{
	bufferCell.x=memory.myCordinateX;
	bufferCell.y=memory.myCordinateY;
	bufferCell.numberCellNear=(int)wallForward+(int)wallLeft+(int)wallRight+(int)wallBack;
	if(wallForward==0)
	{
		bufferCell.whatIsTrue[0]=1;
		if(memory.angle.getAngle()==1)
		{
			bufferCell.yTo[0]=memory.myCordinateY-1;
		}

		else if(memory.angle.getAngle()==2)
		{
			bufferCell.xTo[0]=memory.myCordinateX+1;
		}

		else if(memory.angle.getAngle()==3)
		{
			bufferCell.yTo[0]=memory.myCordinateY+1;
		}

		else if(memory.angle.getAngle()==4)
		{
			bufferCell.xTo[0]=memory.myCordinateX-1;
		}
	}

	if(wallBack==0)
	{
		bufferCell.whatIsTrue[1]=1;
		if(memory.angle.getAngle()==1)
		{
			bufferCell.yTo[1]=memory.myCordinateY+1;
		}

		else if(memory.angle.getAngle()==2)
		{
			bufferCell.xTo[1]=memory.myCordinateX-1;
		}

		else if(memory.angle.getAngle()==3)
		{
			bufferCell.yTo[1]=memory.myCordinateY-1;
		}

		else if(memory.angle.getAngle()==4)
		{
			bufferCell.xTo[1]=memory.myCordinateX+1;
		}
	}

	if(wallLeft==0)
	{
		bufferCell.whatIsTrue[2]=1;
		if(memory.angle.getAngle()==1)
		{
			bufferCell.xTo[2]=memory.myCordinateX-1;
		}

		else if(memory.angle.getAngle()==2)
		{
			bufferCell.yTo[2]=memory.myCordinateY-1;
		}

		else if(memory.angle.getAngle()==3)
		{
			bufferCell.xTo[2]=memory.myCordinateX+1;
		}

		else if(memory.angle.getAngle()==4)
		{
			bufferCell.yTo[2]=memory.myCordinateY+1;
		}
	}

	if(wallRight==0)
	{
		bufferCell.whatIsTrue[3]=1;
		if(memory.angle.getAngle()==1)
		{
			bufferCell.xTo[3]=memory.myCordinateX+1;
		}

		else if(memory.angle.getAngle()==2)
		{
			bufferCell.yTo[3]=memory.myCordinateY+1;
		}

		else if(memory.angle.getAngle()==3)
		{
			bufferCell.xTo[3]=memory.myCordinateX-1;
		}

		else if(memory.angle.getAngle()==4)
		{
			bufferCell.yTo[3]=memory.myCordinateY-1;
		}
	}

}

int main()
{

	while(1)
	{
		checkWall();
		if(wallForward==0)
		{
			goForward();
		}
		else
		{
			turnLeft();
		}
		fild.draw();
		display();
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
