package Classes;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    public static void main(String[] args) {

        try{
            System.out.println("Server waiting for clients...");

            ServerSocket serverSocket = new ServerSocket(9806);
            Socket sck=serverSocket.accept();

            System.out.println("Client connected!");

            InputStreamReader isr=new InputStreamReader(sck.getInputStream());
            BufferedReader serverIn=new BufferedReader(isr);

            String message=serverIn.readLine();
            System.out.println(message);

            OutputStream os = sck.getOutputStream();
            PrintWriter serverOut = new PrintWriter(os, true);

            serverOut.println("Messaje: "+ message);


        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
