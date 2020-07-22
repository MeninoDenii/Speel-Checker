#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "HashTable.h"

int main() {
    struct HashTable table;
    table.buckets = MAX_BUCKETS;//Total de palavras do arquivo do dicionáro
    table.words = MAX_BUCKETS;
    unsigned int i = 0;
    //iniciando todos os nós nulos
    for(i=0;i<table.buckets;i++){
        table.nodes[i] = NULL;
    }

    clock_t start, end;

    start = clock();
    Load_Hash_Table(&table,"ascii.txt");//Carregar dicionário na memoria ram
    end = clock();


    float time = ((float)(end-start))/(CLOCKS_PER_SEC/1000);
    printf("Tempo gasto para carregar o dicionario: %f ms\n",time);

    start = clock();
    Search(&table,"ConstFed.txt");//Busca no dicionário
    end = clock();

    time = ((float)(end-start))/(CLOCKS_PER_SEC/1000);
    printf("Tempo na pesquisa ao dicionario: %f ms\n",time);

    return 0;
}
