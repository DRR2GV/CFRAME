// CFORM.h
#pragma once
#include <string>
#include <Windows.h>
#include <vector>

class COMPONENT {
public:
    virtual ~COMPONENT() {}
    COMPONENT(const wchar_t* text);
    virtual void draw(HDC bufferDC) = 0;
    void setSIZE(int x, int y);
    void setB(int x, int y, int height, int width, COLORREF color, int column);

protected:
    int m_X;
    int m_Y;
    int m_Height;
    int m_Width;
    COLORREF m_Color;
    int m_Column;
};

class BUTTON : public COMPONENT {
public:
    BUTTON(const std::wstring& text);
    virtual void draw(HDC bufferDC) override;
};

class CFRAME {
public:
    enum FrameType { NORMAL, NOBORDER };
    std::vector<COMPONENT*> m_Components;
    CFRAME(const wchar_t* title);
    void setPROPERTIES(int width, int height, bool visible, bool resizable, FrameType type);
    void SHOWWINDOW();
    void BACKCOLOR(COLORREF color);
    void addComponent(COMPONENT component);

private:
    void CreateAndShowWindow();
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    std::vector<COMPONENT*> m_Components;
    int m_Width;
    int m_Height;
    bool m_Visible;
    DWORD m_Style;
    std::wstring m_Title;
    HWND m_hWnd;
    COLORREF m_BackgroundColor;
};
