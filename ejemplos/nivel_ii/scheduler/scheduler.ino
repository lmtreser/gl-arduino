/* Programador de Tareas

   Un TaskScheduler es un programador de tareas que permiten crear
   tareas periódicas sin tener que usar millis o condicionales.

   https://github.com/arkhipenko/TaskScheduler
*/

#include <TaskScheduler.h>

// Declarar las funciones a ejecutar como tareas
void led_blink();
void mensajito();

// Crear el Scheduler que se encargará de gestionar las tareas
Scheduler runner;

// Crear las tareas indicando el tiempo, para siempre, y la función
Task TareaLED(500, TASK_FOREVER, &led_blink);
Task TareaMSG(1000, TASK_FOREVER, &mensajito);

bool statusLED = false;

void setup() {

  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  // Añadir las tareas al programador de tareas
  runner.addTask(TareaLED);
  runner.addTask(TareaMSG);

  // Activar las tareas
  TareaLED.enable();
  TareaMSG.enable();
}

void loop() {

  // Ejecutar el runner en cada loop
  runner.execute();

}

// Función que hace destellar un LED
void led_blink() {
  statusLED = !statusLED;
  digitalWrite(LED_BUILTIN, statusLED);
}

// Función que escribe en el monitor serie
void mensajito() {
  Serial.println("Una segunda tarea en ejecución");
}
