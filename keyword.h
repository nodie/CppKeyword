/* 
 * File:   keyword.h
 * Author: landiyu
 *
 * Created on 2012年10月3日, 下午10:50
 */

#ifndef KEYWORD_H
#define	KEYWORD_H

#include "val.h"


#ifdef	__cplusplus
extern "C" {
#endif



void kwinit(solutionlink sptr, lnlink lineInfo) {
    kwnew = (kwlink) malloc(sizeof (kwnode));
    printf("kwnode size %ld\n", sizeof(kwnode));
    kwnew->keyword = lineInfo->keyword;
    
    kwnew->next = NULL;
    sptr->kwhead = sptr->kwptr = kwnew;
}

bool kwfind(solutionlink sptr, lnlink lineInfo) {
    kwtmp = sptr->kwhead;
    while (kwtmp != NULL) {
        /*
        if (sptr->kwtmp->keyword == lineInfo->solutionid) {
            //printf("find %ld", lineInfo->solutionid);

            return true;
        }
         */
        

        kwtmp = kwtmp->next;
    }

    return false;
}

void kwinsert(solutionlink sptr, lnlink lineInfo) {
    
    if (kwfind(sptr, lineInfo)) {
        return;
    }

    kwnew = (kwlink) malloc(sizeof (kwnode));
    kwnew->keyword = lineInfo->keyword;
    
    kwnew->next = NULL;
    sptr->kwptr->next = kwnew;
    sptr->kwptr = sptr->kwptr->next;
}

void kwview(solutionlink sptr) {
    int i;
    
    kwtmp = sptr->kwhead;
    while (kwtmp != NULL) {
        
        for (i = 0; i < 10; i++) {
            printf("kwid %d\n", *(kwtmp->keyword + i));
        }

        kwtmp = kwtmp->next;
    }
}


#ifdef	__cplusplus
}
#endif

#endif	/* KEYWORD_H */

