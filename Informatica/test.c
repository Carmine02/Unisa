#include <stdio.h>
#define N 5

// Scambia i valori passati dal chiamante
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Chiede in input i valori della sequenza
void inputArray(int *arr, int n) {
    int i;
    for(i=0;i<n;i++){
        printf("Inserisci il valore %d della sequenza: ", i+1);
        scanf("  %d", &arr[i]);
    }
}

// Stampa l'array ordinato
void outputArray(int *arr, int n) {
    int i;
    for(i=0; i<n;i++){
        printf("%d ", arr[i]);
    }
}

// Calcola il minimo numero della sequenza e lo restituisce
int minimo(int *arr, int n){
    int min = 0;
    int i;
    for(i=0; i<n; i++){
        if(arr[i] < arr[min])
            min = i;
    }

    return min;
}

// Scrolla l'array cercando man mano il minimo, se lo trova lo inverte attraverso swap()
void selectionSort(int *arr, int n) {
    int i, min;
    for(i = 0; i<n-1; i++) {
        min = minimo(arr+i, n-i)+i;
        swap(&arr[i], &arr[min]);
    }
}

// Programma principale che chiama i sottoprogrammi
int main(){
    int arr[N];
    inputArray(arr, N);
    selectionSort(arr, N);
    outputArray(arr, N);
}