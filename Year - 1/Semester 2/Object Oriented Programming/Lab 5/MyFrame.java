import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.Image;

import javax.swing.*;
import javax.swing.text.GapContent;

public class MyFrame
{
    private String _title;

    public MyFrame(String title)
    {
        this._title = title;
    }

    public void createFrame()
    {
        JFrame f = new JFrame(_title);
        f.setSize(500, 500);
        f.setLayout(new GridLayout(3, 2, 5, 5));
        f.setVisible(true);

        JLabel username = new JLabel("Username:");
        JLabel password = new JLabel("Password:");

        JTextField enterU = new JTextField("username");
        JTextField enterP = new JTextField("password");
        
        JButton login = new JButton("Login");


        f.getContentPane().add(username);
        f.getContentPane().add(enterU);

        f.getContentPane().add(password);
        f.getContentPane().add(enterP);

        f.getContentPane().add(login, BorderLayout.PAGE_END);

        ImageIcon iconLogo = new ImageIcon(new ImageIcon("./cdss-store-login-icon.png").getImage().getScaledInstance(30, 30, Image.SCALE_DEFAULT));
        // ImageIcon inconLogo = new ImageIcon("./cdss-store-login-icon.png");
        // Image image = inconLogo.getImage();
        // Image newimg = image.getScaledInstance(10, 10, java.awt.Image.SCALE_SMOOTH);
        // inconLogo = new ImageIcon(newimg);

        JLabel img = new JLabel();
        img.setIcon(iconLogo);

        f.getContentPane().add(img);
        
        f.pack();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}