#include <hexutil.h>

char* testfun(){

    char* cc=malloc(5);
    return cc;
}




char* chartostring(unsigned char *bytearray,unsigned long number){

 /*   for(int i=0;i<number;i++){
        printf("%d ",bytearray[i]);
    }*/
    char *localhexstring = malloc(number * 3+1);
    memset(localhexstring,'\0',number*3+1);

//    printf("-----------------------------------\n");
//    //char hexnumber[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
//    char *hexnumber = "0123456789ABCDEF";
//    for(char index1=0; index1<16 ; index1++){
//            for(char index2=0; index2<16 ; index2++){
//                printf("0x%c%c,",hexnumber[index1],hexnumber[index2]);
//            }
//    }
//    printf("-----------------------------------\n");


    unsigned char *ptronebytearray=0;
     unsigned char temparray[256] = {
        0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
        0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
        0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
        0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
        0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
        0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,
        0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,
        0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F,
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,
        0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F,
        0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,
        0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0xBE,0xBF,
        0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF,
        0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xDB,0xDC,0xDD,0xDE,0xDF,
        0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,0xEE,0xEF,
        0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFE,0xFF,
    };
    ptronebytearray=temparray;

    for(unsigned long i=0;i<number;i++){
            for(int j=0;j<256;j++){
               if(bytearray[i]==(unsigned char)ptronebytearray[j] ){
                  //printf("%d\n",ptronebytearray[j]);
                  char* ptrtemponebyte = charnumbertostring(ptronebytearray[j]);

                  localhexstring[i*3+0] = ptrtemponebyte[0];
                  localhexstring[i*3+1] = ptrtemponebyte[1];
                  localhexstring[i*3+2] = ' ';
                }
            }
    localhexstring[i*3+3]='\0';
    }

    return localhexstring;
}

char* charnumbertostring(unsigned char index){
    char *onebytestringarray=malloc(2);
    memset(onebytestringarray,'\0',2);

    if(index%16==15){
            //printf("%c",'F');
            onebytestringarray[1]='F';
    index=index/16;
    }
    else if(index%16==14){
            //printf("%c",'E');
            onebytestringarray[1]='E';
    index=index/16;
    }
    else if(index%16==13){
            //printf("%c",'D');
            onebytestringarray[1]='D';
    index=index/16;
    }
    else if(index%16==12){
            //printf("%c",'C');
            onebytestringarray[1]='C';
    index=index/16;
    }
    else if(index%16==11){
            //printf("%c",'B');
            onebytestringarray[1]='B';
    index=index/16;
    }
    else if(index%16==10){
            //printf("%c",'A');
            onebytestringarray[1]='A';
    index=index/16;
    }
    else if(index%16==9){
            //printf("%c",'9');
            onebytestringarray[1]='9';
    index=index/16;
    }
    else if(index%16==8){
            //printf("%c",'8');
            onebytestringarray[1]='8';
    index=index/16;
    }
    else if(index%16==7){
            //printf("%c",'7');
            onebytestringarray[1]='7';
    index=index/16;
    }
    else if(index%16==6){
            //printf("%c",'6');
            onebytestringarray[1]='6';
    index=index/16;
    }
    else if(index%16==5){
            //printf("%c",'5');
            onebytestringarray[1]='5';
    index=index/16;
    }
    else if(index%16==4){
            //printf("%c",'4');
            onebytestringarray[1]='4';
    index=index/16;
    }
    else if(index%16==3){
            //printf("%c",'3');
            onebytestringarray[1]='3';
    index=index/16;
    }
    else if(index%16==2){
            //printf("%c",'2');
            onebytestringarray[1]='2';
    index=index/16;
    }
    else if(index%16==1){
            //printf("%c",'1');
            onebytestringarray[1]='1';
    index=index/16;
    }
    else if(index%16==0){
            //printf("%c",'0');
            onebytestringarray[1]='0';
    index=index/16;
    }




        if(index%16==15){
            //printf("%c",'F');
            onebytestringarray[0]='F';
    index=index/16;
    }
    else if(index%16==14){
            //printf("%c",'E');
            onebytestringarray[0]='E';
    index=index/16;
    }
    else if(index%16==13){
            //printf("%c",'D');
            onebytestringarray[0]='D';
    index=index/16;
    }
    else if(index%16==12){
            //printf("%c",'C');
            onebytestringarray[0]='C';
    index=index/16;
    }
    else if(index%16==11){
            //printf("%c",'B');
            onebytestringarray[0]='B';
    index=index/16;
    }
    else if(index%16==10){
            //printf("%c",'A');
            onebytestringarray[0]='A';
    index=index/16;
    }
    else if(index%16==9){
            //printf("%c",'9');
            onebytestringarray[0]='9';
    index=index/16;
    }
    else if(index%16==8){
            //printf("%c",'8');
            onebytestringarray[0]='8';
    index=index/16;
    }
    else if(index%16==7){
            //printf("%c",'7');
            onebytestringarray[0]='7';
    index=index/16;
    }
    else if(index%16==6){
            //printf("%c",'6');
            onebytestringarray[0]='6';
    index=index/16;
    }
    else if(index%16==5){
            //printf("%c",'5');
            onebytestringarray[0]='5';
    index=index/16;
    }
    else if(index%16==4){
            //printf("%c",'4');
            onebytestringarray[0]='4';
    index=index/16;
    }
    else if(index%16==3){
            //printf("%c",'3');
            onebytestringarray[0]='3';
    index=index/16;
    }
    else if(index%16==2){
            //printf("%c",'2');
            onebytestringarray[0]='2';
    index=index/16;
    }
    else if(index%16==1){
            //printf("%c",'1');
            onebytestringarray[0]='1';
    index=index/16;
    }
    else if(index%16==0){
            //printf("%c",'0');
            onebytestringarray[0]='0';
    index=index/16;
    }

return onebytestringarray;

    //if(0==index){return;}
    //charnumbertostring(index);
}
