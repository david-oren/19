import sys
import os

sys.path.append("../")
from send_request import send_request
import config
from http.client import HTTPResponse
import socket


def test_chunked_w_trailer() -> str:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((config.SERVER_ADDR, config.SERVER_PORT))
    request_header = "POST /post/print.cgi HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\n"
    client.send(request_header.encode())
    request_header = "5\r\ntest\n\r\n"
    client.send(request_header.encode())
    request_header = "0\r\naccept-language: fr\r\ntest-header: blabla\r\n\r\n"
    client.send(request_header.encode())

    # read and parse http response
    http_response = HTTPResponse(client)
    http_response.begin()
    if http_response.status != 226:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "226"
        )
    if http_response.headers["Content-Type"] != "CGI/MINE":
        return "Bad content-type: {}, expected: {}".format(
            http_response.headers["Content-Type"], "CGI/MINE"
        )
    body = http_response.read().decode("UTF-8")
    # print(body)
    if (
        body.find("HTTP_TEST_HEADER=blabla") == -1
        or body.find("HTTP_ACCEPT_LANGUAGE=fr") == -1
    ):
        return "Missing headers from request"
    if body.find("test") == -1:
        return "Missing content in request"
    # print(body)
    return ""


def test_chunked_multiplezeros() -> str:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((config.SERVER_ADDR, config.SERVER_PORT))
    request_header = "POST /post/print.cgi HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\n"
    client.send(request_header.encode())
    request_header = "5\r\ntest\n\r\n"
    client.send(request_header.encode())
    request_header = "00000\r\n\r\n"
    client.send(request_header.encode())

    # read and parse http response
    http_response = HTTPResponse(client)
    http_response.begin()
    if http_response.status != 226:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "226"
        )
    # print(body)
    return ""


def test_ChunkExtensionNoValue() -> str:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((config.SERVER_ADDR, config.SERVER_PORT))
    request_header = "POST /post/print.cgi HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\n"
    client.send(request_header.encode())
    request_header = "5\r\ntest\n\r\n000;dude\r\n\r\n"
    client.send(request_header.encode())

    # read and parse http response
    http_response = HTTPResponse(client)
    http_response.begin()
    if http_response.status != 226:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "226"
        )
    # print(body)
    return ""


def test_ChunkExtensionUnquotedValue() -> str:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((config.SERVER_ADDR, config.SERVER_PORT))
    request_header = "POST /post/print.cgi HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\n"
    client.send(request_header.encode())
    request_header = "5\r\ntest\n\r\n"
    client.send(request_header.encode())
    request_header = "000;dude=best\r\n\r\n"
    client.send(request_header.encode())

    # read and parse http response
    http_response = HTTPResponse(client)
    http_response.begin()
    if http_response.status != 226:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "226"
        )
    # print(body)
    return ""


def test_MultipleChunkExtensions() -> str:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((config.SERVER_ADDR, config.SERVER_PORT))
    request_header = "POST /post/print.cgi HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\n"
    client.send(request_header.encode())
    request_header = '000;Foo=Bar;dude="The dude is the best";Spam=12345!\r\n\r\n'
    client.send(request_header.encode())

    # read and parse http response
    http_response = HTTPResponse(client)
    http_response.begin()
    if http_response.status != 226:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "226"
        )
    # print(body)
    return ""


def test_DecodeEmptyBodyInPieces() -> str:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((config.SERVER_ADDR, config.SERVER_PORT))
    request_header = "POST /post/print.cgi HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\n"
    client.send(request_header.encode())
    request_header = "0"
    client.send(request_header.encode())
    request_header = "\r"
    client.send(request_header.encode())
    request_header = "\n"
    client.send(request_header.encode())
    request_header = "\r"
    client.send(request_header.encode())
    request_header = "\n"
    client.send(request_header.encode())

    # read and parse http response
    http_response = HTTPResponse(client)
    http_response.begin()
    if http_response.status != 226:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "226"
        )
    # print(body)
    return ""


def test_DecodeEmptyBodyWithExtraStuffAfter() -> str:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((config.SERVER_ADDR, config.SERVER_PORT))
    request_header = "POST /post/print.cgi HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\n"
    client.send(request_header.encode())
    request_header = "0\r\n\r\nHello!"
    client.send(request_header.encode())
    # read and parse http response
    http_response = HTTPResponse(client)
    http_response.begin()
    if http_response.status != 226:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "226"
        )
    body = http_response.read().decode("UTF-8")
    if body.find("Hello!") != -1:
        return "Read too much content"
    return ""


def test_DecodeThreeChunksOnePiece() -> str:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((config.SERVER_ADDR, config.SERVER_PORT))
    request_header = "POST /post/print.cgi HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\n"
    client.send(request_header.encode())
    request_header = "F\r\nHello, World!!!\r\n7\r\nIt's me\r\n0\r\n\r\n"
    client.send(request_header.encode())

    # read and parse http response
    http_response = HTTPResponse(client)
    http_response.begin()
    if http_response.status != 226:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "226"
        )
    body = http_response.read().decode("UTF-8")
    if body.find("Hello, World!!!It's me") == -1:
        return "Missing content 'Hello, World!!!It's me' "
    return ""


def test_DecodeBadTrailer() -> str:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((config.SERVER_ADDR, config.SERVER_PORT))
    request_header = "POST /post/print.cgi HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\n"
    client.send(request_header.encode())
    request_header = "0\r\nX-Foo Bar\r\n\r\n"
    client.send(request_header.encode())

    # read and parse http response
    http_response = HTTPResponse(client)
    http_response.begin()
    if http_response.status != 400:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "400"
        )
    return ""
