/*****************************************************************************************************************
	UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
	FACULTAD DE ESTUDIOS SUPERIORES -ARAGON-

	Computadoras y programacion. 
	(c) Ponga su nombre y numero de cuenta aqui.
	
	Quiso decir: Programa principal de la aplicacion de la distancia de Levenstein.
	
******************************************************************************************************************/


#include "stdafx.h"
#include <string.h>
#include "corrector.h"
#include <ctype.h>
#define MAXELEM 40000
//Funciones publicas del proyecto
/*****************************************************************************************************************
	DICCIONARIO: Esta funcion crea el diccionario completo
	char *	szNombre				:	Nombre del archivo de donde se sacaran las palabras del diccionario	
	char	szPalabras[][TAMTOKEN]	:	Arreglo con las palabras completas del diccionario
	int		iEstadisticas[]			:	Arreglo con el numero de veces que aparecen las palabras en el diccionario
	int &	iNumElementos			:	Numero de elementos en el diccionario
******************************************************************************************************************/
void Diccionario(char *szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int &iNumElementos)
{
	FILE* fp;
	char linea[MAXELEM];
	char palabra[MAXELEM];
	iNumElementos = 0;
	int a = 0;
	int contadorUnic = 0;

	if (fopen_s(&fp, szNombre, "r") != 0) {
		printf("No se pudo abrir el archivo.\n");
	}

	while (fgets(linea, sizeof(linea), fp) != NULL) {
		for (int i = 0; i < strlen(linea); i++) {
			if (linea[i] != ' ' && linea[i] != '(' && linea[i] != ')' && linea[i] != ',' &&
				linea[i] != ';' && linea[i] != '.' &&
				linea[i] != '*' && linea[i] != '}' &&
				linea[i] != '\n' && linea[i] != '>' && linea[i] != '<') {
				palabra[a] = linea[i];
				a++;


			}
			else if (a > 0) {
				palabra[a] = '\0';
				_strlwr_s(palabra);
				//busca si se repite 
				int repetida = 0;
				for (int j = 0; j < iNumElementos; j++) {
					if (strcmp(szPalabras[j], palabra) == 0) {
						repetida = 1;
						iEstadisticas[j]++;
						contadorUnic++;
						break;
					}
				}


				if (!repetida) {
					strcpy_s(szPalabras[iNumElementos], palabra);
					iEstadisticas[iNumElementos] = 1;
					iNumElementos++;
					contadorUnic++;

				}

				a = 0;
			}
		}
	}
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
void	ListaCandidatas		(
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
{

}

/*****************************************************************************************************************
	ClonaPalabras: toma una palabra y obtiene todas las combinaciones y permutaciones requeridas por el metodo
	char *	szPalabraLeida,						// Palabra a clonar
	char	szPalabrasSugeridas[][TAMTOKEN], 	//Lista de palabras clonadas
	int &	iNumSugeridas)						//Numero de elementos en la lista
******************************************************************************************************************/
void copiar(char* szpalabraleida, char aux[TAMTOKEN])
{
    int i;
    for (i = 0; i <= (strlen(szpalabraleida)); i++)
    {
        szpalabraleida[i] = aux[i];
    }
    szpalabraleida[i] = '\0';

}
void	ClonaPalabras(
    char* szPalabraLeida,						// Palabra a clonar
    char	szPalabrasSugeridas[][TAMTOKEN],//Lista de palabras clonadas
    int& iNumSugeridas)						//Numero de elementos en la lista
{

}