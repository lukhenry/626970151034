#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_CASILLAS = 63;
const int CASILLA_OCA_1 = 5;
const int CASILLA_OCA_2 = 9;
const int CASILLA_OCA_3 = 14;
const int CASILLA_OCA_4 = 18;
const int CASILLA_OCA_5 = 23;
const int CASILLA_OCA_6 = 27;
const int CASILLA_OCA_7 = 32;
const int CASILLA_OCA_8 = 36;
const int CASILLA_OCA_9 = 41;
const int CASILLA_OCA_10 = 45;
const int CASILLA_OCA_11 = 50;
const int CASILLA_OCA_12 = 54;
const int CASILLA_OCA_13 = 59;
const int CASILLA_OCA_14 = 63;
const int CASILLA_PUENTE_1 = 6;
const int CASILLA_PUENTE_2 = 12;
const int CASILLA_DADOS_1 = 26;
const int CASILLA_DADOS_2 = 53;
const int CASILLA_POSADA = 19;
const int CASILLA_PRISION = 52;
const int CASILLA_POZO = 31;
const int CASILLA_LABERINTO = 42;
const int CASILLA_MUERTE = 58;
const int TURNOS_POSADA = 1;
const int TURNOS_PRISION = 2;
const int TURNOS_POZO = 3;


bool esOca(int casilla);
bool esPuente(int casilla);
bool esDados(int casilla);
bool esLaberinto(int casilla);
bool esMuerte(int casilla);
bool esPosada(int casilla);
bool esPrision(int casilla);
bool esPozo(int casilla);
bool esMeta(int casilla);
int siguienteOca(int casilla);
int siguientePuente(int casilla);
int siguienteDado(int casilla);
int siguienteLaberinto();
int siguienteMuerte();
int tirarDado();
int quienEmpieza();
int efectoPosicion(int casillaActual);
int efectoTiradas(int casillaActual, int numeroDeTiradas);
int tirarDadoManual();


int main() {

	srand(time(NULL));
	int casilla_1 = 1;
	int casilla_2 = 1;
	int tiradas_1 = 1;
	int tiradas_2 = 1;
	int numero = 1;
	int primero = quienEmpieza();
	int segundo = primero == 1 ? 2 : 1;
	string modo;
	int dado;

	cout << "INTRODUCE EL MODO DE JUEGO, CLASICO O DEPURACION" << endl;
	cin >> modo;
	
	while (!(esMeta(casilla_1)) && !(esMeta(casilla_2))) {
			cout << endl << "PON UN NUMERO ";
			cin >> numero;
			
			

			cout << endl << "TURNO PARA EL JUGADOR " << primero << endl;
			while (tiradas_1 > 0) {
				cout << "CASILLA ACTUAL: " << casilla_1 << endl;
				if (modo == "CLASICO") {
					 dado = tirarDado();
				}
				else {
					dado = tirarDadoManual();
				}
				cout << "VALOR DEL DADO: " << dado << endl;
				
				if (casilla_1 + dado < NUM_CASILLAS +1) {
					casilla_1 += dado;
					casilla_1 = efectoPosicion(casilla_1);
					tiradas_1 = efectoTiradas(casilla_1, tiradas_1);
					
					if (esMeta(casilla_1)) {
						tiradas_1--;
					}

					tiradas_1--;
				}
				else {
					cout << "TE PASASTE";
				}
			}
			if (!(esMeta(casilla_1)) && !(esMeta(casilla_2))) {
				cout << endl << "TURNO PARA EL JUGADOR " << segundo << endl;
			}
			while (tiradas_2 > 0 && !(esMeta(casilla_1)) && !(esMeta(casilla_2))) {
				cout << "CASILLA ACTUAL: " << casilla_2 << endl;
				
				if (modo == "CLASICO") {
					dado = tirarDado();
				}
				else {
					dado = tirarDadoManual();
				}
				cout << "VALOR DEL DADO: " << dado << endl;

				if (casilla_2 + dado < NUM_CASILLAS + 1) {
					casilla_2 += dado;
					casilla_2 = efectoPosicion(casilla_2);
					tiradas_2 = efectoTiradas(casilla_2, tiradas_2);

					if (esMeta(casilla_2)) {
						tiradas_2--;
					}

					tiradas_2--;
				}
				else {
					cout << "TE PASASTE";
				}
			} 
			tiradas_1++;
			tiradas_2++;
	}
	}

bool esOca(int casilla) {
	switch (casilla) {

	case CASILLA_OCA_1:
		return true;
		break;

	case CASILLA_OCA_2:
		return true;
		break;

	case CASILLA_OCA_3:
		return true;
		break;

	case CASILLA_OCA_4:
		return true;
		break;

	case CASILLA_OCA_5:
		return true;
		break;

	case CASILLA_OCA_6:
		return true;
		break;

	case CASILLA_OCA_7:
		return true;
		break;

	case CASILLA_OCA_8:
		return true;
		break;

	case CASILLA_OCA_9:
		return true;
		break;

	case CASILLA_OCA_10:
		return true;
		break;

	case CASILLA_OCA_11:
		return true;
		break;

	case CASILLA_OCA_12:
		return true;
		break;

	case CASILLA_OCA_13:
		return true;
		break;

	case CASILLA_OCA_14:
		return true;
		break;

	default:
		return false;
	}
}

bool esPuente(int casilla) {

	if (casilla == CASILLA_PUENTE_1 || casilla == CASILLA_PUENTE_2) {
		return true;
	}
	else {
		return false;
	}

}

