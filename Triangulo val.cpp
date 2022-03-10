/*El siguiente programa Resuelve un triangulo cualquiera con tres datos entre lados y angulos
 Estudiante: Franz Choque Quispe            ETN-307L  */

#include<iostream>
#include<math.h>

using namespace std;

const double pi = 3.141592654;

double perimetro(double a,double b,double c)
{
	cout<<"\nperimetro = ";
	return a+b+c;	
}

double area(double a,double b,double c)
{	
	double perimetro,s,z,h,area;
	
	perimetro = a+b+c;
	s = perimetro/2;
	z = s*(s-a)*(s-b)*(s-c);
	area = sqrt(z);
	
	cout<<"area = ";
	return area;
}

double mediana1(double a,double b,double c)
{
	cout<<"\nMediana del vertice A al punto medio del lado a \tMed1 = ";
	return (sqrt((2*(pow(b,2)+pow(c,2)))-pow(a,2)))/2;
}

double mediana2(double a,double b,double c)
{
	cout<<"Mediana del vertice B al punto medio del lado b \tMed2 = ";
	return (sqrt((2*(pow(a,2)+pow(c,2)))-pow(b,2)))/2;
}

double mediana3(double a,double b,double c)
{
	cout<<"Mediana del vertice C al punto medio del lado c \tMed3 = ";
	return (sqrt((2*(pow(a,2)+pow(b,2)))-pow(c,2)))/2;
}

void opciones()
{
	cout<<"\nTriangulo de vertices A,B,C cuyos lados opuestos a estos vertices son los lados a,b,c respectivamente"<<endl;
	cout<<"Los angulos situados en los vertices A,B,C son los angulos alfa, beta, gama respectivamente"<<endl;
	cout<<"1.opcion \tTres lados"<<endl;
	cout<<"2.opcion \tTres angulos"<<endl;
	cout<<"3.opcion \tDos lados un angulo"<<endl;	
	cout<<"4.opcion \tDos angulos un lado"<<endl;
	cout<<"5.opcion \tSalir"<<endl;
}

