#include "input.h"
//if were on a windows machine
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#include <conio.h>

//if not on windows
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
int _kbhit(int* input){
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); // Set non-blocking

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        *input = (char)ch;
        return 1;
    }
    return 0;
}
#endif