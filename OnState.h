class OnState : public GarageOpenerState
{
	public:
	OnState(char value[]) : GarageOpenerState(value) {} 
	void ReadData(GarageOpener* state) {state->setState(OnState("OnState"));}
	void ResetMotor(GarageOpener* state) {state->setState(OnState("OnState"));}
	void MoveMoter(GarageOpener* state) {state->setState(OnState("OnState"));}
	void DoorLatch(GarageOpener* state)
	{ 
		if(state->getCDoorLatch().getLatchState() == true) 
		{state->setState(CloseState("CloseState"));}
		else {state->setState(OpenState("OpenState"));}
	};
	bool Calibrate(GarageOpener* state) {
		state->setState(OnState("OnState"));
		CSensor sensor = state->getCSensor(); 
		sensor.Calibrate();
		state->setCSensor(sensor);
		return true;
	};
	char* toString() {return "On State";}

};
