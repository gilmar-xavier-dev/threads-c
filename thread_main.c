#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<pthread.h>

void* rotina(void* ind)
{
    int y = *(int*)ind;
    printf("Iniciando Thread... %d\n", y);
    printf("Finalizando Thread... %d\n", y);
    free(ind);
    return 0;
}

int main()
{
    pthread_t tr[10];
    int i=0,x=0;
    for (i=0;i<10;i++)
    {
        int* z = malloc(sizeof(int));
        *z = i;
        printf("Criando Thread... %d\n", *(int*)z);
        if(pthread_create(&tr[i],NULL,rotina,z) !=0)
        {
            printf("Erro na criação da Thread %d\n",i);
        }
    }
    for (x=0;x<10;x++)
    {
        if(pthread_join(tr[x],NULL) != 0)
        {
            printf("Erro no aguardo da Thread %d\n",x);
        }
    }
    return 0;
}
