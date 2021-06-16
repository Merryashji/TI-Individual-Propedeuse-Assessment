#ifndef SERVO_HPP
#define SERVO_HPP

#include "hwlib.hpp"


/// @file

/// \brief
/// servo motor class
/// \details
/// This is a class for servo motor.
class servo{
private:
    hwlib::target::pin_out & servo_pin;
    
    
/// \brief
/// servo motor public.
/// \details
/// the public part contains the constructor of the servo motor class and the member functions.
public:  
    servo(hwlib::target::pin_out & servo_pin):
    servo_pin(servo_pin){}
    
    
    /// \brief
    /// servo motor public.
    /// \details
    /// this function has a char parameter. According to this values the function move the servo motor to the actual color.
    void move_servo_top1();
    
    
    
    /// \brief
    /// servo motor public.
    /// \details
    /// this function has a char parameter. According to this values the function move the servo motor to the actual color.
    void move_servo_top2();
    
    
    
    /// \brief
    /// servo motor public.
    /// \details
    /// this function has a char parameter. According to this values the function move the servo motor to the actual color.
    void move_servo_bottom( char x );
  
};




#endif