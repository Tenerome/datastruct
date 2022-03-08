package search;

import java.awt.AWTException;
import java.awt.Color;
import java.awt.Image;
import java.awt.Menu;
import java.awt.MenuItem;
import java.awt.PopupMenu;
import java.awt.SystemTray;
import java.awt.TrayIcon;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.event.MouseMotionListener;
import java.io.IOException;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JMenuItem;
import javax.swing.JTextArea;
import javax.swing.ImageIcon;
import java.awt.Font;
import javax.swing.JScrollPane;
import java.awt.Rectangle;

public class win extends JFrame {
	public static win frame = new win();
	JPanel CPane;
	String search="https://www.baidu.com/s?wd=";
	JLabel label;
	JTextArea text = new JTextArea();
	SystemTray systemTray = SystemTray.getSystemTray();
	TrayIcon trayIcon;
	JScrollPane scrollPane;
	private static final long serialVersionUID = 1L;//���ڴ�������϶�
	int xOld = 0;
	int yOld = 0;
	Rectangle rec = new Rectangle (50,50,300,24); 
	//main
	public static void main(final String[] args) {
		frame.setVisible(true);
		//frame.setShape(new RoundRectangle2D.Double(0,0,frame.getWidth(),frame.getHeight(),13D,5D));
	}

