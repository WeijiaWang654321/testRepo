#include <stdio.h>
#include <stdlib.h>
#include "hexutil.h"

int main(int argc,char**argv)
{
    FILE *fp=0;
    FILE *outfp=0;
    char *filename=0;
    unsigned long bytenumber=0;
    unsigned char *streambuff=0;

    if(1==argc){
        printf("please use wwjshexviewer filename\n");
        return 0;
    }else{
        filename=argv[1];
    }

    printf("You want to open the file:%s\n",filename);
    fp=fopen(filename,"rb");
    if(NULL == fp){
        printf("error opening file\n");
        printf("errno:%d\n",errno);
        return 1;
    }
    printf("Succeed opening file\n");

    if(-1==fseek(fp,0,SEEK_SET)){
        printf("error in fseek()\n");
        printf("errno:%d\n",errno);
        return 1;
    }

    printf("Please input how many byte you want to read?\n");
    if(1!=scanf("%lu",&bytenumber)){
            printf("error in scanf() of bytenumber\n");
            return 1;
    }
    printf("You want to read %lu byte\n",bytenumber);

    streambuff=malloc(bytenumber);
    if(bytenumber!=fread(streambuff,1,bytenumber,fp)){
        printf("fread error\n");
        printf("errno:%d\n",errno);
    }
    char* hexstring = chartostring(streambuff,bytenumber);

    outfp = fopen("Hexstringoutput.txt","w");
    if(NULL == outfp){
        printf("error opening file\n");
        printf("errno:%d\n",errno);
        return 1;
    }

    unsigned long stringindex=0;
    unsigned long hexindex=0lu;
    fprintf(outfp,"0x%.16lx: ",hexindex);
    hexindex+=16;
    while(0!=hexstring[stringindex]){

    fprintf(outfp,"%c",hexstring[stringindex]);
        if(0 == ((stringindex+1)%(48)) ){
                fprintf(outfp,"\n");
                fprintf(outfp,"0x%.16lx: ",hexindex);
                hexindex+=16;
        }
    stringindex++;
    }

    fclose(outfp);
    fclose(fp);
    return 0;
}
