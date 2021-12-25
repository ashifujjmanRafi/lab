import java.io.*;
import java.net.*;

public class server1{
    public static ServerSocket ss;
    public static Socket s;
    public static DataInputStream din;
    public static DataOutputStream dout;
    public static void main(String[] args){
        try{

            ss = new ServerSocket(8080);
            s = ss.accept();
            System.out.println("Server is connected");
            din = new DataInputStream(s.getInputStream());
            dout = new DataOutputStream(s.getOutputStream());
            String str;
            while(true){
                str = (String) din.readUTF();
                System.out.println("client: " + str);
                if(str.equals("stop"))
                    break;
                else if(str.equals("list")){
                    File currDir = new File(".");
                    getListFiles(currDir);
                    dout.writeUTF(" ");
                    dout.flush();
                }
            }
            System.out.println("closing the server");
            dout.close();
            ss.close();
        }
        catch(Exception e){
            System.out.println(e);
        }
       
    }
     public static void getListFiles(File curDir){
            try{
                File[] filesList = curDir.listFiles();
                for(File file : filesList){
                    dout.writeUTF(file.getPath()+ "/");
                    dout.flush();
                }
            }
            catch(Exception e){
                System.out.println("error "+e);
            }
        }




}