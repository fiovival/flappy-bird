#pragma once
#include"iostream"
using namespace std;
using namespace System;

class Bird {
public:
	Bird();
	~Bird();
	void borrar();
	bool movinvalido();
	void saltar();
	void mover();
	void dibujar();
	int getx();
	int gety();
	int getancho();
	int getalto();
private:
	float x, y, dy;
	int ancho, alto;
};

Bird::Bird(){
	x = 3;
	y = 20;
	dy = 0;
	ancho = 2;
	alto = 2;
}

Bird::~Bird()
{
}
void Bird::borrar() {
	for (int i = 0; i < alto; i++){
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
		
	}
}
bool Bird::movinvalido() {
	return y + dy < 0 || y + dy + alto>49;
}
void Bird::saltar() { dy = -3; }
void Bird::mover() {
	y += dy;
	dy += 0.3 ;//gravedad
	if (dy > 3.0)dy = 3;//velocidad limite

}
void Bird::dibujar() {
	for (int i = 0; i < alto; i++){
		for (int j = 0; j < ancho; j++){
			Console::SetCursorPosition(x + j, y + i);
			cout << "*";
		}
	}
}

int Bird::getx() { return x; }
int Bird::gety() { return y; }
int Bird::getancho() { return ancho; }
int Bird::getalto() { return alto; }