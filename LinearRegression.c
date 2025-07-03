#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 1000

double alcohol[MAX_ROWS];
double quality[MAX_ROWS];


int loadData() {
    FILE *file = fopen("wine.csv", "r");
    if (!file) {
        perror("Unable to open file");
        return 1;
    }

    
    int i = 0;

    while (fscanf(file, "%lf,%lf", &alcohol[i], &quality[i]) == 2 && i < MAX_ROWS) {
        i++;
    }

    fclose(file);

    printf("Read %d rows from CSV file:\n\n", i);
    return i;
}






int main(){

   int n =  loadData();  //total entries

   int epoches = 1000;

   double alpha = 0.00001;

   double dwrtm =0.0 , dwrtc = 0.0;

   double m = 0.0 , c = 0.0 ;

   for(int count = 0 ; count <= epoches ; count++){
    dwrtm = 0.0; 
    dwrtc = 0.0;


        for (int i = 0 ; i< n; i++){
            

            double x = alcohol[i];
            double y = quality[i];

            dwrtm += -(2.0/n) * x * (y - (m*x + c) );
            dwrtc += -(2.0/n) *(y - (m*x + c) );

        }

    m = m - alpha * dwrtm;
    c = c - alpha * dwrtc;
   
    }    
    printf("Result: y = (%lf)x + (%lf)\n\n",m,c);

   return 0;

}


