class OpeningState : public GarageOpenerState
{
	public:
		OpeningState(char value[]) : GarageOpenerState(value) {}
	void ReadData(GarageOpener* state) {state->setState(OpeningState("OpeningState"));}
	void ResetMotor(GarageOpener* state) {state->setState(OpeningState("OpeningState"));}
	void MoveMoter(GarageOpener* state) 
	{
		state->setState(OpenState("OpenState"));
		//state->getCMotor().MoveMotor((int)state->getCSensor().getDistance());
	}
	void DoorLatch(GarageOpener* state) {state->setState(OpeningState("OpeningState"));}
	bool Calibrate(GarageOpener* state) {state->setState(OpeningState("OpeningState"));}
};
