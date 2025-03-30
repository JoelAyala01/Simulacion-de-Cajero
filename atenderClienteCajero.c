long atenderClienteCajero(int size, int clienteCajero[3][size], int codigoCajero)
{
    int ticketAtendido = 0;
    if(clienteCajero[codigoCajero-1][0] != 0)
    {
        //Ticket al cual se atendio y se mostrara por pantalla
        ticketAtendido = clienteCajero[codigoCajero-1][0];
        clienteCajero[codigoCajero-1][0] = 0;

        for(int c=0; c < size-1; c++)
        {
            clienteCajero[codigoCajero-1][c] = clienteCajero[codigoCajero-1][c+1];
        }
        clienteCajero[codigoCajero-1][size-1]=0;
    }
    return ticketAtendido;
}
