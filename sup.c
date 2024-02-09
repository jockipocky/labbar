#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6


void print_sieves(int max) 
{
  // reserverar minne genom att bestämma längden av array
    int numbers[max * max];

  // ger array värden mellan 2-max alltså nummret som användare valde
    for (int i = 2; i <= max * max; i++) 
    {
        numbers[i] = i;
    }

  // aplicera the Sieve of Eratosthenes algorithm
  int count1 = 1;
  int p = 2;
  while(count1 < max)
  {
        if (numbers[p] != 0) 
        {  // hoppa över om index redan blivit markerat som icke-prim
            for (int i = p * p; i <= max * max; i += p) //addear väret på p varje gång
            {
                numbers[i] = 0;  // markerar flera tal i array till 0 om talen är icke-prim
            }
            count1++;
        }
        p++;
  }


  // skrier ut prim talen
    int count = 1;
    int i = 2;
    while( count < max)
    {
        i++;
        if (numbers[i] != 0) 
        {   
            count++;
        }
    }
    printf("%10d ",numbers[i]);

    printf("\n");
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
