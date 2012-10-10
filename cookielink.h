//
//  cookielink.h
//  CppKeyword
//
//  Created by 於 琦峰 on 12-10-03.
//  Copyright (c) 2012年 於 琦峰. All rights reserved.
//

#include "solutionlink.h"
#include "val.h"

#ifndef CppKeyword_cookielink_h
#define CppKeyword_cookielink_h

void cookieinit(lnlink lineInfo, int cookieHash) {
    cookienew = (cookielink) malloc(sizeof (cookienode));
    //printf("cookienode size %ld\n", sizeof(cookienode));
    cookienew->cookie = lineInfo->cookie;
    cookienew->solutionhead = NULL;
    cookienew->next = NULL;
    cookiehead[cookieHash] = cookieptr[cookieHash] = cookienew;
    solutioninsert(cookiehead[cookieHash], lineInfo);
}

bool cookiefind(lnlink lineInfo, int cookieHash) {
    cookietmp = cookiehead[cookieHash];
    while (cookietmp != NULL) {
        if (cookietmp->cookie == lineInfo->cookie) {
            //printf("find %ld\n", cookietmp->cookie);
            solutioninsert(cookietmp, lineInfo);

            return true;
        }

        cookietmp = cookietmp->next;
    }

    return false;
}

void cookieinsert(lnlink lineInfo, int cookieHash) {
    if (cookiehead[cookieHash] == NULL)
    {
        cookieinit(lineInfo, cookieHash);
        return;
    }

    if (cookiefind(lineInfo, cookieHash)) {
        return;
    }

    cookienew = (cookielink) malloc(sizeof (cookienode));
    cookienew->cookie = lineInfo->cookie;
    cookienew->solutionhead = NULL;
    //solutioninsert(cookienew, lineInfo);
    cookienew->next = NULL;
    solutioninsert(cookienew, lineInfo);

    cookieptr[cookieHash]->next = cookienew;
    cookieptr[cookieHash] = cookieptr[cookieHash]->next;
}

void cookieview() {
    int i;
    for (i = 0; i < 10000; ++i)
    {
        cookietmp = cookiehead[i];
        while (cookietmp != NULL) {
            printf("cookieid %ld\n", cookietmp->cookie);

            solutionview(cookietmp);

            cookietmp = cookietmp->next;
        }
    }
}


#endif
