#include "gy31.hpp"
#include "hwlib.hpp"


void gy31::set_frequentie_scaling(){
    S0.write(1);
    S1.write(0);
};


void gy31::set_filter(bool s2 , bool s3){
    S2.write(s2);
    S3.write(s3);
};


int gy31::read_frequentie(){
    set_frequentie_scaling();
    while (out.read() == 1){} ;
    while (out.read() == 0){} ;    
    int start_timer = hwlib::now_us();
    while (out.read() == 1){} ;
    while (out.read() == 0){} ;
    int end_timer = hwlib::now_us();
    int T = end_timer - start_timer ; 
    double T_s = T * 0.000001; //T -> s
    int frequentie = 1/T_s; // f = 1/T 
    return frequentie/100; 
};


int gy31::get_red_color(){
    set_filter(0,0);
    return read_frequentie();
};


int gy31::get_blue_color(){
    set_filter(0,1);
    return read_frequentie();
};


int gy31::get_green_color(){
    set_filter(1,1);
    return read_frequentie();
};


int gy31::no_color(){
    set_filter(1,0);
    return read_frequentie();
};


char gy31::detect_color(){
    int R = get_red_color();
    int B = get_blue_color();
    int G = get_green_color();
    int N = no_color();
        
    if ( N < 95 ){
        return 'N';
    }else if (R > G && R > B && B > G   ){
        if (N > 110){
            return 'O';
        }
        return 'R'; 
    }else if ( G > R && G > B && B > R  ){
        return 'G';
    }else if (B > R && B > G && G > R ){
        return 'B'; 
    }else if (R > G && R > B && G > B ){
        return 'Y'; 
    }
    return detect_color();
};
