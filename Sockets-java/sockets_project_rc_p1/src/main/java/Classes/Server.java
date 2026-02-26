package Classes;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    public static void main(String[] args) {

        try{
            System.out.println("Server waiting for clients...");
            int clientID=0;

            ServerSocket serverSocket = new ServerSocket(9806);
            serverSocket.setReuseAddress(true);
            Socket sck=null;

            while(true)
            {
                sck=serverSocket.accept();
                System.out.println("Client " + clientID + " connected");
                ClientHandler clientSocket=new ClientHandler(sck, clientID);
                new Thread(clientSocket).start();
                clientID++;
            }

        }catch (Exception e){
            e.printStackTrace();
        }

    }
}
