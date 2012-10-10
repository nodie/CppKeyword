ReadKeywordType()
{
    MYSQL mysql,*sock;    //定义数据库连接的句柄，它被用于几乎所有的MySQL函数
    MYSQL_RES *res;       //查询结果集，结构类型
    MYSQL_FIELD *fd ;     //包含字段信息的结构
    MYSQL_ROW row ;       //存放一行查询结果的字符串数组
    char  qbuf[160];      //存放查询sql语句字符串
	int fieldsnumber;
	int i;
    char *strtmp;
    int paraHash;
    
    mysql_init(&mysql);
    if (!(sock = mysql_real_connect(&mysql,"localhost","root","point9*","rtb_test",0,NULL,0))) {
        printf("Couldn't connect to engine!\n%s\n\n",mysql_error(&mysql));
        exit(1);
    }
    
    sprintf(qbuf,"select * from `_statskeywordrelated` order by id");
    if(mysql_query(sock,qbuf)) {
        printf("Query failed (%s)\n",mysql_error(sock));
        exit(1);
    }
    
    if (!(res=mysql_store_result(sock))) {
        printf("Couldn't get result from %s\n", mysql_error(sock));
        exit(1);
    }
    
    //printf("number of fields returned: %d\n",mysql_num_fields(res));
	fieldsnumber = mysql_num_fields(res);

    i = 0;
    while (row = mysql_fetch_row(res)) {
        asprintf(&strtmp, "%s,%s", row[1], row[3]);
        paraHash = ELFHash(strtmp);
        kvinsert(atoi(row[0]), strtmp, paraHash);

        maxkvid = atoi(row[0]);

        i++;
        /*
		for (i = 0; i < fieldsnumber; i++)
		{
			//printf("%s\t", row[i]);
		}
        //printf("\n");
        */
        //asprintf(&strtmp, "%s,%s", row[1], row[3]);
        //printf("%s\n", strtmp);
    } 

    mysql_free_result(res);
    mysql_close(sock);

    //printf("%d\n", maxkvid);
    //kvview();
}
