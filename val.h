//
//  val.h
//  MyTree
//
//  Created by 於 琦峰 on 12-09-30.
//  Copyright (c) 2012年 於 琦峰. All rights reserved.
//

#ifndef MyTree_val_h
#define MyTree_val_h

char logsPan[] = ",";
char logsPan2[] = "&";
char logsPan3[] = "=";

struct line {
    long cookie;

    int layoutid;
    int siteid;
    int channelgroupid;
    int channelid;
    int campaignid;
    int orderid;
    int solutionid;
    int bannergroupid;
    int bannerid;

    int *keyword;
};
typedef struct line lnnode;
typedef lnnode *lnlink;

// struct slist {
//     int solutionid;

//     //cclink ccroot;

//     struct slist *rptr;
//     struct slist *lptr;
// };
// typedef struct slist snode;
// typedef snode *slink;


// struct kwlist {
//     int *keyword;
//     struct kwlist *next;
// };
// typedef struct kwlist kwnode;
// typedef kwnode *kwlink;

struct solutionlist {
    int solutionid;
    int *keyword;
	short keywordrow;
    //kwlink kwptr, kwhead;
    
    struct solutionlist *next;
};
typedef struct solutionlist solutionnode;
typedef solutionnode *solutionlink;

struct cookielist {
    long cookie;

    solutionlink solutionptr, solutionhead;

    struct cookielist *next;
};
typedef struct cookielist cookienode;
typedef cookienode *cookielink;

cookielink cookieptr[10000], cookiehead[10000], cookienew, cookietmp;
solutionlink solutionnew, solutiontmp;
//kwlink kwnew, kwtmp;

int keywordArray[100000][30];
int keywordArrayTmp[30];


struct kvlist {
    int id;
    char *kv;
    //int kid;
    //int vid;

    struct kvlist *next;
};
typedef struct kvlist kvnode;
typedef kvnode *kvlink;
kvlink kvptr[1000], kvhead[1000], kvnew, kvtmp;
int maxkvid = 0;

struct klist {
    int id;
    char *k;

    struct klist *next;
};
typedef struct klist knode;
typedef knode *klink;
klink kptr, khead, knew, ktmp;


struct vlist {
    int id;
    char *v;

    struct vlist *next;
};
typedef struct vlist vnode;
typedef vnode *vlink;
vlink vptr, vhead, vnew, vtmp;


#endif

