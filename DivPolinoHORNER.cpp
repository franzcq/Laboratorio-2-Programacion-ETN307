/*El siguiente programa resuelve una division de polinomios por el metodo de Horner
 Estudiante: Franz Choque Quispe            ETN-307L  */

#include <iostream>

using namespace std;

int main()
{
	int i,j,m,gradoP,gradoQ,filas,columnas,dimVect,numeroDeOperaciones,recorridoColumnas=0,recorridoFilas=1;
	float sumaDeColumna=0;
	
	cout<<"Ingrese el grado dividendo: "<<endl; cin>>gradoP;
	cout<<"Ingrese el grado divisor: "<<endl; cin>>gradoQ;
	
	if(gradoP<gradoQ)
	{
		cout<<"El grado del Dividendo debe ser mayor que el grado del divisor";
	}
	
	else
	{
		filas = gradoP-gradoQ+2;
		columnas = gradoP+1;
		dimVect = gradoQ+1;
		
		float vectorQ[dimVect];
		float matrizP[filas][columnas];
		float vectorResultado[columnas];
		
		for(i=0;i<=gradoQ;i++)
		{
			vectorQ[i] = 0;
		}
		
		for(i=0;i<filas;i++){
			for(j=0;j<columnas;j++){
				matrizP[i][j] = 0;
			}
		}
		
		cout<<"Ingrese los coeficientes del dividendo: "<<endl;
		for(j=0;j<columnas;j++){
			cin>>matrizP[0][j];
		}
		
		cout<<"Ingrese los coeficientes del divisor: "<<endl;
		for(i=0;i<dimVect;i++){
			cin>>vectorQ[i];
		}
		
		for(i=1;i<dimVect;i++){
			vectorQ[i] = -vectorQ[i];
		}
		
		numeroDeOperaciones = gradoP-gradoQ+1;
		
		for(m=0;m<numeroDeOperaciones;m++){
			
			sumaDeColumna = 0;
			
			for(i=0;i<filas;i++){
				sumaDeColumna = matrizP[i][recorridoColumnas]+sumaDeColumna;
			}
			
			vectorResultado[recorridoColumnas] = sumaDeColumna/vectorQ[0];
			
			for(i=1;i<dimVect;i++){
				matrizP[recorridoFilas][recorridoColumnas+i] = vectorResultado[recorridoColumnas]*vectorQ[i];
			}
			
			recorridoColumnas = recorridoColumnas+1;
			recorridoFilas = recorridoFilas+1;
			
		}
		
		for(i=0;i<columnas;i++){
			vectorResultado[i] = 0;
		}
		
		for(j=0;j<columnas;j++){
			for(i=0;i<filas;i++){
				vectorResultado[j] = vectorResultado[j]+matrizP[i][j];
			}
		}
		
		for(i=0;i<columnas-gradoQ;i++){
			vectorResultado[i] = vectorResultado[i]/vectorQ[0];
		}
		
		for(i=0;i<filas;i++){
				for(j=0;j<columnas;j++){
				cout<<"\t"<<matrizP[i][j];
				}	
			cout<<endl;
			}
			
		cout<<"VectorQ"<<endl;		
		for(i=0;i<dimVect;i++){
			cout<<vectorQ[i]<<endl;
			}
				
		cout<<"Result"<<endl;
		for(i=0;i<columnas;i++){
			cout<<"\t"<<vectorResultado[i];
			}
			
		cout<<"\nDonde los primeros "<<gradoQ+1<<" terminos son el cociente de la división"<<endl;
		cout<<"Y los ultimos "<<gradoP-gradoQ<<" terminos son el residuo de la division"<<endl;
	}

	return 0;
}
