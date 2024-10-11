# Testing de Software en Sistemas Embebidos - CESE UBA
## Trabajo Práctico 2 - 

>Autor: Edilberto Carvajal

Desarrollo de biblioteca para manejo de LEDs y testing automático mediante Desarrollo Guiado por Pruebas (TDD)

### First steps

Crear proyecto e instalar los framewkors utilizando los siguientes pasos:

- Instalación de Ruby
`sudo apt-get install ruby gcov`
- Instalación de Ceedling
`sudo gem install ceedling`
- Creación del repositorio de trabajo
`git init project_name`
- Creación del proyecto ceedling
`ceedling new project_name`

### Tests

Tests desarrollados:

```
1- Inicializacion de puerto
2- Prender un LED individual
3- Apagar un LED individual
4- Prender y apagar varios LEDs
5- Apagar TODOS los LEDs
6- Encender TODOS los LEDs
7- Consultar por un LED encendido
8- Consultar por un LED apagado
9- Consultar por limite de parametro LED
10- Consultar por LED por fuera de los limites
11- Verificar creacion de puerto nulo
12- Revisar limites de los parametros.
13- Revisar parámetros fuera de los limites.
```
