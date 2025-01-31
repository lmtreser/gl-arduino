#include "Contador.h"

Contador::Contador() { // Constructor
  N = 0 ;
  ++Num ;
}
void Contador::SetContador(int n) {
  N = n ;
}

void Contador::Incrementar() {
  N++ ;
}

int Contador::GetCont() {
  return (N) ;
}

int Contador::Num_Objetos() {
  return (Num) ;
}
//-----------------------------------------
int Contador::Num = 0 ;           // Cuidado aqui
//-----------------------------
