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
  // reserverar minne
  int *numbers = (int *)malloc((max + 1) * sizeof(int));


  // sparar värderna från 2 till angivna numret i terminalen
  for (int i = 2; i <= max; i++) 
  {
        numbers[i] = i;
  }

  // verkställer the Sieve of Eratosthenes algorithm
  for (int p = 2; p * p <= max; p++) 
  {
    if (numbers[p] != 0) 
    {  // hoppar över om värdet vid indexet redan är markerat som icke-prim
        for (int i = p * p; i <= max; i += p) 
        {
            numbers[i] = 0;  // markerar indexen som icke-prim med 0
        }
    }
  }

  // skriver ut de kvarstående siffrorna
  
  for (int i = 2; i <= max; i++) 
  {
        if (numbers[i] != 0) 
        {
            print_number(i);
            

        }
  }
  

  // frigör minnet
  free(numbers);
}

int main(int argc, char *argv[]) {
  int max_number;

  if (argc == 2) {
    max_number = atoi(argv[1]);
  } else {
    printf("write a number: ");
    scanf("%d", &max_number);
  }

  print_sieves(max_number);
  print_sieves(max_number);

  return 0;
}
