class ClosingState : public GarageOpenerState
{
	public:
		ClosingState(char value[]) : GarageOpenerState(value) {}
	void ReadData(GarageOpener* state) {state->setState(ClosingState("ClosingState"));}
	void ResetMotor(GarageOpener* state) {state->setState(ClosingState("ClosingState"));}
	void MoveMoter(GarageOpener* state) 
	{
		state->setState(CloseState("CloseState"));
		CMotor motor = state->getCMotor();
		motor.MoveMotor(0);
		state->setCMotor(motor);
		CDoorLatch latch = state->getCDoorLatch();
		latch.setLatchState(true);
		state->setCDoorLatch(latch);
	}
	void DoorLatch(GarageOpener* state) {state->setState(OpeningState("ClosingState"));}
	bool Calibrate(GarageOpener* state) {state->setState(ClosingState("ClosingState"));}
};
