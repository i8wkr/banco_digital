///////////////////___INFORMACIÓN___//////////////////

//Proyecto Final: SISTEMA DE SERVICIO BANCARIO VIRTUAL

//Equipo #1

/*Descripción:  Diseño de sistema automático que permita control de cuentas, manejo de transaciones bancarias, la alta de usuarios y diversos reportes.
			    Incluirá  dos tipos de usuario(usuario de cajero"estandar" y administrador del sistema ). 
			   
			    Sucursales Tlalpan, Santa Fe y Coyoacán.
*/
/*Objetivos:    Administrador:
				1.- Acceso como administrador vía password.
				2.- Alta y baja de ususarios de servicios bancarios.
				3.- Transferecia de dinero a los distintos cajeros.
				4.- Mostrar el estatus de todos los cajeros.
				5.- Mostrar  un reporte de cada usuario en pantalla.
				6.- Ayuda al usuario administrador.
				7.- Salida del sistema.
				
				Usuario:
				1.- Retiro de efectivo.
				2.- Retiro de efectivo (cheque).
				3.- Saldo de cheques.
				4.- Saldo de crédito.
				5.- Pagar.
				6.- Salida del sistema.
*/

/*Pendientes:  -- Cambiar el system(cls),system(pause).
			--Tronar el programa con password 
			-- Pasar valores de una fn1 a fn2


*/

/*Estructura:	1.- Inicio: Validación de Administrador 
				2.-	"id" de usuario.
				3.- Agregar usuario tipo administrador.
					El usuario que agregue éste nuevo perfil de administrador no podrá realizar los siguiente puntos:
						- No se le estará permitido el uso de espacios al inicio del nombre
						- No se le estará permitido el uso de espacios durante la creación de la contraseña
						- Habrá un mínimo en el número de letras de un usuario
				4.- Menú: Administrador ó Usuario.
				5.-Fin
*/
//////////////////////////////////////////////////////		

/*librerías*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Funciones PROTOTIPO */
void logo();
void menu_admin();
void menu();
void panel_admin();
void panel_usu();

void salida();

/*Main*/
int main(){
	
logo();
menu_admin();
void menu();
}	

/*Logo*/
void logo(void){
	
	printf("                                                                     \n");
	printf("                                  $                                  \n");
	printf("                                 $                                   \n");
	printf("                                $$                                   \n");
	printf("                           $    $$$                                  \n");
	printf("                          $$     $$$$                                \n"); 
	printf("                          $$$$    $$$$$                              \n");
	printf("                           $$$$    $$$$                              \n");
	printf("                            $$$$    $$$$$                            \n");
	printf("                       $$$   $$$$   $$$$$$$                          \n");
	printf("                     $$$$$$   $$$$  $$$$$$$$$$                       \n");
	printf("                  $$$$$$$$$$  $$$$  $$$$$$$$$$$                      \n");
	printf("                $$$$$$$$$$$$  $$$$ $$$$$$$$$$$$$                     \n");
	printf("               $$$$$$$$$$$$$  $$$$$$$$$$$$$$$$$$$                    \n"); 
	printf("               $$$$$$$$$$$$$ $$$$$$$$$$$$$$$$$$$$                    \n");
	printf("               $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$                    \n");
	printf("               $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$                     \n");
	printf("                $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$                      \n");
	printf("                 $$$$$$$$$$$$$$$$$$$$$$$$$$$$                        \n");
	printf("                   $$$$$$$$$$$$$$$$$$$$$$$$                          \n");
	printf("                       $$$$$$$$$$$$$$$$$                             \n");
	printf("                                                                     \n");
	printf("                           SANCEN&DER                                \n");
	printf("                     _______________________                         \n"); 
	printf("                      QUEREMOS SER TU BANCO                          \n");
	printf("                                                                     \n");
	
	system("pause");
	system("cls");//CLEAR-CLOOK
}

