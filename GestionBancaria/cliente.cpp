# include <iostream>
# include <cstdlib>

# include "string.h"

# include "cliente.h"
# include "util.h"

using namespace std;

// Definiciones de las funciones necesarias específicas para gestionar clientes

void mostrarCliente ( Cliente elCliente );
char letraDNI(int DNI);
int verificaDNI(char *DNI);
bool comprobarLetra(char numCuenta[]);
bool comprobarNumero(char numCuenta[]);
bool comprobarNumCuenta(char numCuenta[]);

/**********************************************************************************/

/**** FUNCIONES NECESARIAS PARA LLEVAR A CABO LAS FUNCIONALIDADES SOLICITADAS *****/

/**********************************************************************************/

void listarClientes( setClientes variosClientes )  //Listar todas los Clientes
{
    int i;
    if ( variosClientes.numClientes == 0 )
        cout << "\nNo existen clientes que listar.\n";
    else {
        cout << "\nListando clientes...\n";
        for (i = 0; i < variosClientes.numClientes; i++ ) {
            cout << "\nCliente : " << i;
            mostrarCliente( variosClientes.Clientes[ i ] );
        }
    }
}

/*** Funcion para anhadir un cliente ***/
void anhadirCliente(setClientes &variosClientes){

    char nombre[MAXNOMBRE];
    char DNI[MAXDNI];
    char domicilio[MAXDOMICILIO];
    char numCuenta[MAXNUMCUENTA];
    char tipoCuenta[MAXTIPOCUENTA];
    int dia, mes, anho, bisiesto;
    bool comprobar = false;
    char tipoAhorro [8] = "ahorro";
    char tipoCorriente [16] = "corriente";

    if(variosClientes.numClientes == (MAXCLIENTES - 1)){

        cout << "\nNumero maximo de clientes alcanzado, no se pueden almacenar mas clientes\n.";
    }
    else{
        leerCadena("\nIntroduzca el nombre completo del cliente: ", nombre);
        leerCadena("\nIntroduzca el DNI del cliente: ", DNI);
        leerCadena("\nIntroduzca el domicilio del cliente: ", domicilio);

        do{
            leerCadena("\nIntroduzca el numero de cuenta del cliente\nPrimeros 4 digitos hacen referencia al banco(LETRAS MAYUSCULAS),\n2 siguientes al pais y los ultimos 4 al numero de cuenta: ", numCuenta);

            comprobar = comprobarNumCuenta(numCuenta);

        }while(comprobar == false);

        do{
            leerCadena("\nIntroduzca el tipo de cuenta del cliente: ", tipoCuenta);

            if(strcmp(tipoCuenta, tipoAhorro) && strcmp(tipoCuenta, tipoCorriente)){

                cout << "\nTIPO DE CUENTA INCORRECTO\n";
            }

        }while(strcmp(tipoCuenta, tipoAhorro) && strcmp(tipoCuenta, tipoCorriente));

        do{
            anho = leerEntero("\nIntroduzca el anho de apertura de la cuenta: ");

            if(anho > 2018){

                cout << "\nANHO DE APERTURA INCORRECTO\n";
            }

        }while(anho > 2018);

        bisiesto = anho % 4;

        do{
           mes = leerEntero("\nIntroduzca el mes de apertura de la cuenta: ");

           if((mes < 1) || (mes > 12)){

                cout << "\nMES DE APERTURA INCORRECTO\n";
           }

        }while((mes < 1) || (mes > 12));

        if(mes == 2){

            if(bisiesto == 0){

                do{
                    dia = leerEntero("\nIntroduzca el dia de apertura de la cuenta: ");

                    if((dia < 1) || (dia > 29)){

                        cout << "\nDIA DE APERTURA INCORRECTO\n";
                    }

                }while((dia < 1) || (dia > 29));
            }
            else{
                do{
                    dia = leerEntero("\nIntroduzca el dia de apertura de la cuenta: ");

                    if((dia < 1) || (dia > 28)){

                        cout << "\nDIA DE APERTURA INCORRECTO\n";
                    }

                }while((dia < 1) || (dia > 28));
            }
        }
        else{
            if((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)){

                do{
                    dia = leerEntero("\nIntroduzca el dia de apertura de la cuenta: ");

                    if((dia < 1) || (dia > 31)){

                        cout << "\nDIA DE APERTURA INCORRECTO\n";
                    }

                }while((dia < 1) || (dia > 31));
            }
            else{
                do{
                    dia = leerEntero("\nIntroduzca el dia de apertura de la cuenta: ");

                    if((dia < 1) || (dia > 30)){

                        cout << "\nDIA DE APERTURA INCORRECTO\n";
                    }

                }while((dia < 1) || (dia > 30));
            }
        }

        strcpy(variosClientes.Clientes[variosClientes.numClientes].nombre, nombre);
        strcpy(variosClientes.Clientes[variosClientes.numClientes].DNI, DNI);
        strcpy(variosClientes.Clientes[variosClientes.numClientes].domicilio, domicilio);
        strcpy(variosClientes.Clientes[variosClientes.numClientes].numCuenta, numCuenta);
        strcpy(variosClientes.Clientes[variosClientes.numClientes].tipoCuenta, tipoCuenta);
        variosClientes.Clientes[variosClientes.numClientes].fecha.dia = dia;
        variosClientes.Clientes[variosClientes.numClientes].fecha.mes = mes;
        variosClientes.Clientes[variosClientes.numClientes].fecha.anho = anho;

        cout << "\n------------------------------------------------------\n";
        cout << "\nCLIENTE ANHADIDO.\n";
        mostrarCliente(variosClientes.Clientes[variosClientes.numClientes]);

        variosClientes.numClientes++;
    }
}

