#ifndef GENERALLOANINFO_HPP
#define GENERALLOANINFO_HPP

#include<iostream>
using namespace std;

enum LoanMenuOptions{
    PERSONAL = 1,
    PRENDARY,
    MORTGAGE,
    RETURN
};

const void getGeneralLoanInfo();
const void getPersonalLoanInfo(float* _rate);
const void getPrendaryLoanInfo(float* _rate);
const void getMortgageInfo(float* _rate);

#endif