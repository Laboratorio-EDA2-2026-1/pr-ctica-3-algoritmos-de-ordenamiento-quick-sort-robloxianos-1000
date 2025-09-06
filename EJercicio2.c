#include <stdio.h>


void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

double calcularPromedio(int arr[], int low, int high) {
    double suma = 0;
    int count = high - low + 1;
    
    for (int i = low; i <= high; i++) {
        suma += arr[i];
    }
    
    
    return suma / count;
}

int partition(int arr[], int low, int high, double pivot) {
    int left = low;
    int right = high;
    
  
    
    
    
    while (left <= right) {

        while (left <= high && arr[left] < pivot) {
            left++;
        }
        

        while (right >= low && arr[right] >= pivot) {
            right--;
        }
        
        if (left < right) {
            intercambiar(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
   
    return left;
}

void quickSortPromedio(int arr[], int low, int high) {
    if (low >= high) {
        return; 
    }
    
    int large=high+1;
    int privote=arr[0];
    int sameValor;
    
    
    
    for(int k=0; k<large; k++){
    if (privote == arr[k]){
    sameValor++;
    }
    }
    if (sameValor==large){
    printf("ya está arreglado: ");
    for (int i = 0; i < large; i++) {
        printf("%d ", arr[i]);
    
    
    }
    
    return;
    }
    
    
    
    
    
    double pivot = calcularPromedio(arr, low, high);
    
    
    int partitionIndex = partition(arr, low, high, pivot);
    
    
    quickSortPromedio(arr, low, partitionIndex - 1);
    quickSortPromedio(arr, partitionIndex, high);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    
    int arr1[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int m=sizeof(arr1[0]);
    
    
    
    printf("original: ");
    printArray(arr1, n1);
    
    quickSortPromedio(arr1, 0, n1 - 1);
    
    printf("ordenado: ");
    printArray(arr1, n1);
    printf("\n");
    
    int arr2[] = {5,3,2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    
    
    printf("original: ");
    printArray(arr2, n2);
    
    quickSortPromedio(arr2, 0, n2 - 1);
    
    double promedio1 = calcularPromedio(arr2, 0, n2 - 1);
    printf("Promedio con decimales: %.2f\n", promedio1);
    
    
    
    printf("ordenado: ");
    printArray(arr2, n2);
    printf("\n");
    
    printf("elemtnos iguales: \n");
    int arr3[] = {2, 2, 2};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    
    printArray(arr3, n3);
    
    double promedio = calcularPromedio(arr3, 0, n3 - 1);
    printf("Promedio: %.2f\n", promedio);
    
    quickSortPromedio(arr3, 0, n3 - 1);
    
    
    
    return 0;
}
