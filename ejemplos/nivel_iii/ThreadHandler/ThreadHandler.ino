#include "ThreadHandler.h"

int freeMemory();

//first we need to configure ThreadHandler
//1ms driving interrupt
SET_THREAD_HANDLER_TICK(1000)

//using default interrupt timer
THREAD_HANDLER(InterruptTimer::getInstance())

//next we need to create the threads
// //this can be done using the createThread function with a lambda
// Thread* thread1 = createThread(prio, period, offset,
//         []()
//         {
//             //code to run
//         });
// 
// //or with a function pointer
// void run()
// {
//     //code to run
// }
// 
// Thread* thread2 = createThread(prio, period, offset, run);

//but using inheritance is slightly more memory efficient

uint16_t numberOfCreatedThreads = 0;
uint16_t minFreeMemory = -1;
uint16_t priorityMaxTimingError[7] = {0};

class MyThread : public Thread {
public:
    MyThread() : Thread(
        //we want to spread out the threads over 7
        //different priorities
        numberOfCreatedThreads % 7,
        //and we want 6ms period
        6000,
        //and to even out the CPU load we
        //want the start time of the threads
        //to be offset
        1000 * (numberOfCreatedThreads / 12))
    {
        numberOfCreatedThreads++;
    }

    void run() override
    {
        //since all threads will read and write to the monitoring variable
        // we need to add a critical section to avoid racing conditions

        //critical section
        {
            ThreadInterruptBlocker blocker;

            //lets add some code for monitoring memory usage and timing errors

            uint16_t mem = freeMemory();

            if (mem < minFreeMemory)
            {
                minFreeMemory = mem;
            }

            uint16_t timingError = getTimingError();

            uint16_t& maxTimingErrorForPrio = priorityMaxTimingError[getPriority()];

            if (timingError > maxTimingErrorForPrio)
            {
                maxTimingErrorForPrio = timingError;
            }
        }

    }
};

//max size thread array on 
// Arduino Uno:
//      16MHz, 2KB SRAM (ATmega328P)
MyThread threads[7];

//will you ever need 57 threads?
//probably not... so lets try and
//see how ThreadHandler perform with
//just 7 threads
//MyThread threads[7];

void printHeader();

void setup()
{
    Serial.begin(9600);

    //lets also add a nice header printout
    printHeader();

    //to start thread execution we need to call the enableThreadExecution function
    ThreadHandler::getInstance()->enableThreadExecution();
}

void loop()
{
    //next we need to print out the monitoring data
    // with some nice formating

    //we want to print every 500ms
    delay(500);

    Serial.print("| ");

    for (auto& timingError : priorityMaxTimingError)
    {
        uint16_t timingErrorCopy;

        //critical section
        {
            ThreadInterruptBlocker blocker;

            timingErrorCopy = timingError;
            timingError = 0;
        }

        Serial.print(timingErrorCopy);
        Serial.print("us| ");
    }

    uint16_t minMemCopy;

    //critical section
    {
        ThreadInterruptBlocker blocker;

        minMemCopy = minFreeMemory;
        minFreeMemory = -1;
    }

    Serial.print(minMemCopy);
    Serial.print("b| ");
    Serial.print(ThreadHandler::getInstance()->getCpuLoad());
    Serial.println("%|");
}

//to minimize SRAM usage this function will only use
//Serial.print(char). It is quite long so I will just
//copy it in

//SRAM memory optimized function to print header text:
//
//  | Max absolute timing error for each priority    | Free mem|
//  |------------------------------------------------|    ______
//  |   0  |   1  |   2  |   3  |   4  |   5  |   6  |    | CPU|
//
#define p(c) Serial.print(c)
#define pl(c) Serial.println(c)
void printHeader()
{
    p('|');
    p(' ');
    p('M');
    p('a');
    p('x');
    p(' ');
    p('a');
    p('b');
    p('s');
    p('o');
    p('l');
    p('u');
    p('t');
    p('e');
    p(' ');
    p('t');
    p('i');
    p('m');
    p('i');
    p('n');
    p('g');
    p(' ');
    p('e');
    p('r');
    p('r');
    p('o');
    p('r');
    p(' ');
    p('f');
    p('o');
    p('r');
    p(' ');
    p('e');
    p('a');
    p('c');
    p('h');
    p(' ');
    p('p');
    p('r');
    p('i');
    p('o');
    p('r');
    p('i');
    p('t');
    p('y');
    p(' ');
    p(' ');
    p(' ');
    p(' ');
    p('|');
    p(' ');
    p('F');
    p('r');
    p('e');
    p('e');
    p(' ');
    p('m');
    p('e');
    p('m');
    pl('|');

    p('|');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('-');
    p('|');
    p(' ');
    p(' ');
    p(' ');
    p(' ');
    p('_');
    p('_');
    p('_');
    p('_');
    p('_');
    pl('_');

    p('|');
    p(' ');
    p(' ');
    p(' ');
    p('0');
    p(' ');
    p(' ');
    p('|');
    p(' ');
    p(' ');
    p(' ');
    p('1');
    p(' ');
    p(' ');
    p('|');
    p(' ');
    p(' ');
    p(' ');
    p('2');
    p(' ');
    p(' ');
    p('|');
    p(' ');
    p(' ');
    p(' ');
    p('3');
    p(' ');
    p(' ');
    p('|');
    p(' ');
    p(' ');
    p(' ');
    p('4');
    p(' ');
    p(' ');
    p('|');
    p(' ');
    p(' ');
    p(' ');
    p('5');
    p(' ');
    p(' ');
    p('|');
    p(' ');
    p(' ');
    p(' ');
    p('6');
    p(' ');
    p(' ');
    p('|');
    p(' ');
    p(' ');
    p(' ');
    p(' ');
    p('|');
    p(' ');
    p('C');
    p('P');
    p('U');
    pl('|');
}

//freeMemory implementation

#if !defined(__AVR__)

#ifdef __arm__
// should use uinstd.h to define sbrk but Due causes a conflict
extern "C" char* sbrk(int incr);
#else  // __ARM__
extern char *__brkval;
#endif  // __arm__
 
int freeMemory() {
  char top;
#ifdef __arm__
  return &top - reinterpret_cast<char*>(sbrk(0));
#elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
  return &top - __brkval;
#else  // __arm__
  return __brkval ? &top - __brkval : &top - __malloc_heap_start;
#endif  // __arm__
}

#else

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

extern unsigned int __heap_start;
extern void *__brkval;

/*
 * The free list structure as maintained by the
 * avr-libc memory allocation routines.
 */
struct __freelist {
  size_t sz;
  struct __freelist *nx;
};

/* The head of the free list structure */
extern struct __freelist *__flp;

/* Calculates the size of the free list */
int freeListSize() {
  struct __freelist* current;
  int total = 0;
  for (current = __flp; current; current = current->nx) {
    total += 2; /* Add two bytes for the memory block's header  */
    total += (int) current->sz;
  }
  return total;
}

int freeMemory() {
  int free_memory;
  if ((int)__brkval == 0) {
    free_memory = ((int)&free_memory) - ((int)&__heap_start);
  } else {
    free_memory = ((int)&free_memory) - ((int)__brkval);
    free_memory += freeListSize();
  }
  return free_memory;
}

#endif
