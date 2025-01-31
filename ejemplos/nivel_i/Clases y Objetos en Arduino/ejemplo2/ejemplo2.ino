class Contador {
  private:
    int N ;

  public:
    Contador() ;                   // Constructor
    void SetContador(int n) ;      // Declaracion de funcion externa
    void Incrementar() ;            // Declaracion de funcion externa
    int GetCont() ;                 // Declaracion de funcion externa
} ;

// ----------------------------------------
void Contador::SetContador(int n) {
  N = n ;
}

void Contador::Incrementar() {
  N++ ;
}

int Contador::GetCont() {
  return (N);
}
