#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include <cstdlib> // atoi
using namespace std;

//Crear la estructura
typedef struct fichaMedica{
	int cedula,edad,telefono,dia,anio,mes;
	char nombre[30],apellido[30],direccion[20],correo[35],diagnostico[45],medicaciones [45];
	float pago_de_consulta;
	struct fichaMedica *siguiente;
	struct fichaMedica *anterior;
}fichaMedicaClinica;//renombrar a la estructura

typedef fichaMedicaClinica *pNodo, *Lista;

//Prototipo de funciones
pNodo CrearNodo(void);
void Insertar(Lista *l);
void realizarPago(Lista lista);
void Buscar(Lista lista);
void Borrar(Lista *l);
void Mostrar(Lista l);
void Modificar(Lista lista);
int validacionPalabras(char x[]);
int validar_numero(char numero[]);
int validarCedula(int cedula);
int validarNumeroMenu(char numero[]);
int validacionPalabrasCorreo(char x[]);

int main(){
	//Aqui se define el verdadero valor de lista
	Lista lista = NULL;
	char opc[10];
	int op=0,valnum;
	do{
		system ("cls");
		printf("\n\n\n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|");
		printf("    \n\t\t|--/--|            FICHAS DEL PACIENTE          |--/--|");
		printf("    \n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|");
		printf("\n\n\n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|");
		printf("    \n\t\t|--/--|      1. INGRESAR PACIENTE               |--/--|");
		printf("    \n\t\t|--/--|      2. REALIZAR PAGO DE CONSULTA       |--/--|");
		printf("    \n\t\t|--/--|      3. CONSULTAR PACIENTE              |--/--|");
		printf("    \n\t\t|--/--|      4. LISTAR PACIENTES                |--/--|");
		printf("    \n\t\t|--/--|      5. ELIMINAR PACIENTE               |--/--|");
		printf("    \n\t\t|--/--|      6. MODIFICAR DATOS DEL PACIENTE    |--/--|");
		printf("    \n\t\t|--/--|      7. SALIR                           |--/--|");
		printf("    \n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|\n\n");
		
		do{
        	fflush(stdin);
			cout<<"\t\t\t\t     OPCION: ";		scanf("%s",opc);
        	valnum = validarNumeroMenu(opc);
		}while(valnum==0);
        op=atoi(opc);
        fflush(stdin);
		
		switch(op){
			case 1: system("cls");
					Insertar (&lista); //insertar un nodo
					system ("pause");
					break;
			case 2: system("cls");
					realizarPago(lista);
					system ("pause");
					break;
			case 3: system("cls");
					Buscar(lista);
					system ("pause");
					break;
			case 4: system("cls");
					Mostrar (lista);
					system ("pause");
					break;
			case 5: system("cls");
					Borrar (&lista);
					system ("pause");
					break;
			case 6: system("cls");
					Modificar(lista);
					system ("pause");
					break;
			case 7: cout<<"\n\n\t\t\t\tSALIENDO DEL PROGRAMA\n";
					break;
		}		
	}while (op!=7);
	getch ();
	return 0;
}

