import sys
sys.path.append('../')
# from http.client import HTTPResponse
import config
from send_request import send_request

# test rfc7230 section 2.6: Protocol Versioning


def test_http_version() -> str:
    request_header = 'GET / HTTP/0.1\r\nHost:{}\r\n\r\n'.format(
        config.SERVER_NAME)
    http_response = send_request(request_header)
    if http_response.status != 505 and http_response.status // 100 != 4:
        return "Bad status code: {}, expected: {}".format(str(http_response.status), '505 or 4XX')
    return ""
