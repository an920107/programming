import socket

connected_addr = []

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("0.0.0.0", 11111))
server.listen(5)

while True:
    conn, addr = server.accept()
    conn.settimeout(1000)
    print(f"[SERVER] New connection from {str(addr)}")
    connected_addr.append(addr)
    data = conn.recv(1024)
    print(data.decode())
    conn.send("connect".encode())
    conn.close()