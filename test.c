/* Simple C program that connects to MySQL Database server*/
#include <mysql.h>
#include <stdio.h>

void main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "192.168.3.3";
    char *user = "unsis";
    char *password = "some_pass"; /* set me first */
    char *database = "cursoplatzi";
    conn = mysql_init(NULL);
    /* Connect to database */
    if (!mysql_real_connect(conn, server,
            user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    /* send SQL query */
    if (mysql_query(conn, "show tables")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    res = mysql_use_result(conn);
    /* output table name */
    printf("MySQL Tables in mysql database:\n");
    while ((row = mysql_fetch_row(res)) != NULL)
        printf("%s \n", row[0]);
    /* close connection */
    mysql_free_result(res);
    mysql_close(conn);
}

// Compiler: gcc -o test $(mysql_config --cflags) test.c $(mysql_config -–libs)
// Ubuntu unsis: unsis:CETI
// WSL user: 192.168.3.3:ome_pass