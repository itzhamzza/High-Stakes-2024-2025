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


//Intake
void intaking(){
    
        

        if(master.get_digital(DIGITAL_R2)){
            //intakes in
            intake.move_velocity(1200);
            
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
            intake.move_velocity(-600);
            
        }
        else{
            intake.move_velocity(0);
            intake.set_brake_mode(MOTOR_BRAKE_COAST);
            

        }
}

void colorSort(){
    while(true){
    
        // //THIS THORWS OUT RED
            // while (color_sens.get_hue() < 20 && color_sens.get_hue() > 5){
            //    //pros::delay(50);
            //     intake.move_velocity(0);
            //     pros::delay(1000);
            // }
        //THIS THROWS OUT BLUE
               while (color_sens.get_hue() > 215 && color_sens.get_hue() < 230){
                   //pros::delay(500);
                   intake.move_velocity(0);
                   pros::delay(1000);
               }
        pros::delay(100);
    

    }
}

int stage = 0;

void ladybrownMovement(){
    

        if(master.get_digital_new_press(DIGITAL_L1)){
            //arm up
            if (stage == 0){
                ladyBrown.set_brake_mode(MOTOR_BRAKE_HOLD);
                ladyBrown.move_absolute(-85, 200);
                
                stage++;
            }
            else if (stage != 0){
                ladyBrown.move_absolute(-350, 200);
                //stage--;
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
