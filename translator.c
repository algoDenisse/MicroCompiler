#include <stdio.h>
#include <ctype.h>
#include "translator.h"

void translate(){
    
    
    // Abrir el translated file generado por el parser con el lenguaje intermedio.
    translated_file = fopen("output_file.txt", "r" );
    mips_file = fopen ("mips_file.txt","w+"); // file en el cual se guardaran las instrucciones en MIPS
   
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
            fscanf(translated_file, " %1023s",varA);//Obtengo la primera variable (ID) del declare
            fprintf(mips_file, "    %s: .word 0 \n",varA); // Sera siempre un word porque solo hay integers
            //break;
        }else if (strcmp(instruction,"Store")==0){
            printf("Soy un store\n");
            fscanf(translated_file, " %1023s",varA);//Obtengo la primera variable del store
            fscanf(translated_file, " %1023s",varB);//Obtengo la segunda variable del store
            fprintf(mips_file, "    lw  %s, %s \n",varB, varA);
            //break;
        }else if (strcmp(instruction,"Add")==0){
            printf("Soy un add\n");
            fscanf(translated_file, " %1023s",varA);//Obtengo la primera variable del Add 3
            fscanf(translated_file, " %1023s",varB);//Obtengo la segunda variable del Add a
            fscanf(translated_file, " %1023s",varC);//Obtengo la segunda variable del Add temp1
            // mover los operandos a los registros
            fprintf(mips_file, "    lw  $t1, %s \n", varA);
            fprintf(mips_file, "    lw  $t2, %s \n", varB);
            // realizar la suma
            fprintf(mips_file, "    add $t0, $t1, $t2 \n");
            // mover a 
            
            
           // break;
        }else if (strcmp(instruction,"Sub")==0){
            printf("Soy un sub\n");
           // break;
        }else if  (strcmp(instruction,"Read")==0){
            printf("Soy un read\n");
           // break;
        }else if  (strcmp(instruction,"Write")==0){
            printf("Soy un write\n");
//break;
        }else if  (strcmp(instruction,"Halt")==0){
            printf("Soy un halt\n");
           // break;
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