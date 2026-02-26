package Classes;

import java.io.*;
import java.net.Socket;

public class ClientHandler implements Runnable{

    private final Socket clientSocket;

    public ClientHandler(Socket socketClient)
    {
        this.clientSocket = socketClient;
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
                System.out.println("De la client: " + message1);
            }
        }catch(Exception e) {
            System.out.println(e);
            System.out.println("Client connection lost!");
        }
    }
}
