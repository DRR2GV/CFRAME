// Hc.cpp
#include "Hc.h"
#include<wtypes.h>
#include<ColorDlg.h>
#include"CFORM.h"
BUTTON::BUTTON(const std::wstring& text) : m_Text(text) {}

void BUTTON::draw(HDC bufferDC) {
    // Crear un pincel con el color del botón.
    HBRUSH hBrush = CreateSolidBrush(m_Color);

    // Definir las coordenadas del botón.
    int buttonLeft = m_X;
    int buttonTop = m_Y;
    int buttonRight = m_X + m_Width;
    int buttonBottom = m_Y + m_Height;
   
    // Rellenar el rectángulo del botón con el color.
    RECT rect = { buttonLeft, buttonTop, buttonRight, buttonBottom };
    FillRect(bufferDC, &rect, hBrush);

    // Establecer el tamaño de fuente para el botón.
    HFONT hFont = CreateFont(m_FontSize, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial");
    SelectObject(bufferDC, hFont);

    // Establecer el color de texto en negro.
    SetTextColor(bufferDC, RGB(0, 0, 0));

    // Establecer el modo de fondo transparente.
    SetBkMode(bufferDC, TRANSPARENT);

    // Definir el rectángulo de texto.
    RECT textRect = { buttonLeft, buttonTop, buttonRight, buttonBottom };

    // Dibujar el texto en el botón.
    DrawText(bufferDC, m_Text.c_str(), -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    // Liberar el pincel y la fuente.
    DeleteObject(hBrush);
    DeleteObject(hFont);
}

void COMPONENT::setSIZE(int x, int y) {
    m_X = x;
    m_Y = y;
    // Actualizar la posición del componente aquí
}
void COMPONENT::setB(int x, int y, int height, int width, COLORREF color, int column, int fonSize) {
    m_X = x;
    m_Y = y;
    m_Height = height;
    m_Width = width;
    m_Color = color;
    m_COLUMN = column; // Corrección aquí
    m_FontSize = fonSize;
}
