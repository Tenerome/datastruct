package classes;
import java.awt.PopupMenu;
import java.awt.MenuItem;
<<<<<<< HEAD
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
=======
// import java.awt.event.ActionEvent;
// import java.awt.event.ActionListener;
>>>>>>> d0d786b6d1b3c502d5a42ee8ac5b9a7a77a91fb4
import java.awt.Color;
import java.awt.TrayIcon;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JColorChooser;

public class createPopupmenu extends PopupMenu{
    public MenuItem mnext=new MenuItem("Next message");
    public MenuItem mlib=new MenuItem("Library");
    public MenuItem mcolor=new MenuItem("Color");
    public MenuItem mexit=new MenuItem("Exit");
    public createPopupmenu(){
       
        this.add(mnext);
        this.add(mlib);
        this.add(mcolor);
        this.add(mexit);
        // trayicon.setPopupMenu(popmenu);

        // mnext.addActionListener(new ActionListener(){//下一个
        //     circlelink clink2=clink;
        //     public void actionPerformed(ActionEvent e){
        //         clink2=clink2.getNext();
        //         label.setText(clink2.getNext().getData());
        //     }
        // });
        // mcolor.addActionListener(new ActionListener(){//颜色
        //     public void actionPerformed(ActionEvent e){
        //         Color color=JColorChooser.showDialog(panel,"选取颜色", null);
        //         label.setForeground(color);
        //     }
        // });

        // mexit.addActionListener(new ActionListener(){//退出
        //     public void actionPerformed(ActionEvent e){
        //         System.exit(0);
        //     }
        // });
        
    }
}
