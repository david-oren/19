"""
The run_test function is a wrapper for your test.
Your test should be a function that takes a port as an int, and returns a string, empty if the test is
successfull, containing the reason of the failure if failed.
"""
import os
import sys

from send_request import send_request
from testcase.content_length import *
from testcase.header_field import *
from testcase.host import *
from testcase.request_line import *
from testcase.http_version_not_supported import test_http_version
from testcase.get import *
from testcase.post import *
from testcase.put import *
from testcase.chunked import *

from typing import Callable
from tests import *
import config

# import colors
# color letters
RESET = "\033[0m"

C_BLACK = "\033[30m"
C_RED = "\033[31m"
C_GREEN = "\033[32m"
C_YELLOW = "\033[33m"
C_BLUE = "\033[34m"
C_MAGENTA = "\033[35m"
C_CYAN = "\033[36m"
C_WHITE = "\033[37m"
C_GRAY = "\033[90m"
# color letters Gras
C_B_BLACK = "\033[30;01m"
C_B_RED = "\033[31;01m"
C_B_GREEN = "\033[32;01m"
C_B_YELLOW = "\033[33;01m"
C_B_BLUE = "\033[34;01m"
C_B_MAGENTA = "\033[35;01m"
C_B_GRAY = "\033[36;01m"
C_B_WHITE = "\033[37;01m"
C_B_GRAY = "\033[90;01m"
# color background
B_BLACK = "\033[40m"
B_RED = "\033[41m"
B_GREEN = "\033[42m"
B_YELLOW = "\033[43m"
B_BLUE = "\033[44m"
B_MAGENTA = "\033[45m"
B_GRAY = "\033[46m"
B_WHITE = "\033[47m"
B_GRAY = "\033[100m"


def cleanup() -> None:
    """
    Remove file created by the tester to make sure the test is new every run.
    """
    os.system("rm -rf www/tmp/*")
    os.system("rm -rf www/long.txt")


def run_test(test_name: str, test: Callable) -> None:
    """
    Runs a test defined in function test, with the name test_name,
    and prints wether it passed or not.
    """
    try:
        result = test()
    except:
        print(
            "{}Cannot connect to the server on port {}{}".format(
                C_B_RED, config.SERVER_PORT, RESET
            )
        )
        exit(1)
    char = ""
    color = C_GREEN
    if len(result) == 0:
        char = "✅"
    else:
        color = C_RED
        char = "❌"
    print(r"{:40} {}{} {}{}".format(test_name, color, char, result, RESET))


