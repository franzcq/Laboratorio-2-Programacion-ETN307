/*El siguiente programa generará una matriz de Vandermonde y hallara su determinante
 Estudiante: Franz Choque Quispe            ETN-307L  */

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

int numerosAleatorios(int rango){
	int numerosAleatorios;
	
	numerosAleatorios = 1 + rand()%rango;
	
	return numerosAleatorios;
}

int main(){
	
	int numero,i,j,rango=20,x;
	long int determinante=1;
	
	cout<<"Ingrese el valor de n para una matriz n x n"<<endl; cin>>numero;
	
	int matriz[numero][numero],vector[numero];
	
	for (i=0; i<numero; i++){
		for(j=0;j<numero;j++){
			matriz[i][j] = 0;
		}
	}
	
	for(i=0;i<numero;i++){
		matriz[0][i] = 1;
	}
	
	srand(time(NULL));
	
	for(i=0;i<numero;i++){
		matriz[1][i] = numerosAleatorios(rango);
	}
	
	for(j=0;j<numero;j++){
		
		for(i=2;i<numero;i++){
			matriz[i][j] = pow(matriz[1][j],i);
		}
	}
	
	for(i=0;i<numero;i++){
	 	for(j=0;j<numero;j++){
				cout<<"\t\t"<<matriz[i][j];
			}
			cout<<endl;
		}
	
	for(i=0;i<numero;i++){
		vector[i] = matriz[1][i];
	}
	
	for(i=0;i<numero-1;i++){
		for(j=i+1;j<numero;j++){
			x = vector[j]-vector[i];
			determinante = determinante*x;
		}
	}
	
	cout<<"El determinante de esta matriz es: "<<determinante<<endl;

	return 0;
}
