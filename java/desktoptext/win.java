import src.circlelink.circlelink;
import src.createFrame.createFrame;
import src.createLabel.createLabel;
import src.createPanel.createPanel;
import src.createPopupmenu.createPopupmenu;
import src.rwFile.rwFile;

//托盘
import javax.swing.ImageIcon;//可以优化
import java.awt.TrayIcon;
import java.awt.SystemTray;
import java.awt.Image;

public class win{
    public static createFrame frame=new createFrame();
    public static createPanel panel=new createPanel();
    public static createLabel label=new createLabel();
    public static circlelink clink=new circlelink();
    public static createPopupmenu traypopmenu=new createPopupmenu();
    public static TrayIcon trayicon;

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

    public static void setPopmenu(){//弹出菜单
        createPopupmenu.setNext(clink,label);//静态访问函数
        createPopupmenu.setColorchooser(panel,label);
        createPopupmenu.setExit();
        trayicon.setPopupMenu(traypopmenu);
    }

    public static void startPage(){
        panel.add(label);
        frame.add(panel);
        addTray();
        setPopmenu(); 
    }
    public static void main(String[] args) {
        // startPage();
        clink.init();
        String path="./lib";
        new rwFile(path);
        rwFile.initlink(clink);
    } 

}