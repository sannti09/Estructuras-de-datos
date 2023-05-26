//
// Created by J_mud on 29/03/2023.
//

#include "QuadTree.h"
#include <math.h>
#include <fstream>


void QuadTree::setRaiz(NodoQuadTree* nodo){
    this->raiz = nodo;

}
NodoQuadTree* QuadTree::getRaiz(){
    return this->raiz;
}

void QuadTree::crearArbol(std::queue<char> *datos) {
    raiz->crearArbol(datos);
}
void QuadTree::preOrden()
{
    raiz->preOrden();
}
void QuadTree::matrizArbol(std::fstream &arch, int ancho, int alto) {
    std::vector<std::vector<char> > matriz;
    std::vector<char>fila;
    for (int i=0;i<ancho;i++){
        fila.push_back('3');
    }
    for (int i=0; i<alto; i++){
        matriz.push_back(fila);
    }
    //funcion recursiva
    matriz=raiz->matrizNodo(0, ancho-1, 0, alto-1,matriz);

    //crear archivo e imprimir matriz

    arch<<"P1"<<std::endl;
    arch<<ancho<<" "<<alto<<std::endl;
    for(int i=0; i<alto;i++){
        for (int u=0; u<ancho; u++){
            arch<<matriz[i][u]<<" ";
        }
        arch<<"\n";
    }

}





