#include "CFORM.h"
#include<Windows.h>
#include<thread>
#include"Hc.h"
CFRAME::CFRAME(const wchar_t* title) {
    m_Width = 0;
    m_Height = 0;
    m_Visible = false;
    m_Style = 0;
    m_Title = title;
    m_BackgroundColor = RGB(255, 255, 255); // Color de fondo predeterminado (blanco).
}

void CFRAME::setPROPERTIES(int width, int height, bool visible, bool resizable, FrameType type) {
    m_Width = width;
    m_Height = height;
    m_Visible = visible;

    m_Style = WS_OVERLAPPEDWINDOW;

    if (!resizable) {
        m_Style &= ~WS_THICKFRAME;
    }

    if (type == NOBORDER) {
        m_Style &= ~WS_OVERLAPPEDWINDOW;
        m_Style |= WS_POPUP;
    }
}

void CFRAME::SHOWWINDOW() {
    CreateAndShowWindow();
}

void CFRAME::BACKCOLOR(COLORREF color) {
    m_BackgroundColor = color;

    if (m_hWnd != NULL) {
        InvalidateRect(m_hWnd, NULL, TRUE); // Forzar el repintado de la ventana.
    }
}
void CFRAME::CreateAndShowWindow() {
    HINSTANCE hInstance = GetModuleHandle(NULL);

    const wchar_t* className = L"CFRAME_WindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = className;

    RegisterClass(&wc);

    m_hWnd = CreateWindowEx(
        0,
        className,
        m_Title.c_str(),
        m_Style,
        CW_USEDEFAULT, CW_USEDEFAULT,
        m_Width, m_Height,
        NULL,
        NULL,
        hInstance,
        this
    );

    if (m_hWnd == NULL) {
        return;
    }

    ShowWindow(m_hWnd, SW_SHOWDEFAULT);
    UpdateWindow(m_hWnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT CALLBACK CFRAME::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    CFRAME* frame = reinterpret_cast<CFRAME*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    switch (uMsg) {
    case WM_CREATE: {
        LPCREATESTRUCT createStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(createStruct->lpCreateParams));
    }
                  break;
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // Pintar el fondo con el color seleccionado.
        HBRUSH hBackgroundBrush = CreateSolidBrush(frame->m_BackgroundColor);
        FillRect(hdc, &ps.rcPaint, hBackgroundBrush);
        DeleteObject(hBackgroundBrush);

        EndPaint(hwnd, &ps);
    }
                 break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}
