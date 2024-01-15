#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
/*variable de la imagen. APUNTADOR (mapas de bits)
 * Global para no estar abriendo y cerrando el archivo*/
ALLEGRO_BITMAP *icono, *fondo, *mario;
ALLEGRO_SAMPLE *musica_fondo, *musica_salto;
void elige_fondo(int x){
    if(x<=0)//IZQUIERDA
        al_draw_scaled_bitmap(fondo, 0, 1200, 1500, 1000, 0, 0, 1200, 800, 0);
    if(x>=2300)//DERECHA
        al_draw_scaled_bitmap(fondo, 2300, 1200, 1500, 1000, 0, 0, 1200, 800, 0);
    if(x>0 && x<2300)//MOVIBLE
        al_draw_scaled_bitmap(fondo, x, 1200, 1500, 1000, 0, 0, 1200, 800, 0);
}
void mario_normal(int x, int direccion, int movMx){
    if(direccion==1)  //if (viendo hacia la izquierda)
        if(x>0 && x<2300)
            al_draw_scaled_bitmap(mario, 240,0,250,385,460,800-400,216,308,0);//mario estatico
        else
            al_draw_scaled_bitmap(mario, 240, 0, 250, 385, movMx, 800 - 400, 216, 308, 0);//mario movible
    else//viendo a la derecha
        if(x>0 && x<2300)
            al_draw_scaled_bitmap(mario, 240,0,250,385,460,800-400,216,308,ALLEGRO_FLIP_HORIZONTAL);//mario estatico
        else
            al_draw_scaled_bitmap(mario, 240,0,250,385,movMx,800-400,216,308,ALLEGRO_FLIP_HORIZONTAL);//mario movible
}
void mario_camina(int x, int direccion, int movMx){
    int i, j;
    for(i=720;i<=970;i+=250){
        if(direccion==1)  //if (viendo hacia la izquierda)
            if(x>0 && x<2300)
                al_draw_scaled_bitmap(mario, i,0,250,385,460,800-400,216,308,0);//mario estatico
            else
                al_draw_scaled_bitmap(mario, i, 0, 250, 385, movMx, 800 - 400, 216, 308, 0);//mario movible
        else//viendo a la derecha
            if(x>0 && x<2300)
                al_draw_scaled_bitmap(mario, i,0,250,385,460,800-400,216,308,ALLEGRO_FLIP_HORIZONTAL);//mario estatico
            else
                al_draw_scaled_bitmap(mario, i,0,250,385,movMx,800-400,216,308,ALLEGRO_FLIP_HORIZONTAL);//mario movible
        al_flip_display();
    }
    elige_fondo(x);
}
void salto_normal(int x, int direccion, int movMx){
    int i;
    //arriba
    for(i=400;i>=0;i-=100){
        if(direccion==1)  //if (viendo hacia la izquierda)
            if(x>0 && x<2300)
                al_draw_scaled_bitmap(mario, 1220,0,270,385,460-35,i,216,308,0);//mario estatico
            else
                al_draw_scaled_bitmap(mario, 1220, 0, 270, 385, movMx-35, i, 216, 308, 0);//mario movible
        else//viendo a la derecha
            if(x>0 && x<2300)
                al_draw_scaled_bitmap(mario, 1220,0,270,385,460+35,i,216,308,ALLEGRO_FLIP_HORIZONTAL);//mario estatico
            else
                al_draw_scaled_bitmap(mario, 1220,0,270,385,movMx+35,i,216,308,ALLEGRO_FLIP_HORIZONTAL);//mario movible
        al_flip_display();
    }
    //abajo
    for(i=100;i>=400;i+=100){
        if(direccion==1)  //if (viendo hacia la izquierda)
            if(x>0 && x<2300)
                al_draw_scaled_bitmap(mario, 1220,0,270,385,460-35,i,216,308,0);//mario estatico
            else
                al_draw_scaled_bitmap(mario, 1220, 0, 270, 385, movMx-35, i, 216, 308, 0);//mario movible
        else//viendo a la derecha
            if(x>0 && x<2300)
                al_draw_scaled_bitmap(mario, 1220,0,270,385,460+35,i,216,308,ALLEGRO_FLIP_HORIZONTAL);//mario estatico
            else
                al_draw_scaled_bitmap(mario, 1220,0,270,385,movMx+35,i,216,308,ALLEGRO_FLIP_HORIZONTAL);//mario movible
        al_flip_display();
    }
    elige_fondo(x);
}
void salto_parabola(int x, int direccion, int movMx){
    ;
}
int main() {
    ALLEGRO_DISPLAY *disp;
    ALLEGRO_EVENT_QUEUE *eventos;
    ALLEGRO_EVENT evento;
    ALLEGRO_TIMER *timer;
    int fin = 0, redibujar = 1;
    int x=0, direccion=1, movMx=460, camina=0, salto=0, espera=0, salto_par=0;
    if (!al_init()) {
        printf("\nNo se pudo iniciar Allegro");
        fin = 1;
    }
    if(!al_install_keyboard()){
        printf("No se pudo instalar el teclado");
        fin = 1;
    }
    if(!al_init_image_addon()){
        printf("No se cargó el complemento de imágenes");
        fin = 1;
    }
    icono = al_load_bitmap("imagenes/icono.png");
    if(!icono){
        printf("No se cargo la imagen (icono)");
        fin = 1;
    }
    fondo = al_load_bitmap("imagenes/4_Plataforma_herejia.jpg");
    if(!fondo){
        printf("No se cargo la imagen (fondo)");
        fin = 1;
    }
    mario = al_load_bitmap("imagenes/sprites-mario.png");
    if(!mario){
        printf("No se cargo la imagen (mario)");
        fin = 1;
    }
    if(!al_install_audio()){
        printf("No se cargo el complemento de audio");
        fin=1;
    }
    if(!al_init_acodec_addon()){
        printf("No se pudo cargar el complemento de codecs");
        fin=1;
    }
    //mezcla de sonido
    if(!al_reserve_samples(3)){
        printf("No se pudo reservar las pistas");
    }
    musica_fondo = al_load_sample("musica/tema-mario.mp3");
    musica_salto = al_load_sample("musica/salto-mario.mp3");
    if(!musica_fondo || !musica_salto){
        printf("No se cargo la música de fondo y/o salto");
        fin = 1;
    }
    disp = al_create_display(1200,800);
    al_set_window_title(disp, "MARIO BROS");
    al_set_display_icon(disp, icono);
    eventos = al_create_event_queue();
    al_register_event_source(eventos, al_get_display_event_source(disp));
    al_register_event_source(eventos, al_get_keyboard_event_source());
    al_play_sample(musica_fondo,1,0,1,ALLEGRO_PLAYMODE_LOOP,NULL);
    timer = al_create_timer(.5); //creación de un temporizador
    al_register_event_source(eventos, al_get_timer_event_source(timer));//registrar el evento tiempo
    al_start_timer(timer);//comienza el temporizador
    while(!fin){
        if (redibujar==1 && al_event_queue_is_empty(eventos)) {
            elige_fondo(x);
            if(camina==1) {
                mario_camina(x,direccion,movMx);//Imprime a mario con pies abiertos
                camina=0;
            }
            if(salto==1) {
                salto_normal(x, direccion, movMx);
                salto = 0;
            }
            if(salto_par==1) {
                salto_parabola(x, direccion, movMx);
                salto_par = 0;
            }
            mario_normal(x,direccion,movMx);//IMPRIME A MARIO NORMAL
            al_flip_display();
            redibujar = 0;
        }
        al_wait_for_event(eventos, &evento);
        switch(evento.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                fin = 1;
                break;
            case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
                redibujar=1;
                break;
            case ALLEGRO_EVENT_TIMER:
                if(evento.timer.source==timer)
                    espera=1;
                break;
            case ALLEGRO_EVENT_KEY_CHAR:
                switch(evento.keyboard.keycode){
                    case ALLEGRO_KEY_LEFT:
                        direccion=1;
                        camina=1;
                        if(x>-440 && x<=2800) //NO MOVER. Coordenadas específicas del mapa
                            x-=20;
                        if(x<=0|| x>=2300){//NO MOVER. Coordenadas específicas del mapa
                            if (movMx >= 20)//NO MOVER. Coordenadas específicas del mapa
                                movMx -= 20;
                        }
                        printf("\n%i, x=%i",movMx, x); //de apoyo
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        direccion=2;
                        camina=1;
                        if(x>=-440 && x<2800)//NO MOVER. Coordenadas específicas del mapa
                            x+=20;
                        if(x<=0 || x>=2300){//NO MOVER. Coordenadas específicas del mapa
                            if (movMx < 980)//NO MOVER. Coordenadas específicas del mapa
                                movMx += 20;
                        }
                        printf("\n%i, x=%i",movMx,x); //de apoyo
                        break;
                    case ALLEGRO_KEY_SPACE:
                        salto=1;
                        break;
                    case ALLEGRO_KEY_Z:
                        salto_par=1;
                        break;
                }
                redibujar=1;
                break;
        }
    }
    al_destroy_event_queue(eventos);
    al_destroy_display(disp);
    return 0;
}
