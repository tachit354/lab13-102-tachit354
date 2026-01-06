#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double a[],int N,double b[]){
    double sum = 0;
    double Mul = 1;
    double sumC = 0;
    double Avg = 0;
    double x2 = 0;
    double Max = a[0];
    double Min = a[0];

    for(int i = 0; i < N; i++){ 
        sum += a[i];
    }
    Avg = sum/N;
    b[0] = Avg;

    for(int j = 0; j < N; j++){
        x2 += pow(a[j],2); 
    }
    double x = ((x2/N) - pow(Avg,2));
    double S = sqrt(x);
    b[1] = S;

    for(int j = 0; j < N; j++){
        Mul *= a[j];
    }
    b[2] = pow(Mul,1.0/N);

    for(int k = 0; k < N; k++){
        sumC += 1/a[k];
    }
    b[3] = N/sumC;

    for(int i = 0;i < N; i++){
        if(a[i] > Max) Max = a[i];
        if(a[i] < Min) Min = a[i];
    }
    b[4] = Max;
    b[5] = Min;
}