bool esDados(int casilla) {
	if (casilla == CASILLA_DADOS_1 || casilla == CASILLA_DADOS_2) {
		return true;
	}
	else {
		return false;

	}
}

bool esLaberinto(int casilla) {
	if (casilla == CASILLA_LABERINTO) {
		return true;
	}
	else {
		return false;
	}
}

bool esMuerte(int casilla) {
	if (casilla == CASILLA_MUERTE){
		return true;
	}
	else {
		return false;
	}
}

bool esPosada(int casilla) {
	if (casilla == CASILLA_POSADA) {
		return true;
	}
	else {
		return false;
	}
}

bool esPrision(int casilla) {
	if (casilla == CASILLA_PRISION) {
		return true;
	}
	else {
		return false;
	}
}

bool esPozo(int casilla) {
	if (casilla == CASILLA_POZO) {
		return true;
	}
	else {
		return false;
	}
}

bool esMeta(int casilla) {
	if (casilla == 63) {
		return true;
	}
	else {
		return false;
	}
}

int siguienteOca(int casilla) {
	switch (casilla) {

	case CASILLA_OCA_1:
		return CASILLA_OCA_2;
		break;

	case CASILLA_OCA_2:
		return CASILLA_OCA_3;
		break;

	case CASILLA_OCA_3:
		return CASILLA_OCA_4;
		break;

	case CASILLA_OCA_4:
		return CASILLA_OCA_5;
		break;

	case CASILLA_OCA_5:
		return CASILLA_OCA_6;
		break;

	case CASILLA_OCA_6:
		return CASILLA_OCA_7;
		break;

	case CASILLA_OCA_7:
		return CASILLA_OCA_8;
		break;

	case CASILLA_OCA_8:
		return CASILLA_OCA_9;
		break;

	case CASILLA_OCA_9:
		return CASILLA_OCA_10;
		break;

	case CASILLA_OCA_10:
		return CASILLA_OCA_11;
		break;

	case CASILLA_OCA_11:
		return CASILLA_OCA_12;
		break;

	case CASILLA_OCA_12:
		return CASILLA_OCA_13;
		break;

	case CASILLA_OCA_13:
		return CASILLA_OCA_14;
		break;

	/*case CASILLA_OCA_14:
		return CASILLA_OCA_14;
		break;
	*/

	}
}

int siguientePuente(int casilla) {
	if (casilla == CASILLA_PUENTE_1) {
		return CASILLA_PUENTE_2;

	} else {
		return CASILLA_PUENTE_1;
	}
}

int siguienteDado(int casilla) {

	if (casilla == CASILLA_DADOS_1){
		return CASILLA_DADOS_2;
	}
	else {
		return CASILLA_DADOS_1;
	}
}

int siguienteLaberinto() {
	return CASILLA_LABERINTO - 12;
}

int siguienteMuerte() {
	return 1;
}

int tirarDado() {
	int tirada = 1 + rand() % 6;
	return tirada;
}

int quienEmpieza() {
	int jugador = 1 + rand() % 2;
	return jugador;
}

int efectoPosicion(int casillaActual) {
	cout << "PASAS A LA CASILLA: " << casillaActual <<endl;

	if (esOca(casillaActual)){
		cout << "DE OCA EN OCA Y TIRO PORQUE ME TOCA" << endl;
		cout << "EN OCA LLEGAS A LA CASILLA: " << siguienteOca(casillaActual) << endl;
		if (casillaActual == 63 || siguienteOca(casillaActual) == 63) {
			cout << "GANASTE" << endl;
		}
		else {
			cout << "VUELVES A TIRAR" << endl;
			
		}
		return siguienteOca(casillaActual);
		
	}
	else {
		if (esPuente(casillaActual)) {
			
			cout << "DE PUENTE EN PUENTE Y TIRO PORQUE ME LLEVA LA CORRIENTE" << endl;
			cout  << "SALTAS AL PUENTE DE LA CASILLA: " << siguientePuente(casillaActual) << endl;
			cout << "VUELVES A TIRAR" << endl;
			return siguientePuente(casillaActual);
		}
		else {
			if (esMuerte(casillaActual)) {
				cout << endl << "PASAS A LA CASILLA: " << siguienteMuerte();
				return siguienteMuerte();
			}
			else {
				if (esDados(casillaActual)) {
					cout << "DE DADO EN DADO Y TIRO PORQUE ME HA TOCADO" << endl;
					cout  << "PASAS AL DADO: " << siguienteDado(casillaActual) << endl;
					cout << "VUELVES A TIRAR" << endl;
					return siguienteDado(casillaActual);
				}
				else {
					if (esLaberinto(casillaActual)) {
						cout << "PASAS A LA CASILLA: " << siguienteLaberinto();
						return siguienteLaberinto();
					}
					else {
						return casillaActual;
					}
				}

			}
		}
			
	}
}

int efectoTiradas(int casillaActual, int numeroDeTiradas) {
	if (esDados(casillaActual) || esOca(casillaActual) || esPuente(casillaActual)) {
		return numeroDeTiradas += 1;
	}
	else {
		if (esPosada(casillaActual)) {
			return numeroDeTiradas -= 1;
		}
		else {
			if (esPrision(casillaActual)) {
				return numeroDeTiradas -= 2;
			}
			else {
				if (esPozo(casillaActual)) {
					return numeroDeTiradas -= 3;
				}
				else {
					return numeroDeTiradas;

				}
			}
		}
	}

}

int tirarDadoManual() {
	int dado;
	cout << "INTRODUCE EL VALOR DEL DADO: " << endl;
	cin >> dado;
	return dado;
}
