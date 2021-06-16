#include "hwlib.hpp"
#include "gy31.hpp"
#include "servo.hpp"


int main( void ){


   hwlib::wait_ms( 500 );   
   
   namespace target = hwlib::target;  

   auto scl     = target::pin_oc( target::pins::scl );
   auto sda     = target::pin_oc( target::pins::sda );
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
   auto oled    = hwlib::glcd_oled( i2c_bus, 0x3c ); 
   auto font    = hwlib::font_default_8x8();
   auto display = hwlib::terminal_from( oled, font ); 
 
   auto s0 = hwlib::target::pin_out( hwlib::target::pins::d4 );
   auto s1 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto s2 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto s3 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto sensor_out = hwlib::target::pin_in( hwlib::target::pins::d8 );
   auto sensor  = gy31( s0 , s1 , s2 , s3 , sensor_out );
   sensor.color_detection();
   
   auto servo_1_pin = hwlib::target::pin_out( hwlib::target::pins::d9 );
   auto servo_2_pin = hwlib::target::pin_out( hwlib::target::pins::d10 );
   
   auto servo_motor_top = servo(servo_1_pin);
   auto servo_motor_buttom = servo(servo_2_pin);
   
   while(1){
        servo_motor_top.move_servo_top1(); 
        
        hwlib::wait_ms( 500 ); 
        char direction = sensor.color_detection();
        //hwlib::cout << direction << "\n"; 
        display << "\f" << hwlib::flush;
        if (direction == 'R'){
            display << "RED" << hwlib::flush;
            hwlib::wait_ms( 1'000 );
        }else if (direction == 'B'){
            display << "BLUE" << hwlib::flush;
            hwlib::wait_ms( 1'000 );
        }else if (direction == 'G'){
            display << "GREEN" << hwlib::flush;
            hwlib::wait_ms( 1'000 );
        }else if (direction == 'W'){
            display << "brown" << hwlib::flush;
            hwlib::wait_ms( 1'000 );
        }else if (direction == 'Y'){
           display << "YELLOW" << hwlib::flush;
            hwlib::wait_ms( 1'000 );
        }
        
        servo_motor_buttom.move_servo_bottom(direction);
        servo_motor_top.move_servo_top2();       
        hwlib::wait_ms( 1500 );        

   }
}