pNodo CrearNodo(void){
	int val=0,valn=0,validado=0;
	char ed[10],ced[10],tel[10],ani[10],di[10],me[10];
	//Se declara el puntero nuevo
	pNodo nuevo;
	//Se pide espacio de memoria y se hace casting
	nuevo = (pNodo)malloc(sizeof(fichaMedicaClinica));//malloc retorna bytes y se convierte en direccion de memoria con pNodo
	//Se pide dato y se almacena 
	if(nuevo != NULL){
		printf("\n\n\n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|");
		printf("    \n\t\t|--/--|            INGRESE SUS DATOS            |--/--|");
		printf("    \n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|\n\n");
		
		do{
			do{
        		fflush(stdin);
				cout<<"\n\t\t INGRESE SU CEDULA: ";
        		scanf("%s",ced);
        		valn = validar_numero(ced);
			}while(valn==0);
        	nuevo->cedula=atoi(ced);
        	validado=validarCedula(nuevo->cedula);
			fflush(stdin);
		}while(validado==0);

		do{
			printf("\n\t\t INGRESE SU 1ER NOMBRE: ");
			gets(nuevo->nombre);
			val=validacionPalabras(nuevo->nombre);
			fflush(stdin);
		}while(val==0);
		
		do{
			printf("\n\t\t INGRESE SU 1ER APELLIDO: ");
			gets(nuevo->apellido);
			val=validacionPalabras(nuevo->apellido);
			fflush(stdin);
		}while(val==0);
		
		do{
        		fflush(stdin);
				cout<<"\n\t\t INGRESE SU EDAD: ";
        		scanf("%s",ed);
        		valn = validar_numero(ed);
			}while(valn==0);
        nuevo->edad=atoi(ed);
        fflush(stdin);
		
		do{
			printf("\n\t\t INGRESE SU DIRECCION: ");
			gets(nuevo->direccion);
			val=validacionPalabras(nuevo->direccion);
			fflush(stdin);
		}while(val==0);
		
		do{
			printf("\n\t\t INGRESE SU CORREO: ");
			gets(nuevo->correo);
			val=validacionPalabrasCorreo(nuevo->correo);
			fflush(stdin);
		}while(val==0);
		
		do{
        	fflush(stdin);
			cout<<"\n\t\t INGRESE SU TELEFONO: ";
        	scanf("%s",tel);
        	valn = validar_numero(tel);
		}while(valn==0);
        nuevo->telefono=atoi(tel);
		fflush(stdin);
		
		do{
			printf("\n\t\t INGRESE DIAGNOSTICO: ");
			gets(nuevo->diagnostico);
			val=validacionPalabras(nuevo->diagnostico);
			fflush(stdin);
		}while(val==0);
		
		do{
			printf("\n\t\t INGRESE MEDICACION: ");
			gets(nuevo->medicaciones);
			val=validacionPalabras(nuevo->medicaciones);
			fflush(stdin);
		}while(val==0);
		
		do{
			printf("\n\t\t FECHA DE ATENCION ");
			do{
        			fflush(stdin);
					cout<<"\n\t\t INGRESE DIA: ";
        			scanf("%s",di);
        		valn = validar_numero(di);
			}while(valn==0);
        	nuevo->dia=atoi(di);
			if(nuevo->dia>=1 && nuevo->dia<=31)
    		printf("");
    		else{
        	printf("\t\t DIA NO VALIDO, INGRESE UN DIA CORRECTO\n");
    		}fflush(stdin);
    	} while (nuevo->dia<1 || nuevo->dia>31);
		
		do{
			do{
        		fflush(stdin);
				cout<<"\n\t\t INGRESE MES: ";
        		scanf("%s",me);
        		valn = validar_numero(me);
			}while(valn==0);
        	nuevo->mes=atoi(me);
			if(nuevo->mes>=1 && nuevo->mes<=12)
    		printf("");
    		else{
        	printf("\t\t MES NO VALIDO, INGRESE UN MES CORRECTO\n");
    		}fflush(stdin);
    	} while (nuevo->mes<1 || nuevo->mes>12);
  		
  		do{
			do{
        		fflush(stdin);
				cout<<"\n\t\t INGRESE ANIO: ";
        		scanf("%s",ani);
        		valn = validar_numero(ani);
			}while(valn==0);
        	nuevo->anio=atoi(ani);
        	if(nuevo->anio>=2000 && nuevo->anio<=2030)
    		printf("");
    		else{
        	printf("\t\t ANIO NO VALIDO, INGRESE UN ANIO ENTRE 2000 A 2030\n");
    		}fflush(stdin);
    	} while (nuevo->anio<2000 || nuevo->anio>2030);
		return nuevo;
		//No hubo espacio en la RAM
	}else
		return NULL;
}

