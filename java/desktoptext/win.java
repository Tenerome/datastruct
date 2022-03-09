import classes.*;
//窗口组件
// import javax.swing.JFrame;
// import javax.swing.JPanel;
// import javax.swing.JLabel;
// import javax.swing.JButton;//to delete

// import javax.swing.JColorChooser;
import javax.swing.ImageIcon;//可以优化

//其他组件
// import java.awt.Rectangle;
// import java.awt.Dimension;
// import java.awt.Color;
// import java.awt.Font;
//托盘
import java.awt.TrayIcon;
import java.awt.SystemTray;
import java.awt.Image;
//菜单
// import java.awt.PopupMenu;
// import java.awt.MenuItem;
//事件监听
// import java.awt.event.ActionEvent;
// import java.awt.event.ActionListener;

//文件io
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class win{
    public static createFrame frame=new createFrame();
    public static createPanel panel=new createPanel();
    public static createLabel label=new createLabel();
    public static circlelink clink=new circlelink();
    public static createPopupmenu traypopmenu=new createPopupmenu();
    public static TrayIcon trayicon;

    public static void writeFile(){//写文件
        clink.init();
        clink.add("倚楼听戏，临池赏尽浮灯月华，惊鸿刹那，见你秋波恍如倾世桃花。");
        clink.add("山之高，月出小，月之小，何皎皎，我有所思在远道，一日不见兮，我心悄悄。");
        clink.add("醉过才知酒浓，爱过才知情重。你不能做我的诗，正如我不能做你的梦。");
        clink.add("最幸福不过是，你曾温柔呼唤，而我恰好有过应答。");
        clink.add("不知道这漫天的雨是谁碎了的心，只是在这多雨的季节诗意般落下。");
        clink.add("不是蝴蝶飞不过沧海，而是彼岸已经没有了期待。");
    }
    public static String readFile(){//读文件
        File file=new File("./lib/dtbin1.ini");
        String str=new String();
        try{
            FileInputStream input =new FileInputStream(file);
            byte[] bytes=new byte[1024];
            int length=input.read(bytes);
            str=new String(bytes,0,length);
            input.close();
        }catch(Exception e){
            e.printStackTrace();
        }
        return str;
    }

    public static void addTray(){//托盘图标
        ImageIcon icon=new ImageIcon("logo/tray.png");
        Image image=icon.getImage();
        SystemTray systemTray=SystemTray.getSystemTray();
        trayicon=new TrayIcon(image);
        trayicon.setToolTip("DesktopText");
        try {
            systemTray.add(trayicon);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void setPopmenu(){
        traypopmenu.setNext(clink,label);
        traypopmenu.setColorchooser(panel,label);
        traypopmenu.setExit();
        trayicon.setPopupMenu(traypopmenu);
    }

    public static void startPage(){
        panel.add(label);
        frame.add(panel);
        writeFile();
        addTray();
        setPopmenu(); 
    }
    public static void main(String[] args) {
        startPage();
    } 

}