// ConsoleApplication8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//  Signture.h
//  
//
//  Created by Omar Hameed  on 2020-12-10.
//
#ifndef Signture_h
#define Signture_h
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <math.h> 
#define _USE_MATH_DEFINES
# define PI           3.14159265358979323846  /* pi */


typedef float real;
typedef struct { real Re; real imag; } complex;

class Signture
{
public:
	void fft(complex*, int, complex*);
    int* fft_max ( short*, int);
    //Signture();
};
#endif /* waveheader_hpp */

