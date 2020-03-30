class log
{
	private:
		string log="";
		int lenght=0;	
	public:	
		void addElement(char a);
		char getElement();
		bool deleteElement();
};
	
void log::addElement(char a)
{
	log+=a;
	lenght++;
}

char log::getElement()
{
	return log[lenght-1];
}

bool log::deleteElement()
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