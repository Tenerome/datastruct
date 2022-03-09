<<<<<<< HEAD
public class createLabel {
=======
package classes;
import javax.swing.JLabel;

import javax.swing.JLabel;
import java.awt.Font;
import java.awt.Color;
public class createLabel extends JLabel{
    public createLabel(){
        this.setText("海内存知己，天涯若比邻");
        Color cc=Color.black.darker().darker().darker().darker();
        this.setForeground(cc.darker().darker().darker());//设置颜色可选
        this.setBackground(new Color(200,0,200));
        this.setFont(new Font("新宋体",Font.PLAIN,30));
    }
>>>>>>> d0d786b6d1b3c502d5a42ee8ac5b9a7a77a91fb4
    
}
