import sys
import os

sys.path.append("../")
from send_request import send_request
import config


# test rfc7230 section 5.4 Host


def test_post_not_allowed() -> str:
    request_header = "POST / HTTP/1.1\r\nHost: xx\r\n\r\n"
    http_response = send_request(request_header)
    if http_response.status != 405:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "405"
        )
    return ""


def test_post() -> str:
    request_header = "POST /post/post.html HTTP/1.1\r\nHost: xx\r\nContent-Length: 12\r\n\r\nPOST REQUEST"
    http_response = send_request(request_header)
    if http_response.status != 201:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "201"
        )
    if http_response.headers["Location"] != "/post/tmp/post.html":
        return "Bad Location header: {}, expected: {}".format(
            http_response.headers["Location"], "/post/tmp/post.html"
        )
    try:
        f = open("www/tmp/post.html", "r")
    except:
        return "Error: file not created"
    line = f.readline()
    # print(line)
    f.close()
    if line != "POST REQUEST":
        return "Bad content: {}, expected: {}".format(line, "POST REQUEST")

    request_header = "POST /post/post.html HTTP/1.1\r\nHost: xx\r\nContent-Length: 22\r\n\r\n, ANOTHER POST REQUEST"
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    try:
        f = open("www/tmp/post.html", "r")
    except:
        return "Error: file not created"
    line = f.readline()
    print(line)
    f.close()
    if line != "POST REQUEST, ANOTHER POST REQUEST":
        return "Bad content: {}, expected: {}".format(
            line, "POST REQUEST, ANOTHER POST REQUEST"
        )
    return ""


def test_cgi_headers() -> str:
    request_header = "POST /post/test.cgi HTTP/1.1\r\nHost: xx\r\nEvery-Letter-Should-Change-To_Upcase: HELLOOOOO\r\nContent-Length: 16\r\n\r\nHello from body!"
    http_response = send_request(request_header)
    if http_response.status != 226:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "226"
        )
    if http_response.headers["Content-Type"] != "CGI/MINE":
        return "Bad content-type: {}, expected: {}".format(
            http_response.headers["Content-Type"], "CGI/MINE"
        )
    body = http_response.read().decode("UTF-8")
    if (
        body.find("HTTP_EVERY_LETTER_SHOULD_CHANGE_TO_UPCASE=HELLOOOOO") == -1
        or body.find("HTTP_HOST=xx") == -1
        or body.find("Hello from body!") == -1
    ):
        return "Missing headers from request"
    # print(body)
    return ""


def test_cgi_auth_headers() -> str:
    request_header = (
        request_header
    ) = "GET /protected/print.cgi?name=fredrika&age=22 HTTP/1.1\r\nHost:{}\r\nAuthorization: {}\r\n\r\n".format(
        config.SERVER_NAME, config.AUTH_KEY
    )
    http_response = send_request(request_header)
    if http_response.status != 226:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "226"
        )
    body = http_response.read().decode("UTF-8")
    # print(body)
    if (
        body.find("AUTH_TYPE=Basic") == -1
        or body.find("REMOTE_IDENT=Admin") == -1
        or body.find("REMOTE_USER=Admin") == -1
        or body.find("QUERY_STRING=name=fredrika&age=22") == -1
    ):
        return "Missing headers from request"
    # print(body)
    return ""