int main()
{
	int k,m,n=1;
	double a,b,c,alfa,beta,gama;
	float p;

	do
	{	
		opciones();
		cin>>k;
		
		switch(k)
		{
			case 1:
				cout<<"Ingrese el valor del lado a: "<<endl; cin>>a;
				cout<<"Ingrese el valor del lado b: "<<endl; cin>>b;
				cout<<"Ingrese el valor del lado c: "<<endl; cin>>c;
				
				alfa = acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
				beta = acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
				gama = acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b));
				
				cout<<"\nEn radianes: alfa = "<<alfa<<endl;
				cout<<"En radianes: beta = "<<beta<<endl;
				cout<<"En radianes: gama = "<<gama<<endl;
				
				alfa = (alfa*180)/pi;
				beta = (beta*180)/pi;
				gama = (gama*180)/pi;
				
				cout<<"En grados sexagesimales: alfa = "<<alfa<<endl;
				cout<<"En grados sexagesimales: beta = "<<beta<<endl;
				cout<<"En grados sexagesimales: gama = "<<gama<<endl;
				cout<<perimetro(a,b,c)<<endl;
				cout<<area(a,b,c)<<endl;
				cout<<mediana1(a,b,c)<<endl;
				cout<<mediana2(a,b,c)<<endl;
				cout<<mediana3(a,b,c)<<endl;		
				break;
				
			case 2:
				cout<<"Existen infinitos triangulos que se pueden formar con solo tres angulos"<<endl;
				cout<<"Se requiere mas datos";
				break;
				
			case 3:
				cout<<"Ingrese el valor del lado a: "<<endl; cin>>a;
				cout<<"Ingrese el valor del lado b: "<<endl; cin>>b;
				
				do
				{
					cout<<"Elija el angulo que desea introducir"<<endl;
					cout<<"alfa\t presione 1"<<endl;
					cout<<"beta\t presione 2"<<endl;
					cout<<"gama\t presione 3"<<endl; cin>>m;
				}while(m<1 or m>3);
				
				if(m==1)
				{
					cout<<"Ingrese el valor del angulo alfa: "; cin>>alfa;
					
					alfa = (alfa*pi)/180;
					p = (b*sin(alfa))/a;
					beta = asin(p);
					gama = pi-beta-alfa;
					c = (a*sin(gama))/(sin(alfa));
					
					cout<<"\nEl valor del lado restante es c = "<<c<<endl;
					cout<<"En radianes: beta = "<<beta<<endl;
					cout<<"En radianes: gama = "<<gama<<endl;
					
					beta = (beta*180)/pi;
					gama = (gama*180)/pi;
					
					cout<<"En grados sexagesimales: beta = "<<beta<<endl;
					cout<<"En grados sexagesimales: gama = "<<gama<<endl;
					cout<<perimetro(a,b,c)<<endl;
					cout<<area(a,b,c)<<endl;
					cout<<mediana1(a,b,c)<<endl;
					cout<<mediana2(a,b,c)<<endl;
					cout<<mediana3(a,b,c)<<endl;
				}
				
				if(m==2)
				{
					cout<<"Ingrese el valor del angulo beta: "; cin>>beta;
					
					beta = (beta*pi)/180;
					p = (a*sin(beta))/b;
					alfa = asin(p);
					gama = pi-beta-alfa;
					c = (a*sin(gama))/(sin(alfa));
					
					cout<<"\nEl valor del lado restante es c = "<<c<<endl;
					cout<<"En radianes: alfa = "<<alfa<<endl;
					cout<<"En radianes: gama = "<<gama<<endl;
					
					alfa = (alfa*180)/pi;
					gama = (gama*180)/pi;
					
					cout<<"En grados sexagesimales: alfa = "<<alfa<<endl;
					cout<<"En grados sexagesimales: gama = "<<gama<<endl;
					cout<<perimetro(a,b,c)<<endl;
					cout<<area(a,b,c)<<endl;
					cout<<mediana1(a,b,c)<<endl;
					cout<<mediana2(a,b,c)<<endl;
					cout<<mediana3(a,b,c)<<endl;	
				}
				
				if(m==3)
				{
					cout<<"Ingrese el valor del angulo gama: "; cin>>gama;
					
					gama = (gama*pi)/180;
					c = sqrt(pow(a,2)+pow(b,2)-(2*a*b*cos(gama)));
					p = (a*sin(gama))/c;
					alfa = asin(p);
					p = (b*sin(gama))/c;
					beta = asin(p);
					
					cout<<"\nEl valor del lado restante es c = "<<c<<endl;
					cout<<"En radianes: alfa = "<<alfa<<endl;
					cout<<"En radianes: beta = "<<gama<<endl;
					
					alfa = (alfa*180)/pi;
					beta = (beta*180)/pi;
					
					cout<<"En grados sexagesimales: alfa = "<<alfa<<endl;
					cout<<"En grados sexagesimales: beta = "<<beta<<endl;
					cout<<perimetro(a,b,c)<<endl;
					cout<<area(a,b,c)<<endl;
					cout<<mediana1(a,b,c)<<endl;
					cout<<mediana2(a,b,c)<<endl;
					cout<<mediana3(a,b,c)<<endl;
				}
				break;
				
			case 4:
				cout<<"Ingrese el valor de alfa: "<<endl; cin>>alfa;
				cout<<"Ingrese el valor de beta: "<<endl; cin>>beta;
				
				alfa = (alfa*pi)/180;
				beta = (beta*pi)/180;
				gama = pi-alfa-beta;
				
				do
				{
					cout<<"Elija el lado que desea introducir"<<endl;
					cout<<"a\t presione 1"<<endl;
					cout<<"b\t presione 2"<<endl;
					cout<<"c\t presione 3"<<endl; cin>>m;
				} while(m<1 or m>3);
				
				if(m==1)
				{
					cout<<"Ingrese el valor del lado a: "<<endl; cin>>a;
					cout<<"\nEn radianes: gama = "<<gama<<endl;
					
					b = (a*sin(beta))/(sin(alfa));
					c = (a*sin(gama))/(sin(alfa));
					gama = (gama*180)/pi;
					
					cout<<"En grados sexagesimales: gama = "<<gama<<endl;
					cout<<"El valor de los lados restantes es: "<<endl;
					cout<<"\tb = "<<b<<"\t   c = "<<c<<endl;
					cout<<perimetro(a,b,c)<<endl;
					cout<<area(a,b,c)<<endl;
					cout<<mediana1(a,b,c)<<endl;
					cout<<mediana2(a,b,c)<<endl;
					cout<<mediana3(a,b,c)<<endl;
				}
				
				if(m==2)
				{
					cout<<"Ingrese el valor del lado b: "<<endl; cin>>b;
					cout<<"\nEn radianes: gama = "<<gama<<endl;
					
					a = (b*sin(alfa))/(sin(beta));
					c = (b*sin(gama))/(sin(beta));
					gama = (gama*180)/pi;
					
					cout<<"En grados sexagesimales: gama = "<<gama<<endl;
					cout<<"El valor de los lados restantes es: "<<endl;
					cout<<"\ta = "<<a<<"\t   c = "<<c<<endl;
					cout<<perimetro(a,b,c)<<endl;
					cout<<area(a,b,c)<<endl;
					cout<<mediana1(a,b,c)<<endl;
					cout<<mediana2(a,b,c)<<endl;
					cout<<mediana3(a,b,c)<<endl;	
				}
				
				if(m==3)
				{
					cout<<"Ingrese el valor del lado c: "<<endl; cin>>c;
					cout<<"\nEn radianes: gama = "<<gama<<endl;
					
					a = (c*sin(alfa))/(sin(gama));
					b = (c*sin(beta))/(sin(gama));
					gama = (gama*180)/pi;
					
					cout<<"En grados sexagesimales: gama = "<<gama<<endl;
					cout<<"El valor de los lados restantes es: "<<endl;
					cout<<"\ta = "<<a<<"\t   b = "<<b<<endl;
					cout<<perimetro(a,b,c)<<endl;
					cout<<area(a,b,c)<<endl;
					cout<<mediana1(a,b,c)<<endl;
					cout<<mediana2(a,b,c)<<endl;
					cout<<mediana3(a,b,c)<<endl;	
				}
				break;
				
			case 5:
				n = n+1;
				break;
		}
	}while(n==1);
	return 0;
}
