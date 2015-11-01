#pragma once
#ifndef ONE_Y_THREE_C_H
#define ONE_Y_THREE_C_H
#include "Equation.h"

class one_y_three_c : public Equation
{
    private:
        double a,b,c,d;
        double x1,x2;

    public:
        one_y_three_c():a(0),b(0),c(0),d(0),x1(0),x2(0){};
        virtual ~one_y_three_c(){};
        one_y_three_c(const one_y_three_c& other){};


        void getCoeff();
        double* solve();




};

#endif // ONE_Y_THREE_C_H
