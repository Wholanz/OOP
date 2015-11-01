#pragma once
#ifndef TWO_Y_ONE_C_H
#define TWO_Y_ONE_C_H
#include "Equation.h"
class two_y_one_c : public Equation
{
   private:
        double a1,a2;
        double b1,b2;
        double c1,c2;

    public:
        two_y_one_c():a1(0),a2(0),b1(0),b2(0),c1(0),c2(0){};
        virtual ~two_y_one_c(){};
        two_y_one_c(const two_y_one_c& other){};


        void getCoeff();
        double* solve();
};

#endif // TWO_Y_ONE_C_H
