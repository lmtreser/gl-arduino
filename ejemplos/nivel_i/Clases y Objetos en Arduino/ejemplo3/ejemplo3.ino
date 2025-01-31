// Una Clase con Constructor y variable static

class Contador {
  private:
    int N ;
    static int Num ;

  public:
    Contador() ; // Constructor
    void SetContador(int n) ;
    void Incrementar() ;
    int GetCont() ;
    int Num_Objetos() ;
} ;
// :: operador de ámbito
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
Contador C1, C2, C3 ;

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(C1.Num_Objetos());
  Serial.flush();   exit(0);
}
