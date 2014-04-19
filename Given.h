class CSensor
{
private:
	float distance;
	int dataLenght;
	bool calibrate;
public:
	CSensor() 
	{
		distance = 0;
		dataLenght = 0;
	}
  bool Calibrate() // calibrates the sensor
  {
	 calibrate = true;
	  return true;
  }
  void ReadData(int data[]) // Reads the data from the sensor
  {
	  for(int i=0;i<dataLenght; i++)
	  {
		  distance = distance + (float) data[i];
	  }
	  distance = distance / dataLenght;
  }
  float getDistance()
  {
	  return distance;
  }
  int getDataLenght()
  {
	  return dataLenght;
  }
  void setDataLenght(int value)
  {
	  dataLenght = value;
  }
  void printSensorStatus()
  {
	   std::cout << "Sensor is ";
	   if(calibrate == true) {std::cout << "calibrated" << std::endl;}
	  else {std::cout << "not calibrated: error" << std::endl;}
  }
  void printDistanceStatus()
  {
	   std::cout << "Distance is " << distance << std::endl;
  }
};

class CMotor
{
public:
	CMotor() {}
  void ResetMotor(); // moves motor to the starting position
  void MoveMotor(int distance); // Moves motor to the measurement position
};

class CDoorLatch
{
private:
	bool latchState;
public:
	CDoorLatch() {}
  bool getLatchState(void) // determines the state of the door if ture door closed
  {
	  return latchState;
  }
  void setLatchState(bool value)
  {
	  latchState = value;
  }
  void printStatus(void)
  {
	  std::cout << "Door latch is ";
	  if(latchState == true) {std::cout << "closed" << std::endl;}
	  else {std::cout << "open" << std::endl;}
  }
};
