#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 20

//Nome: Matheus Conzatti de Souza Turma: Engenharia da Computação

struct HashTable{
   int data;   
   int Chave;
};

struct HashTable* arrayHash[TAM]; 
struct HashTable* ItemHash;
struct HashTable* item;

int hashCod(int chave) {
   return chave % TAM;
}

struct HashTable *procuraHash(int chave){
    //Obtem o id da Hash
    int hashIndex = hashCod(chave);  
	
    //Mover um elemento na matriz até encontrar o elemnto vazio
    while(arrayHash[hashIndex] != NULL) {
        
        if(arrayHash[hashIndex]-> Chave == chave)
            return arrayHash[hashIndex]; 
                
        //Adiciona um elemento na Hash Table
        ++hashIndex;
            
        //Verifica o tamanho da Matriz
        hashIndex %= TAM;
    }        
        
    return NULL;        
}

void inserir(int chave, int data){
    struct HashTable *item = (struct HashTable*)malloc(sizeof(struct HashTable));
    item -> data = data;  
    item -> Chave = chave;

    //Obtem o id da Hash 
    int hashIndex = hashCod(chave);

    //Mover um elemento na matriz até encontrar o elemnto vazio ou ser excluido
    while(arrayHash[hashIndex] != NULL && arrayHash[hashIndex] -> Chave != -1){
        //Adiciona um elemento na Hash Table
        ++hashIndex;
            
        //Verifica o tamanho
        hashIndex %= TAM;
    }
        
    arrayHash[hashIndex] = item;
}

struct HashTable* excluir(struct HashTable* item){
    int chave = item -> Chave;

    //Obtem o id da Hash
    int hashIndex = hashCod(chave);

    //Mover um elemento na matriz até encontrar o elemnto vazio
    while(arrayHash[hashIndex] != NULL) {
        
        if(arrayHash[hashIndex] -> Chave == chave) {
            struct HashTable* temp = arrayHash[hashIndex]; 
                
            //Adiciona um elemento NULO na posição que foi excluida.
            arrayHash[hashIndex] = ItemHash; 
            return temp;
        }
            
        //Adiciona um elemento na Hash Table
        ++hashIndex;
            
         //Verifica o tamanho
        hashIndex %= TAM;
    }      
        
    return NULL;        
}

void imprimir(){
    for(int i = 0; i < TAM; i++){
        if(arrayHash[i] != NULL)
            printf("(%d, %d)", arrayHash[i] -> Chave, arrayHash[i] -> data);
        else
            printf(" -- ");
    }
        
    printf("\n");
}

int main() {
    ItemHash = (struct HashTable*)malloc(sizeof(struct HashTable));
    ItemHash -> data = -1;  
    ItemHash -> Chave = -1; 

    inserir(1, 20);
    inserir(2, 70);
    inserir(42, 80);
    inserir(4, 25);
    inserir(12, 44);
    inserir(14, 32);
    inserir(17, 11);
    inserir(13, 78);
    inserir(37, 97);

    imprimir();
    item = procuraHash(37);

    if(item != NULL){
        printf("Elemento encontrado: %d\n", item -> data);
    }else{
        printf("Elemento nao encontrado!\n");
    }

    excluir(item);
    item = procuraHash(37);

    if(item != NULL){
        printf("Elemento encontrado: %d\n", item -> data);
    }else{
        printf("Elemento nao encontrado!\n");
    }
}