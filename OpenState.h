class OpenState : public GarageOpenerState
{
	public:
		OpenState(char value[]) : GarageOpenerState(value) {}
	void ReadData(GarageOpener* state) {state->setState(OpenState("OpenState"));}
	void ResetMotor(GarageOpener* state) {state->setState(OpenState("ClosingState"));}
	void MoveMoter(GarageOpener* state) {state->setState(OpenState("OpenState"));}
	void DoorLatch(GarageOpener* state){state->setState(OpenState("OpenState"));}
	bool Calibrate(GarageOpener* state) {
		state->setState(OpenState("OpenState"));
		CSensor sensor = state->getCSensor();
		sensor.Calibrate();
		state->setCSensor(sensor);
	}
};
