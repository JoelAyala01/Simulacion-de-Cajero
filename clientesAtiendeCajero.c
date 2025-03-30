
int clientesAtiendeCajero(int size, int clientesCajero[3][size], int cajero)
{
    int TicketsTotal = 0;
    for(int c=0; c<size; c++)
    {
        if(clientesCajero[cajero][c]!=0)
        {
            TicketsTotal++;
        }
    }

    return TicketsTotal;
}
