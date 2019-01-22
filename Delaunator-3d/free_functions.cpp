//
//  free_functions.cpp
//  Delaunator-3d
//
//  Created by Ivan Radkevich on 1/21/19.
//  Copyright © 2019 Ivan Radkevich. All rights reserved.
//

#include "free_functions.hpp"


template <typename T>
using type_t = T;



//генерирую эллипс
template <size_t N>
type_t<Vertex(&)[N]> generateEllipse(type_t<Vertex(&)[N]> arr, double a, double b, double c, double k, double l, double m, double t)
{
    double x_step = a/t;
    double y_step = b/t;
    double z_step = c/t;
    for(int z = 0; z<=t;z++){
        k=-a+z_step*z;
        
        for(int y=0; y<=t; y++) {
            l=-b+y*y_step;
            
            
            for(int x=0; x<=t; x++) {
                m=-c+x*x_step;
                if(( (k*k)/(a*a)+ (l*l)/(b*b)+(m*m)/(a*z)) <= 1 ){
                    
                    //да, знаю, explitly calling a constructor is a bad tone, but..
                    arr[x+y+z]=Vertex(m,l,k);
                    
                }
            }
        }
        return arr;
    }
}





template <size_t N>
type_t<Vertex(&)[N]> binSort(type_t<Vertex(&)[N]> arr){
    //разбивание на бакеты
    int v = 1;
    int somsht =N;
     Vertex bucket
    //3 потому что в примере 30x30x30
    while(somsht/10>3){
        //как то нужно обойти array size is not a constant expression
        const int bucketSize = somsht/10;
        somsht/=10;
        bucket = new Vertex[pow(10,v)][bucketSize];
        int max_x = arr[0].x;
        for(int i=0;i<N;i++){
            if(arr[i].x>=max_x){
                max_x = arr[i].x;
            }
        }
        for(int i=0;i<N;i++){
            bucket[floor(arr[i].x/max_x)][i]=arr[i];
        }
        
          v++;
        if(somsht/10<=3){
            Vertex swap;
            for(int t =0;t<10;t++){
                for(int i =0; i<somsht;i++){
                    for(int k=i+1;k<somsht;k++){
                        //nandaio!!!????
                        if(bucket[t][i].x >= bucket[t][k].x){
                            swap = bucket[t][i];
                            bucket[t][i]=bucket[t][k];
                            bucket[t][k]=swap;
                        }
                        
                    }
                }
            }
            
        }
    }
    //склеили воедино
    for(int i = 0;i<pow(v,10);i++){
        for(int k = 0;k<somsht;k++){
            arr[k+i*bucketSize]=bucket[i][k];
        }
    }
    v=0;
    Vertex swap;
    for(int i = 0;i<N;i++){
        for(int k = 1;k<N-i;k++){
           if(arr[v].x==arr[v+k].x){
               if(arr[v].y==arr[v+k].y){
                    if(arr[v].z>arr[v+k].z){
                       swap=arr[v];
                       arr[v]=arr[v+k];
                       arr[v+k]=swap;
                   }
                   
               }
               else if(arr[v].y>=arr[v+k].y){
                   swap=arr[v];
                   arr[v]=arr[v+k];
                   arr[v+k]=swap;
               }
           }
       }
    }
    
}




template <size_t N>
double determiNantes(double matrix[N][N]){
    
    int det = 0;
    int submatrix[N][N];
    if (N == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else {
        for (int x = 0; x < N; x++) {
            int subi = 0;
            for (int i = 1; i < N; i++) {
                int subj = 0;
                for (int j = 0; j < N; j++) {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, N - 1 ));
        }
    }
}


//только две конфигурации, 1 и 3, ибо это происходит уже после проверки описанной сферой
//в случае, если вершина другого тэтраэдра лежит внутри описанной сферы
//в этом случае возможны лишь 2 варианта, 1 и 3
int checkConf(Vertex a, Vertex b, Vertex c, Vertex d, Vertex e){
    //https://www.lucidar.me/en/mathematics/how-to-check-if-four-points-are-coplanar/
    if(!(isCoplanar(a, b, c, d))&&!(isCoplanar(a, b, c, e))&&!(isCoplanar(a, b, e, d))&&!(isCoplanar(a, e, c, d))&&!(isCoplanar(e, b, c, d))){
        return 1;
    }
    else if(isCoplanar(a, b, c, d)||isCoplanar(a, b, c, e)||isCoplanar(a, b, e, d)||isCoplanar(a, e, c, d)||isCoplanar(e, b, c, d)){
        return 3;
    }
    
    
    
}


// нужно обобщить на большее количество n, не только 4 на 4. сделаю как будет время
bool isCoplanar(Vertex a, Vertex b, Vertex c, Vertex d, Vertex e){
    
    double matrix[4][4];
    matrix[0][0] = a.x;
    matrix[0][1] = a.y;
    matrix[0][2] = a.z;
    matrix[0][3] = 1;
    
    matrix[1][0] = b.x;
    matrix[1][1] = b.y;
    matrix[1][2] = b.z;
    matrix[1][3] = 1;
    
    matrix[2][0] = c.x;
    matrix[2][1] = c.y;
    matrix[2][2] = c.z;
    matrix[2][3] = 1;
    
    matrix[3][0] = d.x;
    matrix[3][1] = d.y;
    matrix[3][2] = d.z;
    matrix[3][3] = 1;
   
    if(determiNantes(matrix)==0){
        
        return true;
    }
    else{
        return false;
    }
}
