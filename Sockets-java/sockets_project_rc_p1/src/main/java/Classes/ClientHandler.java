package Classes;

import java.io.*;
import java.net.Socket;

public class ClientHandler implements Runnable{

    private final Socket clientSocket;
    private final int clientID;

    public ClientHandler(Socket socketClient, int clientID)
    {
        this.clientSocket = socketClient;
        this.clientID = clientID;
    }

    public void run(){
        try{

            InputStreamReader isr=new InputStreamReader(clientSocket.getInputStream());
            BufferedReader serverIn=new BufferedReader(isr);

            OutputStream os = clientSocket.getOutputStream();
            PrintWriter serverOut = new PrintWriter(os, true);

            String message1=null;

            while(true){
                message1=serverIn.readLine();
                serverOut.println(message1);
                System.out.println("Message from client" + clientID + ": " + message1 +
                        "; port sursa: " + clientSocket.getPort() +
                        "; port destinatie: "+ clientSocket.getLocalPort()+
                        "; adresa IP sursa: " + clientSocket.getInetAddress().getHostAddress()+
                        "; adresa IP destinatie: "+ clientSocket.getLocalAddress().getHostAddress());
            }
        }catch(Exception e) {
            System.out.println(e);
            System.out.println("Client connection lost!");
        }
    }
}
