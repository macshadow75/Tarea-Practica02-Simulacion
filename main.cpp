#include <iostream>
#include <stdio.h>
#include "classes.h"   
#include <fstream>

using namespace std;

void readCoordinates(ifstream &file, int n, item* item_list){
    //Cambiando macros por un tipo de dato
    int e; float r;
    for(int i=0; i<n; i++){
      file >> e >> r;
      item_list[i].setIntFloat(e,r);
      cout << r << endl;
    }
}


int main() {
    char filename[10];
    string line;
    mesh m;
    ifstream file;
    float k,Q;
    int nnodes,neltos,ndirich,nneu;
    
    do{
        cout << "Ingrese el nombre del archivo: ";
        cin >> filename;
        file.open(filename);
    }while(!file);
    
    file >> k >> Q;
    file >> nnodes >> neltos >> ndirich >> nneu;
    
    file >> line;

    //cambiando macros por variables ya declaradas
    m.setParameters(k, Q);
    m.setSizes(nnodes, neltos, ndirich, nneu);
    m.createData();

    readCoordinates(file,10,m.getNodes());

    file.close();

    

    return 0;
}