#include <stdio.h>
#include <windows.h>

#include "mongoose.h"

#pragma comment(lib, "Ws2_32.lib")

static int result = 0;

static void show_index(
    struct mg_connection *conn,
    const struct mg_request_info *request_info,
    void *user_data)
{
    mg_printf(conn, "%s",
        "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n"
        "Hello world!");
}

static void multiply(
    struct mg_connection *conn,
    const struct mg_request_info *request_info,
    void *user_data)
{
    char *multiplier_s   = mg_get_var(conn, "multiplier");
    char *multiplicand_s = mg_get_var(conn, "multiplicand");

    int multiplier   = atol(multiplier_s);
    int multiplicand = atol(multiplicand_s);

    result = multiplier * multiplicand;

    mg_printf(conn,
        "HTTP/1.1 200 OK\r\n\
Content-Type: text/plain\r\n\r\n");

    mg_free(multiplier_s);
    mg_free(multiplicand_s);
}


static void get_result(
    struct mg_connection *conn,
    const struct mg_request_info *request_info,
    void *user_data)
{
    mg_printf(conn,
        "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n%d",
        result);
}
int main()
{
    struct mg_context *ctx = mg_start();
    mg_set_option(ctx, "ports", "33333");

    mg_set_uri_callback(ctx, "/",         &show_index, 0);
    mg_set_uri_callback(ctx, "/multiply", &multiply,   0);
    mg_set_uri_callback(ctx, "/result",   &get_result, 0);

    getchar();
    mg_stop(ctx);

    return 0;
}
