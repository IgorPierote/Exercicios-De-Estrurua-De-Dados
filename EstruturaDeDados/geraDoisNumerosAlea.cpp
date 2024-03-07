#include <random>
#include <iostream>

//Aqui, a biblioteca <random> é incluída. A primeira fornece funcionalidades para geração de números aleatórios

int main() {
    // Cria um objeto chamado rd, que é usado para gerar sementes para os geradores de números aleatórios. A semente é inicializada automaticamente pelo sistema.
    std::random_device rd;
    //é uma classe da biblioteca padrão do C++ que é projetada para fornecer uma fonte de entropia de alta qualidade para ser usada como semente em geradores de números aleatórios. A entropia refere-se à imprevisibilidade ou à quantidade de "caos" nos dados gerados, tornando-os mais adequados para aplicações que exigem números verdadeiramente aleatórios.

    // Inicializa um gerador de números aleatórios uniformemente distribuídos entre 0 e 100, aqui criamos um objeto que recebera um gerador de números com os parametros determinados sendo um objeto para inteiros e um para flutantes
    std::uniform_int_distribution<int> dist_int(0, 100);
    std::uniform_real_distribution<double> dist_real(0.0, 100.0);

    // Gera e imprime um número inteiro aleatório aqui chamamos nosso gerador de numeros passando como condição para a gereção desses números o rd que no caso ira garantir que este número gerado seja aleatorio com base nos parametros definidos pelo criador da biblioteca
    int num_int = dist_int(rd);
    std::cout << "Número inteiro aleatório: " << num_int << std::endl;

    // Gera e imprime um número real aleatório
    double num_real = dist_real(rd);
    std::cout << "Número real aleatório: " << num_real << std::endl;

    return 0;
}