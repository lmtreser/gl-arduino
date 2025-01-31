class Contador {

  private:
    int N ;

  public:
    void SetContador( int n) {
      N = n ;
    }

    void Incrementar() {
      N++ ;
    }

    int GetCont() {
      return (N) ;
    }
} ;

Contador C1, C2 ;

void setup() {

}

void loop() {

  C1.SetContador(0);
  C1.Incrementar() ;
  Serial.print("C1 = ") ;
  Serial.println( C1.GetCont() ) ;

  C2.SetContador(0);
  C2.Incrementar() ;
  C2.Incrementar() ;
  C2.Incrementar() ;
  Serial.print("C2 = ") ;
  Serial.println( C2.GetCont() ) ;

  Serial.flush();   exit(0);      // Abandonar el programa
}
