import socket

host=socket.gethostname()
port=9806

clientSocket = socket.socket()
clientSocket.connect((host, port))

messaje=input("Enter message: ")

while messaje.lower().strip() != 'exit':
    clientSocket.send(messaje.encode())
    response = clientSocket.recv(1024).decode()
    print('From server: ' + response + '; port sursa: '+ str(clientSocket.getpeername()[-1]) + ';  port destinatie: '+ str(clientSocket.getsockname()[-1])  + '; adresa IP sursa: '+ str(clientSocket.getpeername()[0]) + ';  adresa IP destinatie: '+ str(clientSocket.getsockname()[0]) +'\n')
    messaje=input("Enter message: ")

clientSocket.send(messaje.encode())
clientSocket.close()