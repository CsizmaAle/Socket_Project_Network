package Classes;

import java.io.*;
import java.net.Socket;

public class Client1 {

    public static void main(String[] args) {

        try{
            System.out.println("Client1 started");
            Socket sck=new Socket("localhost",9806);

            InputStreamReader isr=new InputStreamReader(System.in);
            BufferedReader userIn=new BufferedReader(isr);
            System.out.println("Enter text:");
            String message=userIn.readLine();

            OutputStream os=sck.getOutputStream();
            PrintWriter userOut=new PrintWriter(os, true);

            userOut.println(message);

            InputStreamReader isr2=new InputStreamReader(sck.getInputStream());
            BufferedReader userIn2=new BufferedReader(isr2);
            System.out.println(userIn2.readLine());


        }catch(Exception e){
            System.out.println(e);
        }

    }

}
