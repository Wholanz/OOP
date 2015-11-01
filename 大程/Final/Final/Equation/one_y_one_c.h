#pragma once
#ifndef ONE_Y_ONE_C_H
#define ONE_Y_ONE_C_H
#include "Equation.h"

class one_y_one_c : public Equation
{
    private:
        double a;
        double b;
    public:
        one_y_one_c():a(0),b(0){};
        virtual ~one_y_one_c(){};
        one_y_one_c(const one_y_one_c& other){};

        void getCoeff();
        double* solve();


};

#endif // ONE_Y_ONE_C_H
