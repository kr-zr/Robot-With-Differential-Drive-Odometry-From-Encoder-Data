
#include "EncoderForOdom.h"
#include "dif_robot_odometry.h"


Encoder_internal_state_t * Encoder::interruptArgs[];

DiffDriveOdom::DiffDriveOdom(float FULL_ROTATION_COUNT,float Wheel_Radius, float Robot_Length, int interval_time,float starting_x, float starting_y){

        COUNTER_PER_ROTATION = FULL_ROTATION_COUNT;
        R = Wheel_Radius;
        b = Robot_Length;

        counter_lijevi = 0.0;
        counter_desni = 0.0;
        pi = 3.14156;
        interval = interval_time;

        current_x = starting_x;
        current_y = starting_y;
        omega = 0;
        Vx = 0;

        previousPosition_left = 0;
        previousPosition_right = 0;

        previousMillis = millis();
        


}

void DiffDriveOdom::getCurrentRobotData(float* omega_f, float* Vx_f, float* current_x_f, float* current_y_f){

    
            // get data from function

            *omega_f = omega;
            *Vx_f = Vx; 
            
            *current_x_f = current_x;
            *current_y_f = current_y;


}

void DiffDriveOdom::refresh_counter(float currentPosition_left_wheel,float currentPosition_right_wheel){

    float d_r;
    float d_l;
    float d_c;
    float theta;
    float omega_l;
    float omega_d;

    currentPosition_left = currentPosition_left_wheel;
    currentPosition_right = currentPosition_right_wheel;

    if (currentPosition_left!=previousPosition_left){
        counter_lijevi = counter_lijevi + currentPosition_left - previousPosition_left;
        previousPosition_left = currentPosition_left;
     }

    if (currentPosition_right!=previousPosition_right){
        counter_desni = counter_desni + currentPosition_right - previousPosition_right;
        previousPosition_right = currentPosition_right;
    }

    currentMillis = millis();
    if (currentMillis - previousMillis > interval){
    
        previousMillis = currentMillis;

        //getting angular speed of both wheels

        omega_l = (counter_lijevi/COUNTER_PER_ROTATION) * 2.0 * pi;
        omega_d = (counter_desni/COUNTER_PER_ROTATION) * 2.0 * pi;
        
        //omega and Vx of the robot

        omega = (-omega_l*R + omega_d*R)/b;
        Vx =(omega_l*R + omega_d * R)/2; 
        
        //calculate the position of the robot in (x,y) coordinates

        d_l = omega_l * R * 1;
        d_r = omega_d * R * 1;

        theta = theta + (d_r-d_l)/b;

        d_c = (d_l+d_r)/2;

        current_x = current_x + d_c * cos(theta); 
        current_y = current_y + d_c * sin(theta);

        //restartaj countere

        counter_lijevi = 0;
        counter_desni = 0;

    }


}



