#include <stdio.h>
#include <stdlib.h>
#include "arducopter.h"
#include <math.h>

void roll(float roll_pid)
{
     float theta = 50000;
     if (roll_pid < 0)
     {
       roll_pid = -1*roll_pid;
      left_roll(theta,roll_pid);            
     }
     if (roll_pid > 0)
     {
      right_roll(theta,roll_pid);        
      }
}

void pitch(float pitch_pid)
{
      float theta = 50000;
     if (pitch_pid < 0)
     {
       pitch_pid = -1*pitch_pid;
      forward_pitch(theta,pitch_pid);            
     }
     if (pitch_pid > 0)
     {
      backward_pitch(theta,pitch_pid);        
     }
}
