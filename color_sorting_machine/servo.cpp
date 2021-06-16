#include "servo.hpp"
#include "hwlib.hpp"


void servo::move_servo_top1(){
    auto servo1 = hwlib::servo_background( servo_pin ); 
        
    servo1.write_us( 2625);
    for(int i = 2625 ; i > 2080; i--) {
        servo1.write_us (i);
        hwlib::wait_ms( 2);
    }
    hwlib::wait_ms( 2000);
}
    

void servo::move_servo_top2(){
    auto servo1 = hwlib::servo_background( servo_pin ); 

    for(int i = 2100 ; i > 1650; i--) {
        servo1.write_us (i);
        hwlib::wait_ms( 2);
    }
    hwlib::wait_ms( 2000);

    for(int i = 1650 ; i < 2625; i++) {
        servo1.write_us (i);
        hwlib::wait_ms( 2);
    }
      
    hwlib::wait_ms( 2000);

}


void servo::move_servo_bottom( char x ){
    auto servo1 = hwlib::servo_background( servo_pin );    
    
    if (x == 'R'){
        servo1.write_us( 1400);
        hwlib::wait_ms( 2000);
    }else if (x== 'Y'){
        servo1.write_us( 1100);
        hwlib::wait_ms( 2000);
    }else if ( x== 'B'){
        servo1.write_us( 900);
        hwlib::wait_ms( 2000);
    }else if ( x== 'G'){
        servo1.write_us( 600);
        hwlib::wait_ms( 2000);
    }else if ( x== 'W'){
        servo1.write_us( 400);
        hwlib::wait_ms( 2000);
    }
}
    
    