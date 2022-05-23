# Taller1-Computaci-n-paralela-y-distribu-da
Para usar la herramienta "make", debe estar instalada dicha herramienta en las máquinas en dónde los archivos c serán compilados. 
Para ello, en la terminal se aplica el comando "sudo apt-get install make". Luego de esto, será posible compilar el archivo "secuencial.c"
mediante el comando "make secuencial". Por otro lado, el archivo "openmp.c" debe ser compilado mediante el comando "make openmp". El
archivo "makefile" da las directivas necesarias al comando "make" para que compile de manera correcta el archivo "openmp.c", mientras que
el archivo "secuencial.c" es compilado por la herramienta "make" con valores por defecto, lo que hace que no sea necesario especificar
comandos para este archivo en el archivo "makefile". Es importante que, para todas las acciones mencionadas, todos los archivos se encuentren
en el mismo directorio.
