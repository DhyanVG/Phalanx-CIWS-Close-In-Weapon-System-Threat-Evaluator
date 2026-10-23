//
// Created by Dhyan Vethik Goutham on 10/22/26.
//

#include <stdio.h>
#include <time.h>

int main() {
   // Sensor Telemetry
   float slant_range;
   float altitude;
   float closing_velocity;
   float radar_cross_section;
   int squawk;
   int state = 0;

   printf("Enter Range (m): ");
   scanf("%f", &slant_range);

   printf("Enter Altitude (m): ");
   scanf("%f", &altitude);

   printf("Enter Velocity (m/s): ");
   scanf("%f", &closing_velocity);

   printf("Enter RCS (m^2): ");
   scanf("%f", &radar_cross_section);

   printf("Enter Squawk Code: ");
   scanf("%d", &squawk);


   //Kinematic & Geometric Evaluation
   float time_to_impact = slant_range / closing_velocity;

   //Elevation Angle
   float angle = altitude / slant_range;


   if (closing_velocity <= 0.0f ||  radar_cross_section < 0.05f) {
      state = 0;
      printf("HOLD FIRE (state = %d)", state);

   } else if ((squawk >= 5200 && squawk <= 5277) || squawk == 1200 || squawk == 7700){
      state = 0;
      printf("HOLD FIRE / FRIENDLY DECONFLICTION (state = %d)", state);

   } else if (slant_range < 150.0f || altitude < 2.0f || angle < 0.005f) {
      state = 3;
      printf("SAFETY INTERLOCK / ABORT (state = %d)", state);

   } else if (slant_range > 2000.0f || time_to_impact > 8.0f) {
      state = 1;
      printf("TARGET TRACK ACQUIRED (state = %d)", state);

   } else if (time_to_impact > 4.0f){
      state = 1;
      printf("TARGET TRACK ACQUIRED / ARMED (state = %d)", state);

   } else {
      state = 2;
      printf("ENGAGE: OPEN FIRE");

   }

   return 0;
}











