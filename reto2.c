#include <stdio.h>
#include <ctype.h>
int main() {
  int opc, cont1, cont2=0, numF, terminos, ancho, num1=0, num2=1, space, ast,i;
  long int factorial=1, fibonacci=1;
  char relleno;
  int hola1=5;
  printf("MENU\n1. Dibujar diamante\n2. Dibujar tablero ajedrez\n3. Secuencia de Fibonacci\n4. Factorial de un número\n5. Salir\nOPCION (1/5): ");
  scanf("\n%i", &opc);
  switch(opc){
    case 1:
      printf("\nDIAMANTE\n\nLongitud de la diagonal: ");
      scanf("\n%i", &ancho);
      if(ancho<=0 || ancho%2==0)
        printf("\nERROR");
      else{
        printf("¿Con relleno? (S/N): ");
        scanf("\n%c", &relleno);
        for(i=1; i<=ancho/2+1; i++){
          for(space=1; space<=ancho/2+1-i; space++) 
            printf(" ");
          if(i!=1) // se imprime siempre, excepto en el primer ciclo
            printf("*");
          for(ast=1; ast<i*2-2; ast++)
            if(relleno=='s'||tolower(relleno)=='s')
              printf("*");
            else
              printf(" ");
          printf("*\n");
        }
        for(i=1; i<=ancho/2; i++){
          for(space=1; space<=i; space++) 
            printf(" ");
          printf("*");
          for(ast=1; ast<ancho-i*2-1; ast++)
            if(toupper(relleno)=='S'||relleno=='S')
              printf("*");
            else
              printf(" ");
          if(i<=ancho/2-1) // se imprime siempre, excepto en el último ciclo
            printf("*\n");
        }
      }
      break;
    case 2:
      printf("\nTABLERO DE AJEDREZ\n\n");
      for(cont1=1;cont1<9;cont1++){
        printf("\t|");
        if(cont1%2==0)
          for(cont2=1;cont2<5;cont2++)
            printf(" #");
        else
          for(cont2=1;cont2<5;cont2++)
            printf("# ");
        printf("|\n");
      }
      break;
    case 3:
      printf("\nSECUENCIA DE FIBONACCI\n\nNúmero de términos: ");
      scanf("\n%i", &terminos);
      if(terminos<0)
        printf("Ese no es un número válido");
      if(terminos==0)
        printf("No hay números por mostrar");
      if(terminos>=1){
        if(terminos>1)
          printf("Los primeros %i términos de la sucesión de Fibonacci son:\n", terminos);
        else
          printf("El primer término de la sucesión de Fibonacci es:\n");
        for(cont1=1;cont1<=terminos;cont1++){
          printf("%li", fibonacci);
          fibonacci=num1+num2;
          num1=num2;
          num2=fibonacci;
          if(cont1<terminos)
            printf(", ");
        }
      }
      printf(".");
      break;
    case 4:
      printf("\nFACTORIAL DE UN NÚMERO\n\nIntroduzca un número positivo: ");
      scanf("\n%i", &numF);
      for(cont1=1;cont1<=numF;cont1++)
        factorial*=cont1;
      if(numF<0)
        printf("Número inválido, sólo puedo calcular el factorial de números positivos.");
      else
        printf("El factorial de %i es: %li.", numF, factorial);
      break;
    default:
      if(opc!=5)
        printf("\nOpción no disponible");
  }
  return 0;
}
