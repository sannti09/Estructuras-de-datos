#include "descomprimir.h"

void descomprimir::procesamiento(int *argc, char *argv[]) {
    QuadTree imagen;
    NodoQuadTree *raiz = new NodoQuadTree;
    std::fstream arch(argv[1], std::ios::in);

    if(argv[1] == NULL || argv[2] == NULL) {
        std::cout << "ARGUMENTOS INSUFICIENTES" << std::endl;
        return;
    }

    if (arch.fail()) {
        std::cout << "ERROR CON EL ARCHIVO " << argv[1] << ": " << strerror(errno) << std::endl;
        return;
    }


    int tam, tam1;
    arch >> tam;
    arch >> tam1;
    if (arch.fail()) {
        std::cout << "ERROR AL LEER EL TAMAÑO DE LA IMAGEN" << std::endl;
        arch.close();
        return;
    }
    std::cout << "Tamaño de la imagen: " << tam << "x" << tam1 << std::endl;

    char caracter;
    while (arch.get(caracter)) {
        this->entrada.push(caracter);
    }
    entrada.pop();

    arch.close();
    imagen.crearArbol(&entrada);

    std::string outputFileName(argv[2]);
    outputFileName += ".pbm";
    std::fstream outP(outputFileName, std::ios::out);

    imagen.matrizArbol(outP, tam, tam1);

    std::cout << "Se ha generado la imagen con el nombre " << argv[2] << std::endl;
    outP.close();
}


int main(int argc, char *argv[])
{
    descomprimir pr;
    pr.procesamiento(&argc, argv);

    return 0;
}

