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

            String message=null;

            while(!"exit".equalsIgnoreCase(message)){
                System.out.println("Enter text:");
                message=userIn.readLine();

                PrintWriter userOut=new PrintWriter(os, true);

                //userOut.print("De la server: ");
                userOut.println(message);

               System.out.println("De la server:" + userIn2.readLine());
            }

        }catch(Exception e){
            System.out.println(e);
        }

    }

}