//Es necesario mandar por referencia
//El verdadero valor de lista esta en el main
void Insertar(Lista *lista){
	//Se declaran punteros nuevo y aux
	pNodo nuevo,aux;
	//Invoca a la funcion CrearNodo()
	nuevo=CrearNodo();
	//malloc si dio espacio de la RAM
	if(nuevo!=NULL){
		//Colocamos aux en la primera posicion de la lista
		aux=*lista;
		//Permite evaluar que aux sea != NULL
		//Verifica si aux tiene que desplazarce por anterior
		if(aux!=NULL){
			while(aux->anterior!=NULL)
				aux=aux->anterior;
		}
		
		//Si la lista esta vacia o se inserta al inicio
		if(aux==NULL || (strcoll(aux->apellido,nuevo->apellido))>0){
			//Añadimos la lista a continuacion del nuevo nodo
			nuevo->siguiente=aux;
			nuevo->anterior=NULL;
			//Lista ya tiene elementos, se inserta inicio
			if(aux!=NULL)
				aux->anterior=nuevo;
			//Lista no tiene elementos, se inserta inicio
			if(*lista==NULL)
				*lista=nuevo;
		}else{
			/*Avanzamos hasta el nodo anterior al nodo insertado*/
			while((aux->siguiente!=NULL)&&(strcoll(aux->siguiente->apellido,nuevo->apellido))<=0){
				aux=aux->siguiente;
			}
			/*Insertamos el nuevo modo despues del nodo anterior,
			se inserta nodo intermedio o nodo final*/
			nuevo->siguiente = aux->siguiente;
			aux->siguiente = nuevo;
			nuevo->anterior = aux;
			//Se finaliza inserccion nodo intermedio
			if(nuevo->siguiente != NULL)
				nuevo->siguiente->anterior = nuevo;
		}
	}else
		printf("\n\t\t NO SE PUEDE INSERTAR");
	}

void realizarPago(Lista lista){
	//se define el puntero aux
	//aux inicia en lista
	pNodo aux = lista;
	int encontrado=0,a=0,val=0,valnum=0;
	char nodoaBuscar[10],opc[10];
	float r=0;
	printf("\n\n\n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|");
	printf("    \n\t\t|--/--|              REALIZAR PAGO              |--/--|");
	printf("    \n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|\n\n");
	
	
	do{
		printf("      \t\t INGRESE SU APELLIDO PARA BUSCAR SU CONSULTA: ");
		gets(nodoaBuscar);
		val=validacionPalabras(nodoaBuscar);
		fflush(stdin);
	}while(val==0);
	//valide que la lista tenga elementos
	if(lista==NULL)
		printf("\t\t LISTA VACIA\n\n");
		//La lista si tiene elementos
		else{
			//para empezar aux desde el inicio
			//de la lista
			while(aux->anterior!=NULL)
				aux = aux->anterior;
			//Mientras encontrado sea diferente de 1 se mantenga en el while
			while(aux!=NULL && encontrado !=1){
				//Condicion para comparar
				if(strcoll(aux->apellido,nodoaBuscar)==0){
					printf("\n\n\n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|");
					printf("    \n\t\t|--/--|            ESCOJA SU CONSULTA           |--/--|");
					printf("    \n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|");
					printf(" \n\n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|");
					printf("    \n\t\t|--/--|           1. MEDICINA GENERAL           |--/--|");
					printf("    \n\t\t|--/--|           2. ESPECIALIZACION            |--/--|");
					printf("    \n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|\n\n");
					do{
        				fflush(stdin);
						cout<<"\t\t\t\t     OPCION: ";		scanf("%s",opc);
        				valnum = validarNumeroMenu(opc);
					}while(valnum==0);
        			a=atoi(opc);
        			fflush(stdin);
				
				if(a==1){
					fflush(stdin);
					//Tercera edad
					if (aux->edad>60){
						aux->pago_de_consulta=50-(50*0.50);
						cout<<"\t\t SU PAGO ES: "<<aux->pago_de_consulta<<"\n\n";
					}
					//Mayor de edad
					else if (aux->edad>18 && aux->edad<=60){
						aux->pago_de_consulta = 50;
						cout<<"\t\t SU PAGO ES: "<<aux->pago_de_consulta<<"\n\n";
					}
					//Menor de edad
					else if (aux->edad>0 && aux->edad<=18){
						aux->pago_de_consulta=50-(50*0.30);
						cout<<"\t\t SU PAGO ES: "<<aux->pago_de_consulta<<"\n\n";
					}
					encontrado=1;
				}if(a == 2){
					fflush(stdin);
					//Tercera edad
					if (aux->edad>60){
						aux->pago_de_consulta=70-(70*0.50);
						cout<<"\t\t SU PAGO ES: "<<aux->pago_de_consulta<<"\n\n";
					}
					//Mayor de edad
					else if (aux->edad>18 && aux->edad<=60){
						aux->pago_de_consulta = 70;
						cout<<"\t\t SU PAGO ES: "<<aux->pago_de_consulta<<"\n\n";
					}
					//Menor de edad
					else if (aux->edad>0 && aux->edad<=18){
						aux->pago_de_consulta=70-(70*0.30);
						cout<<"\t\t SU PAGO ES: "<<aux->pago_de_consulta<<"\n\n";
					}
					encontrado = 1;
				}
			}
				aux = aux->siguiente;
			}
			if (encontrado == 0){
				printf("\n\t\t FICHA DEL PACIENTE NO ENCONTRADA, INGRESE UNA FICHA CORRECTA\n\n");
			}
		} 
	}// se cierra

