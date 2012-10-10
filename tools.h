//
//  tools.h
//  MyTree
//
//  Created by 於 琦峰 on 12-09-30.
//  Copyright (c) 2012年 於 琦峰. All rights reserved.
//

#ifndef MyTree_tools_h
#define MyTree_tools_h

void strtoky(char *str, char *pan, char *line) {
    char *p;
    char strtemp[1024];
    int i = 0;
    int panlen = 0;

    panlen = (int) strlen(pan);

    strcpy(strtemp, str);

    p = strstr(str, pan);
    if (!p) {
        while (strtemp[i] != '\0') {
            *(line + i) = strtemp[i];
            i++;
        }
        *(line + i) = '\0';
        *str = '\0';
    } else {

        strtemp[strlen(str) - strlen(p)] = '\0';

        while (strtemp[i] != '\0') {
            *(line + i) = strtemp[i];
            i++;
        }
        *(line + i) = '\0';

        i = 0;

        while (*(p + i + panlen) != '\0') {
            //printf("%c\n",*(p+i+1));
            *(str + i) = *(p + i + panlen);
            i++;
        }
        *(str + i) = '\0';
    }
}

long From82(char *buf) {

    long s = 0;
    long t = 1;
    int k = 0;
    for (k = 0; k < strlen(buf); k++) {
        s += t * ((int) buf[k] - '-');
        t *= 82;
    }

    if (s < 0) {
        s = -s;
    }

    return s;
}

unsigned int ELFHash( char   * str)
{
        unsigned int hash =   0 ;
        unsigned int x     =   0 ;
         while ( * str)
          {
                 hash = (hash <<   4 ) + ( * str ++ );
                 if ((x = hash &   0xF0000000L ) !=   0 )
                  {
                        hash ^= (x >>   24 );
                        hash &=   ~ x;
                }
        }

         return ((hash&0x7FFFFFFF)/1000%1000);
}

#endif
