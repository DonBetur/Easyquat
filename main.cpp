#include <iostream>
#include <cmath>

using namespace std;
struct  Quat
{
    double L0;
    double L1;
    double L2;
    double L3;
};

struct Ang
{
    double rx;
    double ry;
    double rz;
};

int main()
{
    setlocale(LC_ALL,"rus");
    const double Pi=M_PI;
    struct Ang A;
    struct  Quat Q;
    cout << "Введите rx: "<<endl;
    cin >> A.rx;
    cout << "Введите ry: "<<endl;
    cin >> A.ry;
    cout << "Введите rz: "<<endl;
    cin >> A.rz;
    //Перевод градусов в радианы
    A.rx=A.rx*Pi/180;
    A.ry=A.ry*Pi/180;
    A.rz=A.rz*Pi/180;

    Q.L0=cos(A.rx/2)*cos(A.ry/2)*cos(A.rz/2)-sin(A.rx/2)*sin(A.ry/2)*sin(A.rz/2);
    Q.L1=sin(A.rx/2)*sin(A.ry/2)*cos(A.rz/2)-cos(A.rx/2)*cos(A.ry/2)*sin(A.rz/2);
    Q.L2=sin(A.rx/2)*cos(A.ry/2)*cos(A.rz/2)-cos(A.rx/2)*sin(A.ry/2)*sin(A.rz/2);
    Q.L3=cos(A.rx/2)*sin(A.ry/2)*cos(A.rz/2)-sin(A.rx/2)*cos(A.ry/2)*sin(A.rz/2);

    A.rx=A.rx/(Pi/180);
    A.ry=A.ry/(Pi/180);
    A.rz=A.rz/(Pi/180);
	
double a11=pow(Q.L0,2)+pow(Q.L1,2)-pow(Q.L2,2)-pow(Q.L3,2);
double a22=pow(Q.L0,2)+pow(Q.L2,2)-pow(Q.L1,2)-pow(Q.L3,2);
double a33=pow(Q.L0,2)+pow(Q.L3,2)-pow(Q.L1,2)-pow(Q.L2,2);
double a12=2*Q.L1*Q.L2+Q.L0*Q.L3;
double a13=2*Q.L1*Q.L3-Q.L0*Q.L2;
double a21=2*Q.L1*Q.L2-Q.L0*Q.L3;
double a23=2*Q.L2*Q.L3+Q.L0*Q.L1;
double a31=2*Q.L1*Q.L3+Q.L0*Q.L2;
double a32=2*Q.L2*Q.L3-Q.L0*Q.L1;

    cout << "Значения углов поворота"<<endl;
    cout << "(" << A.rx << " , " << A.ry << " , " << A.rz << ")"<<endl<<endl;

    cout << "Кватернион:"<<endl;
    cout << "( " << Q.L0 << " , " << Q.L1 << " , "<< Q.L2 << " , "<< Q.L3 << " )"<< endl<<endl; 

    cout <<"Аналитически:"<<endl;
    cout<< "Л= " << Q.L0 << " + " << Q.L1 << "*i +  "<< Q.L2 << "*j +  "<< Q.L3 << "*k "<< endl<<endl;

    cout << "| " << a11 << " " << a12 << " " << a13 << " |" << endl;
    cout << "| " << a21 << " " << a22 << " " << a23 << " |" << endl;
    cout << "| " << a31 << " " << a32 << " " << a33 << " |" << endl;
    return 0;

}
