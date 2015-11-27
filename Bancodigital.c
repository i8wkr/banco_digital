// Nombre
// Fecha
// Github ok?
// Desktop ook?

// Importamos librerías
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Número de usuarios
#define NUMUSUARIOS 20
#define NUMSUCURSALES 3
#define NUMREGISTROS 30
// #define DEPURACION 1

// Declaramos la estructura con los datos del usuario
struct info_usuario {

    char nombre[40];
    char apellido_p[40];
    char apellido_m[40];
    char direccion[100];
    char rfc[15];
    int password;
    char mail[50];
    int num_cuenta;
    int num_debito;
    int num_credito;
    int saldo_cheques;
    int saldo_credito;
    int id;
    int admin;
    int estado;

} usuario[NUMUSUARIOS]; 

// Declaramos la estructura con los datos de las sucursales
struct info_sucursal {

    char nombre[30];
    int saldo;

} sucursal[3];

// Declaramos la estructura con los datos de la bitácora de registros
struct info_bitacora {

  int dia;
  int mes;
  int year;
  char registro[150];

} bitacora[NUMREGISTROS];

// Incluimos archivos externos que contienen las funciones
// NOTA: Se incluyen despúes de declarar nuestra estructura para evitar error
#include "admin/altabaja.h"        // Dar de alta o baja a un usuario específico

