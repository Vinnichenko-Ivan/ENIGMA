class loger
{
	private:
		string log="";
		int lenght=0;	
	public:	
		void addElement(char a);
		char getElement();
		bool deleteElement();
};
	
void loger::addElement(char a)
{
	log+=a;
	lenght++;
}

char loger::getElement()
{
	return log[lenght-1];
}

bool loger::deleteElement()
{
	if(lenght>1)
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