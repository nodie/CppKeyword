//
//  solutionlink.h
//  CppKeyword
//
//  Created by 於 琦峰 on 12-10-03.
//  Copyright (c) 2012年 於 琦峰. All rights reserved.
//

#ifndef CppKeyword_solutionlink_h
#define CppKeyword_solutionlink_h

#include "val.h"

void solutionupdate();

void solutioninit(cookielink cptr, lnlink lineInfo) {
        
    //int i, l;

    solutionnew = (solutionlink) malloc(sizeof (solutionnode));
    //printf("solutionnode size %ld\n", sizeof(solutionnode));
    solutionnew->solutionid = lineInfo->solutionid;
    
	solutionnew->keyword = lineInfo->keyword;
    solutionnew->keywordrow = 1;

    solutionnew->next = NULL;
    cptr->solutionhead = cptr->solutionptr = solutionnew;

}

bool solutionfind(cookielink cptr, lnlink lineInfo) {
    solutiontmp = cptr->solutionhead;
    while (solutiontmp != NULL) {
        if (solutiontmp->solutionid == lineInfo->solutionid) {
            //printf("find solutionid %ld %s\n", lineInfo->solutionid, **solutiontmp->keyword);
			solutionupdate(solutiontmp, lineInfo);

            return true;
        }

        solutiontmp = solutiontmp->next;
    }

    return false;
}

void solutioninsert(cookielink cptr, lnlink lineInfo) {
    if (cptr->solutionhead == NULL)
    {
        solutioninit(cptr, lineInfo);
    }

    if (solutionfind(cptr, lineInfo)) {
        return;
    }

    solutionnew = (solutionlink) malloc(sizeof (solutionnode));
    solutionnew->solutionid = lineInfo->solutionid;
    

	solutionnew->keyword = lineInfo->keyword;
    solutionnew->keywordrow = 1;

    solutionnew->next = NULL;
    cptr->solutionptr->next = solutionnew;
    cptr->solutionptr = cptr->solutionptr->next;
}

void solutionupdate(solutionlink solutiontmp, lnlink lineInfo)
{
    int i, l;
	int *tmp;
	bool t = true;

	for (l = 0; l < solutiontmp->keywordrow; l++)
	{
		t = true;
		for (i = 0; i < 30; i++) {
			//printf("p %d keyword %d %d\n", l, *(solutiontmp->keyword + (l * 30) + i), *(lineInfo->keyword + i));
			if (*(solutiontmp->keyword + (l * 30) + i) != *(lineInfo->keyword + i))
			{
				t = false;
				break;
			}
		}

        if (t)
        {
            break;
        }
	}

	if (!t)
	{
        //printf("%d\n", solutiontmp->keywordrow);
        //sleep(1);

		tmp = solutiontmp->keyword;
		solutiontmp->keyword = (int *)malloc(((solutiontmp->keywordrow + 1) * 30) * sizeof(int));

        for (i = 0; i < (solutiontmp->keywordrow * 30); i++)
        {
            *(solutiontmp->keyword + i) = *(tmp + i);
        }

        l = 0;
        for (i = (solutiontmp->keywordrow * 30); i < ((solutiontmp->keywordrow + 1) * 30); i++)
        {
            *(solutiontmp->keyword + i) = *(lineInfo->keyword + l);
            //printf("p %d keyword %d %d\n", i, *(solutiontmp->keyword + i), *(lineInfo->keyword + l));
            l++;
        }

        solutiontmp->keywordrow++;

		// for (l = 0; l < solutiontmp->keywordrow; l++) {
		// 	for (i = 0; i < 30; i++) {
		// 		printf("p %d keyword %d %d\n", ((l * 30) + i), *(solutiontmp->keyword + (l * 30) + i), *(lineInfo->keyword + i));
		// 	}
		// }
	}

	//printf("find %ld\n", lineInfo->solutionid);
}

void solutionview(cookielink cptr) {
    int i, l;
    char *kv;

    solutiontmp = cptr->solutionhead;
    while (solutiontmp != NULL) {
        printf("solutionid %d\n", solutiontmp->solutionid);

        //for (i = 0; i < 10; i++) {
        //printf("keyword %d\n", (cptr->solutiontmp->keyword));
        //}

//        for (i = 0; i < 10; i++) {
//            printf("keyword %d\n", *(cptr->solutiontmp->keyword + i));
//        }
        

        for (l = 0; l < solutiontmp->keywordrow; l++) {
            for (i = 0; i < 30; i++) {
                kv = kvfindid(*(solutiontmp->keyword + (l * 30) + i));
                printf("p %d keyword %d %p %s\n", ((l * 30) + i), *(solutiontmp->keyword + (l * 30) + i), (solutiontmp->keyword + (l * 30)), kv);
            }
        }
        

        solutiontmp = solutiontmp->next;
    }
}



#endif
