#include "autons.hpp"
#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(11, 0, 20);
  chassis.pid_drive_constants_set(20, 1, 100);
  chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  chassis.pid_swing_constants_set(6, 0, 65);

  chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
}
void skills(){
  //tasker.suspend();
  armPiston.set_value(false);
  intake.move_velocity(1200);
  pros::delay(1000);
  chassis.pid_drive_set(9_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait();
  clamper.set_value(true);
  chassis.drive_imu_reset(); 
 chassis.pid_turn_set(140_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(35_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
 chassis.pid_turn_set(-47_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(42_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
 chassis.pid_turn_set(125_deg, TURN_SPEED);
 chassis.pid_wait();
 ladyBrown.move_absolute(-80, 200);
 chassis.pid_drive_set(15_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(2000);
  
 chassis.pid_swing_set(ez::RIGHT_SWING, -50_deg, SWING_SPEED, 20);
  chassis.pid_wait();
  pros::delay(1000);
  ladyBrown.move_absolute(-350,200);
  pros::delay(2000);
  chassis.pid_drive_set(-10_in, DRIVE_SPEED);
  chassis.pid_wait();
 //tasker.resume();






}
void redFiveRing(){
armPiston.set_value(false);
chassis.pid_drive_set(-20_in, DRIVE_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(-7_in, 50);
 chassis.pid_wait();
 clamper.set_value(true);
 pros::delay(200);
 intake.move_velocity(1200);
 pros::delay(500);
 //Ring is in + goal is grabbed
 chassis.pid_turn_set(110_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(21_in, DRIVE_SPEED);
 chassis.pid_wait();
 pros::delay(500);
 //2nd ring in
 chassis.pid_drive_set(-5_in, DRIVE_SPEED);
 chassis.pid_wait();
 intake.move_velocity(1200);
 chassis.drive_imu_reset(); 
 chassis.pid_turn_set(-30_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(13_in, DRIVE_SPEED);
 chassis.pid_wait();
 pros::delay(400);
 //3rd ring in
 chassis.pid_drive_set(-13_in, DRIVE_SPEED);
 chassis.pid_wait();
 intake.move_velocity(1200);
 chassis.drive_imu_reset(); 
 chassis.pid_turn_set(-60_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(12_in, DRIVE_SPEED);
 chassis.pid_wait();
 pros::delay(800);
 //4th ring in
 chassis.drive_imu_reset(); 
 chassis.pid_turn_set(-115_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(40_in, DRIVE_SPEED);
 pros::delay(500);
 intake.move_velocity(1200);
 armPiston.set_value(true);
 chassis.pid_wait();
 armPiston.set_value(false);
 pros::delay(700);
 chassis.pid_drive_set(-5_in, DRIVE_SPEED);
 chassis.pid_wait();
 chassis.drive_imu_reset(); 
 intake.move_velocity(1200);
 chassis.pid_turn_set(-100_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(10_in, DRIVE_SPEED);
 chassis.pid_wait();
}
void blueFiveRing(){
armPiston.set_value(false);
chassis.pid_drive_set(-20_in, DRIVE_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(-7_in, 50);
 chassis.pid_wait();
 clamper.set_value(true);
 pros::delay(200);
 intake.move_velocity(1200);
 pros::delay(500);
 //Ring is in + goal is grabbed
 intake.move_velocity(1200);
 chassis.pid_turn_set(-120_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(21_in, DRIVE_SPEED);
 intake.move_velocity(1200);
 chassis.pid_wait();
 pros::delay(500);
 //2nd ring in
 chassis.pid_drive_set(-5_in, DRIVE_SPEED);
 chassis.pid_wait();
 chassis.drive_imu_reset(); 
 chassis.pid_turn_set(30_deg, TURN_SPEED);
 intake.move_velocity(1200);
 chassis.pid_wait();
 chassis.pid_drive_set(13_in, DRIVE_SPEED);
 chassis.pid_wait();
 pros::delay(400);
 //3rd ring in
 chassis.pid_drive_set(-13_in, DRIVE_SPEED);
 chassis.pid_wait();
 chassis.drive_imu_reset(); 
 chassis.pid_turn_set(60_deg, TURN_SPEED);
 chassis.pid_wait();
 intake.move_velocity(1200);
 chassis.pid_drive_set(12_in, DRIVE_SPEED);
 chassis.pid_wait();
 pros::delay(800);
 //4th ring in
 chassis.drive_imu_reset(); 
 chassis.pid_turn_set(115_deg, TURN_SPEED);
 chassis.pid_wait();
 intake.move_velocity(1200);
 chassis.pid_drive_set(40_in, DRIVE_SPEED);
 pros::delay(500);
 armPiston.set_value(true);
 chassis.pid_wait();
 armPiston.set_value(false);
 intake.move_velocity(1200);
 pros::delay(700);
 chassis.pid_drive_set(-5_in, DRIVE_SPEED);
 chassis.pid_wait();
 chassis.drive_imu_reset(); 
 chassis.pid_turn_set(100_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(10_in, DRIVE_SPEED);
 chassis.pid_wait();
}
void RedPosHalf(){
  chassis.pid_drive_set(-19_in, DRIVE_SPEED);
  chassis.pid_wait();
  clamper.set_value(true);
  chassis.pid_turn_set(-89_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-2_in, DRIVE_SPEED);
  chassis.pid_wait();
  intake.move_velocity(1200);
  pros::delay(1500);
  intake.move_velocity(0);
  chassis.pid_drive_set(4_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-150_deg, TURN_SPEED);
  chassis.pid_wait();
  clamper.set_value(false);
  chassis.pid_drive_set(-23_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, 50);
  chassis.pid_wait();
  pros::delay(800);
  clamper.set_value(true);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-140_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move_velocity(1200);
  chassis.pid_drive_set(23_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-120_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(28_in, 50);
  chassis.pid_wait();
  
}

void BlueNegAWP(){
 // tasker.suspend();
  
  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait();
  clamper.set_value(true);
  chassis.pid_turn_set(-87_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-4_in, DRIVE_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-1200);
  pros::delay(1500);
  intake.move_velocity(0);
  //Ring is in
  chassis.pid_drive_set(7_in, DRIVE_SPEED);
  chassis.pid_wait();
  clamper.set_value(false);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-145_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-25_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, 50);
  chassis.pid_wait();
  clamper.set_value(true);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-125_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-1200);
  chassis.pid_drive_set(20_in, 70);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(16_in, 70);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(47_deg, TURN_SPEED);
  chassis.pid_wait();
  pros::delay(1500);
  chassis.pid_drive_set(-5_in, 70);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-100_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, 50);
  chassis.pid_wait();
  armPiston.set_value(true);
  //tasker.resume();
  

}
void BluePos(){
  //tasker.suspend();
  
  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait();
  clamper.set_value(true);
  chassis.pid_turn_set(87_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-4_in, DRIVE_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-1200);
  pros::delay(1500);
  intake.move_velocity(0);
  //Ring is in
  chassis.pid_drive_set(7_in, DRIVE_SPEED);
  chassis.pid_wait();
  clamper.set_value(false);
  
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(145_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-25_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-14_in, 60);
  chassis.pid_wait();
  clamper.set_value(true);
  //Goal Grabbed
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(120_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-1200);
 
  chassis.pid_drive_set(20_in, 60);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(145_deg, 50);
  chassis.pid_wait();
  pros::delay(1500);
  chassis.pid_drive_set(30_in, 60);
  chassis.pid_wait();


  //tasker.resume();

}
void BlueNeg(){
 // tasker.suspend();
  
  chassis.pid_drive_set(-22_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-5_in, 50);
  chassis.pid_wait();
  
  clamper.set_value(true);
  //Goal has been picked up
  pros::delay(400);
  intake.move_velocity(-1200);
  pros::delay(800);
  //intake.move_velocity(1200);
  pros::delay(200);

  intake.move_velocity(-1200);

  //intake.move_velocity(0);
  //Ring is in
  chassis.pid_turn_set(-98_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-1200);
  chassis.pid_drive_set(8_in, 50);
  chassis.pid_wait();
  pros::delay(1500);
  //intake.move_velocity(1200);
  pros::delay(200);

  intake.move_velocity(-1200);

  //intake.move_velocity(0);
  //2nd Ring is in
  chassis.drive_imu_reset();   
  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait();
  //intake.move_velocity(600);
  pros::delay(500);
  intake.move_velocity(-1200);
  chassis.pid_drive_set(8_in, 50);
  chassis.pid_wait();
  chassis.pid_drive_set(-4_in, 50);
  chassis.pid_wait();
  //3rd Ring is in
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(8_in, 50);
  chassis.pid_wait();
  chassis.pid_drive_set(-4_in, 50);
  chassis.pid_wait();
  //4th Ring is in
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-65_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, 127);
  chassis.pid_wait();
  //tasker.resume();
  

}
void RedPos(){
 // tasker.suspend();
  
  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait();
  clamper.set_value(true);
  chassis.pid_turn_set(-87_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-4_in, DRIVE_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-1200);
  pros::delay(1500);
  intake.move_velocity(0);
  //Ring is in
  chassis.pid_drive_set(7_in, DRIVE_SPEED);
  chassis.pid_wait();
  clamper.set_value(false);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-145_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-25_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-14_in, 60);
  chassis.pid_wait();
  clamper.set_value(true);
  //Goal Grabbed
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-120_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-1200);
 
  chassis.pid_drive_set(20_in, 60);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-145_deg, 50);
  chassis.pid_wait();
  pros::delay(1500);
  chassis.pid_drive_set(30_in, 60);
  chassis.pid_wait();


 // tasker.resume();
}
void RedNeg(){
  //tasker.suspend();
  
  chassis.pid_drive_set(-22_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-5_in, 50);
  chassis.pid_wait();
  
  clamper.set_value(true);
  //Goal has been picked up
  pros::delay(400);
  intake.move_velocity(-1200);
  pros::delay(800);
  //intake.move_velocity(1200);
  pros::delay(200);

  intake.move_velocity(-1200);

  //intake.move_velocity(0);
  //Ring is in
  chassis.pid_turn_set(98_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-1200);
  chassis.pid_drive_set(8_in, 50);
  chassis.pid_wait();
  pros::delay(1500);
  //intake.move_velocity(1200);
  pros::delay(200);

  intake.move_velocity(-1200);

  //intake.move_velocity(0);
  //2nd Ring is in
  chassis.drive_imu_reset();   
  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait();
  //intake.move_velocity(600);
  pros::delay(500);
  intake.move_velocity(-1200);
  chassis.pid_drive_set(8_in, 50);
  chassis.pid_wait();
  chassis.pid_drive_set(-4_in, 50);
  chassis.pid_wait();
  //3rd Ring is in
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(8_in, 50);
  chassis.pid_wait();
  chassis.pid_drive_set(-4_in, 50);
  chassis.pid_wait();
  //4th Ring is in
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(65_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(10_in, 127);
  chassis.pid_wait();
 // tasker.resume();
}

void blueSoloSig(){
  armPiston.set_value(false);
  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-4_in, 50);
  chassis.pid_wait();
  clamper.set_value(true);
  pros::delay(200);
  intake.move_velocity(1200);
  //1st ring in
  chassis.pid_turn_set(72_deg,TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(17_in, DRIVE_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-200);
  pros::delay(200);
  intake.move_velocity(1200);
  //2nd ring in
  pros::delay(600);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-167_deg, TURN_SPEED);
  chassis.pid_wait();
  clamper.set_value(false);
  chassis.pid_wait();
  pros::delay(300);
  chassis.pid_drive_set(50_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(8_in, 50);
  chassis.pid_wait();
  pros::delay(200);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(98_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-15_in, 50);
  chassis.pid_wait();
  clamper.set_value(true);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-128_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(20_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-128_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(22_in, 50);
  chassis.pid_wait();


  /*chassis.pid_drive_set(6_in, 30);
  chassis.pid_wait();
  chassis.pid_drive_set(-3_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(600);
  intake.move_velocity(0);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-110_deg, TURN_SPEED);
  chassis.pid_wait();
 /*
  chassis.pid_drive_set(-18_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(100);
  chassis.pid_drive_set(11_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(1_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset();
  chassis.pid_turn_set(32_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, 50);
  chassis.pid_wait();
  chassis.drive_imu_reset();
  chassis.pid_turn_set(-11_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-1_in, DRIVE_SPEED);
  chassis.pid_wait();
  
  pros::delay(1000);
  intake.move_velocity(1200);
  pros::delay(1000);
  */

}
void redSoloSig(){
  armPiston.set_value(false);
  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-4_in, 50);
  chassis.pid_wait();
  clamper.set_value(true);
  pros::delay(200);
  intake.move_velocity(1200);
  //1st ring in
  chassis.pid_turn_set(-72_deg,TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(17_in, DRIVE_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-200);
  pros::delay(200);
  intake.move_velocity(1200);
  //2nd ring in
  pros::delay(600);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(167_deg, TURN_SPEED);
  chassis.pid_wait();
  clamper.set_value(false);
  chassis.pid_wait();
  pros::delay(300);
  chassis.pid_drive_set(50_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(8_in, 50);
  chassis.pid_wait();
  pros::delay(200);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-98_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-15_in, 50);
  chassis.pid_wait();
  clamper.set_value(true);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(128_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(20_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(128_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(22_in, 50);
  chassis.pid_wait();
}

///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater than the slew distance + a few inches

  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
}

///
// Turn Example
///
void turn_example() {
  // The first parameter is the target in degrees
  // The second parameter is max speed the robot will drive at

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // pid_wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(24_in, 30, true);
  chassis.pid_wait_until(6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // When the robot gets to -6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(-24_in, 30, true);
  chassis.pid_wait_until(-6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();
}

///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is the target in degrees
  // The third parameter is the speed of the moving side of the drive
  // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

  chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();
}

///
// Motion Chaining
///
void motion_chaining() {
  // Motion chaining is where motions all try to blend together instead of individual movements.
  // This works by exiting while the robot is still moving a little bit.
  // To use this, replace pid_wait with pid_wait_quick_chain.
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // Your final motion should still be a normal pid_wait
  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backward
    printf("i - %i", i);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait();

    // If failsafed...
    if (chassis.interfered) {
      chassis.drive_sensor_reset();
      chassis.pid_drive_set(-2_in, 20);
      pros::delay(1000);
    }
    // If the robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, the robot will drive forward and turn 90 degrees.
// If interfered, the robot will drive forward and then attempt to drive backward.
void interfered_example() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}

// . . .
// Make your own autonomous functions here!
// . . .