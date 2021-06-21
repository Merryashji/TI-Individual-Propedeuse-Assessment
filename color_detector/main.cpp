#include "hwlib.hpp"
#include "gy31.hpp"
#include "servo.hpp"
#include "leds.hpp"

int main( void ){
   
   namespace target = hwlib::target;    
 
   auto s0 = hwlib::target::pin_out( hwlib::target::pins::d4 );
   auto s1 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto s2 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto s3 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto sensor_out = hwlib::target::pin_in( hwlib::target::pins::d8 );
   
   
   auto led_yellow = hwlib::target::pin_out( hwlib::target::pins::d9  );
   auto led_green  = hwlib::target::pin_out( hwlib::target::pins::d10 );
   auto led_red    = hwlib::target::pin_out( hwlib::target::pins::d11 );
   auto led_blue   = hwlib::target::pin_out( hwlib::target::pins::d12 );
   auto led_no_color   = hwlib::target::pin_out( hwlib::target::pins::d13 );   
   
   auto servo_1_pin = hwlib::target::pin_out( hwlib::target::pins::d3 );
   auto sensor  = gy31( s0 , s1 , s2 , s3 , sensor_out );
   
   auto servo_motor = servo(servo_1_pin);
   
   auto color_leds = leds(led_yellow , led_green , led_red , led_blue , led_no_color);
   
   // wait for the terminal emulator to start up
   hwlib::wait_ms( 2'000 );
   
   while(1){
        color_leds.reset();
        char direction = sensor.detect_color();
        color_leds.show_color(direction);
        servo_motor.move(direction);
        hwlib::wait_ms( 500 );      
   }
}
