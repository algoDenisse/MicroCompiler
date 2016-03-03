#include <stdio.h>
#include <ctype.h>
#include "translator.h"

void translate(){
    
    
    // Abrir el translated file generado por el parser con el lenguaje intermedio.
    translated_file = fopen("output_file.txt", "r" );
    mips_file = fopen ("mips_file.txt","w+"); // file en el cual se guyardaran las instrucciones en MIPS
   
    char instruction[8]; //Guardara la instruccion que lea del outputfile. Lo maximo que tendra una instruccion son 8 ch
    char varA[1024]; //Argumentos necesarios en la declaracion de ensamblador de 3 direcciones
    char varB[1024];
    char varC[1024];
    //Cuando matchee la primera palabra, vea que le llego
    while(fscanf(translated_file, " %8s", instruction)==1){
        printf("\n\n");
        fwrite( instruction, 1 ,sizeof(instruction), stdout);
        printf("\n");
  
        
        if (strcmp(instruction,"Declare")==0){
            printf("Soy un declare\n");
            fscanf(translated_file, " %1023s",varA);//Obtengo la primera variable del declare
            fscanf(translated_file, " %1023s",varB);//Obtengo la segunda variable del declare
            fprintf(mips_file, "    %s: .word 0 \n",varA);
            
            break;
            }else if (strcmp(instruction,"Add")==0){
            printf("Soy un add\n");
            break;
        }else if (strcmp(instruction,"Sub")==0){
            printf("Soy un sub\n");
            break;
        }else if  (strcmp(instruction,"Read")==0){
            printf("Soy un read\n");
            break;
        }else if  (strcmp(instruction,"Write")==0){
            printf("Soy un write\n");
            break;
        }else if  (strcmp(instruction,"Halt")==0){
            printf("Soy un halt\n");
            break;
        }
        // switch(instruction){
        //     case 'Declare':
        //         printf("Soy un declare\n");
        //         break;
        //     case 'Add':
        //         printf("Soy un add\n");
        //         break;
        //     case 'Sub':
        //         printf("Soy un sub\n");
        //         break;
        //     case 'Read':
        //         printf("Soy un read\n");
        //         break;
        //     case 'Write':
        //         printf("Soy un write\n");
        //         break;
        //     case 'Halt':
        //         printf("Soy un halt\n");
        //         break;
        // }
    }
    
}