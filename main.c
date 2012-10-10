/*
 * File:   main.c
 * Author: ray
 *
 * Created on 2012年9月29日, 下午2:40
 */

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <mysql.h>

#define     _GNU_SOURCE 

#include "val.h"
#include "tools.h"
#include "kvlink.h"
#include "ReadDatabase.h"
#include "cookielink.h"
#include "solutionlink.h"
#include "readlogs.h"

/*
 *
 */


int main(int argc, char** argv) {
	ReadKeywordType();

    //cookieinit();

    readlogs();

	//echoKeywordArray();

    // cookieview();

    return (EXIT_SUCCESS);
}

