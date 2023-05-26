//
// Created by J_mud on 29/03/2023.
//

#ifndef EDD_TALLER_4_QUADTREE_H
#define EDD_TALLER_4_QUADTREE_H
#include "NodoQuadTree.h"
#include <fstream>
class QuadTree{
private:
    NodoQuadTree* raiz = new NodoQuadTree();
public:
    void setRaiz(NodoQuadTree* nodo);
    NodoQuadTree* getRaiz();
    void crearArbol(std::queue<char> *datos);
    void preOrden();
    void matrizArbol(std::fstream &arch, int ancho, int alto);
};

#endif //EDD_TALLER_4_QUADTREE_H
