#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "HashTable.h"
#include "Node.h"

//Função resposável por calcular o hash.
unsigned int hash(char *word, int tam_word){
	
	unsigned int value = 5381;
	int i = 0;
	
	for(i = 0; i < tam_word; i++){
		value  = value * 33 + word[i];
	}
	
	return value;
}
//Função responsável por buscar a palavra no dicionário.
int Word_Search(char *word, struct HashTable *hash_table){
	
	unsigned int num_hash = hash(word,strlen(word)) % hash_table->buckets; //o resultado vai ser o hash da palavra.
	
	struct Node *aux = (struct Node*)malloc(sizeof(struct Node));
	
	aux->word = (char*) malloc(sizeof(char)*(strlen(word)+1));
	
	aux = hash_table->nodes[num_hash];
	
	if(aux == NULL){
		return 1;
	} else {
		while(aux != NULL){
			if(strcmp(aux->word,word) == 0){
				return 0;
			} else { //Se não encontrar a palavra vai para a próxima.
				aux = aux->next;
			}
		}
		
		return -1;
	}
}
//Função responsável por Pesquisar as palavras
void Search(struct HashTable *table, char *path){
	
	FILE *arquivo = NULL;
	arquivo = fopen(path,"r");
	char *token = NULL;
	
	if(arquivo == NULL){
		printf("Nao foi possivel abrir o arquivo!\n");
		fclose(arquivo);
		return;
	} else {
		unsigned int falhas = 0;
		unsigned int contador = 0;
		const char *ignore = " ()\n"; //Ignorando esses caracteres.
		char line[1024];
		
		while(fgets(line,sizeof(line),arquivo) != NULL){
			token = strtok(line,ignore); //transforma a linha em um array de strings.
			while(token != NULL){
				++contador;
				if(Word_Search(token,table) == 0){
					
				} else {
					++falhas;
				}
				
				token = strtok(NULL,ignore);
			}
			
			token = NULL;
		}
		fclose(arquivo);
		
		printf("Fim do arquivo\n");
		printf("Palavras que falharam; %d, Total de palavras %d\n", falhas,contador);
	}	
}
//Função responsável para carregar o dicionário na memoria RAM.
void Load_Hash_Table(struct HashTable *table, char* path)
{
	FILE *arquivo = NULL;
	arquivo = fopen(path,"r");
	
	if(arquivo == NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		fclose(arquivo);
		return;
	} else {
		char string[47];
		while(fscanf(arquivo,"%s",string) != EOF){
			unsigned int indice = hash(string,strlen(string)) % table->buckets;
			
			struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
			new_node->word = (char*) malloc(sizeof(char)*(strlen(string)+1));
			
			strcpy(new_node->word,string);
			new_node->next = NULL;
			
			if(table->nodes[indice] == NULL){
				table->nodes[indice] = new_node;
			} else {
				struct Node *aux = (struct Node*) malloc(sizeof(struct Node)); //criando uma auxiliar
                aux->word = (char*) malloc(sizeof(char)*(strlen(string)+1));
                
                strcpy(aux->word,string);
                aux->next = table->nodes[indice];
                table->nodes[indice] = aux;
			}
		}
		
		return;
	}
	fclose(arquivo);
}
//Funcao print dos elementos do dicionário
void print_hash_table(struct HashTable *hash_table){
    unsigned int i = 0;
    unsigned int cont_nulo = 0;
    unsigned int cont_not_nulo =0;
    for (i = 0; i<hash_table->buckets;i++){
        if(hash_table->nodes[i]==NULL){
            cont_nulo++;
        }else{
            cont_not_nulo++;
        }
    }
    printf("Contagem nulos %d nao nulos %d  total %d\n",cont_nulo,cont_not_nulo, cont_nulo+cont_not_nulo);
}