void Buscar(Lista lista){
	//se define el puntero aux
	//aux inicia en lista
	pNodo aux = lista;
	int encontrado=0,val=0,valnum=0;
	char nodoaBuscar[10];
	printf("\n\n\n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|");
	printf("    \n\t\t|--/--|           CONSULTAR PACIENTE            |--/--|");
	printf("    \n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|\n\n");
	
	do{
		printf("      \t\t INGRESE SU APELLIDO PARA BUSCAR SU CONSULTA: ");
		gets(nodoaBuscar);
		val=validacionPalabras(nodoaBuscar);
		fflush(stdin);
	}while(val==0);
	//valide que la lista tenga elementos
	if(lista==NULL)
		printf("\n\n\t\tLISTA VACIA\n\n");
		//La lista si tiene elementos
		else{
			//para empezar aux desde el inicio
			//de la lista
			while(aux->anterior!=NULL)
				aux = aux->anterior;
			//Mientras encontrado sea diferente de 1 se mantenga en el while
			while(aux!=NULL && encontrado !=1){
				//Condicion para comparar
				if(strcoll(aux->apellido,nodoaBuscar)==0){
					printf("\n\n\n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|");
					printf("    \n\t\t|--/--|       LOS DATOS DE SU CONSULTA SON      |--/--|");
					printf("    \n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|\n\n");
					printf("\n\t\t CEDULA: %d", aux->cedula);
					printf("\n\t\t NOMBRE: %s", aux->nombre);
					printf("\n\t\t APELLIDO: %s", aux->apellido);
					printf("\n\t\t EDAD: %d", aux->edad);
					printf("\n\t\t DIRECCION: %s", aux->direccion);
					printf("\n\t\t CORREO: %s", aux->correo);
					printf("\n\t\t TELEFONO: %d", aux->telefono);
					printf("\n\t\t DIAGNOSTICO: %s", aux->diagnostico);
					printf("\n\t\t MEDICACION: %s", aux->medicaciones);
					printf("\n\t\t FECHA DE ATENCION: %d / %d / %d", aux->dia, aux->mes, aux->anio);
					printf("\n\t\t PAGO DE CONSULTA: %.2f", aux->pago_de_consulta);
					printf("\n\n");
					encontrado=1;
				}
				aux = aux->siguiente;
			}
			if (encontrado == 0){
				printf("\n\t\t FICHA DEL PACIENTE NO ENCONTRADA, INGRESE UNA FICHA CORRECTA\n\n");
			}
		} 
	}// se cierra

