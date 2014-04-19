class GarageOpener
{
	private:  
		GarageOpenerState state;
		int *data;
		CMotor motor;
		CSensor sensor;
		CDoorLatch latch;
		
	public:
		GarageOpener() { state = NULL; }
		GarageOpener(GarageOpenerState value) {state = value;}
		
	GarageOpenerState getState(void)
    {
        return state;
    }

	void setState(GarageOpenerState value)
	{
		state = value;
	}

	int* getData()
	{
		return data;
	}

	void setData(int value[])
	{
		data = value;
	}

	CMotor getCMotor()
	{
		return motor;
	}

	CSensor getCSensor()
	{
		return sensor;
	}

	CDoorLatch getCDoorLatch()
	{
		return latch;
	}

	void setCSensor(CSensor value)
	{
		sensor = value;
	}

	void setCMotor(CMotor value)
	{
		motor = value;
	}

	void setCDoorLatch(CDoorLatch value)
	{
		latch = value;
	}
};
