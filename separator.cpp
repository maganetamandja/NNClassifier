/*take platonic ideals and compare to the test example*/
#include <cmath>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;


class separator {
    //private : vector<vector<float>> platonic_ideals;

   // private : vector<float> test_point;

    
    private : vector<float> compare(vector<float> test_point, vector<vector<float>> platonic_ideals){
        vector<vector<float>> resulting_vector;
        vector<float> resulting_distance;
        vector<float> t_vec;

        int rows = platonic_ideals.size(); 
        int columns = platonic_ideals[0].size();

        float modulus = 0.0;
        //vector<float> resulting_distance_vector;

        for (size_t i = 0; i<rows; ++i){ //createt  a result vector
            //one platonic ideal
            //substract vectors
            //resulting_vector.push_back({0});

           for (size_t j=0; j<columns; ++j) {
            float n = platonic_ideals[i][j]-test_point[j];

            //cout<<"push this in " << to_string(n) << endl;
            
            t_vec.push_back(n);
            //resulting_vector[i][j] = platonic_ideals[i][j]-test_point[j];
            }

            resulting_vector.push_back(t_vec);
            //cout<<"update vector : size of resulting_vector = "<< resulting_vector.size()<<endl;
            t_vec.clear();



        }

        for ( size_t k = 0; k<rows; ++k ){ //find modulus

            //cout << "show me here"<<endl;


            for (size_t l = 0; l<columns;++l){

            modulus = modulus + pow(resulting_vector[k][l],2);
            
                
             //cout<<"the modulus so far = "<< modulus<<endl;
            }
            modulus = sqrt(modulus);

           

            resulting_distance.push_back(modulus);
            modulus = 0;

            //cout<<"show modulus = "<<to_string(modulus)<<endl;



        };





       return resulting_distance;


    };

    private : vector<float> compare_angle(vector<float> test_point_a, vector<vector<float>> platonic_ideals_a){
        vector<float> resuting_angle;
        float angle = 0;
        int rows_a = platonic_ideals_a.size(); 
        int columns_a = platonic_ideals_a[0].size();
        float dot_product=0;
        float mod_idea = 0;
        float mod_test =0;
        float determinant=0;
        for (int j = 0; j<rows_a; ++j){
        //dot product

            //dot_product = inner_product(platonic_ideals_a[j].begin(),platonic_ideals_a[j].end(),test_point_a.begin(),0);
           
            for (int i=0; i<columns_a; ++i){

            dot_product = dot_product + platonic_ideals_a[j][i]*test_point_a[i];
           // determinant = determinant + 
            mod_idea= mod_idea + (platonic_ideals_a[j][i] * platonic_ideals_a[j][i]); //pow(platonic_ideals_a[j][i],2);
            mod_test = mod_test + (test_point_a[i] * test_point_a[i]);

            }

            mod_idea = sqrt(mod_idea);
            mod_test = sqrt(mod_test);

            cout<<"show me dot product "<<dot_product<<endl;
            cout<<"show me mod  idea "<<mod_idea<<endl;
            cout<<"show me mod test "<<mod_test<<endl;

            cout<<"show me mod_test * mod_idea "<<dot_product/(mod_idea*mod_test)<<endl;

            angle = acos(dot_product /(mod_test*mod_idea));



            resuting_angle.push_back(angle) ;
            dot_product =0;
            mod_idea = 0;
            mod_test = 0 ;

        }

        return resuting_angle;

    }

    public : vector<float> return_modulus(vector<float> test_point_p, vector<vector<float>> platonic_ideals_p){

        return compare(test_point_p, platonic_ideals_p);
    
    }
    
    public : vector<float> return_angle(vector<float> test_point_a_p, vector<vector<float>> platonic_ideals_a_p){

        return compare_angle(test_point_a_p, platonic_ideals_a_p);
    
    }


};

vector<float> func_seperator(vector<float> test_point_f, vector<vector<float>> platonic_ideals_f){
    separator separator_obj ;
    return separator_obj.return_modulus(test_point_f, platonic_ideals_f);
}

vector<float> func_seperator_ang(vector<float> test_point_a_f, vector<vector<float>> platonic_ideals_a_f){
    separator separator_a_obj ;
    return separator_a_obj.return_angle(test_point_a_f, platonic_ideals_a_f);
}