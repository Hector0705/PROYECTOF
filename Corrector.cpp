﻿/*****************************************************************************************************************
	UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
	FACULTAD DE ESTUDIOS SUPERIORES -ARAGON-

	Computadoras y programacion. 
	(c) Hector Rogelio Gonzalez Amezquita 321157612
	
	Quiso decir: Programa principal de la aplicacion de la distancia de Levenstein.
	
******************************************************************************************************************/

#include "stdafx.h"
#include <string.h>
#include "corrector.h"
#include <stdio.h>
#define MAXELEM 40000

//Funciones publicas del proyecto
/*****************************************************************************************************************
    DICCIONARIO: Esta funcion crea el diccionario completo
    char *	szNombre				:	Nombre del archivo de donde se sacaran las palabras del diccionario
    char	szPalabras[][TAMTOKEN]	:	Arreglo con las palabras completas del diccionario
    int		iEstadisticas[]			:	Arreglo con el numero de veces que aparecen las palabras en el diccionario
    int &	iNumElementos			:	Numero de elementos en el diccionario
******************************************************************************************************************/
void	Diccionario(char* szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int& iNumElementos)
{
    FILE* fp;
    char linea[MAXELEM];
    char palabra[MAXELEM];
    iNumElementos = 0;
    int a = 0;
    int contadorU = 0;

    if (fopen_s(&fp, szNombre, "r") != 0) {
        printf("No se pudo abrir el archivo.\n");
    }

    while (fgets(linea, sizeof(linea), fp) != NULL) {
        for (int i = 0; i < strlen(linea); i++) {
            if (linea[i] != ' ' && linea[i] != '(' && linea[i] != ')' && linea[i] != ',' &&
                linea[i] != ';' && linea[i] != '.' &&
                linea[i] != '*' && linea[i] != '}' &&
                linea[i] != '\n' &&
                linea[i] != '>' && linea[i] != '<') {
                palabra[a] = linea[i];
                a++;


            }
            else if (a > 0) {
                palabra[a] = '\0';
                _strlwr_s(palabra);

                int pRep = 0;
                for (int j = 0; j < iNumElementos; j++) {
                    if (strcmp(szPalabras[j], palabra) == 0) {
                        pRep = 1;
                        iEstadisticas[j]++;
                        contadorU++;
                        break;
                    }
                }


                if (!pRep) {
                    strcpy_s(szPalabras[iNumElementos], palabra);
                    iEstadisticas[iNumElementos] = 1;
                    iNumElementos++;
                    contadorU++;
                }
                a = 0;
            }
        }
    }
    //Burbujazo
    int pasada, posicion;
    char aux[TAMTOKEN];
    int auxEstadisticas;

    for (pasada = 0; pasada < iNumElementos - 1; pasada++) {
        for (posicion = 0; posicion < iNumElementos - 1; posicion++) {
            if (strcmp(szPalabras[posicion], szPalabras[posicion + 1]) > 0) {
                // orden de palabras
                strcpy_s(aux, szPalabras[posicion]);
                strcpy_s(szPalabras[posicion], szPalabras[posicion + 1]);
                strcpy_s(szPalabras[posicion + 1], aux);

                // Estadisticas 
                auxEstadisticas = iEstadisticas[posicion];
                iEstadisticas[posicion] = iEstadisticas[posicion + 1];
                iEstadisticas[posicion + 1] = auxEstadisticas;
            }
        }
    }
    fclose(fp);

}


/*****************************************************************************************************************
    ListaCandidatas: Esta funcion recupera desde el diccionario las palabras validas y su peso
    Regresa las palabras ordenadas por su peso
    char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
    int		iNumSugeridas,						//Lista de palabras clonadas
    char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
    int		iEstadisticas[],					//Lista de las frecuencias de las palabras
    int		iNumElementos,						//Numero de elementos en el diccionario
    char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
    int		iPeso[],							//Peso de las palabras en la lista final
    int &	iNumLista)							//Numero de elementos en la szListaFinal
******************************************************************************************************************/
void coparre(char szpalabraleida[NUMPALABRAS][TAMTOKEN], char aux[TAMTOKEN], int fila)
{
    int i;
    for (i = 0; szpalabraleida[fila][i] != '\0', i++;)
    {
        aux[i] = szpalabraleida[fila][i];
    }
    aux[i] = '\0';

}

void	ListaCandidatas(
    char	szPalabrasSugeridas[NUMPALABRAS][TAMTOKEN],	//Lista de palabras clonadas
    int		iNumSugeridas,						//Lista de palabras clonadas
    char	szPalabras[NUMPALABRAS][TAMTOKEN],				//Lista de palabras del diccionario
    int		iEstadisticas[],					//Lista de las frecuencias de las palabras
    int		iNumElementos,						//Numero de elementos en el diccionario
    char	szListaFinal[NUMPALABRAS][TAMTOKEN],			//Lista final de palabras a sugerir
    int		iPeso[],							//Peso de las palabras en la lista final
    int& iNumLista)							//Numero de elementos en la szListaFinal
{

}
/*****************************************************************************************************************
    ClonaPalabras: toma una palabra y obtiene todas las combinaciones y permutaciones requeridas por el metodo
    char *	szPalabraLeida,						// Palabra a clonar
    char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
    int &	iNumSugeridas)						//Numero de elementos en la lista
******************************************************************************************************************/

