import sys

sys.path.append("../")
from send_request import send_request
import config

# test rfc7230 section 5.4 Host


def test_get_dir_no_index() -> str:
    request_header = "GET /auto HTTP/1.1\r\nHost: {}\r\n\r\n".format(config.SERVER_NAME)
    http_response = send_request(request_header)
    if http_response.status != 404:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    return ""


def test_get_dir_autoindex() -> str:
    request_header = "GET /auto HTTP/1.1\r\nHost: {}\r\n\r\n".format(config.SERVER_NAME3)
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    body = http_response.read().decode("UTF-8")
    index = body.find("file.html")
    if index == -1:
        return "Bad auto index: {}, expected: {}".format(str(body), "file.html")
    return ""


def test_get_dir_index() -> str:
    request_header = "GET / HTTP/1.1\r\nHost: {}\r\n\r\n".format(config.SERVER_NAME3)
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    body = http_response.read().decode("UTF-8")
    if body != "google":
        return "Bad content: {}, expected: {}".format(str(body), "google")
    return ""


def test_content_neg_lang() -> str:
    request_header = (
        "GET /auto/file HTTP/1.1\r\nHost: {}\r\nAccept-Language: fr\r\n\r\n".format(config.SERVER_NAME3)
    )
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    body = http_response.read().decode("UTF-8")
    # print(body)
    if body.find("fr") == -1:
        return "Bad content: {}, expected: {}".format(str(body), "html fr utf-8")
    if http_response.headers["Content-Language"] != "fr":
        return "Missing Content-Language header"
    return ""


def test_content_neg_lang_double() -> str:
    request_header = "GET /auto/file HTTP/1.1\r\nHost: {}\r\nAccept-Language: en-US, fr\r\n\r\n".format(config.SERVER_NAME3)
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    body = http_response.read().decode("UTF-8")
    if body.find("fr") == -1:
        return "Bad content: {}, expected: {}".format(str(body), "html fr")
    if http_response.headers["Content-Language"] != "fr":
        return "Missing Content-Language with value of 'fr'"
    return ""


def test_content_neg_charset() -> str:
    request_header = (
        "GET /auto/file HTTP/1.1\r\nHost: {}\r\nAccept-Charset: \r\n\r\n".format(config.SERVER_NAME3)
    )
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    body = http_response.read().decode("UTF-8").splitlines()
    if body[0].find("utf-8") != -1:
        return "Bad content: '{}', expected: '{}'".format(str(body[0]), "html")
    return ""


def test_content_neg_charset_utf8() -> str:
    request_header = (
        "GET /auto/file HTTP/1.1\r\nHost: {}\r\nAccept-Charset: utf-8 \r\n\r\n".format(config.SERVER_NAME3)
    )
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    body = http_response.read().decode("UTF-8").splitlines()
    if body[0].find("utf-8") == -1:
        return "Bad content: '{}', expected: '{}'".format(str(body[0]), "html xx utf-8")
    if http_response.headers["Content-Type"] != "text/html; charset=utf-8":
        return "Expected Content-Language header with value of 'text/html; charset=utf-8', actual: {}".format(
            http_response.headers["Content-Type"]
        )
    return ""
