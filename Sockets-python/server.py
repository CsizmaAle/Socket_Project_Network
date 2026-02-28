
import socket

host=socket.gethostname()
serverSocket = socket.socket()
serverSocket.bind((host, 9806))
serverSocket.listen(3)

clientID = 0

print('Server waiting for clients...\n')

connection, adress=serverSocket.accept()
print('Client ' + clientID + ' connected\n')
clientID+=1

while True:
    
    
    
    
    