/*Regitro*/
void menu_admin(void){
	
///////__id: Contador__///////
/*Se generará cada vez que una entidad sea agregada al banco*/

	int nip_id_admin[4]={0,0,0,0};//CORREGIR
	int nip_id_cont;
/////////////////////////////
	
			printf("\n_________________________________________\n");
		printf("\tSERVICIO BANCARIO VIRTUAL\n");
			printf("_________________________________________\n");
		printf(" El sistema no ha detectado ADMINISTRADOR\n\n\n\n");
					
			system("pause");
			system("cls");
					
			printf("\n_________________________________________\n");
		printf("\tSERVICIO BANCARIO VIRTUAL\n");
			printf("_________________________________________\n");
					
/////////////////////////////////////////////////////__Variables__///////////////////////////////////////////////////////////
		char admin_nombre[40]={0},admin_apellido[80]={0},admin_password[40]={0};//Nombre, apellido y contraseña
		
		int  admin_nombre_enteros=0,admin_apellido_enteros=0,admin_password_enteros=0;//Strlen del nombre de ususario
		int  admin_cont=0,admin_cont_reset,admin_cont2,admin_cont3;//Contadores
		
		char admin_password_espacio=0;
		char admin_password_show[40]={0},admin_password_verif[40]={0};//Contraseñas "*", Verificación de espacio en contraseña
		
		char admin_nombre_ficha[40]={0};//Nombre concatenado en ficha

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		/*INICIO:*/
		
		admin_nombre_enteros=strlen(admin_nombre);
		if(admin_nombre_enteros==0){//Si no hay registro de administrador
				printf("\n");
				
			printf("\t  Agregar Administrador\n");
			printf("\n");
			printf("\n");
					printf("_________________________________________\n");
			
			printf("NOMBRE(S): ");
				gets(admin_nombre);
			admin_nombre_enteros=strlen(admin_nombre);
		
				/*1.- Comprobación de error: Menor de 3 ó Espacio*/
				if((admin_nombre_enteros<3)||(admin_nombre[0]==32)){
							do{											
								printf("\n");
							
								printf("\t*****\n");
								printf("\tERROR\n");
								printf("\t*****");
							
								printf("\n\n");
							
								printf("\tNombre de Administrador no valido\n\n");
							
								system("pause");
								system("cls");
								
								admin_nombre_enteros=0;//Limpieza de enteros
								
							
								printf("NOMBRE(S): ");		
								gets(admin_nombre);
								admin_nombre_enteros=strlen(admin_nombre);
						
							}
							while((admin_nombre_enteros<3)||(admin_nombre[0]==32));
				}
				
			
			printf("APELLIDOS: ");
				gets(admin_apellido);
			admin_apellido_enteros=strlen(admin_apellido);
			
				/*1.- Comprobación de error: Menor a 1 ó Espacio*/
				if((admin_apellido_enteros<=1)||(admin_apellido[0]==32)){
							do{
								printf("\n");
							
								printf("\t*****\n");
								printf("\tERROR\n");
								printf("\t*****");
							
								printf("\n\n");
							
								printf("\tNombre de ususario no valido\n\n");
							
								system("pause");
								system("cls");
								
								admin_apellido_enteros=0;//Limpieza de enteros
								
																			
								printf("NOMBRE: %s\n",admin_nombre);
								printf("APELLIDOS: ");
								gets(admin_apellido);
								admin_apellido_enteros=strlen(admin_apellido);
							
							}
							while((admin_apellido_enteros<=1)||(admin_apellido[0]==32));
				}
			
					printf("_________________________________________\n");
			
			printf("PASSWORD \n");
			printf("(8 Digitos): ");
				gets(admin_password);
		admin_password_enteros=strlen(admin_password);
		
				/*1.- Comprobación de error: Menor a 8 ó Espacio*/
				if((admin_password_enteros<8)||(admin_password_espacio==32)){
							printf("\n");
							do{
								printf("\t*****\n");
								printf("\tERROR\n");
								printf("\t*****");
								
								printf("\n\n");
								
								printf("\tPassword no valido\n\n");
								
									system("pause");
									system("cls");
									
								printf("PASSWORD \n");
								printf("(8 Digitos): ");
									gets(admin_password);
									admin_password_enteros=strlen(admin_password);	
									
									for(admin_cont3=0;admin_cont3<admin_password_enteros;admin_cont3++){
										admin_password_espacio=admin_password[admin_cont3];
									}	
							}
							while((admin_password_enteros<8)||(admin_password_espacio==32));		
				}
				if(admin_password_enteros>=8){
					printf("Correcto!\n");
				}
				
					system("pause");
					system("cls");

					printf("_________________________________________\n");
				printf("VALIDACION \n");
				printf("(Volver a escribir su PASSWORD): ");
					gets(admin_password_verif);
					
			admin_password_enteros=strlen(admin_password);//Enteros a convertir
			strcpy(admin_password_show,admin_password);//Convertir cadena a *********
		
				if(strcmp(admin_password_verif,admin_password)!=0){//Comparación de igualdad entre el password y el verificación
					
					printf("_________________________________________\n");	
									
					admin_password_enteros=admin_password_enteros-3;//Enteros a convertir (-3)
											
					for(admin_cont2=0;admin_cont2<admin_password_enteros;admin_cont2++){
						admin_password_show[admin_cont2]='*';//Convertir cadena a *********
										
					}
					printf("%s\n",admin_password_show);//Muestra de contraseña con *********
					printf("_________________________________________\n");
					
					printf("No coinside su PASSWORD\n\n Volver a escribirla: ");
					gets(admin_password_verif);
					
									admin_cont++;
								if(admin_cont==3){//Contador de verificación: máximo (3) intentos para volver al menú
									printf("\nNumero de intentos(3)\nRegistro fallido");
									menu_admin();//Devolución al menú-admin de (0) valores
								}
								
				}
				
					printf("_________________________________________\n");	
						printf("Guardado correctamente!\n");
					printf("_________________________________________\n");
					
					printf("\n\n\n\n");
					
					/*Ficha del administrador*/
					
					strcpy(admin_nombre_ficha,admin_nombre);//Concatenar las cadenas
					strcat(admin_nombre_ficha," ");
					strcat(admin_nombre_ficha,admin_apellido);
					
					printf("*****************************************\n");	
						printf("Ficha del administrador\n");
					printf("*****************************************\n");
					
					printf("\n");
					
					printf("Nombre: ");
					puts(admin_nombre_ficha);
					
					printf("Password: ");
					puts(admin_password);
					
					printf("Nip id: ");
					for(nip_id_cont=0;nip_id_cont<4;nip_id_cont++){
					printf("%d",nip_id_admin[nip_id_cont]);	
						if(nip_id_cont<3){
						printf("-");
						}
					}
					
					printf("\n\n");
					printf("\n*****************************************\n");

					system("pause");
		}
		else{
			printf("_________________________________________\n");	
			printf(" El sistema ha detectado ADMINISTRADOR\n\n");
			printf("Admin %s",admin_nombre);
			printf("_________________________________________\n");
			
		
		}
		
		
}//fn menu_admin


