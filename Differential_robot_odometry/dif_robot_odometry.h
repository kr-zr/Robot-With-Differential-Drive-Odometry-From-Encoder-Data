#ifndef dif_robot_odometry_h_
#define dif_robot_odometry_h_

#include "Arduino.h"




class DiffDriveOdom{

    public: 
        
        DiffDriveOdom(float FULL_ROTATION_COUNT,float Wheel_Radius, float Robot_Length, int interval_time,float starting_x, float starting_y);
        void refresh_counter(float currentPosition_left_wheel,float currentPosition_right_wheel);
        void getCurrentRobotData(float* omega_f, float* Vx_f, float* current_x_f, float* current_y_f);
     

    private:
        
        float COUNTER_PER_ROTATION;
        float R; 
        float b;
        float pi;
        long previousMillis;
        long currentMillis;
        float counter_lijevi;
        float counter_desni;
        int interval;

        float omega;
        float Vx;
        float current_x;
        float current_y;

        float previousPosition_left;
        float previousPosition_right;
        float currentPosition_left;
        float currentPosition_right;



      
};

#endif
