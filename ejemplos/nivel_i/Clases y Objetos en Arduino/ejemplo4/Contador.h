#ifndef Contador_h
#define Contador_h

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

#endif
