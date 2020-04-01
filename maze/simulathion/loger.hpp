class loger
{
	private:
		string log="";
		int lenght=0;	
	public:	
		void addElement(char a);
		char getElement();
		bool deleteElement();
		void display();
};
	
void loger::addElement(char a)
{
	log+=a;
	lenght++;
}

void loger::display()
{
	cout<<endl<<log<<endl;
}

char loger::getElement()
{
	if(lenght>=1)
	{
		return log[lenght-1];
	}
	else{
		return 'N';
	}
}

bool loger::deleteElement()
{
	if(lenght>=1)
	{
		log.pop_back();
		lenght--;
	}
	else
	{
		return 0;
	}
	return 1;
}