#define _GNU_SOURCE

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE* file;
    file = fopen("/uploads/nagyfalbe.txt", "r");
    
    char line[500];
    
    fgets(line, sizeof(line), file);
    
    char *token = strtok(line, " ");

    int orhelyek = atoi(token);
    int orsegek;
    
    while(token != NULL) {
        orsegek = atoi(token);
        token = strtok(NULL, " ");
    }
    
    int orsegekLeirasai[orsegek];
    
    for(int i = 0; i < orsegek; i++) {
        fgets(line, sizeof(line), file);
        orsegekLeirasai[i] = atoi(line);
    }
    
    int orhelyAdatok[orhelyek];
    
    for(int i = 0; i < orhelyek; i++) {
        orhelyAdatok[i] = 0;
    }
    
    for(int j = 0; j < orsegek; j++) {
        if(orhelyAdatok[ orsegekLeirasai[j] - 1 ] != 1) {
            orhelyAdatok[orsegekLeirasai[j]-1] = 1;
        }
    }
    
    for(int i = 0; i < orhelyek; i++) {
        printf("%d\t", orhelyAdatok[i]);
    }
    

    // első sorba a védett szakaszok száma
    
    int vedettSzakaszok = 0;
    
    int tempVedettSzakasz = 0;
    
    for(int i = 0; i < orhelyek; i++) {
        if(orhelyAdatok[i] == 0) {
            if(tempVedettSzakasz >= 2) {
                vedettSzakaszok++;
            }
            
            tempVedettSzakasz = 0;
        }
        
        if(orhelyAdatok[i] == 1) {
            tempVedettSzakasz++;
            
            if(i == orhelyek - 1) {
                if(tempVedettSzakasz >= 2) {
                    vedettSzakaszok++;
                }
            }
        }
    }

    // a második sorba az őrzött szakaszok száma kerüljön
    
    int orzottSzakaszok = 0;
    
    int tempOrzottSzakasz = 0;
    
    for(int i = 0; i < orhelyek - 1; i++) {
        if(orhelyAdatok[i] == 0 && orhelyAdatok[i + 1] == 1) {
            tempOrzottSzakasz++;
            
            if(i == orhelyek - 2) {
                orzottSzakaszok++;
            }
        }
        
        if(orhelyAdatok[i] == 1) {
            tempOrzottSzakasz++;
            
            if(i == orhelyek - 2) {
                orzottSzakaszok++;
            }
        }
        
        if(orhelyAdatok[i] == 0 && orhelyAdatok[i + 1] == 0) {
            if(tempOrzottSzakasz >= 1) {
                orzottSzakaszok++;
            }
            
            tempOrzottSzakasz = 0;
        }
    }
    
    printf("\nVédett szakaszok: %d\n", vedettSzakaszok);
    
    printf("Örzött szakaszok: %d", orzottSzakaszok);
    
    fclose(file);
    
    file = fopen("/myfiles/nagyfalki.txt", "w");
    
    fprintf(file, "%d\n", vedettSzakaszok);
    fprintf(file, "%d", orzottSzakaszok);
    
    fclose(file);
    
    return 0;
}