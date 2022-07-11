from datetime import datetime
from plot import genHTML
import socket


def printTime(s= ""):
    print("[" + datetime.now().strftime("%H:%M:%S") + "] ", end= "")
    if (s == ""): return
    print(s)

HOST = "0.0.0.0"
PORT = 9217

soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
soc.bind((HOST, PORT))
soc.listen(3)

while True:

    conn, addr = soc.accept()
    printTime("NEW CONNECTION FROM " + str(addr))

    read_in = conn.recv(1024).decode().strip("\n\r")
    trader_id = read_in.split("-")[0]
    trader_pair = read_in.split("-")[1]
    printTime("CLIENT: " + trader_id + trader_pair)

    try:
        genHTML(trader_id, trader_pair)
        html_file = open("html/%s-%s.html" % (trader_id, trader_pair), "r")
        html_file_lines = html_file.readlines()
    except:
        conn.send("ERROR\n".encode())
        printTime("SERVER: ERROR")
        conn.close()
        continue

    printTime("SERVER: " + "BEGIN")
    conn.send("BEGIN\n".encode())

    for line in html_file_lines:
        line = line.strip("\n\r")
        printTime("HTML: " + line)
        conn.send((line + "\n").encode())

    conn.send("END\n".encode())
    printTime("SERVER: END")
    conn.close()
