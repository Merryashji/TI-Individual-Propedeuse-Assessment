#ifndef LEDS_HPP
#define LEDS_HPP

#include "hwlib.hpp"

/// @file

/// \brief
/// leds class
/// \details
/// This is a class for color for 5 leds.
class leds{
private:
    hwlib::pin_out & l1;
    hwlib::pin_out & l2;
    hwlib::pin_out & l3;
    hwlib::pin_out & l4;
    hwlib::pin_out & l5;
    
    
/// \brief
/// class public
/// \details
/// the public part contains the constructor of the leds color and the member functions.
public:
    leds( hwlib::pin_out & l1 , hwlib::pin_out & l2 , hwlib::pin_out & l3 , hwlib::pin_out & l4 ,
    hwlib::pin_out & l5):
    
    l1(l1), l2(l2) , l3(l3) , l4(l4) , l5(l5){}
    
    
    /// \brief
    /// show_color
    /// \details
    /// this function has a char parameter. According to this values the function turns the actual color led on.
    void show_color(char color ); 


    /// \brief
    /// reset
    /// \details
    /// this function turns all the leds off. 
    void reset();
};


#endif