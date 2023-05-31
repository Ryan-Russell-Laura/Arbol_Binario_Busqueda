//Arbol binario de busqueda(ABB)

#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *derecha;
    Nodo *izquierda;
};

Nodo *arbol=NULL;
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void menu();
void mostrarArbol(Nodo *arbol, int contador);
bool busqueda(Nodo *,int);

int main(){   
    menu();
    return 0;
}
//Funcion para crear nodo
Nodo *crearNodo(int n){
    Nodo *nuevo_nodo=new Nodo();

    nuevo_nodo->dato=n;
    nuevo_nodo->derecha=NULL;
    nuevo_nodo->izquierda=NULL;
    return nuevo_nodo;
}
//Funcion para insertar un nodo
void insertarNodo(Nodo *&arbol,int n){
    if (arbol==NULL){
        Nodo *nuevo_nodo=crearNodo(n);
        arbol=nuevo_nodo;
    }else{
        int valorRaiz=arbol->dato;
        cout<<"\n  Iteracion con dato="<<n<<endl;
        cout<<"  ----------------------\n";
        cout<<"\n  Condicion:"<<n<<"<="<<valorRaiz<<"?\n";
        if(n<=valorRaiz){
        	cout<<"  Respuesta: VERDAD (Se avanza a la izquierda)\n";
            insertarNodo(arbol->izquierda,n);            
        }else{
        	cout<<"  Respuesta: FALSO (Se avanza a la derecha)\n";
            insertarNodo(arbol->derecha,n);
        }
    }
}
//Funcion que obtiene el numero de niveles del arbol
int contnivel(Nodo *arbol){
	if (arbol!=NULL){
		int izquierda=contnivel(arbol->izquierda)+1;
		int derecha=contnivel(arbol->derecha)+1;
		if(izquierda>derecha){
		   return izquierda;
		}else{
		   return derecha;
		}
	}
}
//Funcion para mostrar un arbol por niveles
void mostrarArbolNiveles(Nodo *arbol, int nivel){	
    if (arbol == NULL)
    {
        return;
    }else{
        if(arbol!=NULL){
			if(nivel==0){
				cout<<"\t  "<<arbol->dato<<" ";
			}
			mostrarArbolNiveles(arbol->izquierda,nivel-1);
			mostrarArbolNiveles(arbol->derecha,nivel-1);
		}
    }
}
//Funcion para buscar un elemento
bool busqueda(Nodo *arbol,int n){
		
	if(arbol==NULL){
		return false;
	}else if(arbol->dato==n){//si el nodo es igual al elemento
		int valorRaiz=arbol->dato;
		cout<<"\n  Condicion:"<<n<<"<="<<valorRaiz<<"?\n";
		cout<<"  Respuesta: VERDAD (NODO ENCONTRADO)\n";
		return true;
	}
	else if(n<arbol->dato){
		int valorRaiz=arbol->dato;
		cout<<"\n  Condicion:"<<n<<"<="<<valorRaiz<<"?\n";
		cout<<"  Respuesta: VERDAD (Se avanza a la izquierda)\n";			
		return busqueda(arbol->izquierda,n);
	}else{
		int valorRaiz=arbol->dato;
		cout<<"\n  Condicion:"<<n<<"<="<<valorRaiz<<"?\n";
		cout<<"  Respuesta: FALSO (Se avanza a la derecha)\n";		
		return busqueda(arbol->derecha,n);
	}	
}

