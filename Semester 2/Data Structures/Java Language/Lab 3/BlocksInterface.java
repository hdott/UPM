import java.awt.BorderLayout;
import java.awt.Color;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class BlocksInterface
{
    public BlocksInterface()
    {
        var frame = new JFrame("Cartiere si Persoane");
        frame.setSize(1000, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setBackground(Color.WHITE);
        frame.add(new MenuPanel(frame), BorderLayout.LINE_START);
        // frame.add(new Buttons(Color.GREEN, "TEST"), BorderLayout.LINE_START);

        frame.setVisible(true);
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(()   ->
        {
            new BlocksInterface();
        });
    }
}