#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int ganar( char frase[] ){
  int i = 0, s = 0;
  while( frase[i] != '\0' ){
    if( frase[i] == '_')
      s++;
    i++;
  }
  return s;
}
void plural(int variable){
  if(variable != 1)
    printf("s)");
  else
    printf(")");
}
void jugador(char *apu_tablero, int turno, int x, int y){
  if (turno%2 == 0)
    *(apu_tablero+(x*3)+y) = 'O';
  else
    *(apu_tablero+(x*3)+y) = 'X';
}
void impresion(char *apu_matriz, int filas, int columnas){
  int i, j;
  printf("\n");
  for ( i = 0; i < filas; i++ ){
    for ( j = 0; j < columnas; j++ ){
      printf( "\t%c\t" , *apu_matriz );
      if( j < columnas-1 )
        printf("|");
      apu_matriz++;
    }
    if( i < filas-1 )
      printf("\n--------------------------\n");
  }
  printf("\n");
}
void ahorcado(char *apu_ahorcado, int filas, int columnas, int parte){
  int i, j;
  printf("\n");
  if( parte == 2)
    *(apu_ahorcado+(3*9)+6) = 'O'; 
  if( parte == 1){
    *(apu_ahorcado+(4*9)+5) = '/'; 
    *(apu_ahorcado+(4*9)+6) = '|'; 
    *(apu_ahorcado+(4*9)+7) = '\\'; 
  }
  if( parte == 0){
    *(apu_ahorcado+(5*9)+5) = '/'; 
    *(apu_ahorcado+(5*9)+7) = '\\'; 
  }
  for ( i = 0; i < filas; i++ ){
    for ( j = 0; j < columnas; j++ ){
      printf( "%c" , *apu_ahorcado );
      apu_ahorcado++;
    }
    printf("\n");
  }
  printf("\n");
}
int ganador( char tablero[][3] )
{
  int s = 0, i = 0;
  if(tablero[0][0]==tablero[1][1] && tablero[1][1]==tablero[2][2])
    s++;
  if(tablero[2][0]==tablero[1][1] && tablero[1][1]==tablero[0][2])
    s++;
  for ( i = 0; i < 3 ; i++ ){
    if(tablero[i][0]==tablero[i][1] && tablero[i][1]==tablero[i][2])
      s++;
    if(tablero[0][i]==tablero[1][i] && tablero[1][i]==tablero[2][i])
      s++;
  }
  return s;
}
int main() {
  int opc, x, y, mov, aleatorio, longitud;
  char frase[2][10], letra, palabras[12][10] = { {"manzana"}, {"helado"}, {"cuaderno"}, {"guitarra"}, {"regalo"}, {"reto"}, {"carruaje"}, {"botella"}, {"ahorcado"}, {"ave"},};
  printf("=========================================================\n");
  printf("\n\t\t\t\t\t\tRETO 5\n");
  printf("\n=========================================================");
  do{
    int i = 0, ganaste = 0, vida = 3;
    char tablero [3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
    char dibujo [9][9] = { {' ',' ','+','-','-','-','+',' ',' '},{' ',' ','|',' ',' ',' ','|',' ',' '},{' ',' ','|',' ',' ',' ','|',' ',' '},{' ',' ','|',' ',' ',' ',' ',' ',' '},{' ',' ','|',' ',' ',' ',' ',' ',' '},{' ',' ','|',' ',' ',' ',' ',' ',' '},{' ',' ','|',' ',' ',' ',' ',' ',' '},{' ',' ','|',' ',' ',' ',' ',' ',' '},{"========="}, };
    printf( "\n\nMENU\n\n1. Ahorcado\n2. Gato\n3. Salir\n\nOPCION (1/3): " );
    scanf( "\n%i" , &opc );
    switch( opc ){
      case 1:
        srand( time(NULL) );
        aleatorio = rand()%10;
        longitud = strlen( palabras[aleatorio] );
        strcpy( frase[0], palabras[aleatorio] );
        for( i = 0 ; i < longitud ; i++ )
          frase[0][i] = '_';
        printf("\n");
        do{
          ahorcado(&dibujo[0][0], 9, 9, vida);
          strcpy( frase[1], frase[0] );
          for( i = 0 ; i < longitud ; i++ )
            printf( "%c", toupper( frase[0][i] ) );
          printf(" (%i vida", vida);
          plural(vida);
          printf("\nIntroduzca una letra: ");
          scanf( "\n%c" , &letra );
          for( i = 0 ; i < longitud ; i++ )
            if( tolower(letra) == palabras[aleatorio][i] )
              frase[0][i] = palabras[aleatorio][i];
          ganaste = ganar( frase[0] );
          if ( strcmp( frase[1], frase[0] ) == 0 )
            vida--;
          if( vida == 0 )
            ganaste = 0;
        }
        while( ganaste != 0 );
        ahorcado(&dibujo[0][0], 9, 9, vida);
        for( i = 0 ; i < longitud ; i++ )
          printf( "%c", toupper( frase[0][i] ) );
        printf( " (%i vida" , vida );
        plural( vida );
        if (vida == 0)
          printf("\n\nPerdiste :( La palabra era %s", palabras[aleatorio]);
        else{
          printf("\n\n¡Ganaste! La palabra era %s y ", palabras[aleatorio]); 
          if( vida == 1 )
            printf("te quedó %i vida", vida );
          else
            printf("te quedaron %i vidas", vida );
        }
        break;
      case 2:
        printf("\n\n\tGATO\n\nJugador 1 - Cruz (X)\nJugador 2 - Círculo (O)\n"); 
        printf("\nNombre del jugador 1: ");
        scanf("%10s", palabras[10]);
        printf("Nombre del jugador 2: ");
        scanf("%10s", palabras[11]);
        do{
          impresion( &tablero[0][0] , 3 , 3 );
          i++;
          do{
            if( i % 2 == 0 )
              printf("\n¿Movimiento de %s (jugador 2)? ", palabras[11]);
            else 
              printf("\n¿Movimiento de %s (jugador 1)? ", palabras[10]);
            scanf( "\n%i" , &mov );
            if( mov < 1 || mov > 9 )
              printf("Celda inválida. Debe introducir un número entre 1 y 9.\n");
            else{
              if (mov >= 1 && mov <= 3)
                x = 0;
              if (mov >= 4 && mov <= 6)
                x = 1;
              if (mov >= 7 && mov <= 9)
                x = 2;
              if (mov == 1 || mov == 4 || mov == 7)
                y = 0;
              if (mov == 2 || mov == 5 || mov == 8)
                y = 1;
              if (mov == 3 || mov == 6 || mov == 9)
                y = 2;
              if( tablero[x][y] == 'X' || tablero[x][y] == 'O' ){
                printf("Celda ocupada, elija otra.\n");
                mov=0;
              }
              else
                jugador( &tablero[0][0], i, x, y);
            }
          }
          while( mov < 1 || mov > 9 );
        }
        while( ganador(tablero) == 0 );
        impresion( &tablero[0][0] , 3 , 3 );
        if( i % 2 == 0 )
          printf("\n\n%s (JUGADOR 2) GANA", palabras[11]);
        else
          printf("\n\n%s (JUGADOR 1) GANA" , palabras[10]);
        break;
      default:
        if(opc!=3)
          printf("\n\n\tOPCIÓN NO DISPONIBLE\n");
    }
    if( opc == 1 || opc == 2 ){
      printf(".\nPresione una tecla para regresar al menú...");
      getchar();
      getchar();
    }
  }
  while( opc != 3 );
  return 0;
}
