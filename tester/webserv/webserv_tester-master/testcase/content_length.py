import sys

sys.path.append("../")
import config
from send_request import send_request

# test rfc7230 section 3.3.2: Content Length


def test_neg_content_length() -> str:
    length = "-1"
    request_header = "GET / HTTP/1.1\r\nHost:{}\r\nContent-Length: {}\r\n\r\n".format(
        config.SERVER_NAME, length
    )
    http_response = send_request(request_header)
    if http_response.status != 400:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "400"
        )
    return ""


def test_big_content_length() -> str:
    length = "100000000000000000000000"
    request_header = "GET / HTTP/1.1\r\nHost:{}\r\nContent-Length: {}\r\n\r\n".format(
        config.SERVER_NAME, length
    )
    http_response = send_request(request_header)
    if http_response.status != 400:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "400"
        )
    return ""


def test_alpha_content_length() -> str:
    length = "NOTDIGIT"
    request_header = "GET / HTTP/1.1\r\nHost:{}\r\nContent-Length: {}\r\n\r\n".format(
        config.SERVER_NAME, length
    )
    http_response = send_request(request_header)
    if http_response.status != 400:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "400"
        )
    return ""


def test_length_and_chunked() -> str:
    request_header = "GET / HTTP/1.1\r\nHost:{}\r\nContent-Length: 10000\r\nTransfer-Encoding: chunked\r\n\r\n0\r\n\r\n".format(
        config.SERVER_NAME
    )
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    return ""


def test_double_length() -> str:
    request_header = "GET / HTTP/1.1\r\nHost:{}\r\nContent-Length: 1\r\nContent-Length: 0\r\n\r\n".format(
        config.SERVER_NAME
    )
    http_response = send_request(request_header)
    if http_response.status != 400:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    return ""


def test_big_put() -> str:
    len = 100000000  # 10M
    request_header = (
        "PUT /put/long.txt HTTP/1.1\r\nHost:{}\r\nContent-Length: {}\r\n\r\n{}".format(
            config.SERVER_NAME, len, ("X" * len)
        )
    )
    http_response = send_request(request_header)
    if http_response.status != 201:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "201"
        )
    return ""


def test_big_post() -> str:
    len = 100000000  # 10M
    request_header = (
        "POST /put/long.txt HTTP/1.1\r\nHost:{}\r\nContent-Length: {}\r\n\r\n{}".format(
            config.SERVER_NAME, len, ("X" * len)
        )
    )
    http_response = send_request(request_header)
    if http_response.status // 100 != 2:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "2XX"
        )
    return ""
