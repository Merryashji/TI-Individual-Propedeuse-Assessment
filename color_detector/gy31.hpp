#ifndef GY31_HPP
#define GY31_HPP

#include "hwlib.hpp"

/// @file

/// \brief
/// GY-31 color sensor class
/// \details
/// This is a class for color sensor GY-31(TCS3200).
class gy31{
private:
    hwlib::pin_out & S0;
    hwlib::pin_out & S1;
    hwlib::pin_out & S2;
    hwlib::pin_out & S3;
    hwlib::pin_in  & out;
    
    
/// \brief
/// GY-31 public.
/// \details
/// the public part contains the constructor of the GY-31 color sensor class and member functions.
public:  
    gy31(hwlib::pin_out & S0 , hwlib::pin_out & S1 , hwlib::pin_out & S2, hwlib::pin_out & S3 ,hwlib::pin_in & out):
    S0(S0),
    S1(S1),
    S2(S2),
    S3(S3),
    out(out){}
    
    
    /// \brief
    /// Setting frequency-scaling to 20%
    /// \details
    /// This function set the frequency-scaling to 20%.
    void set_frequentie_scaling();
    
    
    /// \brief
    /// Setting filtered photodiodes to be read
    /// \details 
    /// This function has two control pins S2 and S3 as parameters to select the filtered photodiodes.   
    void set_filter(bool s2 , bool s3);
    
    
    /// \brief
    /// read_frequentie
    /// \details
    /// this function will read the output frequency and put it into the variable frequency.
    int read_frequentie();
    
    
    /// \brief
    /// get_red_color().
    /// \details
    /// this function set red filtered photodiodes to be read and returns the frequency as integer.
    int get_red_color();
    
    
    /// \brief
    /// get_blue_color().
    /// \details
    /// this function set blue filtered photodiodes to be read and returns the frequency as integer.
    int get_blue_color();
    
    
    /// \brief
    /// \brief
    /// get_green_color().
    /// \details
    /// this function set green filtered photodiodes to be read and returns the frequency as integer.
    int get_green_color();
    
    
    /// \brief
    /// no_color().
    /// \details
    /// this function set no filter and returns the frequency as integer.
    int no_color();
    
    
    /// \brief
    /// detect_color.
    /// \details
    /// this function reads 4 different values Red, Green, Blue and no color. According to these values the function returs the actual color as char.
    char detect_color();
};



#endif
