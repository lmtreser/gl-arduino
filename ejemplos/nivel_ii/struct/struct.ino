/* Tipos de datos estructurados

  Es posible definir estructuras de datos que agrupan campos
  de otros tipos de datos. La sintaxis se muestra a continuación:

    struct nombre_de_la_estructura
    {
      tipo_1 nombre_del_campo1;
      tipo_2 nombre_del_campo2;
      ...
      tipo_N nombre_del_campoN;
    }; estructura1, estructura2;

  La construcción anterior sólo define un nuevo tipo de datos, no
  se declara variable alguna. Es decir, la construcción anterior
  tiene la misma entidad que el tipo “int” o “float”. El nombre del
  nuevo tipo estructurado definido es “struct nombre_de_la_estructura”.

*/

// Constantes para definir el tamaño de los arreglos de datos usados
const int NOMBRE_SIZE = 15;
const int APELLIDO_SIZE = 15;

// Declaración de una estructura de datos
struct usuario {
  unsigned long dni;
  char nombre[NOMBRE_SIZE];
  char apellido[APELLIDO_SIZE];
  boolean permiso;
};

// Declaración de variables usando la estructura creada
struct usuario persona1, persona2;

void setup() {

  Serial.begin(9600);

  // Cargar datos a la primera variable de la estructura
  // Para cargar un string en los arreglos de char se utiliza
  // la función strcpy --> strcpy(array, string)
  persona1.dni = 20234567;
  strcpy(persona1.nombre, "Bilbo");
  strcpy(persona1.apellido, "Bolson");
  persona1.permiso = false;

  // Cargar datos a la segunda variable de la estructura
  persona2.dni = 25876543;
  strcpy(persona2.nombre, "Frodo");
  strcpy(persona2.apellido, "Bolson");
  persona2.permiso = true;

}

void loop() {

  // Mostrar datos de la primera variable de la estructura
  Serial.println("-- PERSONA #1 --");
  Serial.print("- DNI: ");
  Serial.println(persona1.dni);
  Serial.print("- NOMBRE: ");
  Serial.println(persona1.nombre);
  Serial.print("- APELLIDO: ");
  Serial.println(persona1.apellido);
  Serial.print("- PERMISO: ");
  Serial.println(persona1.permiso);
  Serial.println("");
  delay(1000);

  // Mostrar datos de la primera variable de la estructura
  Serial.println("-- PERSONA #2 --");
  Serial.print("- DNI: ");
  Serial.println(persona2.dni);
  Serial.print("- NOMBRE: ");
  Serial.println(persona2.nombre);
  Serial.print("- APELLIDO: ");
  Serial.println(persona2.apellido);
  Serial.print("- PERMISO: ");
  Serial.println(persona2.permiso);
  Serial.println("");
  delay(1000);

}
