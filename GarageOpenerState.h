class GarageOpenerState : public DomainObject
{
	public:
		GarageOpenerState() {}
		GarageOpenerState(char value[]) : DomainObject(value) {}
	virtual	void ReadData(GarageOpenerState state) {}
	virtual void ResetMotor(GarageOpenerState state) {}
	virtual void MoveMoter(GarageOpenerState state) {}
	virtual void DoorLatch(GarageOpenerState state) {}
}; 
