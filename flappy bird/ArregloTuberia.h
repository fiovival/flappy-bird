#pragma once
#include"Tuberia.h"
class ArregloTuberia
{
public:
	ArregloTuberia();
	~ArregloTuberia();
	//----------------------
	void agregar(Tuberia* dato);
	void eliminar(int pos);
	Tuberia* at(int pos);
	int size();
private:
	int n;
	Tuberia** arr;
};

ArregloTuberia::ArregloTuberia()
{
	n = 0;
	arr = new Tuberia * [n];
}

ArregloTuberia::~ArregloTuberia(){
	delete[] arr;
}

void ArregloTuberia::agregar(Tuberia* dato){
	Tuberia** aux = new Tuberia * [n + 1];
	for (int i = 0; i < n; i++){
		aux[i] = arr[i];
	}
	aux[n] = dato;
	delete[] arr;
	arr = aux;
	aux = nullptr;
	delete aux;
	n++;
}
void ArregloTuberia::eliminar(int pos){
	Tuberia** aux = new Tuberia * [n - 1];
	for (int i = 0; i < n - 1; i++){
		if (i < pos)aux[i] = arr[i];
		else aux[i] = arr[i + 1];
	}
	delete[] arr;
	arr = aux;
	aux = nullptr;
	delete aux;
	n--;
}
Tuberia* ArregloTuberia::at(int pos) { return arr[pos]; }
int ArregloTuberia::size() { return n; }