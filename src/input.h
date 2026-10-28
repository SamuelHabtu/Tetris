#ifndef INPUT_H
#define INPUT_H
#include <stdio.h>
#include <stdbool.h>
#if !defined(_WIN32) && !defined(_WIN64)
int _kbhit();
#else
#include <windows.h>
#include <conio.h>


#endif
#endif