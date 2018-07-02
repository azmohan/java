include    <stdio.h>

struct data
{
    int x;
    int y;
};

int main(int argc, char *argv[])
{
    struct data f;
    FILE* file=fopen("data1", "r");
    int ret=fread(&f, sizeof(struct data), 1, file);
    printf("ret=%d\n", ret);
    fclose(file);
    printf("f.x=%d\n",f.x);
    printf("f.y=%d\n",f.y);

    return 0;
}
