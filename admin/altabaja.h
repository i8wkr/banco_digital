/*

*/

void altabaja(struct info_usuario usuario[NUMUSUARIOS], struct info_sucursal sucursal[NUMSUCURSALES], struct info_bitacora bitacora[NUMREGISTROS], int num_usuarios, int num_sucursales, int num_registros) {

	int i, opc, opcion, user_id, band = 0, last_index, existe = 0, opc_;
	char option[5], option2[5], temp[5];

	srand(time(0));

	do {

		printf("\n¿Qué desea hacer?\n");
		printf("1. Dar de alta a un usuario.\n");
		printf("2. Dar de baja a un usuario.\n");
		printf("3. Cancelar.\n");
		printf("Opción: ");
		scanf("%d", &opc);
		getchar();

		if (opc < 1 || opc > 3) {

			printf("\nAl parecer no ingresaste una opción correcta. Intenta de nuevo.\n");
			sleep(3);

		}

	} while(opc < 1 || opc > 3);

	switch (opc) {

		// Damos de alta al usuario (dos opciones: 1. usuario nuevo 2. ya existente pero dado de baja)
		case 1:
		
				do {

					printf("\nEl usuario..\n");
					printf("1. Es un nuevo usuario.\n");
					printf("2. Se dió de baja anteriormente.\n");
					printf("3. Cancelar.\n");
					printf("Opción: ");
					scanf("%d", &opcion);
					getchar();

					if (opcion < 1 || opcion > 3) {

						printf("\nAl parecer no ingresaste una opción correcta. Intenta de nuevo.\n");

					}

				} while(opcion < 1 || opcion > 3);

				switch (opcion) {

					case 1:

						// Calculamos el último espacio vacío y guardamos su índice en last_index
						for (i = 0; i < num_usuarios; i++) {

						    if (usuario[i].estado != 1 && usuario[i].estado != 0) {
						    
						    	last_index = i;
						    	break;

						    }

						}

						do {

							printf("\nNUEVO USUARIO: \n");
							printf("Nombre(s): ");
					        gets(usuario[last_index].nombre);

					        printf("Apellido Paterno: ");
					        gets(usuario[last_index].apellido_p);

					        printf("Apellido Materno: ");
					        gets(usuario[last_index].apellido_m);

			          		printf("Dirección (calle y número): ");
			          		gets(usuario[last_index].direccion);

					        printf("RFC: ");
					        gets(usuario[last_index].rfc);

					        do {

					            printf("PIN (4 dígitos): ");
					            scanf("%d", &usuario[last_index].password);
					            getchar();

					            if (usuario[last_index].password < 1000 || usuario[last_index].password > 9999) {

					            	printf("\n¡Cuidado! Su PIN debe de ser de 4 números, intente de nuevo\n");

					            }

					        } while (usuario[last_index].password < 1000 || usuario[last_index].password > 9999);

					        printf("Mail: ");
					        gets(usuario[last_index].mail);

					        // Generamos su numero de cuenta y verificamos si es único
					        do {

					        	band = 0;

						        usuario[last_index].num_cuenta = rand() % 900 + 100;

						        for (i = 0; i < last_index; i++) {

						        	if (usuario[i].num_cuenta == usuario[last_index].num_cuenta) {

						        		band = 1;

						        	}

						        }

						    } while (band == 1);

						    // Generamos su numero de debito y verificamos si es único
					        do {

					        	band = 0;

						        usuario[last_index].num_debito = rand() % 900 + 100;

						        for (i = 0; i < last_index; i++) {

						        	if (usuario[i].num_debito == usuario[last_index].num_debito) {

						        		band = 1;

						        	}

						        }

						    } while (band == 1);

						    // Generamos su numero de credito y verificamos si es único
					        do {

					        	band = 0;

						        usuario[last_index].num_credito = rand() % 900 + 100;

						        for (i = 0; i < last_index; i++) {

						        	if (usuario[i].num_credito == usuario[last_index].num_credito) {

						        		band = 1;

						        	}

						        }

						    } while (band == 1);

					        usuario[last_index].saldo_cheques = 0;

					        usuario[last_index].saldo_credito = 0;

					        usuario[last_index].id = last_index;

					        usuario[last_index].admin = 0;

					        usuario[last_index].estado = 1;

					        printf("\nVerifique que sus datos son correctos:\n");
				          	printf("Nombre: %s %s %s\n", usuario[last_index].nombre, usuario[last_index].apellido_p, usuario[last_index].apellido_m);
				          	printf("Dirección: %s\n", usuario[last_index].direccion);
				          	printf("RFC: %s\n", usuario[last_index].rfc);
				          	printf("Mail: %s\n", usuario[last_index].mail);
				          	printf("PIN: %d\n", usuario[last_index].password);
				          	printf("Su numero de cuenta es: %d\n", usuario[last_index].num_cuenta);
				          	printf("SU número de cuenta de cheques es: %d\n", usuario[last_index].num_debito);
				          	printf("Su número de cuenta de crédito es: %d\n", usuario[last_index].num_credito);

				          	printf("\nIMPORTANTE: Anote y guarde sus credenciales en un lugar seguro.\n");
				          	printf("\nLos datos se capturaron correctamente? y/n?\n");
				          	gets(temp);

						} while(strcmp(temp, "y") != 0);

						break;

					// Se dio de baja anteriormente
					case 2:

						do {

							opc_ = 0;

							// Pedimos el numero de cuenta del usuario que vamos a reactivar
							do {

								printf("\nNúmero de cuenta del usuario que se dio de baja: ");
								scanf("%d", &user_id);
								getchar();

								if (user_id < 100 || user_id > 999) {

									printf("\nAl parecer no ingresaste un número de cuenta correcto. Intenta de nuevo.\n");

								}

							} while(user_id < 100 || user_id > 999);

							// Verificamos que existe un usuario con ese numero de cuenta dado de baja
							for (i = 0; i < num_usuarios; i++) {

								// Si existe un usuario dado de baja:
								if (usuario[i].num_cuenta == user_id && usuario[i].estado == 0) {

									// !Encontré un usuario que ya se habia registrado con nosotros pero se dio de baja!
									printf("\nNombre: %s %s %s\n", usuario[i].nombre, usuario[i].apellido_p, usuario[i].apellido_m);
									printf("Número de cuenta: %d\n", usuario[i].num_cuenta);
									printf("Saldo cheques: %d\n", usuario[i].saldo_cheques);
									printf("Saldo crédito: %d\n", usuario[i].saldo_credito);

									// Lo doy de alta?
									printf("¿Seguro que desea volver de dar de alta al usuario? y/n\n");
									printf("Opción: ");
									gets(option);

									if (strcmp(option, "y") == 0) {
										
										// Lo damos de alta
										usuario[i].estado = 1;

										// Avisamos al usuario que ya se dio de alta
										printf("\nEl usuario %s %s %s, con número de cuenta: %d, se ha dado de alta\n", usuario[i].nombre, usuario[i].apellido_p, usuario[i].apellido_m, usuario[i].num_cuenta);
										opc_ = 0;

										sleep(3);

									} else {

										printf("\nDesea:\n");
										printf("1. Ingresar un nuevo número de cuenta.\n");
										printf("2. Salir\n");
										printf("Opción: ");
										scanf("%d", &opc_);
										getchar();

									}

									// Encontré un usuario
									existe = 1;
									
								// Si ingresa un usuario que ya esta dado de alta:
								} else if (usuario[i].num_cuenta == user_id && usuario[i].estado == 1) {

									// Encontré un usuario, pero ya esta dado de alta
									printf("\nAl parecer el usuario con número de cuenta %d ya esta dado de alta.\n", usuario[i].num_cuenta);
									printf("\nDesea:\n");
									printf("1. Ingresar un nuevo número de cuenta.\n");
									printf("2. Salir\n");
									printf("Opción: ");
									scanf("%d", &opc_);
									getchar();

									// Encontré un usuario
									existe = 1;

								}

							} // FOR LOOP

							// Si terminé el loop y no encuentro ningun usuario con número de cuenta que pedí
							if (existe == 0) {

								printf("\nNo se encontró el usuario con número de cuenta %d\n", user_id);
								printf("\nDesea:\n");
								printf("1. Ingresar un nuevo número de cuenta.\n");
								printf("2. Salir\n");
								printf("Opción: ");
								scanf("%d", &opc_);
								getchar();

							}

						} while(opc_ == 1);

						break;

					case 3:
						printf("\nCANCELANDO ALTA/BAJA USUARIO..\n");
						sleep(3);
						break;

				} // SWITCH ANIDADO

			break;

		// Damos de baja a usuario
		case 2:

			do {

				existe = 0;

				printf("\nDAR DE BAJA UN USUARIO\n");

				printf("Ingrese el número de cuenta del usuario: ");
				scanf("%d", &user_id);
				getchar();

				for (i = 0; i < num_usuarios; i++) {

					// Si encontramos un usuario que se encuentra dado de alta
					if (usuario[i].num_cuenta == user_id && usuario[i].estado == 1) {

						// Encontre a:
						printf("\nNombre: %s %s %s\n", usuario[i].nombre, usuario[i].apellido_p, usuario[i].apellido_m);
						printf("Número de cuenta: %d\n", usuario[i].num_cuenta);
						printf("Saldo cheques: %d\n", usuario[i].saldo_cheques);
						printf("Saldo crédito: %d\n", usuario[i].saldo_credito);

						// ¿Lo doy de baja?
						printf("¿Seguro que desea darlo de baja? (y/n)\n");
						printf("Opción: ");
						gets(option);

						if (strcmp(option, "y") == 0) {
										
							// Lo damos de baja
							usuario[i].estado = 0;

							// Avisamos al usuario que ya se dio de alta y salimos
							printf("\nEl usuario %s %s %s, con número de cuenta: %d, se ha dado de baja\n", usuario[i].nombre, usuario[i].apellido_p, usuario[i].apellido_m, usuario[i].num_cuenta);
							opc_ = 0;

							sleep(3);

						} else {

							printf("\nDesea:\n");
							printf("1. Ingresar un nuevo número de cuenta.\n");
							printf("2. Salir\n");
							printf("Opción: ");
							scanf("%d", &opc_);
							getchar();

						}

						// Encontré un usuario
						existe = 1;

					// Si encontramos un usuario que existe pero ya se dio de baja
					} else if (usuario[i].num_cuenta == user_id && usuario[i].estado == 0) {

						printf("\nAl parecer el usuario con número de cuenta %d ya esta dado de baja.\n", usuario[i].num_cuenta);
						printf("\nDesea:\n");
						printf("1. Ingresar un nuevo número de cuenta.\n");
						printf("2. Salir\n");
						printf("Opción: ");
						scanf("%d", &opc_);
						getchar();

						// Encontré un usuario
						existe = 1;

					}

				} // FOR LOOP

				// Si terminé el loop y no encuentro ningun usuario con número de cuenta que pedí
				if (existe == 0) {

					printf("\nNo se encontró el usuario con número de cuenta %d\n", user_id);
					printf("\nDesea:\n");
					printf("1. Ingresar un nuevo número de cuenta.\n");
					printf("2. Salir\n");
					printf("Opción: ");
					scanf("%d", &opc_);
					getchar();

				}

			} while(opc_ == 1);

			break;

		case 3:
			printf("\nCANCELANDO ALTA/BAJA USUARIO..\n");
			sleep(3);
			break;

	} // SWITCH 

} // FUNC ALTA O BAJA

// TO LOWER 'Y'
