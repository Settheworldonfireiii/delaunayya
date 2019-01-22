//
//  free_functions.hpp
//  Delaunator-3d
//
//  Created by Ivan Radkevich on 1/21/19.
//  Copyright © 2019 Ivan Radkevich. All rights reserved.
//

#ifndef free_functions_hpp
#define free_functions_hpp

#include <stdio.h>
#include <vector>
#include <math.h>
#include <valarray>

#include "entities.hpp"


using namespace std;


template <typename T>
using type_t = T;

template <size_t N>
type_t<Vertex(&)[N]> generateEllipse(type_t<Vertex(&)[N]> arr, double a, double b, double c, double k, double l, double m, double t);


template <size_t N>
type_t<Vertex(&)[N]> binSort(type_t<Vertex(&)[N]> arr);
#endif /* free_functions_hpp */

template <size_t N>
double determiNantes(double a[N][N]);

bool isCoplanar(Vertex a, Vertex b, Vertex c, Vertex d);

int checkConf(Vertex a, Vertex b, Vertex c, Vertex d, Vertex e);