	// ���췽��
	public win() {
		// �������
		setResizable(true);
		setBounds(rec);
		//setBounds(100, 100, 600, 48);
		setUndecorated(true); // ȥ�߿�
		//setBackground(new Color(0, 0, 0, 0)); // frame͸��
		CPane = new JPanel();
		CPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(CPane);
		CPane.setLayout(null);
		//CPane.setBackground(new Color(0, 0, 0, 0)); // CPane͸��
		label = new JLabel("T");
		label.setForeground(Color.white);
		label.setFont(new Font("Imprint MT Shadow", Font.PLAIN, 26));
		label.setBounds(2, 0, 24, 24);
		CPane.add(label);
		text.setForeground(Color.black.darker().brighter().brighter().brighter());
		text.setFont(new Font("������", Font.PLAIN, 18));
		text.setBounds(24, 0, 272, 24);
		text.setBorder(null);
		scrollPane = new JScrollPane();
		scrollPane.setBorder(null);
		scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_NEVER);
		scrollPane.setBounds(26, 0, 275, 26);
		CPane.add(scrollPane);
		setOpacity(0.6f); // ����͸����
		//frame.setBackground(new Color(0,0,0,0));
		setType(JFrame.Type.UTILITY); // ȥ��������ͼ��
		scrollPane.setViewportView(text);
		// ****************����ʵ��*******************//
		adddrag();
		addsearch();
		setTray();
		textpopmenu();
	}

	// *********************����*****************************//
	// �������϶�
	public void adddrag() {
		this.addMouseListener(new MouseAdapter() {
			public void mousePressed(final MouseEvent e) {
				xOld = e.getX();
				yOld = e.getY();
			}
		});
		this.addMouseMotionListener((MouseMotionListener) new MouseMotionAdapter() {
			public void mouseDragged(final MouseEvent e) {
				final int xOnScreen = e.getXOnScreen();
				final int yOnScreen = e.getYOnScreen();
				final int xx = xOnScreen - xOld;
				final int yy = yOnScreen - yOld;
				win.this.setLocation(xx, yy);
			}
		});
	}

	// ������Ŀո�ת��Ϊ+
	public String content(final String content) {
		if (content == null) {
			return "";
		}
		return content.replaceAll(" ", "+");
	}

	public void setnull() {
		// if (text.getText().trim().equals(""))
		// 	text.setText("");
		// else if (text.getText().trim().equals(""))
		// 	text.setText("");
		// else if (text.getText().trim().equals(""))
		// 	text.setText("");
		// else
		text.setText("");
	}

	// traypopupMenu
	public void traypopmenu() {
		// �����˵�
		final PopupMenu PM = new PopupMenu();
		final MenuItem S1 = new MenuItem("AlwaysOnTop"); // ����ǰ��
		PM.add(S1);
		final Menu M = new Menu("Engine");
		PM.add(M); // ����Ӳ˵�
		final MenuItem m1 = new MenuItem("Google");
		M.add(m1);
		final MenuItem m2 = new MenuItem("Baidu��");
		M.add(m2);
		final MenuItem m3 = new MenuItem("Sougou");
		M.add(m3);
		final MenuItem m4 = new MenuItem("360");
		M.add(m4);
		final MenuItem m5 = new MenuItem("Bing");
		M.add(m5);
		final Menu M2 = new Menu("Style"); // TODO ����
		PM.add(M2);
		final MenuItem m21 = new MenuItem("White��");
		M2.add(m21);
		final MenuItem m22 = new MenuItem("Black");
		M2.add(m22);
		final MenuItem m23 = new MenuItem("Gray");
		M2.add(m23);
		final MenuItem m24 = new MenuItem("Green");
		M2.add(m24);
		final MenuItem m25 = new MenuItem("Blue");
		M2.add(m25);
		final MenuItem m26 = new MenuItem("Yellow");
		M2.add(m26);
		final MenuItem m27 = new MenuItem("Pink");
		M2.add(m27);
		final MenuItem m28 = new MenuItem("Purple");
		M2.add(m28);
		final Menu M3 = new Menu("Size");
		PM.add(M3);
		final MenuItem m31 = new MenuItem("Small��");
		M3.add(m31);
		final MenuItem m32 = new MenuItem("Medium");
		M3.add(m32);
		final MenuItem m33 = new MenuItem("Large");
		M3.add(m33);
		PM.addSeparator(); // ��ӷָ���
		final MenuItem m6 = new MenuItem("Exit");
		PM.add(m6);
		// ����ǰ��
		S1.addActionListener(new ActionListener() {

			int i = 0;

			public void actionPerformed(final ActionEvent e) {
				i = i + 1;
				if (i % 2 == 1) {
					frame.setAlwaysOnTop(true);
					S1.setLabel("AlwaysOnTop��");
				} else if (i % 2 == 0) {
					frame.setAlwaysOnTop(false);
					S1.setLabel("AlwaysOnTop");
				}
			}
		});
		// ���������л�
		M.addActionListener(new ActionListener() {
			public void actionPerformed(final ActionEvent e) {
				switch (e.getActionCommand()) {
					case "Google": {
						search = "http://www.google.com/search?q=";
						m1.setLabel("Google��");
						m2.setLabel("Baidu");
						m3.setLabel("Sougou");
						m4.setLabel("360");
						m5.setLabel("Bing");
					}
						break;
					case "Baidu": {
						search = "https://www.baidu.com/s?wd=";
						m1.setLabel("Google");
						m2.setLabel("Baidu��");
						m3.setLabel("Sougou");
						m4.setLabel("360");
						m5.setLabel("Bing");
					}
						break;
					case "Sougou": {
						search = "https://www.sogou.com/web?query=";
						m1.setLabel("Google");
						m2.setLabel("Baidu");
						m3.setLabel("Sougou��");
						m4.setLabel("360");
						m5.setLabel("Bing");
					}
						break;
					case "360": {
						search = "https://www.so.com/s?q=";
						m1.setLabel("Google");
						m2.setLabel("Baidu");
						m3.setLabel("Sougou");
						m4.setLabel("360��");
						m5.setLabel("Bing");
					}
						break;
					case "Bing": {
						search = "https://cn.bing.com/search?q=";
						m1.setLabel("Google");
						m2.setLabel("Baidu");
						m3.setLabel("Sougou");
						m4.setLabel("360");
						m5.setLabel("Bing��");
					}
						break;
				}
			}
		});
		// �˳�
		m6.addActionListener(new ActionListener() {
			public void actionPerformed(final ActionEvent e) {
				System.exit(0);
			}
		});
		// �л���ʽ
		M2.addActionListener(new ActionListener() {
			public void actionPerformed(final ActionEvent e) {
				switch (e.getActionCommand()) {
					case "White": {
						setWhite();
						m21.setLabel("White��");
						m22.setLabel("Black");
						m23.setLabel("Gray");
						m24.setLabel("Green");
						m25.setLabel("Blue");
						m26.setLabel("Yellow");
						m27.setLabel("Pink");
						m28.setLabel("Purple");
					}
						break;
					case "Black": {
						setBlack();
						m21.setLabel("White");
						m22.setLabel("Black��");
						m23.setLabel("Gray");
						m24.setLabel("Green");
						m25.setLabel("Blue");
						m26.setLabel("Yellow");
						m27.setLabel("Pink");
						m28.setLabel("Purple");
					}
						break;
					case "Gray": {
						setGray();
						m21.setLabel("White");
						m22.setLabel("Black");
						m23.setLabel("Gray��");
						m24.setLabel("Green");
						m25.setLabel("Blue");
						m26.setLabel("Yellow");
						m27.setLabel("Pink");
						m28.setLabel("Purple");
					}
						break;
					case "Green": {
						setGreen();
						m21.setLabel("White");
						m22.setLabel("Black");
						m23.setLabel("Gray");
						m24.setLabel("Green��");
						m25.setLabel("Blue");
						m26.setLabel("Yellow");
						m27.setLabel("Pink");
						m28.setLabel("Purple");
					}
						break;
					case "Blue": {
						setBlue();
						m21.setLabel("White");
						m22.setLabel("Black");
						m23.setLabel("Gray");
						m24.setLabel("Green");
						m25.setLabel("Blue��");
						m26.setLabel("Yellow");
						m27.setLabel("Pink");
						m28.setLabel("Purple");
					}
						break;
					case "Yellow": {
						setYellow();
						m21.setLabel("White");
						m22.setLabel("Black");
						m23.setLabel("Gray");
						m24.setLabel("Green");
						m25.setLabel("Blue");
						m26.setLabel("Yellow��");
						m27.setLabel("Pink");
						m28.setLabel("Purple");
					}
						break;
					case "Pink": {
						setPink();
						m21.setLabel("White");
						m22.setLabel("Black");
						m23.setLabel("Gray");
						m24.setLabel("Green");
						m25.setLabel("Blue");
						m26.setLabel("Yellow");
						m27.setLabel("Pink��");
						m28.setLabel("Purple");
					}
						break;
					case "Purple": {
						setPurple();
						m21.setLabel("White");
						m22.setLabel("Black");
						m23.setLabel("Gray");
						m24.setLabel("Green");
						m25.setLabel("Blue");
						m26.setLabel("Yellow");
						m27.setLabel("Pink");
						m28.setLabel("Purple��");
					}
						break;
				}
			}
		});
		M3.addActionListener(new ActionListener() {
			public void actionPerformed(final ActionEvent e) {
				switch (e.getActionCommand()) {
					case "Small": {
						rec=new Rectangle(frame.getX(),frame.getY(),300,24);
						frame.setBounds(rec);
						label.setBounds(0, 0, 24, 24);
						scrollPane.setBounds(24, 0, 273, 24);
						text.setBounds(24, 0, 272, 24);
						label.setFont(new Font("Imprint MT Shadow", Font.PLAIN,frame.getHeight()+2));
						text.setFont(new Font("������", Font.PLAIN, frame.getHeight()-6));
						m31.setLabel("Small��");
						m32.setLabel("Medium");
						m33.setLabel("Large");
					}
						break;
					case "Medium": {
						rec=new Rectangle(frame.getX(),frame.getY(),375,30);
						frame.setBounds(rec);
						label.setBounds(0, 0, 30, 30);
						scrollPane.setBounds(30, 0, 345, 30);
						text.setBounds(30, 0, 340, 30);
						label.setFont(new Font("Imprint MT Shadow", Font.PLAIN,frame.getHeight()+2));
						text.setFont(new Font("������", Font.PLAIN, frame.getHeight()-6));
						m31.setLabel("Small");
						m32.setLabel("Medium��");
						m33.setLabel("Large");
					}
						break;
					case "Large": {
						rec=new Rectangle(frame.getX(),frame.getY(),450,36);
						frame.setBounds(rec);
						label.setBounds(0, 0, 36, 36);
						scrollPane.setBounds(36, 0, 414, 36);
						text.setBounds(36, 0, 410, 36);
						label.setFont(new Font("Imprint MT Shadow", Font.PLAIN,frame.getHeight()+2));
						text.setFont(new Font("������", Font.PLAIN, frame.getHeight()-6));
						m31.setLabel("Small");
						m32.setLabel("Medium");
						m33.setLabel("Large��");
					}
						break;
				}
			}
		});
		trayIcon.setPopupMenu(PM);
	}

	// ����ϵͳ����
	public void setTray() {
		final ImageIcon icon = new ImageIcon(this.getClass().getResource("tuopan.png"));
		final Image image = icon.getImage(); // ��ȡͼƬ
		trayIcon = new TrayIcon(image); // ��������ͼ��
		trayIcon.setToolTip("Tenero����"); // ��ӹ�����ʾ�ı�
		traypopmenu();
		// ����ʵ��
		try {
			systemTray.add(trayIcon); // �������ͼ��
		} catch (final Exception e) {
			e.printStackTrace();
		}
	}

	// �س�������
	public void addsearch() {
		text.addKeyListener(new KeyAdapter() {
			public void keyTyped(final KeyEvent e) {
				if ((char) e.getKeyChar() == KeyEvent.VK_ENTER) {
					final String cmd = "cmd.exe /c start ";
					final String file = search + content(text.getText());
					try {
						Runtime.getRuntime().exec(cmd + file);
						setnull();
					} catch (final IOException ignore) {
						ignore.printStackTrace();
					}
				}
			}
		});
	}

	public void textpopmenu() {
		final JPopupMenu PM = new JPopupMenu();
		final JMenuItem m1 = new JMenuItem("Tray��");
		PM.add(m1);
		m1.addActionListener(new ActionListener() {
			int i = 0;

			public void actionPerformed(ActionEvent e) {
				i = i + 1;
				if (i % 2 == 1) {
					systemTray.remove(trayIcon);
					m1.setText("Tray");
				} else if (i % 2 == 0) {
					try {
						systemTray.add(trayIcon);
					} catch (final AWTException e1) {
						e1.printStackTrace();
					}
					m1.setText("Tray��");
				}
				
			}
		});
		text.setComponentPopupMenu(PM);
	}
	
	public void setWhite() {
		  label.setForeground(Color.white);
		  text.setBackground(Color.white);        //TODO ���text����͸�����ı���������
		  text.setText("");
		  text.setForeground(Color.black.darker().darker());
	}
	public void setBlack() {
		  label.setForeground(Color.black);
		  text.setBackground(Color.black);
		  text.setText("");
		  text.setForeground(Color.white.brighter().brighter());
	}
	public void setGray() {
		  label.setForeground(Color.gray);
		  text.setBackground(Color.gray);
		  text.setText("");
		  text.setForeground(Color.black.darker().darker());
	}
	public void setGreen() {
		  label.setForeground(new Color(164,211,164));
		  text.setBackground(new Color(164,211,164));
		  text.setText("");
		  text.setForeground(Color.black.darker().darker());
	}
	public void setBlue() {
		  label.setForeground(new Color(164,204,211));
		  text.setBackground(new Color(164,204,211));
		  text.setText("");
		  text.setForeground(Color.black.darker().darker());
	}
	public void setYellow() {
		  label.setForeground(new Color(211,204,164));
		  text.setBackground(new Color(211,204,164));
		  text.setText("");
		  text.setForeground(Color.black.darker().darker());
	
	}
	public void setPink() {
		  label.setForeground(new Color(211,164,172));
		  text.setBackground(new Color(211,164,172));
		  text.setText("");
		  text.setForeground(Color.black.darker().darker());
	}
	public void setPurple() {
		  label.setForeground(new Color(187,164,211));
		  text.setBackground(new Color(187,164,211));
		  text.setText("");
		  text.setForeground(Color.black.darker().darker()); 
	}
	//end
	}


