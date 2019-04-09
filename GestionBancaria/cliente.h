#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

    # include "estructura.h"

    // Declaraciones de las funciones necesarias específicas para gestionar clientes
    // Los prototipos proporcionados pueden ser modificados en sus argumentos y en el tipo de dato devuelto

    void listarClientes ( setClientes variosClientes );
    void anhadirCliente(setClientes &variosClientes);
    void eliminarCliente(setClientes &variosClientes);
    void buscarNumCuenta(setClientes variosClientes);
    void buscarDNI(setClientes variosClientes);
    void listarDnisInvalidos(setClientes variosClientes);

#endif // UTIL_H_INCLUDED
