
#include <iostream>
using namespace std;

//Funkcja sortująca
/**
 * *Operacje dominujące:
    * *np.   currElement = arr[i]; j = i-1;arr[j+1] = arr[j]; j--;
    * *będziemy zliczać ile razy wykonane zostały instrukcje: arr[j+1] = arr[j]; j--;
    * *dlatego że te operacje zostaną wykonane największą ilość razy
**/
int insertSort(int arr[], int n){

    int i, j, currElement;
    int dom=0;

    for (i = 1; i < n; i++){
        currElement = arr[i];
        j = i-1;
 
        while (j >= 0 && arr[j] > currElement){
            arr[j+1] = arr[j];
            j--;
            dom++;
        }
        arr[j + 1] = currElement;
    }
    return dom;
}
 
//Pomocnicza funkcja, wypisująca zawartość tablicy
void display(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getWorstTimeComplex(int n){
    //Pesymistyczna złożoność algorytmu -> O(n^2/2)
    return ((n*(n-1))/2)+1;
}
int getMedianTimeComplex(int n){
    //Średnia złożoność algorytmu -> Suma od i=2 do n po (i+1)/2
    int sum = 0;
    for (int i = 2; i < n; i++){
        sum += (i+1)/2;
    }
    return sum;
}
int getWorstDelta(int n){
    return ((n*(n-1))/2)+1 - 1;
}

int main(){
    //Sprawdzam ilość operacji dla najgorszej możliwej tablicy, więc takiej posortowanej malejąco, oraz dla losowej tablicy 20 elementów
    int arrayWorstCase[] = {1109,986,882,758,444,433,418,345,343,202,109,86,82,58,44,33,18,5,3,2};
    int arrayRandom[] = {7,58,13,56,3,100,82,79,86,32,80,36,17,23,40,6,74,10,88,94};

    int size = sizeof(arrayWorstCase) / sizeof(arrayWorstCase[0]);
    int domWorst = 0; int domRandom = 0;

    domWorst = insertSort(arrayWorstCase, size);
    cout << "Posortowana tablica (najgorszy przypadek): ";
    display(arrayWorstCase, size);
    cout << "Ilość operacji dominujących wykonanych przez algorytm: " << domWorst;

    cout << endl; cout << endl;

    domRandom = insertSort(arrayRandom, size);
    cout << "Posortowana tablica (pierwotnie losowa): ";
    display(arrayRandom, size);
    cout << "Ilość operacji dominujących wykonanych przez algorytm: " << domRandom;


    cout << endl;cout << endl;
    cout << "Złożoność pesymistyczna dla podanej ilości elementów: " << getWorstTimeComplex(size) << endl;
    cout << "Miara wrażliwości: " << getWorstDelta(size) << endl;
    cout << "Złożoność średnia dla podanej ilości elementów: " << getMedianTimeComplex(size) << endl;
    return 0;
}

//Autor: Maciej Macuga