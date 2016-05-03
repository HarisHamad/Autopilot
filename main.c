#include <stdio.h>
#include <stdlib.h>
#include "code.h"

float x_cord_error[2];
float y_cord_error[2]; 
float alt_error =0;
float lat_current;
float lon_current;
float lat_next;
float lon_next;


float PID(float kp,float ki, float kd,float error[2])
{     
    float P,I,D;
	P = kp*(error[1]);
	I = ki*(0.5)*(error[0]+error[1]);
	D = kd*(error[1]-error[0]);
	return P+I+D;
}

float gps_conv(float lat,float lon)
{
      float x,y;
      return x,y;
}



int main(int argc, char *argv[])
{
     float kp,ki,kd;
     kp = get_roll_kp();
     ki= get_roll_ki();
     kd = get_roll_kd();
     
     lat_current=get_current_latitude();
     lon_current=get_current_longitude();
     lat_next=get_destination_latitude();
     lon_next=get_destination_longitude();
     
     float cur_x,cur_y,dest_x,dest_y,cur_alt,desire_alt;
     
     
     
     cur_alt= get_current_altitude();
     desire_alt = get_coordinate_set_altitude();
     
     alt_error = desire_alt - cur_alt;
     
     float x_error,y_error;
     x_error = dest_x - cur_x;
	 y_error = dest_y - cur_y;
	 
	 x_cord_error[1]=x_error;
	 y_cord_error[1]=y_error;
	 
	 float roll_pid = PID(kp,ki,kd,x_cord_error);
	 float pitch_pid = PID(kp,ki,kd,y_cord_error);
     
     roll(roll_pid);
     pitch(pitch_pid);
     x_cord_error[0] = x_cord_error[1];
	 y_cord_error[0] = y_cord_error[1];
     alt_throttle(alt_error);
	 
	 
	
  system("PAUSE");	
  return 0;
}
