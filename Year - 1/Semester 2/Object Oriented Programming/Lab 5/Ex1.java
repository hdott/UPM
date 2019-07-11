import java.awt.BorderLayout;
import java.awt.Color;

import javax.swing.*;

public class Ex1
{
    public static void main(String[] args)
    {
        JFrame f = new JFrame("My Hello Window");
        f.setSize(500, 500);

        f.add(new JButton("PAGE_START"), BorderLayout.PAGE_START);
        f.add(new JButton("LINE_START"), BorderLayout.LINE_START);
        f.add(new JButton("CENTER"), BorderLayout.CENTER);
        f.add(new JButton("LINE_END"), BorderLayout.LINE_END);
        f.add(new JButton("PAGE_END"), BorderLayout.PAGE_END);
        
        f.pack();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}