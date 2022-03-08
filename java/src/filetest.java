import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class filetest {
    public static void main(String[] args) {
        File file=new File("./", "config.ini");
        //写文件
        try{
            if(!file.exists()){
                file.createNewFile();//如果不存在就创建
            }
            FileOutputStream output =new FileOutputStream(file);
            byte[] bytes="can i help you?".getBytes();
            output.write(bytes);
            output.close();
            System.out.println("write succeed");
        }catch(IOException e){
            e.printStackTrace();
        }
        //读文件
        try {
            FileInputStream input=new FileInputStream(file);
            byte[] bytes2=new byte[1024];
            int length=input.read(bytes2);
            System.out.println("文本的信息是："+new String(bytes2,0,length));
            input.close();
            System.out.println("读文件成功");
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
