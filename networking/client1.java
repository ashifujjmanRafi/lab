import java.io.*;
import java.net.*;
import java.util.Scanner;

public class client1{
    public static Socket s;
    public static DataInputStream din;
    public static DataOutputStream dout;

    public static void main(String[] args){
        try{
            s= new Socket("localhost",8080);
            din = new DataInputStream(s.getInputStream());
            dout = new DataOutputStream(s.getOutputStream());
            String str;
            Scanner sn= new Scanner(System.in);
            while(true){
                System.out.println("Message is:");
                str = sn.nextLine();
                dout.writeUTF(str);
                dout.flush();
                if(str.equals("stop")){
                    break;
        
                }
                else if(str.equals("list")){
                    getListFiles();
                }
            }
            dout.close();
            s.close();
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
    public static void getListFiles(){
        try{
            System.out.println("server runnig");
            while(true){
                String temp = (String) din.readUTF();
                System.out.println(temp);
                if(temp.equals(" ")){
                    break;
                }
            }
            System.out.println("server ended");
        }
        catch(Exception e) {
      System.out.println("Something went wrong...\n" + e);
    }
    }
}