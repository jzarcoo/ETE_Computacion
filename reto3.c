#include <stdio.h>
int main() 
{
  int opc, alto_A, alto_T, cont1, espacio, letra, ULAM, calif[9], calif_A=0, calif_R=0;
  float promedio=0;
  do
  {
    printf("\n\nMENU\n\n1. Calificaciones");
    printf("\n2. Conjetura de ULAM/Collatz");
    printf("\n3. Pinito navideño");
    printf("\n4. Salir\nOPCION (1/4): ");
    scanf("\n%i", &opc);
    switch(opc)
    {
      case 1:
        calif_A=0;
        calif_R=0;
        printf("\n\n\tCALIFICACIONES\n\n");
        for(cont1=0;cont1<10;cont1++)
        {
          do
          {
            printf("Calificación materia %i: ", 1+cont1);
            scanf("\n%i", &calif[cont1]);
            if(calif[cont1]<0 || calif[cont1]>10)
              printf("\n¡¡Calificación inválida!!\n\n");
            else
            {
              promedio+=calif[cont1];
              if(calif[cont1]<6)
                calif_R++;
              else
                calif_A++;
            }
          }
          while(calif[cont1]<0 || calif[cont1]>10);
        }
        printf("\nEl promedio de las calificaciones es: %.1f", promedio/=10);
        if(calif_R==1)
          printf("\n%i materia reprobada y ", calif_R);
        else
          printf("\n%i materias reprobadas y ", calif_R);
        if(calif_A==1)
          printf("%i materia aprobada.\n", calif_A);
        else
          printf("%i materias aprobadas.\n", calif_A);
        break;
      case 2:
        printf("\n\n\tCONJETURA DE ULAM/COLLATZ\n");
        do
        {
          printf("\nDame un número entero positivo: ");
          scanf("\n%i", &ULAM);
          if(ULAM==0)
            printf("No hay números por mostrar, introduzca otro valor.\n");
          if(ULAM<0)
            printf("Ese no es un número válido, introduzca otro valor.\n");
        }
        while(ULAM<1);
        cont1=1;
        if(ULAM==1)
          printf("1.\nEsta sucesión tiene %i término.\n", cont1);
        else
        {
          while(ULAM!=1)
          {
            printf("%i, ",ULAM);
            if(ULAM%2==0)
              ULAM/=2;
            else
              ULAM=ULAM*3+1;
            cont1++;
          }
          printf("1.\nEsta sucesión tiene %i términos.\n", cont1);
        }
        break;
      case 3:
        printf("\n\n\tPINITO NAVIDEÑO\n");
        do
        {
          printf("\nAlto de la punta: ");
          scanf("\n%i", &alto_A);
          if(alto_A>10 || alto_A<3 || alto_A%2==0)
            printf("Ese no es un número válido, introduzca otro valor.\n");
        }
        while(alto_A>10 || alto_A<3 || alto_A%2==0);
        do
        {
          printf("\nAlto del rectángulo: ");
          scanf("\n%i", &alto_T);
          if(alto_T>10 || alto_T<3)
            printf("Ese no es un número válido, introduzca otro valor.\n");
        }
        while(alto_T>10 || alto_T<3);
        for(cont1=1;cont1<=alto_A;cont1++)
        {
          printf("\n\t");
          for(espacio=0;espacio<alto_A-cont1;espacio++)
            printf(" ");
          for(letra=0;letra<cont1*2-1;letra++)
            printf("A");
        }
        for(cont1=1;cont1<=alto_T;cont1++)
        {
          printf("\n\t");
          for(espacio=1;espacio<=alto_A/2+1;espacio++)
            printf(" ");
          for(letra=1;letra<=alto_A-2;letra++)
            printf("T");
        }
        break;
      default:
        if(opc!=4)
          printf("\n\n\tOPCIÓN NO DISPONIBLE\n");
    }
  }
  while(opc!=4);
  return 0;
}
