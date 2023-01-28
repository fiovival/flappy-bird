#pragma once
#include<iostream>
using namespace std;
using namespace System;

class Tuberia {
public:
	Tuberia();
	~Tuberia();
	void borrar();
	bool movinvalido();
	void mover();
	void dibujar();
	bool colision(int x, int y, int ancho, int alto);
private:
	float x, y1, y2, dx;
	int ancho, alto;
};

Tuberia::Tuberia() {
	ancho = 2;
	y1 = rand()%(30-10+1)+10;
	y2 = y1+5+(rand()%5);

	dx = -1;
	x = 119-ancho;
}

Tuberia::~Tuberia()
{
}
void Tuberia::borrar() {
	for (int i = 0; i < y1; i++) {
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j,i);
			cout << " ";
		}
	}
	for (int i = 0; i < 50-y2; i++) {
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j,y2+i);
			cout << " ";
		}
	}
}
bool Tuberia::movinvalido(){
	return x + dx < 0;
}
void Tuberia::mover(){
	x += dx;
}
void Tuberia::dibujar() {
	for (int i = 0; i < y1; i++) {
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, i);
			cout << "*";
		}
	}
	for (int i = 0; i < 50 - y2; i++) {
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y2 + i);
			cout << "*";
		}
	}
}
bool Tuberia::colision(int x, int y, int ancho, int alto) {
	return false;
}