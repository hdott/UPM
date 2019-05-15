import java.awt.Color;

import javax.swing.JButton;
import javax.swing.JPanel;

public class Buttons extends JButton
{
    private static final long serialVersionUID = 1L;

    public Buttons(Color color, String name, JPanel panel)
    {
        var button = new JButton(name);
        button.setBackground(color);

        panel.add(button);
    }
}