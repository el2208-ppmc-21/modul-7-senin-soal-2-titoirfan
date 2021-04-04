/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
*   Modul               : 
*   Soal                : 
*   Hari dan Tanggal    : 
*   Nama (NIM)          : 
*   Asisten (NIM)       : 
*   Nama File           : 
*   Deskripsi           : 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// representasi stack menggunakan linked list
struct stack{
    char *kata;
    struct stack* next;
};

// fungsi membuat node baru dalam stack
struct stack* newNode(char * word){ 
	struct stack* stackNode = (struct stack*)malloc(sizeof(struct stack)); 
	
    // alokasi memori untuk potongan kata
    stackNode->kata = (char*)malloc(strlen(word));

    // memasukkan kata kedalam stack
    strcpy(stackNode->kata, word);
	stackNode->next = NULL; 

	return stackNode; 
} 

// fungsi memasukkan kata kedalam stack
void push(struct stack** root, char * word){ 
	struct stack* stackNode = newNode(word); 
	stackNode->next = *root; 
	*root = stackNode; 
}  

// fungsi untuk menampilkan isi stack
void printStack(struct stack * root){
    struct stack * temp;
    
    temp = root;

    while ((temp) != NULL){
        printf("%s ", temp->kata);
        temp = temp-> next;
    }
    printf("\n");
}

// fungsi mengurutkan kata dalam kalimat
void sortingStack(struct stack * head){
    struct stack* temp = head;
    int i;
    int count = 1;
    char x[1000];

    // menghitung jumlah kata dalam kalimat
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }

    // proses sorting
    for(i = 0; i < count; i++){
        temp = head; // reset
        while(temp->next != NULL){
            // jika kata memiliki urutan abjad lebih besar dari kata setelahnya
            if(strcmp(temp->kata,temp->next->kata) > 0){ 
                // tukar
                strcpy(x,temp->kata);
                strcpy(temp->kata,temp->next->kata);
                strcpy(temp->next->kata,x);
            }
            temp = temp->next;
        }
    }
}

int main(){
    struct stack* stackNode = NULL;
    char kata[1000];
    char * temp;

    // menerima input dari pengguna
    printf("Masukkan kalimat: ");
    scanf(" %[^\n]%*c", kata);

    // memasukkan semua kata dalam kalimat ke dalam stack
    temp = strtok(kata, " \n");
    while(temp != NULL){
        push(&stackNode, temp);
        temp = strtok(NULL, " \n");
    }

    // print hasil kalimat yang dibalik    
    printf("\nKalimat dibalik: ");
    printStack(stackNode);

    // print hasil kalimat yang sudah diurutkan
    printf("\nKata berurutan: ");
    sortingStack(stackNode);
    printStack(stackNode);

    return 0;
}
