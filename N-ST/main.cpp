// main.cpp
#include "CFORM.h"
#include "Hc.h"

// main.cpp
int main() {
    CFRAME frame(L"Mi Ventana");
    frame.setPROPERTIES(800, 600, true, true, CFRAME::NORMAL);

    BUTTON button(L"BOTON1 agregado");
    button.setB(50, 50, 100, 200, RGB(255, 0, 0), 0);
    frame.addComponent(&button); // Pasa el objeto BUTTON en lugar de puntero

    frame.SHOWWINDOW();
    return 0;
}
