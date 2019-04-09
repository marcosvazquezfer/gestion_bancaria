//Programa main para gestion de Clientes de entidades bancarias

# include <iostream>
# include <cstdlib>

# include "string.h"

# include "estructura.h"
# include "cliente.h"
# include "util.h"

using namespace std;

int menu();

int main() {

    int opcion;

    setClientes variosClientes;

    variosClientes.numClientes = 0; // Inicializamos el numero de clientes

    // Valores iniciales de prueba

    strcpy(variosClientes.Clientes[0].nombre, "Mercedes Lorenzo");
    strcpy(variosClientes.Clientes[0].DNI, "41235674C");
    strcpy(variosClientes.Clientes[0].domicilio, "Delicias, 25");
    strcpy(variosClientes.Clientes[0].numCuenta, "BBVAES0508");
    strcpy(variosClientes.Clientes[0].tipoCuenta, "ahorro");
    variosClientes.Clientes[0].fecha.dia = 15;
    variosClientes.Clientes[0].fecha.mes = 4;
    variosClientes.Clientes[0].fecha.anho = 2013;


    strcpy(variosClientes.Clientes[1].nombre, "Cosme Pazos");
    strcpy(variosClientes.Clientes[1].DNI, "33271682C");
    strcpy(variosClientes.Clientes[1].domicilio, "Retiro,34");
    strcpy(variosClientes.Clientes[1].numCuenta, "BSCHES1234");
    strcpy(variosClientes.Clientes[1].tipoCuenta, "corriente");
    variosClientes.Clientes[1].fecha.dia = 30;
    variosClientes.Clientes[1].fecha.mes = 9;
    variosClientes.Clientes[1].fecha.anho = 2014;

    strcpy(variosClientes.Clientes[2].nombre, "Enrique Bueno");
    strcpy(variosClientes.Clientes[2].DNI, "98765432Z");
    strcpy(variosClientes.Clientes[2].domicilio, "Plaza del Comendador");
    strcpy(variosClientes.Clientes[2].numCuenta, "BKBKES4978");
    strcpy(variosClientes.Clientes[2].tipoCuenta, "ahorro");
    variosClientes.Clientes[2].fecha.dia = 29;
    variosClientes.Clientes[2].fecha.mes = 6;
    variosClientes.Clientes[2].fecha.anho = 2012;

    strcpy(variosClientes.Clientes[3].nombre, "Bernardo Requejo");
    strcpy(variosClientes.Clientes[3].DNI, "45986104J");
    strcpy(variosClientes.Clientes[3].domicilio, "Diagonal, 345");
    strcpy(variosClientes.Clientes[3].numCuenta, "PBNKDF3234");
    strcpy(variosClientes.Clientes[3].tipoCuenta, "ahorro");
    variosClientes.Clientes[3].fecha.dia = 1;
    variosClientes.Clientes[3].fecha.mes = 1;
    variosClientes.Clientes[3].fecha.anho = 2008;

    strcpy(variosClientes.Clientes[4].nombre, "Luisa Legazpi");
    strcpy(variosClientes.Clientes[4].DNI, "87253640K");
    strcpy(variosClientes.Clientes[4].domicilio, "Callejuela del Parque, 46");
    strcpy(variosClientes.Clientes[4].numCuenta, "ABNAAU2436");
    strcpy(variosClientes.Clientes[4].tipoCuenta, "corriente");
    variosClientes.Clientes[4].fecha.dia = 18;
    variosClientes.Clientes[4].fecha.mes = 3;
    variosClientes.Clientes[4].fecha.anho = 2015;

    variosClientes.numClientes = 5;

    cout << "\nBienvenido a GesBANCO--Sistema gestor de entidades bancarias.\n";
    do {
        opcion = menu();
        switch ( opcion ) {
            case 1: listarClientes ( variosClientes );
                    break;
            case 2: anhadirCliente(variosClientes);
                    break;
            case 3: eliminarCliente(variosClientes);
                    break;
            case 4: buscarNumCuenta(variosClientes);
                    break;
            case 5: buscarDNI(variosClientes);
                    break;
            case 6: cout << "\nSe debe implementar la funcionalidad";
                    break;
            case 7: cout << "\nSe debe implementar la funcionalidad";
                    break;
            case 8: listarDnisInvalidos(variosClientes);
                    break;
            case 9: cout << "\nGracias por utilizar los servicios de GesBANCO.\n";
                    break;
            default:cout << "Opcion no valida\n" << endl;
        }
    } while ( opcion != 9 );
    return 0;
}

int menu()
{
    int opcion;
    cout << "\n######################################################\n";
    cout << "\nQue operacion desea realizar?";
    do {
        cout << "\n1. Listar clientes";
        cout << "\n2. Insertar cliente";
        cout << "\n3. Eliminar cliente";
        cout << "\n4. Buscar cliente por NumCuenta";
        cout << "\n5. Buscar cliente por DNI";
        cout << "\n6. Modificar datos de un Cliente";
        cout << "\n7. Visualizar clientes por cada tipo de cuenta";
        cout << "\n8. Buscar DNIs invalidos";
        cout << "\n9. Salir\n";
        cout << "\n######################################################\n";
        opcion = leerEntero ( "Opcion: ");

    } while ( opcion < 0 || opcion > 10 );

    return opcion;
}
