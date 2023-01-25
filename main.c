#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main()
{
    double F,x,a,b,delta;
    int N,n,i;
    char group_name[5],student_name[16];
    FILE *input,*output,*outbin,*inbin;



    input=fopen("C:\\lab5.2\\lab5.2_in.txt","r");
        if(input==NULL)
        {
            printf("\n\t\t\tERROR!\n");
            getche();
            exit(1);
        }

    fscanf(input, "%lf %lf %d %lf %s %s", &a, &b, &N, &delta, &group_name, &student_name);
    fclose(input);
    printf("a=%.2lf\nb=%.2lf\nN=%d\ndelta=%.2lf\n%s\n%s\n\n", a, b, N, delta, group_name, student_name);


    output=fopen( "C:\\lab5.2\\lab5.2_out.txt", "w" );
        if(output==NULL)
        {
            printf("\n\t\t\tERROR!\n");
            getche();
            exit(1);
        }


    outbin=fopen( "C:\\lab5.2\\lab5.2.bin", "wb" );
        if(outbin==NULL)
        {
            printf("\n\t\t\tERROR!\n");
            getche();
            exit(1);
        }


    if(N==0)
        N=((b-a)/delta)+1;

    if(delta==0)
        delta=(b-a)/(N-1);


    fprintf(output,"\t+-----------------------------------------------+\n");
    fprintf(output,"\t|\tN\t|\tX\t|\tF(x)\t|\n");
    fprintf(output,"\t+-----------------------------------------------+\n");

    for(i=1;i<=N+1;i++)
    {
        F=0.25*pow(a,5)+4*pow(a+20,4)-2*a;
        fwrite( &i, sizeof(int), 1, outbin );
        fwrite( &a, sizeof(double), 1, outbin );
        fwrite( &F, sizeof(double), 1, outbin );
        fprintf(output,"\n\t|\t%d\t|\t%.2f\t|\t%.2f|\n",i,a,F);
        fprintf(output,"\t+-----------------------------------------------+\n");
        a=a+delta;
    }

    fprintf(output, "\n\t\t %s %s", student_name, group_name);
    fclose(output);
    fclose(outbin);


    inbin=fopen("C:\\lab5.2\\lab5.2.bin","rb");
        if(inbin==NULL)
            {
                printf("\n\t\t\tERROR!\n");
                getche();
                exit(1);
            }
    printf("\t+-----------------------------------------------+\n");
    printf("\t|\tN\t|\tX\t|\tF(x)\t|\n");
    printf("\t+-----------------------------------------------+\n");

    for(i=1;i<=N;i++)
    {
        fread(&n, sizeof(int),1,inbin );
        fread(&x, sizeof(double),1,inbin );
        fread(&F, sizeof(double),1,inbin );
        printf ("\n\t|\t%d\t|\t%.2f\t|\t%.2f|\n",n,x,F);
        printf("\t+-----------------------------------------------+\n");
    }

    fclose(inbin);

    return 0;

    }


