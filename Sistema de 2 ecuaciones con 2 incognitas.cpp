/*El siguiente programa resuelve un sistema de dos ecuaciones lineales con dos incognitas
 Estudiante: Franz Choque Quispe            ETN-307L  */

#include<iostream>

using namespace std;

int main(){
	
	float a,b,c,d,e,f,x,y,casoEspecial;
	
	cout<<"Sistema de dos Ecuaciones con dos incognitas de la forma: \n\t ax + by = c\n\t dx + ey = f"<<endl;
	cout<<"Ingrese el valor de a: "<<endl; cin>>a;
	cout<<"Ingrese el valor de b: "<<endl; cin>>b;
	cout<<"Ingrese el valor de c: "<<endl; cin>>c;
	cout<<"Ingrese el valor de d: "<<endl; cin>>d;
	cout<<"Ingrese el valor de e: "<<endl; cin>>e;
	cout<<"Ingrese el valor de f: "<<endl; cin>>f;
	
	x = ((c*e)-(f*b))/((a*e)-(b*d));
	y = ((a*f)-(c*d))/((a*e)-(b*d));
	casoEspecial = (a*e)-(b*d);
	
	if(casoEspecial!=0){
		cout<<"El valor de x es: "<<x<<endl;
		cout<<"El valor de y es: "<<y<<endl;
	
	}
	else {
		cout<<"Tanto x como y poseen infinitas soluciones"<<endl;
	}
	
	return 0;
}
