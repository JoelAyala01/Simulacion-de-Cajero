#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_CAJEROS 3

int main()
{
    int size, opcion=0;
    printf("====================BIENVENIDOS A AYALA BANK====================\n");
    printf("\n Cuantos clientes soporta cada cajero: ");
    scanf("%d", &size);
    system("cls");

    //Creacion de matriz del cajero
    int clientesCajeros[MAX_CAJEROS][size];

    //Asignacion de 0 a todas las posiciones del cajero
    memset(clientesCajeros, 0, sizeof(clientesCajeros));
    int maxTicket = 0;
    int codigocajero = 0;

    do{
    system("cls");
    Menu();
    scanf("%d", &opcion);
    system("cls");

    switch(opcion)
    {
    case 1:
        //Generar Ticket
        generarNumeroTicket(size, clientesCajeros);
        printf("\nPresione una tecla para continuar...\n");
        getche();

        break;

    case 2:
        //Atender cliente en cajero deseado!
        printf("\nIntroduzca No. de cajero a procesar: ");
        scanf("%d", &codigocajero);

        if(codigocajero > 3 || codigocajero < 1)
        {
            printf("\nSolo hay 3 cajeros disponibles!\n");
        }
        else
        {
            int *nTicket = &clientesCajeros[codigocajero-1][0];
            printf("\nEl ticket No. %d ha sido atendido exitosamente!\n", *nTicket);
            atenderClienteCajero(size, clientesCajeros, codigocajero);
        }

        printf("\nPresione una tecla para continuar...\n");
        getche();
        break;

    case 3:
        //Consultar cantidad de clientes por cajeros
        printf("%-8s" "%16s", "Cajero", "Tickets En Cola\n");
        printf("%-24s", "------------------------\n");

        printf("%-2d" "%16d\n", 1, clientesAtiendeCajero(size, clientesCajeros, 0));
        printf("%-2d" "%16d\n", 2, clientesAtiendeCajero(size, clientesCajeros, 1));
        printf("%-2d" "%16d\n", 3, clientesAtiendeCajero(size, clientesCajeros, 2));

        int TotalTickets = (clientesAtiendeCajero(size, clientesCajeros, 0)+clientesAtiendeCajero(size, clientesCajeros, 1)+clientesAtiendeCajero(size, clientesCajeros, 2));

        printf("\n------------------------\n");
        printf("%-6s" "%16d", "Total", TotalTickets);

        printf("\nPresione una tecla para continuar...\n");
        getche();
        break;

    case 4:
        //Listar Clientes en Cola
        listarClientesEnCola(size, clientesCajeros);

        printf("\nPresione una tecla para continuar...\n");
        getche();

    break;

    case 5:
        printf("\n\nCerrando!...\n\n\n");
        sleep(1);
        opcion = 5;
        break;

    default:
        system("cls");
        printf("OPcion invalida! \n");
        printf("\nPresione una tecla para continuar...\n");
        getche();
    }

    }while(opcion != 5);
    return 0;
}
