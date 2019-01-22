//
//  entities.hpp
//  Delaunator-3d
//
//  Created by Ivan Radkevich on 1/20/19.
//  Copyright © 2019 Ivan Radkevich. All rights reserved.
//

#ifndef entities_hpp
#define entities_hpp

#include <stdio.h>
#include "free_functions.hpp"


class Vertex{
    
public:
    Vertex(){};
    
    Vertex(double xx, double yy, double zz):
    x(xx), y(yy), z(zz){}
    
    Vertex(Vertex& v):
    x(v.x),y(v.y),z(v.z){}
   // int& operator[] (const int index);
    double x,y,z;
};




class Edge{
    
public:
    
    Edge(){};
    
    Edge(Vertex vv1, Vertex vv2):
    v1(vv1), v2(vv2){}
    
    Edge(Edge& e1):
    v1(e1.v1),v2(e1.v2){}
    
    Vertex popVertex();
    
    Vertex v1,v2;
};



class Face{
    //я роняю Запад, уууу
    //добавить указатели на инцидентные рёбра
public:
    Face(){};
    Face(Vertex vv1, Vertex vv2, Vertex vv3):
    v1(vv1),v2(vv2),v3(vv3){}
    
    bool isCoplanar(Vertex v);
    bool isOnTheOpposite(Vertex v, Vertex c);
    bool isCircumsphereCorrect(Vertex v, Vertex i);
    
    Edge popEdge();
    
    
    Vertex v1, v2, v3;
    Edge e1, e2, e3;
    
    //указатели на инцидентные, а не граничные рёбра
    //next и prev определяется, принадлежат ли они следующему или предыдущему треугольнику
    //в списке в триангуляции
    Edge *next1, *next2, *next3;
    Edge *prev1, *prev2, *prev3;
    
    };





class Tetrahedron{
    
public:
    Tetrahedron(){};
    Tetrahedron(Vertex vv1, Vertex vv2, Vertex vv3, Vertex vv4);
    //Tetrahedron(Point pp1, Point pp2, Point pp3, Point pp4);
    bool isPointOnTheOpposite();
    bool isInCircumsSphere();
    
    int configuRation();
    void transformationTwotoThree();
    void transformationThreetoTwo();
    void transformationTwotoTwo();
    void transformationFourtoFour();
    
    Face popFace();
    
    Face boFa1, boFa2, boFa3, boFa4;
    
    //boFa1 - 4,3,2 ; boFa2 - 4 1 3; boFa3 - 4 2 1; boFa4 - 1 2 3
    Vertex v1,v2,v3,v4;
    //Point p1,p2,p3,p4;
    Vertex centroid;
    
    
    
};







class Triangulation{
    
//содержит массив тэтраэдров
//добавление boundary point
public:
    Triangulation(){};
    
    
    Tetrahedron popTetr();
    void addVertex(Vertex v);
    void addTetrahedron(Tetrahedron tt);
    
    
    std::vector<Tetrahedron> tetrs;
    
   // int checkConf(Tetrahedron a, Tetrahedron b);
    
    
};



//для фейса чёт такое
struct Node {
    int data;
    struct Node* next; // Pointer to next node in DLL
    struct Node* prev; // Pointer to previous node in DLL
};
 

#endif /* entities_hpp */
