
void listarClientesEnCola(int size, int clientesCajero[3][size])
{
        printf("\n\n");
        printf("%-10s" "%-17s", "Cajero", "Tickets en Cola\n");
        printf("-----------------------------------------------------------------\n");

        for(int f=0; f<3; f++)
        {
            printf("%-10d", f+1);
            for(int c=0; c<size; c++)
            {
                if(clientesCajero[f][c]==0)
                {
                    printf("");
                }
                else
                {
                    printf("%-6d", clientesCajero[f][c]);
                }
            }
            printf("\n");
        }
        return;
}
