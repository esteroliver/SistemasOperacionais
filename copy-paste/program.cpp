#include <unistd.h> //constantes para controle de arquivo
#include <fcntl.h> //chamadas open e close

//argv são os argumentos que vamos passar pelo terminal
int main(int argc, char **argv){
    const char *copia_fn = argv[1];
    const char *cola_fn = argv[2];

    int copia = open(copia_fn, O_RDONLY); //vai ler o arquivo e colocar em copia
    int cola = open(cola_fn, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR); //vai escrever e criar o arquivo do argumento 2

    char buf[1024];
    int s;
    while((s = read(copia, buf, 1024)) != 0)
        write(cola, buf, s);
    close(copia);
    close(cola);
    return 0;
}