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

        var addButton = new Buttons(Color.BLUE, "Adauga", leftMenu);
        var delButton = new Buttons(Color.BLUE, "Sterge", leftMenu);
        var schButton = new Buttons(Color.BLUE, "Cauta", leftMenu);
        
        frame.add(leftMenu, BorderLayout.WEST);
    }
}