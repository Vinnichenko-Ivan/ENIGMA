struct cell
{
		int xTo[4]={0};
		int yTo[4]={0};
		bool whatIsTrue[4]={0};
		int x,y;
		int counter=0;
};

bool cellEqualityCordinate(cell a,cell b)
{
	return (a.x==b.x && a.y==b.y);
}

void addCell(vector<cell> fieldInMemory,cell bufferCell)
{
	bool equality=1;
	for(int i =0;i<fieldInMemory.size();i++)
	{
		if(cellEqualityCordinate(fieldInMemory[i],bufferCell))
		{
			equality=0;
		}
	}
	if(equality)
	{
		fieldInMemory.push_back(bufferCell);
	}
}

int findCellOnCordinate(vector<cell> fieldInMemory,int x,int y)
{
	cell buffCell;
	buffCell.x=x;
	buffCell.y=y;
	for(int i =0;i<fieldInMemory.size();i++)
	{
		if(cellEqualityCordinate(fieldInMemory[i],buffCell))
		{
			return i;
		}
	}
}

string path(int xIn,int yIn,int xOut,int yOut,vector<cell> fieldInMemory)
{
	
}

cell newCell(WallAround wallAroundIn,memoryCordinate memory)
{
	cell bufferCell;
	bufferCell.x=memory.myCordinateX;
	bufferCell.y=memory.myCordinateY;
	if(wallAroundIn.wallForward==0)
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

	if(wallAroundIn.wallBack==0)
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

	if(wallAroundIn.wallLeft==0)
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

	if(wallAroundIn.wallRight==0)
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
	return bufferCell;
}