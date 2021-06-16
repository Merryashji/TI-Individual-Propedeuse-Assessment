#include "servo.hpp"
#include "hwlib.hpp"

    
void servo::move( char x ){
    auto servo1 = hwlib::servo_background( servo_pin );    
    
    if (x == 'R'){
        servo1.write_us( 1100);
        hwlib::wait_ms( 200);
    }else if ( x== 'Y'){
        servo1.write_us( 500);
        hwlib::wait_ms( 200);
    }else if (x== 'O'){
        servo1.write_us( 300);
        hwlib::wait_ms( 200);
    }else if (x== 'G'){
        servo1.write_us( 800);
        hwlib::wait_ms( 200);
    }else if (x== 'B'){
        servo1.write_us( 1500);
        hwlib::wait_ms( 200);
    }else if (x== 'N'){
        servo1.write_us( 1900);
        hwlib::wait_ms( 200);
    }
}
    
    