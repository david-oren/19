import sys
import os

sys.path.append("../")
from send_request import send_request
import config

# test rfc7230 section 5.4 Host


def test_put_not_allowed() -> str:
    request_header = "PUT / HTTP/1.1\r\nHost: xx\r\n\r\n"
    http_response = send_request(request_header)
    if http_response.status != 405:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "405"
        )
    return ""


def test_put() -> str:
    request_header = "PUT /post/put.html HTTP/1.1\r\nHost: xx\r\nContent-Length: 11\r\n\r\nPUT REQUEST"
    http_response = send_request(request_header)
    if http_response.status != 201:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "201"
        )
    if http_response.headers["Location"] != "/post/tmp/put.html":
        return "Bad Location header: {}, expected: {}".format(
            http_response.headers["Location"], "/post/tmp/put.html"
        )
    try:
        f = open("www/tmp/put.html", "r")
    except:
        return "Error: file not created"
    line = f.readline()
    # print(line)
    f.close()
    if line != "PUT REQUEST":
        return "Bad content: {}, expected: {}".format(line, "PUT REQUEST")

    request_header = "PUT /post/put.html HTTP/1.1\r\nHost: xx\r\nContent-Length: 19\r\n\r\nANOTHER PUT REQUEST"
    http_response = send_request(request_header)
    if http_response.status != 204:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "204"
        )
    try:
        f = open("www/tmp/put.html", "r")
    except:
        return "Error: file not created"
    line = f.readline()
    # print(line)
    f.close()
    if line != "ANOTHER PUT REQUEST":
        return "Bad content: {}, expected: {}".format(line, "ANOTHER PUT REQUEST")
    return ""
