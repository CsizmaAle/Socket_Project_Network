package Classes;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    public static void main(String[] args) {

        try{
            System.out.println("Server waiting for clients...");

            ServerSocket serverSocket = new ServerSocket(9806);
            serverSocket.setReuseAddress(true);
            Socket sck=null;

            while(true)
            {

                sck=serverSocket.accept();
                System.out.println("Client connected");
                ClientHandler clientSocket=new ClientHandler(sck);
                new Thread(clientSocket).start();
            }

        }catch (Exception e){
            e.printStackTrace();
        }

    }
}
