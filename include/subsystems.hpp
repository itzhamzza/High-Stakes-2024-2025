#pragma once

#include "api.h"

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');
inline pros::Motor intake(20, pros::v5::MotorGears::blue);



inline pros::MotorGroup ladyBrown({-1,5}, pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
inline pros::Distance distance_sens(19);

inline pros::Rotation rotation_sens(18);

inline pros::Optical color_sens(8);

inline pros::adi::DigitalOut clamper('A', 0);

inline pros::adi::DigitalOut doink('B', 0);

inline pros::adi::DigitalOut armPiston('C', 0);