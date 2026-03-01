import socket
import threading

def clientHandler(connection, address, clientID):
    while True:
        message=connection.recv(1024).decode()
        if(message!=""):
            print('From client ' + str(clientID) + ': ' + message + '; port sursa: '+ str(address[-1]) + ';  port destinatie: '+ str(connection.getsockname()[-1])  + '; adresa IP sursa: '+ str(address[0]) + ';  adresa IP destinatie: '+ str(connection.getsockname()[0]) +'\n')
            connection.send(message.encode())
        if message.lower().strip() == 'exit':
            print('Client ' + str(clientID) + ' disconnected\n')
            connection.close()
            break

host=socket.gethostname()
serverSocket = socket.socket()
serverSocket.bind((host, 9806))
serverSocket.listen(3)

clientID = 0
print('Server waiting for clients...\n')

while True:
    connection, adress=serverSocket.accept()
    print('Client ' + str(clientID) + ' connected\n')
    thread = threading.Thread(target=clientHandler, args=(connection, adress, clientID))
    thread.start()
    clientID+=1  
    
    
    
