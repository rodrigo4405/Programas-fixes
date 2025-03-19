#include <windows.h>
#include <time.h>
#include <stdlib.h>

const int _INT = 5 * 60 * 1000; // 5 * 1000 = 5000ms => 5s * 60 => 5m
const int DUR = 1 * 1000;

const int MAX_FREQ = 2000;
const int MIN_FREQ = 400;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    srand(time(0));
    while (1) {
        Beep(rand() % MAX_FREQ + MIN_FREQ, DUR);
        Sleep(_INT);
    }
}