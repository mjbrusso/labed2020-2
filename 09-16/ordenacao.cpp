#include <utility>

template <typename T>
void bubblesort(T vet[], int n) {
  bool trocou;
  do {
    trocou = false;
    for (int i = 0; i < n - 1; i++) {
      if (vet[i] > vet[i + 1]) {
        std::swap(vet[i], vet[i + 1]);
        trocou = true;
      }
    }
    n--;
  } while (trocou);
}


template<typename T>
void selectionsort(T vet[], int n)
{
    while (n > 1) {
        int posm = 0;
        for (int i = 1; i < n; i++) {
            if (vet[i] > vet[posm]) posm = i;
        }
        n--;
        if (posm != n)
            std::swap(vet[posm], vet[n]);
    }
}

template<typename T>
void insertionsort(T vet[], int n)
{
    for(int i=1; i<n; ++i) {
        T aux=vet[i];
        int j=i-1;
        while(j>=0 && vet[j]>aux) {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = aux;
    }
}