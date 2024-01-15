#include <stdio.h>
#define PI 3.1416
int main() 
{
  int opc, num, dinero;
  float tempC, tempF, r, h;
  printf("Bienvenido Usuario\n\nMENU");
  printf("\n1. Conversión de Celsius a Fahrenheit");
  printf("\n2. Conversión de Fahrenheit a Celsius");
  printf("\n3. Cálculo de mi cambio");
  printf("\n4. Volumen de un cono");
  printf("\n5. Salir\nOPCION (1/5): ");
  scanf("\n%i", &opc);
  switch(opc)
  {
    case 1:
      printf("\nTemperatura en Celsius: ");
      scanf("\n%f", &tempC);
      printf("La temperatura en grados Fahrenheit es %.2f", 32+tempC*1.8);
      break;
    case 2:
      printf("\nTemperatura en Fahrenheit: ");
      scanf("\n%f", &tempF);
      printf("La temperatura en grados Celsius es %.2f", (tempF-32)*(5.0/9));
      break;
    case 3:
      printf("\nCantidad $");
      scanf("\n%i", &dinero);
      if(dinero>=1000)
      {
        if((num=dinero/1000)==1)
          printf("%i\r1 billete de $1000\n", dinero-=1000);
        else
          printf("%i\r%i billetes de $1000\n", dinero-=num*1000, num);
      }
      if(dinero>=500)
        printf("%i\r1 billete de $500\n", dinero-=500);
      if(dinero>=200)
      {
        if((num=dinero/200)==1)
          printf("%i\r1 billete de $200\n", dinero-=200);
        else
          printf("%i\r2 billetes de $200\n", dinero-=400);
      }
      if(dinero>=100)
        printf("%i\r1 billete de $100\n", dinero-=100);
      if(dinero>=50)
        printf("%i\r1 billete de $50\n", dinero-=50);
      if(dinero>=20)
      {
        if((num=dinero/20)==1)
          printf("%i\r1 billete de $20\n", dinero-=20);
        else
          printf("%i\r2 billetes de $20\n", dinero-=40);
      }
      if(dinero>=10)
        printf("%i\r1 moneda de $10\n", dinero-=10);
      if(dinero>=5)
        printf("%i\r1 moneda de $5\n", dinero-=5);
      if(dinero>=2)
      {
        if((num=dinero/2)==1)
          printf("%i\r1 moneda de $2\n", dinero-=2);
        else
          printf("%i\r2 monedas de $2\n", dinero-=4);
      }
      if(dinero==1)
        printf("1 moneda de $1");
      break;
    case 4:
      printf("\nRadio: ");
      scanf("\n%f", &r);
      printf("Altura: ");
      scanf("\n%f", &h);
      printf("El volumen del cono es %.2f", (PI*h*r*r)/3);
      break;
    default:
      if(opc!=5)
        printf("\nOpción no disponible");
  }
  return 0;
}
