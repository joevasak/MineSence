class CloseState : public GarageOpenerState
{
	public:
		CloseState(char value[]) : GarageOpenerState(value) {}
	void ReadData(GarageOpener* state)
	{
		if(state->getCDoorLatch().getLatchState() == true)
		{
			state->setState(OpeningState("OpeningState"));
			CSensor sensor = state->getCSensor();
			sensor.ReadData(state->getData());
			state->setCSensor(sensor);
			CDoorLatch latch = state->getCDoorLatch();
			latch.setLatchState(false);
			state->setCDoorLatch(latch);
		}
	}
	void ResetMotor(GarageOpener* state) {state->setState(CloseState("CloseState"));}
	void MoveMoter(GarageOpener* state) {state->setState(CloseState("CloseState"));}
	void DoorLatch(GarageOpener* state) {state->setState(CloseState("CloseState"));}
	bool Calibrate(GarageOpener* state) {state->setState(CloseState("CloseState"));}
};
