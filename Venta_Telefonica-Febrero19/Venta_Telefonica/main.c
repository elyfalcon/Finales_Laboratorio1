#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Ventas.h"
#include "Tools.h"
#include "Vista.h"

#define NOM_ARCH "data.csv"
#define NOM_ARCH2 "JUNIOR.csv"
#define NOM_ARCH3 "ESTANDAR.csv"
#define NOM_ARCH4 "EXPERTO.csv"



int main()
{

    int opcion,choice;
    char seguir='S';

    ArrayList *ListaVentas;
    ListaVentas=al_newArrayList();
    ArrayList *ListaAux;
    ListaAux=al_newArrayList();
    eVentas* vendedor;


     if(ListaVentas!=NULL)
    {
        while(seguir=='S')
        {
            vista_ShowMenu("\n1: Cargar Archivos\n2: Listar Vendedores\n3: Calcular Comisiones\n4: Generar Archivo de Comisiones\n5: Agregar vendedores\n6: Dar de baja un Vendedor\n7: El que mas vendio\n");
            scanf("%d",&opcion);
            tools_ValidaMenu(opcion,0,7);
            switch(opcion)
            {
            case 1:
                cargarDesdeArchivo(ListaVentas,NOM_ARCH);
              //  vista_MuestraElementos(ListaVentas,"LISTA DE VENTAS","POR VENDEDORES",vista_MuestraUnElemento,0,ListaVentas->len(ListaVentas),25);
                break;
            case 2:
                if(ListaVentas !=NULL)
                {
                     vista_MuestraElementos(ListaVentas,"LISTA DE VENTAS","POR VENDEDORES",vista_MuestraUnElemento,0,ListaVentas->len(ListaVentas),25);

                }
                else
                    printf("NADA PARA MOSTRAR");
                    break;
                case 3:
                if(al_map(ListaVentas,CalcularSalary)==1)
                 {
                       printf("Se pudieron calcular todas las comisiones\n");
                       system("pause\n");
                       vista_MuestraElementos(ListaVentas,"LISTA DE VENDEDORES","SE CALCULAN COMISI8ONES",vista_MuestraUnElemento,0,ListaVentas->len(ListaVentas),25);
                       system("pause\n");
                   }

                    else
                        printf("No se pudieron calcular todos\n");
                    break;
            case 4:
                system("cls");
                choice=ventas_SeleccionarNivel(ListaVentas);
                ListaAux=al_filterListaPorNivel(ListaVentas,funcionQuefiltra, choice);
                        if(ListaAux !=NULL)
                        {
                            switch (choice)
                            {
                            case 0:
                                vista_MuestraElementos(ListaAux,"VENDEDORES","COMISIONES DE NIVEL JUNIOR",vista_MuestraUnElemento,0,ListaAux->len(ListaAux),25);
                                GuardarArchivoT(ListaAux,NOM_ARCH2);
                                break;


                            case 1:
                                vista_MuestraElementos(ListaAux,"VENDEDORES","COMISIONES DE NIVEL ESTANDARD",vista_MuestraUnElemento,0,ListaAux->len(ListaAux),25);
                                GuardarArchivoT(ListaAux,NOM_ARCH3);
                                break;

                            case 2:
                                vista_MuestraElementos(ListaAux,"VENDEDORES","COMISIONES DE NIVEL EXPERTO",vista_MuestraUnElemento,0,ListaAux->len(ListaAux),25);
                                GuardarArchivoT(ListaAux,NOM_ARCH4);
                                break;
                            }
                        }

                    break;
                    case 5:
                        arch_Alta_Empleado(ListaVentas);
                        break;
                    case 6:
                        vista_MuestraElementos(ListaVentas,"LISTADO DE VENDEDORES","CON SUS COMISIONES",vista_MuestraUnElemento,0,ListaVentas->len(ListaVentas),25);
                        arch_borrar(ListaVentas);
                        break;
                    case 7:
                        vendedor=BuscaMaximo(ListaVentas,comparaVendedor,1);
                        system("cls");
                        printf("========================================================================\n");
                        printf("  ID\t  NOMBRE\tNIVEL\tCANTIDAD VENDIDA\tMONTO\tCOMISION\n");
                        printf("=========================================================================\n");
                        vista_MuestraUnElemento(vendedor);
                        printf("-------------------------------------------------------------------------\n");
                        system("pause");
                        break;
            case 0:
                seguir='N';

            }

        }

    }

    return 0;
}
