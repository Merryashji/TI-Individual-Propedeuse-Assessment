#include "hwlib.hpp"
#include "gy31.hpp"

int main( void ){
   
   namespace target = hwlib::target;    
 
   auto s0 = hwlib::target::pin_out( hwlib::target::pins::d4 );
   auto s1 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto s2 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto s3 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto sensor_out = hwlib::target::pin_in( hwlib::target::pins::d8 );   
   
   auto sensor  = gy31( s0 , s1 , s2 , s3 , sensor_out );
   
   // wait for the terminal emulator to start up
   hwlib::wait_ms( 2'000 );
   
   while(1){
        hwlib::cout << sensor.no_color() << " " <<sensor.get_red_color() << " "<< sensor.get_blue_color() <<" "<< sensor.get_green_color()<< "\n";
        hwlib::wait_ms( 500 );      
   }
}