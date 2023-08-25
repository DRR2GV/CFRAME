// Hc.h
#pragma once
#include <string>
#include <wtypes.h>
#include"CFORM.h"
#include <Color.Dlg>
class COMPONENT {
public:
    virtual ~COMPONENT() {}
    COMPONENT(const wchar_t* text);
    void setSIZE(int x, int y); // Cambiar tamaño
    void setB(int x, int y, int height, int width, COLORREF color, int column, int fontSize);
    virtual void draw(HDC bufferDC)=0;
private:
    std::wstring m_Text;
    int m_X;
    int m_Y;
    int m_Height;
    int m_Width;
    COLORREF m_Color;
    int m_COLUMN;
    int m_FontSize;
};

class BUTTON {
public:
    BUTTON(const std::wstring& text);
    virtual void draw(HDC bufferDC);
    void setSIZE(int x,int y);
    void setB(int x, int y, int height, int width, COLORREF color, int column, int fontSize);

private:
    std::wstring m_Text;
    int m_X;
    int m_Y;
    int m_FontSize;
    int m_Height;
    int m_Width;
    COLORREF m_Color;
    int m_COLUMN;
 };
 
