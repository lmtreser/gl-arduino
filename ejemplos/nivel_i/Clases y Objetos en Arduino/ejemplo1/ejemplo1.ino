class Contador {

  private:
    int N ;

  public:
    // Constructor
    Contador() {
      N = 0 ;
    }

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

void setup() {
}

Contador C1,C2;

void loop() {

  Serial.println( C1.GetCont() ) ;
  Serial.println("...............");

  C1.Incrementar() ;
  Serial.print("C1 = ") ;
  Serial.println( C1.GetCont() ) ;

  C2.Incrementar() ;
  C2.Incrementar() ;
  C2.Incrementar() ;
  Serial.print("C2 = ") ;
  Serial.println( C2.GetCont() ) ;

  Serial.flush();   exit(0);
}