/*** Función para eliminar un cliente dado su NUMERO DE CUENTA ***/
void eliminarCliente(setClientes &variosClientes){

    //char DNI[MAXDNI];
    char numCuenta[MAXNUMCUENTA];
    int iguales = 0;
    bool n = false;

    leerCadena("\nIntroduzca el NUMERO DE CUENTA del cliente que desea eliminar: ", numCuenta);

    //Comprueba si el array de clientes que recibe esta vacio
    if ( variosClientes.numClientes == 0 ){

        cout << "\nNo existen clientes que eliminar.\n";
    }
    else {//Si no esta vacio:
        //Recorre el array
        for (int i = 0; i < variosClientes.numClientes; i++ ) {

            /*Comprueba si el Numero de Cuenta del cliente es igual al Numero de Cuenta del cliente que se quiere eliminar,
              si es asi iguales = 0
            */
            iguales = strcmp(variosClientes.Clientes[i].numCuenta, numCuenta);

            //Si iguales es 0 elimina el cliente
            if(iguales == 0){

                n = true;

                cout << "\nEliminando el Cliente con NUMERO DE CUENTA: " << variosClientes.Clientes[i].numCuenta
                     << " y nombre: " << variosClientes.Clientes[i].nombre << ".\n";

                for(int j = i; j < variosClientes.numClientes; j++){

                    variosClientes.Clientes[j] = variosClientes.Clientes[j+1];
                }

                variosClientes.numClientes = variosClientes.numClientes - 1;

                cout << "\nCliente eliminado.\n";

                break;
            }
        }

        //Si el valor de n no ha cambiado quiere decir que el Numero de Cuenta no es el de ningun cliente
        if(n == false){

            cout << "\nEl Numero de Cuenta no coincide con el de ningun cliente.\n";
        }
    }
}

/*** Funcion para buscar un cliente por su Nº de Cuenta ***/
void buscarNumCuenta(setClientes variosClientes)
{
    char numIntrod[MAXNUMCUENTA];
    bool existeNum=false;

    do{
        leerCadena("\nIntroduce el numero de cuenta del cliente que quieres buscar:  ", numIntrod);
    }while(strlen(numIntrod) != (MAXNUMCUENTA - 1));

    for(int i = 0; i < variosClientes.numClientes; i++)
        if((strcmp(numIntrod, variosClientes.Clientes[i].numCuenta))==0){

            mostrarCliente (variosClientes.Clientes[ i ]);
            existeNum = true;
        }

    if (existeNum == false)
        cout << "\nEl numero de cuenta introducido NO esta registrado.\n";
}

/*** Funcion para buscar un cliente por su DNI ***/
void buscarDNI(setClientes variosClientes)
{
    char DNI[MAXDNI];
    bool existeDNI=false;

    do{
        leerCadena("\nIntroduce el DNI del cliente que quieres buscar:  ", DNI);
    }while(strlen(DNI) != (MAXDNI-1));

    for(int i = 0; i < variosClientes.numClientes; i++)
        if((strcmp(DNI, variosClientes.Clientes[i].DNI))==0){

            mostrarCliente (variosClientes.Clientes[ i ]);
            existeDNI = true;
        }

    if (existeDNI == false)
        cout << "\nEl DNI introducido NO esta registrado.\n";
}

