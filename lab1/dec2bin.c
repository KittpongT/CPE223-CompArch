/*
    CPE223 :: Computer Architecture
    Number Reoresentation Lab
    This code is to convert decimal number to binary number in 3 ways:
    1. Sign & Magnitude
    2. 1's Complement
    3. 2's Complement

    Team members:
    65070501003 Kittipong Tapyou
    65070501050 Wonsatorn Sungsilapawech
    65070501059 Apichat Aimimpak
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 32

char *findBin(int n)
{
    char *binary = (char *)malloc(sizeof(char) * MAX);
    int i = 0;
    while (n > 0)
    {
        binary[i++] = n % 2 + '0';
        n /= 2;
    }
    binary[i] = '\0';
    return binary;
}

void invertBits(char *binary)
{
    while (*binary)
    {
        *binary = (*binary == '0') ? '1' : '0';
        binary++;
    }
}

char *signMagnitude(int n)
{
    int i = 0;
    char sign = n < 0 ? '1' : '0';
    n = n < 0 ? -n : n;

    char *binary = findBin(n);
    int nbits = strlen(binary);
    char *temp = (char *)malloc(sizeof(char) * (MAX + 1));
    temp[0] = sign;

    for (i = 1; i <= nbits; i++)
    {
        temp[i] = binary[nbits - i];
    }
    temp[i] = '\0';

    return temp;
}

char *onesComplement(int n)
{
    if (n < 0)
    {
        char *temp = signMagnitude(-n);
        invertBits(temp);
        return temp;
    }
    else
    {
        char *temp = signMagnitude(n);
        return temp;
    }
}

char *twosComplement(int n)
{
    char *temp = onesComplement(n);

    if (n < 0)
    {
        int carry = 1;
        for (int i = strlen(temp) - 1; i >= 0; i--)
        {
            if (temp[i] == '1' && carry == 1)
            {
                temp[i] = '0';
            }
            else if (temp[i] == '0' && carry == 1)
            {
                temp[i] = '1';
                carry = 0;
            }
        }
    }

    return temp;
}

int main()
{
    int n;
    printf("Enter decimal number:");
    scanf("%d", &n);

    printf("\nBinary>>>>>>>>>>>>>>>>>>>\n");
    printf("Sign & Magnitude: %s\n", signMagnitude(n));
    printf("1's Complement: %s\n", onesComplement(n));
    printf("2's Complement: %s\n", twosComplement(n));

    return 0;
}