void menu(){
	
	void inicio_sesion(void){
	//AGREGAR PASO DE VALORES DE LA OTRA FUNCIÓN Y TAMBIÉN EL ARREGLO DE USUSARIOS
		int inicio_sesion_id;
		char inicio_sesion_password_admin[40],inicio_sesion_password_usuario[40];
		
		char inicio_sesion_n_ususario;
			
			
			printf("Si todavía no dispone de una cuenta\ningrese ESPACIO \n");
			printf("_________________________________________\n");
			
			scanf("%c",&inicio_sesion_n_ususario);
			getchar();
			
			if(inicio_sesion_n_ususario==32){
				/*agregar ususario ARREGLO*/
			}
			else{
					printf("id: ");
					scanf("%d",inicio_sesion_id);
					/*Administrador Menú*/
					if(inicio_sesion_id==0){
						
						printf("Password: ");
						scanf("%s",inicio_sesion_password_admin);
						
						if(strcmp(inicio_sesion_password_admin,password_admin)==0){
						printf("BIENVENIDO %s\n",admin_nombre);
						
						printf("1.- Alta y baja de ususarios de servicios bancarios.\n");
						printf("2.- Transferecia de dinero a los distintos cajeros.\n");
						printf("3.- Mostrar el estatus de todos los cajeros.\n");
						printf("4.- Mostrar  un reporte de cada usuario en pantalla.\n");
						printf("5.- Ayuda al usuario administrador.\n\n");
						printf("6.- Salida del sistema.\n");
						
						}
						else{
							printf("\nPASSWORD INCORRECTA\n");
							inicio_sesion();
						}
						
					}
					/*Usuario Menú*/
					else{
						
						printf("Password: ");
						scanf("%d",inicio_sesion_password_usuario);//COMPARACIÓN CON ARREGLO, RECORRE LUGARES
						if(strcmp(,)==0){//COMPARACIÓN CON EL ARREGLO RECORRE LUGARES
							
						printf("1.- Retirar efectivo.\n");
						printf("2.- Retirar efectivo cheque.\n");
						printf("3.- Saldo cheques.\n");
						printf("4.- Saldo credito.\n");
						printf("5.- Pagar.\n\n");
						printf("6.- Salida del sistema.\n");
						
						}
						
					}
			}//else
				
					
					
					printf("\n\n\n\n");
					
				
						
						
					
}//fn menu