/*** Funcion que comprueba si los DNIs existentes en el sistema son validos o no ***/
void listarDnisInvalidos(setClientes variosClientes){

    char DNI[MAXDNI];

    for(int i = 0; i < variosClientes.numClientes; i++){

        strcpy(DNI, variosClientes.Clientes[i].DNI);

        if(!verificaDNI(DNI)){
            /*** MOSTRAR TODOS LOS DATOS DEL CLIENTE ***/
            cout << "\nEl DNI " << DNI << " no es correcto.\n";
            cout << "\nDATOS DEL CLIENTE\n";
            mostrarCliente(variosClientes.Clientes[i]);
        }
    }
}

/**********************************************************************************************/

/**** FUNCIONES ADICIONALES NECESARIAS PARA LLEVAR A CABO LAS FUNCIONALIDADES SOLICITADAS *****/

/**********************************************************************************************/

void mostrarCliente( Cliente elCliente )
{
    char meses [ ][ 12 ] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};      // Para visualizar los meses
    cout << "\n\tNombre: " << elCliente.nombre;
    cout << "\n\tDNI: " << elCliente.DNI;
    cout << "\n\tdomicilio: " << elCliente.domicilio;
    cout << "\n\tNumCuenta: " << elCliente.numCuenta;
    cout << "\n\ttipoCuenta: " << elCliente.tipoCuenta;
    cout << "\n\tFecha: " << elCliente.fecha.dia << " de " << meses [ elCliente.fecha.mes -1 ] << " de " << elCliente.fecha.anho << endl;
    cout << "\n------------------------------------------------------\n";
}

/*** Función que genera la letra correcta para un DNI en función del número ***/
char letraDNI(int DNI){

    char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";

    return letra[DNI % 23];
}

/*** Función que verifica si el DNI introducido por el usuario es correcto ***/
int verificaDNI(char *DNI){

    //Comprueba la longitud
    if(strlen(DNI) != (MAXDNI - 1)){

        return 0;
    }
    else{
        //Genera la letra correcta para los numeros del DNI introducidos por el usuario y comprueba si coincide con la letra introducida por este
        return (letraDNI(atoi(DNI)) == DNI[8]);
    }
}

/*** Función que comprueba si un número de cuenta es válido ***/
bool comprobarNumCuenta(char numCuenta[]){

    bool letra = false;
    bool numero = false;

    if(strlen(numCuenta) == (MAXNUMCUENTA - 1)){

        letra = comprobarLetra(numCuenta);
        numero = comprobarNumero(numCuenta);

        if((letra == true) && (numero == true)){

            return true;
        }
        else{
            cout << "\nNumero de Cuenta INCORRECTO.\n\n";
            return false;
        }
    }
    else{
        cout << "\nNumero de Cuenta INCORRECTO, supera la longitud maxima (10).\n\n";
        return false;
    }
}

/*** Función que compruba si los 4 primeros dígitos de un número de cuenta son letras ***/
bool comprobarLetra(char numCuenta[]){

    int cont = 0;

    for(int i = 0; i < 4; i++){

         if((numCuenta[i] == 'A') || (numCuenta[i] == 'B') || (numCuenta[i] == 'C') || (numCuenta[i] == 'D') || (numCuenta[i] == 'E') || (numCuenta[i] == 'F') || (numCuenta[i] == 'G') || (numCuenta[i] == 'H') || (numCuenta[i] == 'I') || (numCuenta[i] == 'J') || (numCuenta[i] == 'K') || (numCuenta[i] == 'L') || (numCuenta[i] == 'M') || (numCuenta[i] == 'N') || (numCuenta[i] == 'Ñ') || (numCuenta[i] == 'O') || (numCuenta[i] == 'P') || (numCuenta[i] == 'Q') || (numCuenta[i] == 'R') || (numCuenta[i] == 'S') || (numCuenta[i] == 'T') || (numCuenta[i] == 'U') || (numCuenta[i] == 'V') || (numCuenta[i] == 'W') || (numCuenta[i] == 'X') || (numCuenta[i] == 'Y') || (numCuenta[i] == 'Z')){

            cont++;
         }
    }

    if(cont == 4){

        return true;
    }
    else{
        return false;
    }
}

/*** Función que compruba si los 6 últimos dígitos de un número de cuenta son números ***/
bool comprobarNumero(char numCuenta[]){

    int cont = 0;

    for(int i = 4; i < MAXNUMCUENTA; i++){

        if((numCuenta[i] == '0') || (numCuenta[i] == '1') || (numCuenta[i] == '2') || (numCuenta[i] == '3') || (numCuenta[i] == '4') || (numCuenta[i] == '5') || (numCuenta[i] == '6') || (numCuenta[i] == '7') || (numCuenta[i] == '8') || (numCuenta[i] == '9')){

            cont++;
        }
    }

    if(cont == 6){

        return true;
    }
    else{
        return false;
    }
}
