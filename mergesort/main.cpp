#include <iostream>

using namespace std;

void merge1(int arr[], int inicio, int meio, int fim){
    int temp_left = meio - inicio + 1;
    int temp_right = fim - meio;

    int arr_left[temp_left];
    int arr_right[temp_right];

    int i,j,k;

    for(i = 0; i < temp_left; i++ )
        arr_left[i] = arr[inicio+i];
    for(i = 0; i < temp_right; i++)
        arr_right[i] = arr[meio+i+1];

    i=0,j=0,k=inicio;

    while(i < temp_left && j < temp_right){
        if(arr_left[i]<=arr_right[j]){
            arr[k]=arr_left[i];
            i++;
        }
        else {
            arr[k] = arr_right[j];
            j++;
        }
        k++;
    }
    while(i<temp_left){
        arr[k] = arr_left[i];
        i++;
        k++;
    }
    while(j<temp_right){
        arr[k] = arr_right[j];
        j++;
        k++;
    }

}
void mergesort(int arr[], int inicio, int fim){
    if(inicio<fim){
        int meio = inicio + (fim-inicio)/2;

        mergesort(arr, inicio, meio);
        mergesort(arr, meio+1, fim);

        merge1(arr, inicio, meio, fim);
    }
}

int main()
{
    int tamanho;

    cin >> tamanho;

    int arr[tamanho];

    for(int i = 0; i < tamanho; i++)
        cin >> arr[i];

    mergesort(arr, 0, tamanho+1);

    for(int i = 0; i < tamanho; i++)
        cout << arr[i] << " ";

    return 0;
}

