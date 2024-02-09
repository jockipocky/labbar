#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

//by jacob

// Function to check if a number is prime
int is_prime(int num)
{
    if (num < 2) {
        return 0; // Not prime
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Not prime
        }
    }
    return 1; // Prime
}

// Function to print a number in the specified format
void print_number(int num)
{
    static int count = 0;
    printf("%10d ", num); //skapar ett mellan rum mellan talen så att de kan staplas på varandra när de skrivs ut.
    count ++;
    if(count == COLUMNS)
    {
        printf("\n");
    }
   


}
// Function to print prime numbers up to n
void print_primes(int n)
{
    
    int count = 1;
    for (int i = 2; i <= n; i++) {

        print_number(i);
    }

}


int main(int argc, char *argv[])
{
    int max_number;

    if (argc == 2) {
        max_number = atoi(argv[1]);
    } else {
        printf("Please enter a number: ");
        scanf("%d", &max_number);
    }

    print_primes(max_number);
    print_primes(max_number);
    return 0;
}