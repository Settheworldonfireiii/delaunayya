//
//  main.cpp
//  Delaunator-3d
//
//  Created by Ivan Radkevich on 1/20/19.
//  Copyright © 2019 Ivan Radkevich. All rights reserved.
//

#include <iostream>
#include "entities.hpp"
#include "free_functions.hpp"
#include <iostream>
#include <valarray>
//#include <pcl/io/pcd_io.h>
//#include <pcl/point_types.h>


int main(int argc, const char * argv[]) {
    // читаем из пойнт клауда..пока не работает ибо трудно на мак хедеры поставить
    
/*    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    
    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("test_pcd.pcd", *cloud) == -1) //* load the file
    {
        PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
        return (-1);
        
    }
    
    
    int n = cloud->points.size();
    Vertex *Vertices = new Vertex[n];
    //можн напрямую использовать Point data type
    for (size_t i = 0; i < cloud->points.size (); ++i){
        Vertices[i].x=points[i].x;
        Vertices[i].y=points[i].y;
        Vertices[i].z=points[i].z;
    }
   Vertices = binSort(Vertices);
 
 */
    double k, l, m, x_step, y_step, z_step, a,b,c;
    double t =  30;
    a = 10;
    b = 6;
    c = 8;
    x_step = a/t;
    y_step = b/t;
    z_step = c/t;
   
    Vertex *Vertices = new Vertex[t];
    Vertices = generateEllipse(Vertices, a, b, c, k, l, m, t);//???
   
    std::cout << "Hello, World!\n";
    
    

    //перегрузить оператор
    Tetrahedron first_tetr = Tetrahedron(Vertices[std::slice(0,4,1)]);
    int i = 4;
    while(first_tetr.isCoplanar()){
        i++;
        first_tetr.v4 = Vertices[i];
    }
    Triangulation tt;
    tt.addTetrahedron(first_tetr);
    //добавить также треугольники этого тэтраэдра в стэк
    for(int j=i;j<=(t+1)*(t+1)*(t+1);j++){
        //check if j is on the opposite of triangulation-1 boundary face 1 if not 2 if not 3 if not 4
        //if it is add it to triangulation
        tt.addVertex(Vertices[j]);
        //add face on stack
        while(//стэк треугольников не пуст)
              
              Tetrahedron[i-1]
              
              //если всякий раз будет добавляться лишь одна точка т.е. лишь один треугольник - всё просто
              
              //снимаю треугольник со стэка
              //проверяю каждый граничный треугольник c помощью isCircumSphereCorrect
              
              
              //если некорректно, то check configuration
              //в зависимости от конфигурации (1 или 3) применяю преобразования(пока что не написал функции)
              //добавляю новые треугольники в стэк
        
    }
    


    return 0;
}
