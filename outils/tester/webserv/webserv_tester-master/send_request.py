import sys

sys.path.append("../")
from http.client import HTTPResponse
import socket
import config


def send_request(request_header: str) -> str:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((config.SERVER_ADDR, config.SERVER_PORT))
    client.send(request_header.encode())
    # read and parse http response
    http_response = HTTPResponse(client)
    http_response.begin()
    return http_response


def regex_match(request_header: str) -> str:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((config.SERVER_ADDR, config.SERVER_PORT))
    client.send(request_header.encode())
    # read and parse http response
    http_response = HTTPResponse(client)
    http_response.begin()
    return http_response
