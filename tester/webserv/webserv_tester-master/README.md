# **42 WEBSERV TESTER**

This is a simple python tester built upon [@tommarx](https://github.com/t0mm4rx/webserv/tree/main/tests)'s and [@hygioni](https://github.com/hygoni/webserv_tester)'s. It will test:

- RFC: request line syntax checking, headers,
- Basic HTTP methods: GET, POST, PUT, DELETE and HEAD
- Status codes
- Basic cgi
- Server name matching
- Routing
- Authentification
- Chunked transfer encoding
- Mandatory headers

Run with `sudo python3 main.py` on ubuntu. Make sure that any changes of ports and server names will be updated in the config.py as well.
