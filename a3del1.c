#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

//by jacob

void print_number(int num)
{
    static int count = 0;
    printf("%10d ", num); //skapar ett mellan rum mellan talen så att de kan staplas på varandra när de skrivs ut.
    count ++;
    if(count == COLUMNS)
    {
        printf("\n");
        count = 0;
    }
}

void print_sieves(int max) 
{
  // reserverar minne genom att bestämma längden av array
    int numbers[max + 1];

  // ger array värden mellan 2-max alltså nummret som användare valde
    for (int i = 2; i <= max; i++) 
    {
        numbers[i] = i;
    }

  // aplicera the Sieve of Eratosthenes algorithm
    for (int p = 2; p * p <= max; p++) //p * p är för att inget sammansatt tal har primfaktorer som är större än roten ur talet
    {
        if (numbers[p] != 0) 
        {  // hoppa över om index redan blivit markerat som icke-prim
            for (int i = p * p; i <= max; i += p) //addear väret på p varje gång
            {
                numbers[i] = 0;  // markerar flera tal i array till 0 om talen är icke-prim
            }
        }
    }

  // skrier ut prim talen

    for (int i = 2; i <= max; i++) 
    {
        if (numbers[i] != 0) 
        {
            print_number(i);
            

        }
    }
    
}

int main(int argc, char *argv[]) {
  int max_number;

  if (argc == 2) {
    max_number = atoi(argv[1]);
  } else {
    printf("Please enter an integer number as a command-line argument: ");
    scanf("%d", &max_number);
  }

  print_sieves(max_number);

  return 0;
}
