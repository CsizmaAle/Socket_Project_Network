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
                       "; port sursa: " + sck.getLocalPort() +
                       "; port destinatie: "+ sck.getPort()+
                       "; adresa IP sursa: " + sck.getLocalAddress().getHostAddress()+
                       "; adresa IP destinatie: "+ sck.getInetAddress().getHostAddress());
            }while(!"exit".equalsIgnoreCase(message));

        }catch(Exception e){
            System.out.println(e);
        }

    }

}