void CopiaDePalab(
    char szPalabrasSugeridas[][TAMTOKEN], // Lista de palabras clonadas
    int iNumSugeridas,                    // N?mero de elementos en la lista
    char szPalabrasCopia[][TAMTOKEN],     // Nuevo arreglo de arreglos (destino)
    int& iNumCopia)                       // N?mero de elementos en la nueva lista (se actualizar?)
{
    iNumCopia = 0;

    for (int i = 0; i < iNumSugeridas; ++i)
    {
        strcpy_s(szPalabrasCopia[i], szPalabrasSugeridas[i]);
        iNumCopia++;
    }
}


void	ClonaPalabras(
    char* szPalabraLeida,						// Palabra a clonar
    char	szPalabrasSugeridas[][TAMTOKEN],//Lista de palabras clonadas
    int& iNumSugeridas)						//Numero de elementos en la lista
{
    char	Palabras[3300][TAMTOKEN];
    char aux[TAMTOKEN];
    int i;
    int j = 0;
    iNumSugeridas = 0;
    int pasadas = 0;
    char letrasaz[TAMTOKEN] = "abcdefghijklmnñopqrstuvwxyzáéíóú";
    int longiP = strlen(szPalabraLeida);
    int contador = 0;

    for (i = 0; i <= longiP; i++)
    {
        aux[i] = szPalabraLeida[i];
    }
    aux[i] = '\0';

    for (pasadas = 0; pasadas <= longiP; pasadas++)
    {
        strcpy_s(szPalabraLeida, TAMTOKEN, aux);
        for (i = 0; i <= longiP; i++)
        {
            if (i != pasadas)
            {
                szPalabraLeida[j] = aux[i];
                j++;
            }
        }
        szPalabraLeida[i + 1] = '\0';
        strcpy_s(Palabras[iNumSugeridas], szPalabraLeida);
        iNumSugeridas++;
        j = 0;
    }

    for (j = 0; j < strlen(szPalabraLeida); j = j + 1)
    {
        if ((szPalabraLeida[j + 1]) == '\0')
        {
            j++;
            break;
        }
        else
        {
            strcpy_s(szPalabraLeida, TAMTOKEN, aux);
            szPalabraLeida[j] = aux[j + 1];
            szPalabraLeida[j + 1] = aux[j];
            strcpy_s(Palabras[iNumSugeridas], szPalabraLeida);
            iNumSugeridas++;
            contador++;
        }
    }

    for (pasadas = 0; pasadas < strlen(szPalabraLeida); pasadas++)
    {

        strcpy_s(szPalabraLeida, TAMTOKEN, aux);
        for (i = 0; i < strlen(letrasaz); i++)
        {
            strcpy_s(szPalabraLeida, TAMTOKEN, aux);
            szPalabraLeida[pasadas] = letrasaz[i];
            szPalabraLeida[j + 1] = '\0';
            strcpy_s(Palabras[iNumSugeridas], szPalabraLeida);
            iNumSugeridas++;

        }
    }

    for (pasadas = 0; pasadas < strlen(szPalabraLeida); pasadas++)
    {

        for (j = 0; j < strlen(letrasaz); j++)
        {
            int a = 0;
            strcpy_s(szPalabraLeida, TAMTOKEN, aux);

            for (i = 0; i < strlen(szPalabraLeida) + 1; i++)
            {
                if (i != pasadas)
                {
                    szPalabraLeida[i] = aux[a];
                    a++;
                }
                else
                {
                    szPalabraLeida[i] = letrasaz[j];
                }
            }
            szPalabraLeida[strlen(szPalabraLeida) + 1] = '\0';
            strcpy_s(Palabras[iNumSugeridas], szPalabraLeida);
            iNumSugeridas++;
        }
    }
    //Ordenar las palabas
    int pasada, posicion;
    char auxOrden[TAMTOKEN];

    for (pasada = 0; pasada < iNumSugeridas - 1; pasada++) {
        for (posicion = 0; posicion < iNumSugeridas - 1; posicion++) {
            if (strcmp(Palabras[posicion], Palabras[posicion + 1]) > 0) {

                strcpy_s(auxOrden, Palabras[posicion]);
                strcpy_s(Palabras[posicion], Palabras[posicion + 1]);
                strcpy_s(Palabras[posicion + 1], auxOrden);

            }
        }
    }
    // Copiar las palabras ordenadas a szPalabrasSugeridas
    CopiaDePalab(Palabras, iNumSugeridas, szPalabrasSugeridas, iNumSugeridas);
}