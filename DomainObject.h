class DomainObject
{
	private:
	char* name;

public:
	DomainObject() {}
	DomainObject(char value[]) : name(value) {}
	~DomainObject() {}
	void setName(char value[]) {name = value;}
	char* getName(void) {return name;}
};