////Mostrar por pantalla toda la lista
//Se muestra en orden ascendente
//Se envía por valor porque no se modifica puntero lista
void Mostrar(Lista lista){
	//se define el puntero aux
	//aux inicia en lista
	pNodo aux = lista;
	//valide que la lista tenga elementos
	if(lista==NULL)
		printf("\n\n\t\t Lista vacia\n\n");
		//La lista si tiene elementos
		else{
			//para empezar aux desde el inicio
			//de la lista
			while(aux->anterior!=NULL)
				aux = aux->anterior;
			printf("\n\n\n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|");
			printf("    \n\t\t|--/--|            LISTA DE PACIENTES           |--/--|");
			printf("    \n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|\n\n");
			//imprime los valores de la lista
			while(aux!=NULL){
				printf("\n\t\t CEDULA: %d", aux->cedula);
				printf("\n\t\t NOMBRE: %s", aux->nombre);
				printf("\n\t\t APELLIDO: %s", aux->apellido);
				printf("\n\t\t EDAD: %d", aux->edad);
				printf("\n\t\t DIRECCION: %s", aux->direccion);
				printf("\n\t\t CORREO: %s", aux->correo);
				printf("\n\t\t TELEFONO: %d", aux->telefono);
				printf("\n\t\t DIAGNOSTICO: %s", aux->diagnostico);
				printf("\n\t\t MEDICACION: %s", aux->medicaciones);
				printf("\n\t\t FECHA DE ATENCION: %d / %d / %d", aux->dia, aux->mes, aux->anio);
				printf("\n\t\t PAGO DE CONSULTA: %.2f", aux->pago_de_consulta);
				printf("\n\n");
				aux = aux->siguiente;
			}
		} 
	}// se cierra
	
//Permite borrar un elemento
//Lista se vera modificado, entonces se maneja referencia
void Borrar(Lista *lista){
	//Define puntero auxiliar
	pNodo aux;
	//Variable local temporal
	int val=0;
	char letra[10];
	
	if(*lista != NULL){
		printf("\n\n\n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|");
		printf("    \n\t\t|--/--|             BORRAR PACIENTE             |--/--|");
		printf("    \n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|\n\n");
		
		do{
			printf("      \t\t INGRESE SU APELLIDO PARA BUSCAR SU CONSULTA: ");
			gets(letra);
			val=validacionPalabras(letra);
			fflush(stdin);
		}while(val==0);
		
		//Buscar el nodo de valor letra
		aux = *lista;
		
		while(aux!=NULL && (strcoll(aux->apellido,letra))<0)
			aux = aux->siguiente;
			
		while(aux!=NULL && (strcoll(aux->apellido,letra))>0)
			aux = aux->anterior;
			
		//EL valor v no esta en la lista
		if(aux==NULL || (strcoll(aux->apellido,letra))!=0){
			cout<<"\n\t\t FICHA DEL PACIENTE NO ENCONTRADA, INGRESE UNA FICHA CORRECTA\n\n";
			return; //Sale del procedimiento
		}
		
		//Para borrar el nodo
		//Si lista apunta al nodo que queremos borrar, depl
		if(aux == *lista){
			if(aux->anterior)
				*lista = aux->anterior;
			else
				*lista = aux->siguiente;
		}
		if(aux->anterior!=NULL)
			aux->anterior->siguiente = aux->siguiente;
			
		if(aux->siguiente!=NULL)
			aux->siguiente->anterior = aux->anterior;
		
		free(aux);
		cout<<"\n\t\t PACIENTE ELIMINADO\n\n";
	}else
		printf("\n\t\t NO EXISTEN PACIENTES PACIENTES EN LA LISTA\n\n");
	}//se cierra