void menu(){
    int dato,opcion;
    bool bandera=false;
    bool cazador=false;
    do
    {
        cout<<"\n";
      	cout<<"  |---------------------------------------------|"<<endl;
   	  	cout<<"  |  PROGRAMA: ARBOL BINARIO DE BUSQUEDA (ABB)  |"<<endl;
      	cout<<"  |---------------------------------------------|"<<endl;
      	cout<<"  |                                             |"<<endl;
      	cout<<"  |      [1] CREAR Y MOSTRAR ARBOL INICIAL      |"<<endl;
      	cout<<"  |      [2] INSERTAR NUEVO NODO                |"<<endl;
      	cout<<"  |      [3] MOSTRAR ARBOL ACTUALIZADO          |"<<endl;
      	cout<<"  |      [4] BUSCAR UN NODO DEL ARBOL           |"<<endl;
      	cout<<"  |      [5] SALIR                              |"<<endl;
		cout<<"  |                                             |"<<endl;
      	cout<<"  |---------------------------------------------|"<<endl;
      	cout<<"  |      ©2023 Ryan Russell Laura Chambilla     |"<<endl;
	  	cout<<"  |---------------------------------------------|"<<endl;  
      
      	cout<<endl<<"  POR FAVOR ELIJA UNA OPCION: ";        
        cin>>opcion;
        switch(opcion)
        {
	        case 1:
	        	if(cazador==true){
	        			cout<<"\n  Esta opcion no se puede ejecutar porque el arbol inicial ya no es el mismo\n";
	        			cout<<"  Por favor si desea ver el nuevo arbol actualizado, elija la opcion 3\n\n";
				}else{
					cazador=true;   
					while(bandera==false){	        		
		        		bandera=true;
		        		insertarNodo(arbol,60);
		        		insertarNodo(arbol,30);
		        		insertarNodo(arbol,20);
		        		insertarNodo(arbol,55);
		        		insertarNodo(arbol,35);
		        		insertarNodo(arbol,45);
		        		insertarNodo(arbol,40);
		        		insertarNodo(arbol,50);
		        		insertarNodo(arbol,70);
		        		insertarNodo(arbol,90);
		        		insertarNodo(arbol,80);
		        		insertarNodo(arbol,95);						
					}
					cout<<"\n  ARBOL INICIAL CONSTRUIDO"<<endl;
					cout<<"  ------------------------\n\n";
					for(int i=0;i<contnivel(arbol);i++){
						cout<<"  Nivel "<<i<<":"<<endl;
						mostrarArbolNiveles(arbol,i);
						cout<<"\n\n";	
					}
					cout<<endl;
	                cout<<"  Nota: Las iteraciones se pueden observar mas arriba del arbol...\n"<<endl;	   
				}	             	
				system("pause");
				break;	
			case 2:
				cazador=true;     
	            cout<<"\n  Digite el valor del nuevo Nodo: ";
	            cin>>dato;
	            insertarNodo(arbol,dato);
	            cout<<"\n  MOSTRANDO ARBOL ACTUALIZADO"<<endl;
	            cout<<"  ---------------------------\n\n";
	            for(int i=0;i<contnivel(arbol);i++){
					cout<<"  Nivel "<<i<<":"<<endl;
					mostrarArbolNiveles(arbol,i);
					cout<<"\n\n";	
				}
	            cout<<endl;
	            cout<<"  Nota: Las iteraciones se pueden observar mas arriba del arbol...\n"<<endl;
	            system("pause");
				break;
	        case 3:
	        	if(cazador==true){
	        		cout<<"\n  MOSTRANDO ARBOL ACTUALIZADO"<<endl;
	            	cout<<"  ---------------------------\n\n";
	            	for(int i=0;i<contnivel(arbol);i++){
						cout<<"  Nivel "<<i<<":"<<endl;
						mostrarArbolNiveles(arbol,i);
						cout<<"\n\n";	
					}
				}else{
					cout<<"\n  Advertencia: Antes de usar esta opcion\n"; 
					cout<<"  usted debe crear el arbol inicial o insertar nuevos nodos\n\n";
				}	            
				system("pause");
				break;
	        case 4:
	        	if(cazador==true){
		        	cout<<"\n  Digite el valor del nodo a buscar:";
		        	cin>>dato;
		        	if(busqueda(arbol,dato)==true){
		        		cout<<"\n  El nodo con el valor "<<dato<<" ha sido encontrado en el arbol\n\n";
					}else{
						cout<<"\n  Nodo NO encontrado en el arbol\n";
					}
					cout<<"\n";
				}else{
					cout<<"\n  Advertencia: Antes de usar esta opcion\n"; 
					cout<<"  usted debe crear el arbol inicial o insertar nuevos nodos\n\n";
				}
	            system("pause");	            
	            break;				            
        }
        system("cls");
    }while(opcion!=5);
    cout<<"\n  Gracias por usar el programa...\n\n";
}
