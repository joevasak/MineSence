class OpeningState : public GarageOpenerState
{
	public:
		OpeningState(char value[]) : GarageOpenerState(value) {}
	void ReadData(GarageOpener* state) {state->setState(OpeningState("OpeningState"));}
	void ResetMotor(GarageOpener* state) {state->setState(OpeningState("OpeningState"));}
	void MoveMoter(GarageOpener* state) 
	{
		state->setState(OpenState("OpenState"));
		CMotor motor =  state->getCMotor();
		CSensor sensor = state->getCSensor();
		//motor.MoveMotor((int)sensor.getDistance());
		state->setCMotor(motor);
	}
	void DoorLatch(GarageOpener* state) {state->setState(OpeningState("OpeningState"));}
	bool Calibrate(GarageOpener* state) {state->setState(OpeningState("OpeningState"));}
};
