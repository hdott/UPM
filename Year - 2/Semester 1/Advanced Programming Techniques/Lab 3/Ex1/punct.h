#pragma once
#include "dreapta.h"


class Punct{
    private:
        double x,
                y;
        
    public:
        // friend class Dreapta;
        static Dreapta dreapta;
        static int punct1_poz,
                    punct2_neg,
                    punct3_dr;
        

        Punct(double x=1, double y=1);
        Punct(const Punct&);
        ~Punct();
        
        inline double getX(){return this->x;};
        inline double getY(){return this->y;};
        inline void setX(double x){this->x = x;};
        inline void setY(double y){this->y = y;};
        inline void setXY(double x, double y){
            this->x = x;
            this->y = y;
        }
        friend double distanta(const Punct, const Punct); 
};