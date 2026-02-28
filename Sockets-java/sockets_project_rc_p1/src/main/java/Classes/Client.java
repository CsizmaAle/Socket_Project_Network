package Classes;

import java.io.*;
import java.net.Socket;

public class Client {

    public static void main(String[] args) {

        try{
            System.out.println("Client started");
            Socket sck=new Socket("localhost",9806);

            InputStreamReader isr=new InputStreamReader(System.in);
            BufferedReader userIn=new BufferedReader(isr);

            OutputStream os=sck.getOutputStream();

            InputStreamReader isr2=new InputStreamReader(sck.getInputStream());
            BufferedReader userIn2=new BufferedReader(isr2);

            PrintWriter userOut=new PrintWriter(os, true);

            String message=null;

            do{
                System.out.print("Enter message: ");
                message=userIn.readLine();

                if(message.equalsIgnoreCase("exit"))break;

                userOut.println(message);

               System.out.println("Message from server:" + userIn2.readLine() +
                       "; port sursa: " + sck.getPort() +
                       "; port destinatie: "+ sck.getLocalPort()+
                       "; adresa IP sursa: " + sck.getInetAddress().getHostAddress()+
                       "; adresa IP destinatie: "+ sck.getLocalAddress().getHostAddress());
            }while(!"exit".equalsIgnoreCase(message));

        }catch(Exception e){
            System.out.println(e);
        }

    }

}