void Modificar(Lista lista){
	int val=0, valn=0, validado=0;
	char ed[10],ced[10],tel[10],ani[10],di[10],me[10];
	//se define el puntero aux
	//aux inicia en lista
	pNodo aux = lista;
	int encontrado=0;
	char nodoaBuscar[10];
	printf("\n\n\n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|");
	printf("    \n\t\t|--/--|       MODIFICAR DATOS DEL PACIENTE      |--/--|");
	printf("    \n\t\t|--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--|\n\n");
	
	do{
		printf("      \t\t INGRESE SU APELLIDO PARA BUSCAR SU CONSULTA: ");
		gets(nodoaBuscar);
		val=validacionPalabras(nodoaBuscar);
		fflush(stdin);
	}while(val==0);
	//valide que la lista tenga elementos
	if(lista==NULL)
		printf("\n\t\t Lista vacia\n\n");
		//La lista si tiene elementos
		else{
			//para empezar aux desde el inicio
			//de la lista
			while(aux->anterior!=NULL)
				aux = aux->anterior;
			//Mientras encontrado sea diferente de 1 se mantenga en el while
			while(aux!=NULL && encontrado !=1){
				//Condicion para comparar
				if(strcoll(aux->apellido,nodoaBuscar)==0){
					
					do{
						do{
        					fflush(stdin);
							cout<<"\n\t\t INGRESE SU CEDULA: ";
        					scanf("%s",ced);
        					valn = validar_numero(ced);
						}while(valn==0);
        				aux->cedula=atoi(ced);
        				validado=validarCedula(aux->cedula);
        				fflush(stdin);
					}while(validado==0);
					
					do{
						printf("\n\t\t INGRESE SU 1ER NOMBRE: ");
						gets(aux->nombre);
						val=validacionPalabras(aux->nombre);
						fflush(stdin);
					}while(val==0);
					
					do{
						printf("\n\t\t INGRESE SU 1ER APELLIDO: ");
						gets(aux->apellido);
						val=validacionPalabras(aux->apellido);
						fflush(stdin);
					}while(val==0);
					
					do{
        				fflush(stdin);
						cout<<"\n\t\t INGRESE SU EDAD: ";
        				scanf("%s",ed);
        				valn = validar_numero(ed);
					}while(valn==0);
        			aux->edad=atoi(ed);
        			fflush(stdin);
        			
					do{
						printf("\n\t\t INGRESE SU DIRECCION: ");
						gets(aux->direccion);
						val=validacionPalabras(aux->direccion);
						fflush(stdin);
					}while(val==0);
		
					do{
						printf("\n\t\t INGRESE SU CORREO: ");
						gets(aux->correo);
						val=validacionPalabrasCorreo(aux->correo);
						fflush(stdin);
					}while(val==0);
		
					do{
        				fflush(stdin);
						cout<<"\n\t\t INGRESE SU TELEFONO: ";
        				scanf("%s",tel);
        				valn = validar_numero(tel);
					}while(valn==0);
        			aux->telefono=atoi(tel);
					fflush(stdin);
		
					do{
						printf("\n\t\t INGRESE DIAGNOSTICO: ");
						gets(aux->diagnostico);
						val=validacionPalabras(aux->diagnostico);
						fflush(stdin);
					}while(val==0);
		
					do{
						printf("\n\t\t INGRESE MEDICACION: ");
						gets(aux->medicaciones);
						val=validacionPalabras(aux->medicaciones);
						fflush(stdin);
					}while(val==0);
		
					do{
						printf("\n\t\t FECHA DE ATENCION ");
						do{
        					fflush(stdin);
							cout<<"\n\t\t INGRESE DIA: ";
        					scanf("%s",di);
        					valn = validar_numero(di);
						}while(valn==0);
        				aux->dia=atoi(di);
						if(aux->dia>=1 && aux->dia<=31)
    					printf("");
    					else{
        				printf("\t\t DIA NO VALIDO, INGRESE UN DIA CORRECTO\n");
    					}fflush(stdin);
    				} while (aux->dia<1 || aux->dia>31);
		
					do{
						do{
        					fflush(stdin);
							cout<<"\n\t\t INGRESE MES: ";
        					scanf("%s",me);
        					valn = validar_numero(me);
						}while(valn==0);
        				aux->mes=atoi(me);
						if(aux->mes>=1 && aux->mes<=12)
    					printf("");
    					else{
        				printf("\t\t MES NO VALIDO, INGRESE UN MES CORRECTO\n");
    					}fflush(stdin);
    				} while (aux->mes<1 || aux->mes>12);
  		
  					do{
						do{
        					fflush(stdin);
							cout<<"\n\t\t INGRESE ANIO: ";
        					scanf("%s",ani);
        					valn = validar_numero(ani);
						}while(valn==0);
        				aux->anio=atoi(ani);
        				if(aux->anio>=2000 && aux->anio<=2030)
    					printf("");
    					else{
        				printf("\t\t ANIO NO VALIDO, INGRESE UN ANIO ENTRE 2000 A 2030\n");
    					}fflush(stdin);
    				} while (aux->anio<2000 || aux->anio>2030);
					
					cout<<"\n\n\t\t SUS DATOS FUERON MODIFICADOS\n\n";
					encontrado=1;
				}
				aux = aux->siguiente;
			}
			if (encontrado == 0){
				printf("\n\t\t FICHA DEL PACIENTE NO ENCONTRADA, INGRESE UNA FICHA CORRECTA\n\n");
			}
		} 
	}// se cierra

