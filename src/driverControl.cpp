#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"
bool dir = false;

//Redirect
void Redirecter(){
    if(master.get_digital(DIGITAL_UP)){
        dir = true;
        pros::delay(50);
        master.rumble(".");
        
    }
    else if(master.get_digital(DIGITAL_DOWN)){
        dir = false;
        pros::delay(50);
        master.rumble(".");
    }


}

bool sortering = false;
//Intake
void intaking(){
    
        

        if(master.get_digital(DIGITAL_R2) && sortering == false){
            //intakes in
            intake.move_velocity(-1200);
            
            if (dir == true){
                intake.move_velocity(-300); 
                if(color_sens.get_hue() < 15 && color_sens.get_hue() > 8){
                    intake.move_velocity(300);
                    pros::delay(1000);
                }
            }        

        }
        else if(master.get_digital(DIGITAL_R1)){
            //intakes out
            intake.move_velocity(600);
            
        }
        else{
            intake.move_velocity(0);
            //intake.set_brake_mode(MOTOR_BRAKE_COAST);
            

        }
}

void colorSort(){
    while(true){
    
        // //THIS THORWS OUT RED
            //  if (color_sens.get_hue() < 20 && color_sens.get_hue() > 5){
            //     pros::delay(10);
            //         sortering = true;
            //         intake.move_relative(1000000000,10000);
            //         pros::delay(1000);
            //         sortering = false;
            //  }
        //THIS THROWS OUT BLUE
               if (color_sens.get_hue() < 230 && color_sens.get_hue() > 210){
                pros::delay(10);
                    sortering = true;
                    intake.move_relative(1000000000,10000);
                    pros::delay(1000);
                    sortering = false;
                   //pros::delay(100);
                   //sortering = true;
                   //intake.move_velocity(-1200);
                   //pros::delay(1000);
                   //sortering = false;
               }
               pros::delay(10);

    }
}

int stage = 0;


void ladybrownMovement(){
    

        if(master.get_digital_new_press(DIGITAL_L1)){
            //arm up
            if (stage == 0){
                ladyBrown.set_brake_mode(MOTOR_BRAKE_HOLD);
                intake.set_brake_mode(MOTOR_BRAKE_HOLD);
            
                ladyBrown.move_absolute(-450, 200);
                
                stage++;
            }
            else if (stage == 1){
                intake.set_brake_mode(MOTOR_BRAKE_COAST);
                ladyBrown.move_absolute(-1000, 200);
                stage++;
            }
            else if(stage == 2){
                ladyBrown.move_absolute(-2000, 200);

            }

            
            //rotation_sens.reset();
           // while (rotation_sens.get_position() > 27000){
            
             //   ladyBrown.move_velocity(-600);
               // locker.set_value(true);
            //}
            

        }
        else if(master.get_digital_new_press(DIGITAL_L2)){
            //arm down
            ladyBrown.move_absolute(12, 200);
            ladyBrown.set_brake_mode(MOTOR_BRAKE_COAST);
            intake.set_brake_mode(MOTOR_BRAKE_COAST);
            stage = 0;
            //rotation_sens.reset();
            //while (rotation_sens.get_position() <= 35700){
              //  ladyBrown.move_velocity(600);
                
            //}
            
        }
        
        pros::delay(100);
    

}

void intakeExtender(){
    if(master.get_digital_new_press(DIGITAL_X)){
        //Arm Extender
        armPiston.set_value(true);
       
    }
    else if(master.get_digital_new_press(DIGITAL_A)){
        //Arm Extender Off
        armPiston.set_value(false);
        
    }
}

void clamping(){

    if(master.get_digital(DIGITAL_Y)){
        //clamps on
        clamper.set_value(true);
        

    }
    else if(master.get_digital(DIGITAL_RIGHT)){
        //clamps off
        clamper.set_value(false);
        
    }

}

void doinker(){

    if(master.get_digital(DIGITAL_UP)){
        //clamps on
      doink.set_value(true);
        

    }
     if(master.get_digital(DIGITAL_DOWN)){
        //clamps off
        doink.set_value(false);
        
    }

}
