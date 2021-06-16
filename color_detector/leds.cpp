#include "leds.hpp"

void leds::reset(){
    l1.write(0);
    l2.write(0);
    l3.write(0);
    l4.write(0);
    l5.write(0);
}

void leds::show_color(char color){
    reset();
    if (color == 'Y'  ){
        l1.write(1);
    }else if ( color == 'G'  ){
        l2.write(1);
    }else if ( color == 'R'  ){
        l3.write(1); 
    }else if (color  == 'B'  ){
        l4.write(1);
    }else if (color  == 'N'  ){
        l5.write(1);
    }else if (color  == 'O'  ){
        l3.write(1);
        l1.write(1);
    }
        
}

