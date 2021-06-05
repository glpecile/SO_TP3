# TP3 SO - README

<hr>

## Autores

- [Roberto Catalan](https://github.com/rcatalan98)
- [María Victoria Conca](https://github.com/Mickyconca)
- [Gian Luca Pecile](https://github.com/glpecile).

## Aplicación

Supere los desafíos del juego inspirado en CTF.

## Compilación

Ejecutar `make` o `make all` para el compilado de los archivos.

Si desea remover los mismos, ejecute `make clean` en el mismo directorio donde fue realizada la compilación.

## Ejecución

Para correr el programa y jugar al juego, ejecutar el archivo **server** corriendo `./server` junto con **client** corriendo `./client` en otra terminal conectada al mismo contenedor para poder contestar los desafíos.

## Testeo

Para el testeo con tanto **PVS-Studio**, **Cppcheck** como **Valgrind** se debe primero instalar **PVS-Studio** de no tenerlo, de la siguiente manera en su contenedor de _docker_.

```bash
apt-get update
apt-get install pvs-studio
pvs-studio-analyzer credentials "PVS-Studio Free" "FREE-FREE-FREE-FREE"
```

Luego correr el siguiente comando:

```bash
 make test
```

Los resultados se encontrarán de la siguiente manera:

- **PVS-Studio:** report.tasks
- **Valgrind:** results.valgrind
- **Cppcheck:** output.txt

Para remover los mismos, correr el comando `make cleanTest` en el mismo directorio donde fue realizada la compilación.
