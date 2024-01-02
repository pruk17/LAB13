#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double numA[], int Allnum, double numB[]){
    double Asum = 0, SDsum = 0, Gnum = 1, Hnum = 0;
    double Max = numA[0];
    double Min = numA[0];
    for(int i = 0; i < Allnum; i++ ) Asum  += numA[i];
    numB[0] = Asum/Allnum;

    for(int i = 0; i < Allnum; i++ ) SDsum += pow(numA[i] - numB[0], 2);
    numB[1] = sqrt(SDsum/Allnum);

    for(int i = 0; i < Allnum; i++ ) Gnum *= numA[i];
    numB[2] = pow(Gnum, 1.0/Allnum);

    for(int i = 0; i < Allnum; i++ ){ 
    Hnum += 1/numA[i];

    if (Max == numA[i]) Max = Max;
    else if (Max < numA[i]) Max = numA[i];
    if (Min == numA[i]) Min = Min;
    else if (Min > numA[i]) Min = numA[i];
    } 
    numB[3] = Allnum/Hnum;
    numB[5] = Min;
    numB[4] = Max;
}
