//
//  kvlink.h
//  CppKeyword
//
//  Created by 於 琦峰 on 12-10-03.
//  Copyright (c) 2012年 於 琦峰. All rights reserved.
//

#ifndef CppKeyword_kvlink_h
#define CppKeyword_kvlink_h

#include "val.h"

void kvupdate();

void kvinit(int id, char *kv, int hash) {
        
    kvnew = (kvlink) malloc(sizeof (kvnode));
    //printf("kvnode size %ld\n", sizeof(kvnode));
    asprintf(&(kvnew->kv), "%s", kv);
    kvnew->id = id;
    
    kvnew->next = NULL;
    kvhead[hash] = kvptr[hash] = kvnew;

}

int kvfind(char* kv, int hash) {
    kvtmp = kvhead[hash];
    while (kvtmp != NULL) {
        if (strcmp(kvtmp->kv, kv) == 0) {
            //printf("find %s\n", kv);
			//kvupdate(kvtmp, lineInfo);

            return kvtmp->id;
        }

        kvtmp = kvtmp->next;
    }

    return 0;
}

char* kvfindid(int id) {
    int i;
    for (i = 0; i < 1000; ++i)
    {        
        kvtmp = kvhead[i];
        while (kvtmp != NULL) {
            if (kvtmp->id == id) {
                //printf("find %s\n", kv);
                //kvupdate(kvtmp, lineInfo);

                return kvtmp->kv;
            }

            kvtmp = kvtmp->next;
        }
    }

    return NULL;
}

void kvinsert(int id, char* kv, int hash) {
    if (kvhead[hash] == NULL)
    {
        kvinit(id, kv, hash);
        return;
    }

    kvnew = (kvlink) malloc(sizeof (kvnode));
    asprintf(&(kvnew->kv), "%s", kv);
    kvnew->id = id;

    kvnew->next = NULL;
    kvptr[hash]->next = kvnew;
    kvptr[hash] = kvptr[hash]->next;
}

int kvinsertnew(char* kv, int hash) {
    if (kvhead[hash] == NULL)
    {
        maxkvid++;
        kvinit(maxkvid, kv, hash);
        return maxkvid;
    }

    kvnew = (kvlink) malloc(sizeof (kvnode));
    asprintf(&(kvnew->kv), "%s", kv);
    maxkvid++;
    kvnew->id = maxkvid;

    kvnew->next = NULL;
    kvptr[hash]->next = kvnew;
    kvptr[hash] = kvptr[hash]->next;

    return maxkvid;
}

void kvview() {
    int i;
    for (i = 0; i < 1000; ++i)
    {
        kvtmp = kvhead[i];
        while (kvtmp != NULL) {
            printf("kvid %d %s\n", kvtmp->id, kvtmp->kv);

            kvtmp = kvtmp->next;
        }
    }
}



#endif