def run() -> None:
    """
    Entrypoint of the tester
    """
    print(r"{}{}### TESTING HEAD ###{}".format(C_B_WHITE, B_GRAY, RESET))
    run_test("HEAD /", test_head)
    print(r"{}{}### TESTING GET ###{}".format(C_B_WHITE, B_GRAY, RESET))
    run_test("GET /", test_get)
    run_test("GET /a/", test_get_dir_index)
    run_test("GET /virtual/a/", test_get_dir_not_allowed)
    run_test("GET /b, checking custom 404 page", test_custom_404)
    run_test("GET /doidjo...", test_404)
    run_test("GET /index/a/", test_autoindex)
    run_test("100 GET /", test_multiple_get)
    run_test("GET with different index", test_different_index)
    run_test("GET / on port 8080 and 8081", test_multiple_ports)
    run_test("     /auto, Host: default_server", test_get_dir_no_index)
    run_test("     /auto, Host: google.com", test_get_dir_autoindex)
    run_test("         /, Host: google.com", test_get_dir_index)
    run_test("/auto/file, Accept-Language: fr", test_content_neg_lang)
    run_test("/auto/file, Accept-Language: en-US, fr", test_content_neg_lang_double)
    run_test("/auto/file, Accept-Charset: ", test_content_neg_charset)
    run_test("/auto/file, Accept-Charset: utf-8", test_content_neg_charset_utf8)

    run_test("PUT /a/long.txt", test_big_put)
    run_test("POST /a/long.txt", test_big_post)

    print(r"{}{}### TESTING POST ###{}".format(C_B_WHITE, B_GRAY, RESET))
    run_test("POST /", test_wrong_post)
    run_test("/", test_post_not_allowed)
    run_test("/post/tmp/a.html * 2", test_post)
    run_test("POST /post/test too big payload", test_too_big_request)
    run_test("POST /test.cgi ", test_cgi_headers)
    run_test("GET /protected/print.cgi ", test_cgi_auth_headers)

    print(r"{}{}### TESTING CHUNKED ###{}".format(C_B_WHITE, B_GRAY, RESET))
    run_test("Testing read content & trailer", test_chunked_w_trailer)
    run_test("00000", test_chunked_multiplezeros)
    run_test("000;dude", test_ChunkExtensionNoValue)
    run_test("000;dude", test_ChunkExtensionUnquotedValue)
    run_test("000;Foo=Bar", test_MultipleChunkExtensions)
    run_test("0", test_DecodeEmptyBodyInPieces)
    run_test("0\\r\\n\\r\\nHello!", test_DecodeEmptyBodyWithExtraStuffAfter)
    run_test("F\\r\\nHello, World!!!", test_DecodeThreeChunksOnePiece)
    run_test("0\\r\\nX-Foo Bar", test_DecodeBadTrailer)

    print(r"{}{}### TESTING PUT ###{}".format(C_B_WHITE, B_GRAY, RESET))
    run_test("/", test_put_not_allowed)
    run_test("/post/tmp/a.html * 2", test_put)
    run_test("POST /post/test too big payload", test_too_big_request)
    run_test("PUT /post/c * 2", test_two_puts)

    print(r"{}{}### TESTING DELETE ###{}".format(C_B_WHITE, B_GRAY, RESET))
    run_test("PUT /post/test, DELETE /post/test", test_delete)
    run_test("DELETE /post/gone", test_delete_no_file)

    print(r"{}{}### TESTING REQUEST LINE ###{}".format(C_B_WHITE, B_GRAY, RESET))
    run_test("GET / HTTP/0.1", test_http_version)
    run_test("GET  /  HTTP/1.1", test_request_line_multiple_space)
    run_test("GET /{A*10^10} HTTP/1.1", test_request_line_too_long)

    print(r"{}{}### TESTING HEADERS ###{}".format(C_B_WHITE, B_GRAY, RESET))
    run_test("Testing mandatory headers", test_headers)
    run_test("Testing protected realm", test_auth_no_key)
    run_test("Testing protected realm access", test_auth)
    run_test("Testing case insensitive", test_case_insensitive)
    print(r"{}1. testing host header:{}".format(C_CYAN, RESET))
    run_test("GET / HTTP/1.1\\r\\n\\r\\n", test_missing_host)
    run_test("Host: naver.com\\r\\nHost: hyeyoo.com", test_double_host)
    run_test("Host: xxx\\r\\nHost: xxx", test_multiple_host)
    run_test("Host: hyeyoo@hyeyoo.com", test_invalid_host)
    print(r"{}2. testing content-length header{}".format(C_CYAN, RESET))
    run_test("Content-Length: -1", test_neg_content_length)
    run_test("Content-Length: 10^20", test_big_content_length)
    run_test("Content-Length: NOTDIGIT", test_alpha_content_length)
    run_test("Content-Length & Chunked", test_length_and_chunked)
    run_test("Content-Length * 2", test_double_length)
    print(r"{}3. testing headers{}".format(C_CYAN, RESET))
    run_test("GET / HTTP/1.1\\r\\nHost :", test_space_before_colon)
    run_test("GET / HTTP/1.1\\r\\n: empty", test_missing_header_name)
    run_test("GET / HTTP/1.1\\r\\nUser-Agent: {A*10^11}", test_header_too_long)


if __name__ == "__main__":
    cleanup()
    run()
