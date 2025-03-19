#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

const int NINDEX_X = 0; // GetSystemMetrics nIndex SM_CXSCREEN
const int NINDEX_Y = 1; // GetSystemMetrics nIndex SM_CYSCREEN

const int widthLims = 55; // width occupied by x
const int heightLims = 30; // height " " "

void get_res(int *scr);
void get_mouse_pos(POINT *pnt);
void move_mouse(int *scr);

enum _ {W, H};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    srand(time(0)); // set seed

    int scr[2];
    int *pScr = &scr[0];
    get_res(pScr);

    //printf("%ix%i\n", scr[W], scr[H]);

    POINT pnt;
    POINT *pPnt = &pnt;

    while (1) {
        get_mouse_pos(pPnt);
        if (pnt.x > scr[W] - widthLims && pnt.y < scr[H] + heightLims) {
            // printf("{%i (%i), %i (%i)} %li, %li\n", scr[W], scr[W]- widthLims, scr[H], scr[H] + heightLims, pnt.x, pnt.y);
            move_mouse(pScr);
        }
    }
}

void get_res(int *scr) {
    scr[W] = GetSystemMetrics(NINDEX_X);
    scr[H] = GetSystemMetrics(NINDEX_Y);
}

void get_mouse_pos(POINT *pnt) {
    if (GetCursorPos(pnt)) {
        Sleep(50);
    }
}

void move_mouse(int *scr) {
    int rand_x = rand() % scr[W];
    int rand_y = rand() % scr[H];

    SetCursorPos(rand_x, rand_y);
}