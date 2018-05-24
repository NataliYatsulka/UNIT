#include <stdio.h>
#include <stdlib.h>

int g_massPal;
int g_arrPrime;
int g_secondPrime;


void findMaxPalidrome(int massPal, int firstPr, int *arrPrime)
{
    int a;
    int b;
    int i;
    
    a = massPal / firstPr;
    b = massPal%firstPr;
    i = g_arrPrime;
    if (b == 0)
    {
        while (i-- >= 0)
        {
            if (a == arrPrime[i]) {
                g_secondPrime = a;
                break ;
            }
        }
    }
    return ;
}

int check_prime(int number)
{
    int tmp;
    
    tmp = 0;
    if ((number % 2 == 0) || (number % 3 == 0) || (number % 5 == 0))
        return 0;
    for (int i = 4; i < number; i++)
    {
        if (number % i == 0)
            tmp = 0;
        if (number == i + 1)
            tmp = 1;
    }
    return tmp;
}

int check_palindrome(int numb)
{
    int tmp = 0;
    int reverse = 0;
    
    tmp = numb;
    while(tmp != 0){
        reverse = reverse * 10;
        reverse = reverse + (tmp % 10);
        tmp = tmp / 10;
    }
    if (numb == reverse)
        return 1;
    else
        return 0;
}

int main()
{
    int *arrPrime;
    int *massPalindrome;
    int firstPrime;
    int k;
    int j;
    
    g_massPal = 0;
    g_secondPrime = -1;
    k = 0;
    j = 0;
    arrPrime = (int *)malloc(sizeof(int));
    massPalindrome = (int *)malloc(sizeof(int));
    for (int i = 100000000; i <= 9999800001; i++) {
        if (check_palindrome(i) == 1){
            massPalindrome[g_massPal] = i;
            //            printf("%d, ", massPalindrome[g_massPal]);
            g_massPal++;
        }
    }
    printf("\n\n\n");
    g_arrPrime = 0;
    for (int i = 10000; i < 99999; i++)
    {
        if (check_prime(i) == 1){
            arrPrime[g_arrPrime] = i;
            //            printf("%d, ", arrPrime[g_arrPrime]);
            g_arrPrime++;
        }
    }
    j = g_massPal;
    while (j-- >= 0)
    {
        k = g_arrPrime;
        while (k-- >= 0) {
            firstPrime = arrPrime[k];
            findMaxPalidrome(massPalindrome[j], firstPrime, arrPrime);
            if (g_secondPrime > 0)
            {
                printf("%d, %d, %d", firstPrime, g_secondPrime, massPalindrome[j]);
                break ;
            }
        }
    }
    printf("\ng_massPal = %d\n", g_massPal);
    printf("\ng_arPrime = %d\n", g_arrPrime);
    return (0);
}
