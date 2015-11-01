#pragma once
#ifndef ONE_Y_TWO_C_H
#define ONE_Y_TWO_C_H
#include "Equation.h"

class one_y_two_c : public Equation
{
    private:
        double a;
        double b;
        double c;

    public:
        one_y_two_c():a(0),b(0),c(0){};
        virtual ~one_y_two_c(){};
        one_y_two_c(const one_y_two_c& other){};

        void getCoeff();
        double* solve();

};

#endif // ONE_Y_TWO_C_H