int validacionPalabras(char x[]){
	for(int i=0;i<strlen(x);i++){
		if(!(x[i]>=65 && x[i]<=90 || x[i]>=97 && x[i]<=122)){ //Rango de letras en tabla ASCII
		printf("\t\t INGRESE SOLO LETRAS  \n\n");
		return 0;
		}
	}
	return 1;
}

int validar_numero(char numero[]){
    int i;
    for(i=0; i<strlen(numero); i++){
        if(!(isdigit(numero[i]))){
            printf("\t\t INGRESE SOLO NUMEROS\n");
            return 0;
        }
    }
    return 1;
}

int validarCedula(int cedul){
		int a,b,c,d,e,f,g,h,i,j,k,pares,impares,total,dec=0;
		a=cedul/1000000000;
        cedul=cedul-(a*1000000000);
        b=cedul/100000000;
        cedul=cedul-(b*100000000);
        c=cedul/10000000;
        cedul=cedul-(c*10000000);
        d=cedul/1000000;
        cedul=cedul-(d*1000000);
        e=cedul/100000;
        cedul=cedul-(e*100000);
        f=cedul/10000;
        cedul=cedul-(f*10000);
        g=cedul/1000;
        cedul=cedul-(g*1000);
        h=cedul/100;
        cedul=cedul-(h*100);
        i=cedul/10;
        cedul=cedul-(i*10);
        j=cedul/1;
        cedul=cedul-(j*1);
        if (cedul>2400000000LL){
                cout<<"\n\t\t INGRESE UN NUMERO DE CEDULA VALIDO"<<endl;
        }else{
                pares=b+d+f+h;
                a=a*2;
                if (a>9){
                        a=a%10+a/10;
                }
                c=c*2;
                if (c>9){
                        c=c%10+c/10;
                }
                e=e*2;
                if (e>9){
                        e=e%10+e/10;
                }
                g=g*2;
                if (g>9){
                        g=g%10+g/10;
                }
                i=i*2;
                if (i>9){
                        i=i%10+i/10;
                }
                impares=a+c+e+g+i;
                total=pares+impares;

                while (dec-total!=j && dec<total+10){
                        dec=dec+10;
                }
                if (dec-total!=j){
                    cout<<"\t\t CEDULA ERRONEA, INGRESE UNA CORRECTA"<<endl;
                    return 0;
                }
        }
    cout<<"\t\t SU CEDULA EXISTE"<<endl;
    return 1;
}

int validarNumeroMenu(char numero[]){
    int i;
    for(i=0; i<strlen(numero); i++){
        if(!(isdigit(numero[i]))){
            printf("\t\t\t          INGRESA SOLO NUMEROS\n\n");
            return 0;
        }
    }
    return 1;
}

int validacionPalabrasCorreo(char x[]){
	for(int i=0;i<strlen(x);i++){
		if(!(x[i]>=46 && x[i]<=90 || x[i]>=97 && x[i]<=122)){ //Rango de letras en tabla ASCII
		printf("\t\t CARACTERES INGRESADOS INCORRECTOS  \n\n");
		return 0;
		}
	}
	return 1;
}