int main() {

  // Declaramos nuestras variables
  FILE* archivo;
  int i, login_id, login_pass, validate = 0, opc, opc_admin, kill = 0, current_user;
  char temp[5];
  srand(time(0));

  /* PRIMERA PARTE: CONFIGURAR ARCHIVO Y ESTRUCTURA DE USUARIOS */

  // Con respecto al archivo que guarda la información de los usuarios.
  // Si el archivo no existe, creamos uno y pedimos los datos el administrador. 
  // Si existe el archivo, guardamos su información dentro del arreglo de estructuras usuario[]
  archivo = fopen("archivos/usuarios.dat", "rb");

  if (archivo == NULL) {

    archivo = fopen("archivos/usuarios.dat", "wb");

    for (i = 0; i < NUMUSUARIOS; i++) {

      // El primer usuario se llena como si fuera administrador
      if (i == 0) {

        printf("Bienvenido SUPERUSER. Al parecer es la primera vez que corre el programa, por lo tanto usted es el administrador del sistema.\n");

        do {

          printf("Favor de ingresar los siguientes datos para comenzar a utilizar la plataforma:\n");

          printf("Nombre(s): ");
          gets(usuario[i].nombre);

          printf("Apellido Paterno: ");
          gets(usuario[i].apellido_p);

          printf("Apellido Materno: ");
          gets(usuario[i].apellido_m);

          printf("Dirección (calle y número): ");
          gets(usuario[i].direccion);

          printf("RFC: ");
          gets(usuario[i].rfc);

          do {

            printf("PIN (4 dígitos): ");
            scanf("%d", &usuario[i].password);
            getchar();

            if (usuario[i].password < 1000 || usuario[i].password > 9999) {

              printf("\n¡Cuidado! Su PIN debe de ser de 4 números, intente de nuevo\n");

            }

          } while (usuario[i].password < 1000 || usuario[i].password > 9999);

          printf("Mail: ");
          gets(usuario[i].mail);

          // Como es el primer usuario, no se repiten los numeros de cuenta, débito y crédito.
          usuario[i].num_cuenta = rand() % 900 + 100;
          
          usuario[i].num_debito = rand() % 900 + 100;
          
          usuario[i].num_credito = rand() % 900 + 100;

          usuario[i].saldo_cheques = 0;

          usuario[i].saldo_credito = 0;

          usuario[i].id = 0;

          // Por ser el primer usuario, es el administrador del sistema
          usuario[i].admin = 1;

          usuario[i].estado = 1;

          // ALGO MAMADOR PARA IMPRESIONAR AL PROFESOR
          /*
          for (i = 5; i > 0; i--) {

            printf("Configurando sus datos (%d segundos restantes).\n", i);
            sleep(1);

          } */
          
          printf("\nVerifique que sus datos son correctos:\n");
          printf("Nombre: %s %s %s\n", usuario[i].nombre, usuario[i].apellido_p, usuario[i].apellido_m);
          printf("Dirección: %s\n", usuario[i].direccion);
          printf("RFC: %s\n", usuario[i].rfc);
          printf("Mail: %s\n", usuario[i].mail);
          printf("PIN: %d\n", usuario[i].password);
          printf("Su numero de cuenta es: %d\n", usuario[i].num_cuenta);
          printf("SU número de cuenta de cheques es: %d\n", usuario[i].num_debito);
          printf("Su número de cuenta de crédito es: %d\n", usuario[i].num_credito);

          printf("\nIMPORTANTE: Anote y guarde sus credenciales en un lugar seguro.\n");
          printf("\nLos datos se capturaron correctamente? y/n?\n");
          gets(temp);

        } while(strcmp(temp, "y") != 0);

      } else {

        strcpy(usuario[i].nombre, "N/A");
        strcpy(usuario[i].apellido_p, "N/A");
        strcpy(usuario[i].apellido_m, "N/A");
        strcpy(usuario[i].direccion, "N/A");
        strcpy(usuario[i].rfc, "N/A");
        usuario[i].password = 0;
        strcpy(usuario[i].mail, "N/A");
        usuario[i].num_cuenta = 0;
        usuario[i].num_debito = 0;
        usuario[i].num_credito = 0;
        usuario[i].saldo_cheques = 0;
        usuario[i].saldo_credito = 0;
        usuario[i].id = -1;
        usuario[i].admin = 0;
        usuario[i].estado = -1;

      }
      
    }

    fclose(archivo);

  } else {

    // Copiamos la información del archivo al arreglo de usuario[]
    fread(usuario, sizeof(usuario), 1, archivo);
    fclose(archivo);

  }

  /* PRIMERA PARTE: CONFIGURAR ARCHIVO Y ESTRUCTURA DE SUCURSALES */

  // Con respecto al archivo que guarda la información de las sucursales
  // Si el archivo no existe, creamos uno con los datos de las sucursales
  // Si existe el archivo, guardamos su información dentro del arreglo de estructuras sucursal[]
  archivo = fopen("archivos/sucursales.dat", "rb");

  if (archivo == NULL) {

    archivo = fopen("archivos/sucursales.dat", "wb");

    for (i = 0; i < NUMSUCURSALES; i++) {

      if (i == 0) {
        
        strcpy(sucursal[i].nombre, "Tlalpan"); 
        sucursal[i].saldo = 0;

      } else if (i == 1) {

        strcpy(sucursal[i].nombre, "Santa Fe"); 
        sucursal[i].saldo = 0;

      } else if (i == 2) {

        strcpy(sucursal[i].nombre, "Coyoacán"); 
        sucursal[i].saldo = 0;

      } else {

        strcpy(sucursal[i].nombre, "N/A"); 
        sucursal[i].saldo = 0;

      }

    }

    fclose(archivo);

  } else {

    // Copiamos la información del archivo al arreglo de sucursal[]
    fread(sucursal, sizeof(sucursal), 1, archivo);
    fclose(archivo);

  }

  /* PRIMERA PARTE: CONFIGURAR ARCHIVO Y ESTRUCTURA DE BITÁCORA */

  // Con respecto al archivo que guarda los registros de la bitácora
  // Si el archivo no existe, creamos uno con registros vacíos
  // Si existe el archivo, guardamos su información dentro del arreglo de estructuras bitacora[]
  archivo = fopen("archivos/bitacora.dat", "rb");

  if (archivo == NULL) {

    archivo = fopen("archivos/bitacora.dat", "wb");

    for (i = 0; i < NUMREGISTROS; i++) {

      bitacora[i].dia = 0;
      bitacora[i].mes = 0;
      bitacora[i].year = 0;
      strcpy(bitacora[i].registro, "N/A");

    }

    fclose(archivo);

  } else {

    // Copiamos la información del archivo al arreglo de bitacora[]
    fread(bitacora, sizeof(bitacora), 1, archivo);
    fclose(archivo);

  }

  /* SEGUNDA PARTE: INICIO DE SESIÓN COMO USUARIO O ADMINISTRADOR */

  // Cuando un usuario salga, se despliega el menú para iniciar sesión de nuevo
  // Sólamente el administrador puede matar el programa, al momento de salir de su sesión
  do {

    validate = 0;

    // INICIO DE SESIÓN
    printf("%d\n", usuario[0].num_cuenta);
    printf("%s\n", usuario[0].nombre);
    printf("%d\n", usuario[0].password);

    do {
      printf("\nSANCENDER. Inicio de sesión\n");

      printf("Número de cuenta: ");
      scanf("%d", &login_id);
      getchar();

      printf("NIP: ");
      scanf("%d", &login_pass);
      getchar();

      if (login_pass < 1000 || login_pass > 9999) {

        printf("\nAl parecer tu NIP o número de cuenta está mal escrito. Intenta de nuevo.\n");

      }

    } while (login_pass < 1000 || login_pass > 9999);

    // Comprobamos las credenciales

    for (i = 0; i < NUMUSUARIOS; i++) {

      if (usuario[i].num_cuenta == login_id) {

        if (usuario[i].password == login_pass) {

          printf("\nBienvenid@ %s!\n\n", usuario[i].nombre);
          current_user = usuario[i].id;
          validate = 1;

        }

      }

    }

    // Si las credenciales fueron correctas (validate = 1), desplegamos el menú correspondiente.
    if (validate == 1) {

      #ifdef DEPURACION
          printf("LOGIN SUCCESS\n");
      #endif

      if (usuario[current_user].admin == 1) {

        // Imprimimos el menú de superuser

        do {

          printf("1. Alta o baja de usuario.\n");
          printf("2. Transferencia de dinero a cajero.\n");
          printf("3. Mostrar el estado de los cajeros.\n");
          printf("4. Mostrar reporte de usuario.\n");
          printf("5. Ayuda para el administrador.\n");
          printf("6. Salir.\n");

          // Guardamos la opciòn del usuario en 'opc'
          do {
            printf("\nOpciòn: ");
            scanf("%d", &opc);
            getchar();

            if (opc < 1 || opc > 7) {

              printf("\n*WARNING: opciòn no disponible. Intente de nuevo.\n\n");

            }

          } while (opc < 1 || opc > 7);

          // Dependiendo de la opciòn del usuario, nos vamos al funcion especìfica
          switch(opc) {

            case 1:
              altabaja(usuario, sucursal, bitacora, NUMUSUARIOS, NUMSUCURSALES, NUMREGISTROS);
              break;

            case 2:
              
              break;

            case 3:
              
              break;
       
            case 4:
              
              break;

            case 5:
              
              break;

            case 6:
              
              break;

            case 7:
              printf("\n");
              for(i=0;i<NUMUSUARIOS;i++){
                printf("(index %d) %s %s %s. %d.\n", i, usuario[i].nombre, usuario[i].apellido_p, usuario[i].apellido_m, usuario[i].estado);
              }
              printf("\n");
              break;

          } // SWITCH

        } while (opc != 6); // Mientras el usuario no ingrese '0', se muestra el menù de nuevo

        // ¿Desea salir de su sesión o salir del programa?
        do {

          printf("\n1. Salir de sesión.\n2. Cerrar el programa.\n");
          printf("Opción: ");
          scanf("%d", &opc_admin);
          getchar();

          if (opc_admin < 1 || opc_admin > 2) {

            printf("\n*WARNING: opción no disponible. Intente de nuevo.\n");

          }

        } while(opc_admin < 1 || opc_admin > 2);

        if (opc_admin == 2) {

          kill = 1;
          
        }

      } else if (usuario[current_user].admin == 0) {
        
        // Imprimimos el menú de usuario

        do {

          printf("1. Retiro de efectivo (cuenta de cheques).\n");
          printf("2. Retiro de efectivo (tarjeta de crédito).\n");
          printf("3. Mostrar saldo de la cuenta de cheques.\n");
          printf("4. Mostrar saldo de la tarjeta de crédito.\n");
          printf("5. Reaizar pago de tarjeta de crédito con la cuenta de cheques.\n");
          printf("6. Salir.\n");
          
          // Guardamos la opciòn del usuario en 'opc'
          do {
            printf("\nOpciòn: ");
            scanf("%d", &opc);
            getchar();

            if (opc < 1 || opc > 6) {

              printf("\n*WARNING: opciòn no disponible. Intente de nuevo.\n\n");

            }

          } while (opc < 1 || opc > 6);

          // Dependiendo de la opciòn del usuario, nos vamos al funcion especìfica
          switch(opc) {

            case 1:
            
              break;

            case 2:
              
              break;

            case 3:
              
              break;
       
            case 4:
              
              break;

            case 5:
              
              break;

            case 6:
              printf("SALIENDO...\n");
              break;

          } // SWITCH

        } while (opc != 6); // Mientras el usuario no ingrese '0', se muestra el menù de nuevo

      } else {

        printf("ERROR276\n");
        // usuario[i].admin = basura;

      }

    } else {

      printf("\nNúmero de cuenta o contraseña no válidos. Intente de nuevo\n\n");

    }

  } while(kill == 0);  

  // Una vez que desea terminar el programa, abrimos los archivos y guardamos la información que se generó
  archivo = fopen("archivos/usuarios.dat", "wb");
  fwrite(usuario, sizeof(usuario), 1, archivo);
  fclose(archivo);

  archivo = fopen("archivos/sucursales.dat", "wb");
  fwrite(sucursal, sizeof(sucursal), 1, archivo);
  fclose(archivo);

  archivo = fopen("archivos/bitacora.dat", "wb");
  fwrite(bitacora, sizeof(bitacora), 1, archivo);
  fclose(archivo);

  return 0;

} // MAIN

/*
NOTA: 
El menú ya se encuentra listo, falta agregarle detalles estéticos y mejor UI*/

