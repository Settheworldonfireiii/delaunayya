//
//  entities.cpp
//  Delaunator-3d
//
//  Created by Ivan Radkevich on 1/20/19.
//  Copyright © 2019 Ivan Radkevich. All rights reserved.
//

#include "entities.hpp"



Tetrahedron::Tetrahedron(Vertex vv1, Vertex vv2, Vertex vv3, Vertex vv4){
    v1 = vv1;
    v2 = vv2;
    v3 = vv3;
    v4 = vv4;
    centroid.x = (v1.x+v2.x+v3.x+v4.x)/4;
    centroid.y = (v1.y+v2.y+v3.y+v4.y)/4;
    centroid.z = (v1.z+v2.z+v3.z+v4.z)/4;
    boFa1 = Face(vv2, vv3, vv4);
    boFa2 = Face(vv1, vv4, vv3);
    boFa3 = Face(vv1, vv2, vv3);
    boFa4 = Face(vv1, vv3,vv2);
    
    
}


/*версия без Тэтраэдра как такового
bool Face::isCoplanar(<#Vertex v#>){
    Vertex matrix[4][4];
    matrix[0][0] = v1.x;
    matrix[0][1] = v1.y;
    matrix[0][2] = v1.z;
    matrix[0][3] = 1;
    
    matrix[1][0] = v2.x;
    matrix[1][1] = v2.y;
    matrix[1][2] = v2.z;
    matrix[1][3] = 1;
    
    matrix[2][0] = v3.x;
    matrix[2][1] = v3.y;
    matrix[2][2] = v3.z;
    matrix[2][3] = 1;
    
    matrix[3][0] = v.x;
    matrix[3][1] = v.y;
    matrix[3][2] = v.z;
    matrix[3][3] = 1;
    
    
    int submatrix[4][4];
    if (n == 2){
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    }
    else {
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
        }
        if(det==0){return true;}
        else{ return false;}
    
}


}
*/

bool Face::isOnTheOpposite(Vertex v, Vertex c){
    double a[3][3];
   
    a[0][0]=v1.x-v.x;
    a[1][0]=v2.x-v.x;
    a[2][0]=v3.x-v.x;
    a[0][1]=v1.y-v.y;
    a[1][1]=v2.y-v.y;
    a[2][1]=v3.y-v.y;
    a[0][2]=v1.z-v.z;
    a[1][2]=v2.z-v.z;
    a[2][2]=v3.z-v.z;
    double det1=determiNantes(a);
    
    a[0][0]=v1.x-c.x;
    a[1][0]=v2.x-c.x;
    a[2][0]=v3.x-c.x;
    a[0][1]=v1.y-c.y;
    a[1][1]=v2.y-c.y;
    a[2][1]=v3.y-c.y;
    a[0][2]=v1.z-c.z;
    a[1][2]=v2.z-c.z;
    a[2][2]=v3.z-c.z;
    double det2=determiNantes(a);
    
    if(det1*det2>=0){
        
        return false;
    }
    else{
        return true;
    }
        
   
    
    
   
}



bool Face::isCircumsphereCorrect(Vertex v, Vertex i){
    double a[5][5];
    a[0][0]=v1.x;
    a[1][0]=v2.x;
    a[2][0]=v3.x;
    a[3][0]=v.x;
    a[4][0]=i.x;
    
    a[0][1]=v1.y;
    a[1][1]=v2.y;
    a[2][1]=v3.y;
    a[3][1]=v.y;
    a[4][1]=i.y;
    
    
    a[0][2]=v1.z;
    a[1][2]=v2.z;
    a[2][2]=v3.z;
    a[3][2]=v.z;
    a[4][2]=i.z;
    
    a[0][3]=pow(v1.x,2)+pow(v1.y,2)+pow(v1.z,2);
    a[1][3]=pow(v2.x,2)+pow(v2.y,2)+pow(v2.z,2);
    a[2][3]=pow(v1.x,2)+pow(v1.y,2)+pow(v1.z,2);
    a[3][3]=pow(v.x,2)+pow(v.y,2)+pow(v.z,2);
    a[4][3]=pow(i.x,2)+pow(i.y,2)+pow(i.z,2);
    
    
    a[0][4]=1;
    a[1][4]=1;
    a[2][4]=1;
    a[3][4]=1;
    a[4][4]=1;
    
    if(determiNantes(a)>=0){
        return true;
    }
    else{
        return false;
    }
    
    
}







}
/*int& Vertex::operator[] (const int index)
{
    return this[index];
}  */

/*Tetrahedron::Tetrahedron(Point pp1, Point pp2, Point pp3, Point pp4){
    p1 = pp1;
    p2 = pp2;
    p3 = pp3;
    p4 = pp4;
    centroid.x = (p1.x+p2.x+p3.x+p4.x)/4;
    centroid.y = (p1.y+p2.y+p3.y+p4.y)/4;
    centroid.z = (p1.z+p2.z+p3.z+p4.z)/4;
}
*/




//int Triangulation::checkConf(Tetrahedron a, Tetrahedron b){
    
    
}
