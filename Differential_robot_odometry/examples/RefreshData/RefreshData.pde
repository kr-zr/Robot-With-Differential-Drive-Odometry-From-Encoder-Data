#include <EncoderForOdom.h>
#include <dif_robot_odometry.h>

float COUNTER_PER_ROTATION = 1632.0, R=0.03875, b = 0.323; //robot/wheel specs
int interval = 1000;

Encoder lijevi(2,6);
Encoder desni(3,7);

DiffDriveOdom robot(COUNTER_PER_ROTATION,R,b,interval,0.0,0.0);    //initialization


float currentPosition_lijevi;
float currentPosition_desni;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  //read current positions from encoder
  currentPosition_lijevi = lijevi.read();
  currentPosition_desni = desni.read();

  //refresh data
  robot.refresh_counter(currentPosition_lijevi,currentPosition_desni);   //use data from encoder to update odometry info

}