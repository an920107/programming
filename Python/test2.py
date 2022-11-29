<<<<<<< HEAD
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
=======
from datetime import datetime
from socket import socket, AF_INET, SOCK_STREAM
import threading
import json

connection_list = []

def send_all(name, type, message):
    global connection_list
    time = datetime.now().strftime("%H:%M:%S")
    tosend = f'{{"name":{name},"type":{type},"time":"{time}","message":"{message}"}}\n'
    print(f'[{name}] {message} ({time})')
    for conn in connection_list:
        conn.send(tosend.encode())

def connection(conn: socket, addr):
    global connection_list
    connection_list.append(conn)
    conn.settimeout(10)
    first_flag = True
    try:
        while True:
            data = json.loads(conn.recv(1024).decode())
            online = data["online"]
            if (online == -1):
                break
            elif (online == 1):
                send_all(data["name"], 1, data["message"])
            elif (online == 0):
                if (first_flag):
                    send_all(data["name"], 0, "Joined the chatting room.")
                    first_flag = False
    except:
        pass
    send_all(data["name"], 0, "Left the chatting room.")
    connection_list.remove(conn)
    conn.close()
    print(f"[SERVER] Disconnected from {str(addr)}")

server = socket(AF_INET, SOCK_STREAM)
server.bind(("0.0.0.0", 22222))
server.listen(5)

while True:
    (conn, addr) = server.accept()
    print(f"[SERVER] New connection from {str(addr)}")
    threading.Thread(target= connection, args= (conn, addr)).start()
>>>>>>> 1a197e9ccd16a1a8eb8aca10c3ef491b6940a5b4
