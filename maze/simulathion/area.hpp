class area
{
	private:
		string orange="\x1B[1;33;40m";
		string blue="\x1B[0;34;40m";
		string white="\x1B[0;0;40m";	
		string red="\x1B[0;31;40m";	
		string green="\x1B[1;32;40m";
		string magneta="\x1b[35;40m";
		string cyan="\x1b[36;40m";
		myAngleRotate angle;
		int x,y;
		int buff;
		int myCordinateX=0,myCordinateY=0,X,Y;
		void generate();
		void check();
		vector<vector<vector<double>>> zone;
	public:
		area(int xIn, int yIn);
		void draw();
		bool turnLeft();
		bool goForward();
		bool turnRight();
		bool goBack();
		bool checkWallLeft();
		bool checkWallBack();
		bool checkWallRight();
		bool checkWallForward();
};

area::area(int xIn, int yIn)
{
	srand( time(0) );
	x=xIn;
	y=yIn;
	zone.resize(x);
	for (int i = 0; i < x; ++i) 
	{
    	zone[i].resize(y);     	
     	for (int j = 0; j < y; ++j)
     	{
        	zone[i][j].resize(6);
     	}
 	}
 	generate();
 	myCordinateX=rand()%x;
 	myCordinateY=rand()%y;
 	X=myCordinateX;
 	Y=myCordinateY;
 	zone[myCordinateX][myCordinateY][0]=3;
}

bool area::turnLeft()
{
	angle.turnLeft();
	return 1;
}

bool area::turnRight()
{
	angle.turnRight();
	return 1;
}

bool area::goBack()
{
	if(checkWallBack()==0)
	{
		zone[myCordinateX][myCordinateY][0]=1;
		if(angle.getAngle()==1)
		{
			myCordinateY++;
		}

		else if(angle.getAngle()==2)
		{
			myCordinateX--;
		}

		else if(angle.getAngle()==3)
		{
			myCordinateY--;
		}

		else if(angle.getAngle()==4)
		{
			myCordinateX++;
		}
		zone[myCordinateX][myCordinateY][0]=2;
	}
	else
	{
		cout<<"error";
		while(1){}
	}
}

bool area::goForward()
{
	if(checkWallForward()==0)
	{
		zone[myCordinateX][myCordinateY][0]=1;
		if(angle.getAngle()==1)
		{
			myCordinateY--;
		}

		else if(angle.getAngle()==2)
		{
			myCordinateX++;
		}

		else if(angle.getAngle()==3)
		{
			myCordinateY++;
		}

		else if(angle.getAngle()==4)
		{
			myCordinateX--;
		}
		zone[myCordinateX][myCordinateY][0]=2;
	}
	else
	{
		cout<<"error";
		while(1){}
	}
}

void area::generate()
{
	for(int xi=0;xi<x;xi++)
	{
		for(int yi=0;yi<y;yi++)
		{
			buff=rand()%2;
			zone[xi][yi][rand()%4+1]=1;
		}
	}
	 for(int xi=0;xi<x;xi++)
	 {
	 	for(int yi=0;yi<y;yi++)
	 	{
			for(int n=1;n<5;n++)
			{
				if(n==1&&yi>0)
				{
					zone[xi][yi-1][3]=zone[xi][yi][1];
				}
				else if(n==2&&xi<x-1)
				{
					zone[xi+1][yi][4]=zone[xi][yi][2];
				}
				else if(n==3&&yi<y-1)
				{
					zone[xi][yi+1][1]=zone[xi][yi][3];
				}
				else if(n==4&&xi>0)
				{
					zone[xi-1][yi][2]=zone[xi][yi][4];
				}
			}
		}		
	}
	for(int ix=0;ix<x;ix++)
	{
		zone[ix][0][1]=1;
	}
	for(int ix=0;ix<x;ix++)
	{
		zone[ix][y-1][3]=1;
	}
	for(int yx=0;yx<y;yx++)
	{
		zone[0][yx][4]=1;
	}
	for(int yx=0;yx<y;yx++)
	{
		zone[x-1][yx][2]=1;
	}
}

