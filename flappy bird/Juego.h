#pragma once
#include"ArregloTuberia.h"
#include"Bird.h"
#include<conio.h>
class Juego{
public:
	Juego();
	~Juego();
	bool jugar();
private:
	ArregloTuberia* arr;
	Bird* objpajaro;
};
Juego::Juego(){
	arr = new ArregloTuberia();
	objpajaro = new Bird();
}
Juego::~Juego(){}
bool Juego::jugar() {
	objpajaro->borrar();
	if(objpajaro->movinvalido()){ return 1; }
	objpajaro->mover();
	objpajaro->dibujar();
	if (kbhit()) { _getch(); objpajaro->saltar(); }
	if (rand() % 1000 < 5) { arr->agregar(new Tuberia()); }
	for (int i = 0; i < arr->size(); i++){
		arr->at(i)->borrar();
		if (arr->at(i)->movinvalido()) { arr->eliminar(i); i--; }
		else {
			arr->at(i)->mover();
			arr->at(i)->dibujar();
			//colision con jugador
		}
	}
	return 0;
}