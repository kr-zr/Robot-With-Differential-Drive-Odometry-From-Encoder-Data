# Robot-With-Differential-Drive-Odometry-From-Encoder-Data

Arduino library that builds upon an already existing Arduino Encoder library and enables one to calculate and extract linear and angular velocity of a robot with a differential drive, as well as estimate current position of the robot in (x,y) coordinates.
The example on how to update data for calculating velocity and position from encoder data is included with the library.
Other than the functions used in the example, there is also the function getCurrentRobotData(float* omega_f, float* Vx_f, float* current_x_f, float* current_y_f) which you can use to read current velocity and position of the robot.
