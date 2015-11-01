#pragma once
#ifndef THREE_Y_ONE_C_H
#define THREE_Y_ONE_C_H
#include "Equation.h"

class three_y_one_c : public Equation
{
    private:
        double a1,a2,a3;
        double b1,b2,b3;
        double c1,c2,c3;
        double d1,d2,d3;

    public:
        three_y_one_c():a1(0),a2(0),a3(0),b1(0),b2(0),b3(0),c1(0),c2(0),c3(0),d1(0),d2(0),d3(0){};
        virtual ~three_y_one_c(){};
        three_y_one_c(const three_y_one_c& other){};


        void getCoeff();
        double* solve();



};

#endif // THREE_Y_ONE_C_H
