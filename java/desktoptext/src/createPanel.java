package classes;
import javax.swing.JPanel;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class createPanel extends JPanel {
    public createPanel(){
        this.setOpaque(true);
    }    
    public createPanel(JFrame frame){
        this.setSize(frame.getWidth(),frame.getHeight());
    }
}
