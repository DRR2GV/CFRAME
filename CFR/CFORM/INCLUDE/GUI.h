#pragma once
#include <Windows.h>
#include <string>

class GUI {
public:
    enum WindowType {
        NORMAL,
        BANNER_ONLY
    };
    GUI();
    void GFC(int X, int H, const char* text, COLORREF color, bool resizable, WindowType windowType);
    void ICO(const std::string& iconFilePath);
    void MSGWSLOOP();
    static LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    static const int DEFAULT = 0; // Ejemplo de valor por defecto

private:
    int X;
    int H;
    const char* text;
    COLORREF color;
    bool resizable;
    HWND hwnd;
    HINSTANCE hinstance;
    HICON icon;
    MSG mensaje;
    WNDCLASSEX wincl;
};
