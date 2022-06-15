import java.util.Random;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

class createText{
    public static char fun(){//random function
        char c;
        Random rd=new Random();
        int a=rd.nextInt(97,113);// left ≤ x ＜ right
        int b=rd.nextInt(0,27);//a-z和空格等概率生成
        if(b==0){
            c=(char)(32);
        }else{
            c=(char)a;
        }
        return c;
    }
    public static void writeFile(String str){//write file
        File file=new File("./", "wordcount.txt");
        try{
            if(!file.exists()){
                file.createNewFile();//create if the file doesn't exist
            }
            FileOutputStream output =new FileOutputStream(file,true);//add to but not cover
            byte[] bytes=str.getBytes();
            output.write(bytes);
            output.close();
            System.out.println("write succeed");
        }catch(IOException e){
            e.printStackTrace();
        }
    }
    public static void Main(){
        String str="";
        for(int i=0;i<=20000;i++){
            str+=fun();
        }
        writeFile(str);
    }
}