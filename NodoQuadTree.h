//
// Created by J_mud on 29/03/2023.
//

#ifndef EDD_TALLER_4_NODOQUADTREE_H
#define EDD_TALLER_4_NODOQUADTREE_H
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

class NodoQuadTree{
private:
    char color = 'n';
    NodoQuadTree *hijos[4];
public:
    NodoQuadTree();
    void setColor(char color);
    char getColor();
    void setHijo(int pos, NodoQuadTree *nodo);
    NodoQuadTree* getHijo(int pos);
    void crearArbol(std::queue<char> *datos);
    void preOrden();
    std::vector<std::vector<char> > rellenar(int minX,int maxX,int minY,int maxY,char color,std::vector<std::vector<char> > &matriz);
    std::vector<std::vector<char> > matrizNodo(int xInf, int xSup, int yInf, int ySup,std::vector<std::vector<char> > &matriz);

};



#endif //EDD_TALLER_4_NODOQUADTREE_H
