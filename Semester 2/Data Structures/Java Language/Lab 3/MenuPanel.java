import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class MenuPanel extends JPanel
{
    private static final long serialVersionUID = 1L;

    public MenuPanel(JFrame frame)
    {
        var leftMenu = new JPanel(new GridLayout(0, 1, 2, 2));
        leftMenu.setSize(200, 100);

        Buttons addButton = new Buttons(Color.BLUE, "Adauga");
        Buttons delButton = new Buttons(Color.BLUE, "Sterge");
        Buttons schButton = new Buttons(Color.BLUE, "Cauta");

        leftMenu.add(addButton);
        leftMenu.add(delButton);
        leftMenu.add(schButton);
        
        frame.add(leftMenu, BorderLayout.WEST);
    }
}