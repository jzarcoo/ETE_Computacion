#include <stdio.h>
#include <ctype.h>
#include <string.h>
void plural(int variable)
{
  if(variable!=1)
    printf("s");
}
void histograma (int asteriscos)
{
  int i = 0;
  for(i = 0; i < asteriscos; i++)
    printf("*");
}
int main() 
{
  int opc, longitud, i, j, palabra, palindroma, mayus, minus, nums, caract_esp, puntos, electores, voto;
  int candidatos[4];
  char frase[27], frase2[27], contrasenia[17];
  do
  {
    printf("\n\n\nMENU\n1. Analiza una contraseña");
    printf("\n2. Palíndromos");
    printf("\n3. Votaciones");
    printf("\n4. Salir\nOPCION (1/4): ");
    scanf("%i", &opc);
    switch(opc)
    {
      case 1:
        mayus=0;
        minus=0;
        caract_esp=0;
        nums=0;
        puntos=0;
        printf("\n\n\tANALIZA UNA CONTRASEÑA\n\n");
        printf("Introduce una contraseña de máximo 15 caractéres: ");
        getchar();
        fgets(contrasenia, 17, stdin);
        longitud = strlen(contrasenia);
        longitud -= 1;
		  // printf("%s.",contrasenia);
        contrasenia[longitud] = '\0';
		  // printf("%s.",contrasenia);
        printf("La contraseña %s tiene %i caracteres:\n", contrasenia, longitud);
        for(i = 0; i < longitud; i++)
        {
          if(islower(contrasenia[i]) != 0)
            minus++;
          if(isupper(contrasenia[i]) != 0)
            mayus++;
          if(isdigit(contrasenia[i]) != 0)
            nums++;
          if(isalnum(contrasenia[i]) == 0)
            caract_esp++;
        }
        printf("%i mayúscula", mayus);
        plural(mayus);
        printf(",\n%i minúscula", minus);
        plural(minus);
        printf(",\n%i número", nums);
        plural(nums);
        printf(" y\n%i caracter", caract_esp);
        if(caract_esp==1)
          printf(" especial.\n");
        else
          printf("es especiales.\n");
        if(mayus > 0 || minus > 0)
          puntos+=5;
        printf("\nEl puntaje de seguridad de tu contraseña es: %i.", puntos+=longitud+((nums+caract_esp)*2));
        printf("\nTu contraseña es ");
        if(puntos >= 25)
          printf("MUY ");
        if(puntos < 18 && puntos >= 11)
          printf("POCO ");
        if(puntos <= 10)
          printf("IN");
        printf("SEGURA.\n\n");
        printf("\nCaracteres\t|");
        histograma(longitud);
        printf("\nMayúsculas\t|");
        histograma(mayus);
        printf("\nMinúsculas\t|");
        histograma(minus);
        printf("\nNúmeros\t\t|");
        histograma(nums);
        printf("\nEspeciales\t|");
        histograma(caract_esp);
        break;
      case 2:
        i = 0;
        j = 0; 
        palabra = 0;
        palindroma = 0;
        printf("\n\n\tPALÍNDROMOS\n\n");
        printf("Escribe una frase de máximo 25 caracteres: ");
        getchar();
        fgets(frase, 27, stdin);
        frase[ ( strlen(frase) ) - 1 ] = '\0';
        while(frase[i] != '\0')
        {
          if(frase[i] != ' ')
          {
            frase2[j] = frase[i];
            j++;
          }
          else
            palabra++;
          i++;
        }
        frase2[j]='\0';
        longitud = strlen(frase2);
        for( i = 0; i < longitud; i++)
          if( tolower( frase2[i] ) != tolower( frase2[longitud - 1 - i] ) )
            palindroma++;
        if(palabra != 0)
          printf("La frase %s ", frase);
        else
          printf("La palabra %s ", frase);
        if(palindroma != 0)
          printf("no ");
        printf("es palindroma.");
        break;
      case 3:
        candidatos[0] = 0;
        candidatos[1] = 0;
        candidatos[2] = 0;
        candidatos[3] = 0;
        printf("\n\n\tVOTACIONES\n\n");
        printf("¿Cuántos electores votarán? ");
        do
        {
          scanf("\n%i", &electores);
          if(electores > 10 )
            printf("\nEl número máximo de electores es 10.\nPor favor ingresa otra cantidad: ");
          if(electores <= 0)
            printf("\nEl número de electores no es válido.\nPor favor ingresa otra cantidad: ");
        }
        while(electores > 10 || electores <= 0);
        for(i = 0; i < electores; i++)
        {
          printf("Voto elector %i (1/2/3/4): ", 1+i);
          do
          {
            scanf("\n%i", &voto);
            if(voto < 1 || voto > 4)
              printf("Candidato no registrado. Voto elector %i (1/2/3/4): ", 1+i);
          }
          while(voto < 1 || voto > 4);
          candidatos[voto-1]++;
        }
        printf("\n----Resultados----");
        for(i = 0; i < 4; i++)
        {
          printf("\nCandidato %i: %i voto", 1+i, candidatos[i]);
          plural(candidatos[i]);
        }
        printf("\n\n#####################\n");
        if(candidatos[0]>candidatos[1] && candidatos[0]>candidatos[2] && candidatos[0]>candidatos[3])
          printf(" Gano el candidato 1");
        else
          if(candidatos[1]>candidatos[0] && candidatos[1]>candidatos[2] && candidatos[1]>candidatos[3])
            printf(" Gano el candidato 2");
          else
            if(candidatos[2]>candidatos[0] && candidatos[2]>candidatos[1] && candidatos[2]>candidatos[3])
              printf(" Gano el candidato 3");
            else
              if(candidatos[3]>candidatos[0] && candidatos[3]>candidatos[1] && candidatos[3]>candidatos[2])
                printf(" Gano el candidato 4");
              else
                printf("\tHubo un empate");
        printf("\n#####################");
        break;
      default:
        if(opc!=4)
          printf("\n\n\tOPCIÓN NO DISPONIBLE");
    }
  }
  while(opc!=4);
  return 0;
}