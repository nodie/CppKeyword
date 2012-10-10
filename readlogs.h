//
//  readlogs.h
//  MyTree
//
//  Created by 於 琦峰 on 12-09-30.
//  Copyright (c) 2012年 於 琦峰. All rights reserved.
//

#ifndef MyTree_readlogs_h
#define MyTree_readlogs_h

#include "val.h"
#include "cookielink.h"

int* inputKeywordArray();

void readlogs() {

    DIR *dp;
    FILE *fp;
    struct dirent *dpptr;

    const char *path = "/home/samelog/logs/";
//    const char *path = "c:/home/samelog/logs/";
    
    char fullPath[1024];
    char fileLine[1024];
    char fileLineTemp[1024];
    char *fileLineInfo;
	char *fileLineTempPtr;
    char *lpInfo;
    char *paraInfo1;
    char *paraInfo2;
    char *paraInfo3;
    int paraID;
    int paraHash;
    int cookieHash;

    lnlink lineInfo;

    int i, l, k = 0;

    dp = opendir(path);
    while ((dpptr = readdir(dp)) != NULL) {
//        if (dpptr->d_name[0] != '.') {
        if (strcmp(dpptr->d_name, "rtb_test.2011-11-16.18.Standard.192.168.32.134") == 0) {
            sprintf(fullPath, "%s%s", path, dpptr->d_name);
            printf("%s\n", fullPath);

            if ((fp = fopen(fullPath, "r")) == NULL) {
                perror("Trendlogs Error!\n");
                exit(0);
            }

            while (fgets(fileLine, 1024, fp)) {
                //printf("%s", fileLine);

                k++;

                if ((k % 100) == 0)
                {
                    printf("%d\t", k);
                }

                lineInfo = (lnlink) malloc(sizeof (lnnode));

                strcpy(fileLineTemp, fileLine);
                fileLineTemp[strlen(fileLineTemp) - 1] = '\0';
				fileLineTempPtr=fileLineTemp;

                i = 0;
				while(fileLineInfo=strsep(&fileLineTempPtr,logsPan))
				{

                    //printf("%s\n",fileLineTempPtr);
                    //printf("%s\n",fileLineInfo);

                    if (i == 4) {
                        //printf("%ld\n", sizeof(lnnode));
                        //printf("%s\n", fileLineInfo);
                        lineInfo->cookie = From82(fileLineInfo);
                        //printf("%ld\n", lineInfo->cookie);
                    }
                    if (i == 6) {
                        lineInfo->layoutid = atoi(fileLineInfo);
                    }
                    if (i == 7) {
                        lineInfo->siteid = atoi(fileLineInfo);
                    }
                    if (i == 8) {
                        lineInfo->channelgroupid = atoi(fileLineInfo);
                    }
                    if (i == 9) {
                        lineInfo->channelid = atoi(fileLineInfo);
                    }
                    if (i == 10) {
                        lineInfo->campaignid = atoi(fileLineInfo);
                    }
                    if (i == 11) {
                        lineInfo->orderid = atoi(fileLineInfo);
                    }
                    if (i == 12) {
                        lineInfo->solutionid = atoi(fileLineInfo);
                    }
                    if (i == 13) {
                        lineInfo->bannergroupid = atoi(fileLineInfo);
                    }
                    if (i == 14) {
                        lineInfo->bannerid = atoi(fileLineInfo);
                    }
                    if (i == 15) {
                        //printf("%s\n", fileLineInfo);

                        for (l = 0; l < 30; l++)
                        {
                            keywordArrayTmp[l] = 0;
                        }

                        l = 0;
                        while(lpInfo=strsep(&fileLineInfo,logsPan2))
                        {
                            //printf("%s\n", lpInfo);
                            paraInfo1 = strsep(&lpInfo,logsPan3);
                            if (*(paraInfo1) == '_')
                            {
                                //printf("%s\t", paraInfo1);
                                paraInfo2 = strsep(&lpInfo,logsPan3);
                                //printf("%s\n", paraInfo2);
                                paraInfo3 = (char *) malloc(sizeof (char) * 1024);
                                sprintf(paraInfo3, "%s,%s", paraInfo1, paraInfo2);
                                paraHash = ELFHash(paraInfo3);
                                //printf("%s %d\n", paraInfo3, paraHash);
                                paraID = kvfind(paraInfo3, paraHash);
                                if (paraID == 0)
                                {
                                    paraID = kvinsertnew(paraInfo3, paraHash);
                                }
                                //printf("paraID %d\n", paraID);
                                keywordArrayTmp[l] = paraID;
                                free(paraInfo3);

                                l++;
                            }
                        }

                        lineInfo->keyword = inputKeywordArray();
                        //printf("%s\n", *(lineInfo->keyword));

                        break;
                    }

                    i++;
                }

                cookieHash = lineInfo->cookie % 10000;
                cookieinsert(lineInfo, cookieHash);
                
                //free(lineInfo->keyword);
                //lineInfo->keyword = NULL;
                free(lineInfo);
            }
            fclose(fp);
        }
    }
    closedir(dp);

}

int* inputKeywordArray() {
    int i, j, k;
	bool t = true;
    for (i = 0; i < 100000; i++) {
        if (keywordArray[i][0] == 0) {
            break;
        }
        
		t = true;
        for (j = 0; j < 30; j++) {
            if (keywordArrayTmp[j] != keywordArray[i][j]) {
				t = false;
                break;
            }
        }

		if (t)
		{
			return keywordArray[i];
		}
    }
    
    for (k = 0; k < 30; k++) {
        keywordArray[i][k] = keywordArrayTmp[k];
		//printf("%i %p\n", i, keywordArray[i]);
    }

    return keywordArray[i];
}

void echoKeywordArray() {
    int i, j;
    for (i = 0; i < 100000; i++) {
        if (keywordArray[i][0] == 0) {
            continue;
        }
        
        for (j = 0; j < 30; j++) {
            printf("%d,", keywordArray[i][j]);
        }
        
        printf("\n");
    }
}

#endif
