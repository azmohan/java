#include    <stdio.h>

int main(int argc, char *argv[])
{
    int a[3][4]={0};
    int b[3][4]={0};
    int c[3][4]={0};

    int i;
    int j;

    for(i=0; i<3; i++) {
        for(j=0; j<4; j++) {
            a[i][j]=i*4+j+1;
            b[i][j]=13-(i*4+j+1);
        }
    }

    for(i=0; i<3; i++) {
        for(j=0; j<4; j++) {
            printf("%-5d", a[i][j]);
        }
        printf("\n");
    }


    printf("\n");
    for(i=0; i<3; i++) {
        for(j=0; j<4; j++) {
            printf("%-5d", b[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            c[i][j]=a[i][j]+b[i][j];
            printf("%-5d", c[i][j]);
        }

        printf("\n");
    }

    return 0;

}
