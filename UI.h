#pragma once
#include "service.h"
#include <iterator>

class UI
{
private:
    Service service;
public:
    UI();
    UI(const Service& service);
    ~UI();

    void addProdus();
    void updateProdus();
    void deleteProdus();
    void displayProdus();
    void show_menu();
    void cumparaProdus();
    void returneazaProdus();
    int run();
    void display();

    //void cumparareProdus();
    //void returnareProdus();
};