void area::draw()
{
	system("clear");	
	zone[X][Y][0]=3;
	check();
	for(int yi=0;yi<y;yi++)
	{
		for(int xi=0;xi<x;xi++)
		{
			if(zone[xi][yi][4]==1)
			{
				cout<<blue<<1<<white;
			}
			else
			{
				if(zone[xi][yi][1])
				{
					cout<<blue<<1<<white;
				}
				else
				{
					cout<<zone[xi][yi][1];
				}
			}
			if(zone[xi][yi][1])
			{
				cout<<blue<<1<<white;
			}
			else
			{
				cout<<zone[xi][yi][1];
			}
			if(zone[xi][yi][2]==1)
			{
				cout<<blue<<1<<white;
			}
			else
			{
				if(zone[xi][yi][1])
				{
					cout<<blue<<1<<white;
				}
				else
				{
					cout<<zone[xi][yi][1];
				}
			}
		}
		cout<<endl;
		for(int xi=0;xi<x;xi++)
		{
			if(zone[xi][yi][4])
			{
				cout<<blue<<1<<white;
			}
			else
			{
				cout<<zone[xi][yi][4];
			}
			if(zone[xi][yi][0]==0)
			{
				cout<<red<<zone[xi][yi][0]<<white;
			}
			else if(zone[xi][yi][0]==1)
			{
				cout<<orange<<zone[xi][yi][0]<<white;
			}
			else if(zone[xi][yi][0]==2)
			{
				cout<<green<<zone[xi][yi][0]<<white;
			}
			else
			{
				cout<<cyan<<zone[xi][yi][0]<<white;
			}
			if(zone[xi][yi][2])
			{
				cout<<blue<<1<<white;
			}
			else
			{
				cout<<zone[xi][yi][2];
			}
		}
		cout<<endl;
		for(int xi=0;xi<x;xi++)
		{
			if(zone[xi][yi][4]==1)
			{
				cout<<blue<<1<<white;
			}
			else{
				if(zone[xi][yi][3])
				{
					cout<<blue<<1<<white;
				}
				else
				{
					cout<<zone[xi][yi][3];
				}
			}
			if(zone[xi][yi][3])
			{
				cout<<blue<<1<<white;
			}
			else
			{
				cout<<zone[xi][yi][3];
			}
			if(zone[xi][yi][2]==1)
			{
				cout<<blue<<1<<white;
			}
			else
			{
				if(zone[xi][yi][3])
				{
					cout<<blue<<1<<white;
				}
				else
				{
					cout<<zone[xi][yi][3];
				}
			}
		}
		cout<<endl;
	}
	cout<<myCordinateX<<" : "<<myCordinateY<<endl;
}

void area::check()
{
	zone[myCordinateX][myCordinateY][0]=2;
}

bool area::checkWallForward()
{
	return zone[myCordinateX][myCordinateY][angle.getAngle()];
}

bool area::checkWallLeft()
{
	if(angle.getAngle()==1)
	{
		return zone[myCordinateX][myCordinateY][4];
	}
	else
	{
		return zone[myCordinateX][myCordinateY][angle.getAngle()-1];
	}
}

bool area::checkWallRight()
{
	if(angle.getAngle()==4)
	{
		return zone[myCordinateX][myCordinateY][1];
	}
	else
	{
		return zone[myCordinateX][myCordinateY][angle.getAngle()+1];
	}
}

bool area::checkWallBack()
{
	if(angle.getAngle()==1||angle.getAngle()==2)
	{
		return zone[myCordinateX][myCordinateY][angle.getAngle()+2];
	}
	else
	{
		return zone[myCordinateX][myCordinateY][angle.getAngle()-2];	
	}
}
