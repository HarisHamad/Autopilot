#include <stdio.h>
#include <stdlib.h>
#include "arducopter.h"
#include <math.h>
#include "code.h"

float lat_error[2];
float lon_error[2]; 
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

int main(int argc, char *argv[])
{
    lat_current=get_current_latitude();
     lon_current=get_current_longitude();
     lat_next=get_destination_latitude();
     lon_next=get_destination_longitude();
     
     float lat_err,lon_err;
	lat_err= lat_next - lat_current;
	lon_err= lon_next - lon_current;
  system("PAUSE");	
  return 0;
}
