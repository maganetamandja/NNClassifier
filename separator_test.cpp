#include <cmath>
#include <vector>
#include <iostream>
#include "separator.h"

#include <algorithm>
#include <iterator>

using namespace std;


int main() {
   
    vector<vector<float>> platonic_ideals_test{{0.1,0.7},{0.2,0.6},{0.3,0.1},{0.4,0.5}};// platonic ideals of 4 classes and 2 dimentions space
    vector<float> test_point_test{0.05,0.5};

    vector<float> v_result;

    v_result = func_seperator(test_point_test,platonic_ideals_test);

    //cout<<v_result.size()<<endl;

    for (int i = 0; i<v_result.size();++i){
        cout<<v_result[i]<<endl;
    }
    //cout <<"I got here fine"<<endl;
    return 0;

};

