#include"Juego.h"
void main() {
	srand(time(0));
	Console::SetWindowSize(120,50);
	Juego* obj = new Juego();
	while (1) {
		if (obj->jugar())break;
		_sleep(100);
	}
	delete obj;
}