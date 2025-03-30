
long generarNumeroTicket(int size, int clientesCajero[][size])
{
    int maxTicket = 0, cajeroAsinado = -1, minCliente = size + 1;
    int cajeroLleno = 0;

    ///Verifica si los cajeros estan llenos!
    for(int f=0; f<3; f++)
    {
        for(int c=0; c<size; c++)
        {
            if(clientesCajero[f][c]!=0)
            {
                cajeroLleno++;
            }
        }
    }
    if(cajeroLleno >= size*3)
    {
        printf("\nLos cajeros estan llenos, vuelva luego! \n");
        return -1;
    }

    ///Buscar el ticket mayor para seguir generando
    for(int f=0; f<3; f++)
    {
        for(int c=0; c<size; c++)
        {
            if(clientesCajero[f][c] > maxTicket)
            {
                maxTicket = clientesCajero[f][c];
                //se establece el ticket mas alto
            }
        }
    }

    int nuevoTicket = maxTicket + 1;



///Busca espacios vacios y determina el cajero con mas disponibilidad
     for (int f = 0; f < 3; f++)
        {
            int clientesEnEspera = 0;
            for (int c = 0; c < size; c++)
            {
                if (clientesCajero[f][c] != 0)
                {
                    clientesEnEspera++; // Cuenta cuántos clientes hay en este cajero
                }
            }

        // Si este cajero tiene menos clientes que el mínimo encontrado hasta ahora, lo seleccionamos
        if (clientesEnEspera < minCliente)
            {
                minCliente = clientesEnEspera;
                cajeroAsinado = f; // Guardamos el número del cajero con menos clientes
            }
        }


     printf("\nSu No. de Ticket es: %d y sera atendido por el cajero %d \n", nuevoTicket, cajeroAsinado+1);

    ///Aqui si se genera el ticket en el cajero correspondiente
    for(int c=0; c<size; c++)
    {
        if(clientesCajero[cajeroAsinado][c] == 0)
        {
            clientesCajero[cajeroAsinado][c] = nuevoTicket; //Se le asigna el nuevo ticket
            return nuevoTicket;
        }
    }



    ///Avisa si todos los cajeros estan llenos!
    if(maxTicket <= (size*3))
    {
        return -1;
    }

    ///


    return 0;
}
