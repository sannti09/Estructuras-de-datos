//
// Created by J_mud on 29/03/2023.
//

#include "NodoQuadTree.h"
#include <fstream>
#include <cstring>



NodoQuadTree::NodoQuadTree() {
    this-> hijos[0] = NULL;
    this-> hijos[1] = NULL;
    this-> hijos[2] = NULL;
    this-> hijos[3] = NULL;
   }



void NodoQuadTree::setColor(char color) {
    this->color = color;

}
char NodoQuadTree::getColor(){
    return color;

}
void NodoQuadTree::setHijo(int pos, NodoQuadTree *nodo)
{
    hijos[pos] = nodo;
}
NodoQuadTree* NodoQuadTree::getHijo(int pos){
    return this->hijos[pos];
}
void NodoQuadTree::crearArbol(std::queue<char> *datos) {
    if(datos->empty())
        return;
    char aux = datos->front();
    datos->pop();
    this->setColor(aux);


    if(aux == '2')
    {
        hijos[0] = new NodoQuadTree();
        hijos[1] = new NodoQuadTree();
        hijos[2] = new NodoQuadTree();
        hijos[3] = new NodoQuadTree();

        hijos[0] ->crearArbol(datos);
        hijos[1] ->crearArbol(datos);
        hijos[2] ->crearArbol(datos);
        hijos[3] ->crearArbol(datos);
    }
    return;

}
void NodoQuadTree::preOrden() {
    std::cout << color << " ";
    if(hijos[0] != NULL)
        hijos[0]->preOrden();
    if(hijos[1] != NULL)
        hijos[1]->preOrden();
    if(hijos[2] != NULL)
        hijos[2]->preOrden();
    if(hijos[3] != NULL)
        hijos[3]->preOrden();
    return;
}





std::vector<std::vector<char> > NodoQuadTree::matrizNodo(int xInf, int xSup, int yInf, int ySup,std::vector<std::vector<char> > &matriz){
    if (this->color=='2'){
        int rangoX=0, rangoY=0;
        rangoX=(xSup-xInf)/2;
        rangoY=(ySup-yInf)/2;

        hijos[0]->matrizNodo(xInf,xInf+rangoX,yInf,yInf+rangoY,matriz);
        hijos[1]->matrizNodo(xInf+rangoX+1,xSup,yInf,yInf+rangoY,matriz);
        hijos[2]->matrizNodo(xInf+rangoX+1,xSup,yInf+rangoY+1,ySup,matriz);
        hijos[3]->matrizNodo(xInf,xInf+rangoX,yInf+rangoY+1,ySup,matriz);


    }
    else{
        this->rellenar(xInf, xSup,yInf, ySup,this->color, matriz);
    }
    return matriz;

}

std::vector<std::vector<char> > NodoQuadTree::rellenar(int minX,int maxX,int minY,int maxY,char color,std::vector<std::vector<char> > &matriz){
    for(int i=minX;i<=maxX;i++){
        for(int j=minY;j<=maxY;j++){
            matriz[j][i]=color;
        }
    }
    return matriz;
}




