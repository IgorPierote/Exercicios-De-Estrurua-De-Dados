#include <random>
#include <iostream>
#include <algorithm>
#include <chrono>

//  Aqui temos o método de bubble sort, este metodo compara elementos adjacentes e troca-os se estiverem fora de ordem crescente, o processo é repetido até que o array esteja completamente ordenado. depreciado e não é mais utilizado em sistemas hoje em dia apenas para fins educativos.

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos se estiverem fora de ordem
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Aqui temos novamente a biblioteca usada no exercicio anterior para garantir a aleatoriedade de certas aplicações normalmente padronizadas 
    std::random_device rd;

    // Inicializa um gerador de números aleatórios uniformemente distribuídos entre 0 e 1000
    std::uniform_int_distribution<int> dist(0, 1000);

    // Cria um array de 100 inteiros
    int arr[100];

    // Registra o tempo inicial da geração do array
    auto start_gen = std::chrono::high_resolution_clock::now();

    // Preenche o array com números aleatórios
    for (int i = 0; i < 100; i++) {
        arr[i] = dist(rd);
    }

    // Registra o tempo final da geração do array, aqui usamos a biblioteca chronos, usada para gravar o tempo de execução de cada parte selecionada do código para podermos verificar onde está levanod mais tempo e podemos analisar o porque está parte do código leva mais tempo que a outra
    auto end_gen = std::chrono::high_resolution_clock::now();

    // Calcula e imprime o tempo de geração do array
    std::chrono::duration<double> elapsed_gen = end_gen - start_gen;
    std::cout << "Tempo de geração do array: " << elapsed_gen.count() << "s\n";

    // Imprime o array não ordenado
    std::cout << "Arranjo não ordenado:\n";
    for (int i = 0; i < 100; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    // Registra o tempo inicial da ordenação por Quick Sort
    auto start_sort_quick = std::chrono::high_resolution_clock::now();

    // Ordena o array, Aqui utilizamos o metodo quick sort para a ordenação do array ideia central do Quick Sort é escolher um elemento do array como central e particionar o array de modo que todos os elementos menores que o central fiquem à esquerda, e todos os elementos maiores que o central fiquem à direita. Em seguida, o mesmo processo é aplicado recursivamente aos sub-arrays resultantes até que todos estejam em seus devidos lugares.
    std::sort(arr, arr + 100);

    // Registra o tempo final da ordenação por Quick Sort
    auto end_sort_quick = std::chrono::high_resolution_clock::now();

    // Calcula e imprime o tempo de execução da ordenação por Quick Sort
    std::chrono::duration<double> elapsed_sort_quick = end_sort_quick - start_sort_quick;
    std::cout << "Tempo de execução da ordenação por Quick Sort: " << elapsed_sort_quick.count() << "s\n";

    // Imprime o array ordenado por Quick Sort
    std::cout << "Array ordenado por Quick Sort:\n";
    for (int i = 0; i < 100; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    // Registra o tempo inicial da ordenação por Bubble Sort
    auto start_sort_bubble = std::chrono::high_resolution_clock::now();

    // Chama a função Bubble Sort para ordenar o array
    bubbleSort(arr, 100);

    // Registra o tempo final da ordenação por Bubble Sort
    auto end_sort_bubble = std::chrono::high_resolution_clock::now();

    // Calcula e imprime o tempo de execução da ordenação por Bubble Sort
    std::chrono::duration<double> elapsed_sort_bubble = end_sort_bubble - start_sort_bubble;
    std::cout << "Tempo de execução da ordenação por Bubble Sort: " << elapsed_sort_bubble.count() << "s\n";

    // Imprime o array ordenado por Bubble Sort
    std::cout << "Array ordenado por Bubble Sort:\n";
    for (int i = 0; i < 100; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
