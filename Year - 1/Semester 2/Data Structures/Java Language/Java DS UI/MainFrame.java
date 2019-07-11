import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.ScrollPane;
import java.awt.TextField;
import java.awt.Toolkit;
import java.awt.Window;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.SwingUtilities;

public class MainFrame extends JFrame{

    private static final long serialVersionUID = 1L;
    private LinkedList linkedList;
    private JPanel lista;
    private JPanel listaControl;
    private JScrollPane listaScroll;
    private AVLTree avlTree;
    private JPanel avlTreePanel;
    private JPanel avlTreeControl;
    private JScrollPane avlTreeScrool;

    public MainFrame() {
        setSize(Toolkit.getDefaultToolkit().getScreenSize().width/2,
                Toolkit.getDefaultToolkit().getScreenSize().height/2);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);

        
        /*
         * Jpanel to hold the buttons on the WEST side of the main frame
         */
        var buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(15, 1));
        add(BorderLayout.WEST, buttonPanel);

        /*
         * Linked List
         */
        linkedList = new LinkedList();
        lista = new JPanel();
        lista.setLayout(new GridLayout(100, 1));
        listaScroll = new JScrollPane(lista, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
                                    JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        listaControl = new LinkedListPanel();
        
        /*
         * Linked List Button
         */
        var linkedListButton = new JButton("Linked List");
        linkedListButton.addActionListener(l -> {
            Container contentPane = getContentPane();
            contentPane.add(BorderLayout.CENTER, listaScroll);
            contentPane.add(BorderLayout.EAST, listaControl);
            contentPane.revalidate();
            contentPane.repaint();
        });
        buttonPanel.add(linkedListButton);

        /*
         * Linked List Control Panel
         */
        var linkedListControlPanel = new JPanel();
        linkedListControlPanel.setLayout(new GridLayout(15, 1));


        /*
         * Doubly Linked List Button
         */
        var doublyLLbutton = new JButton("Doubly Linked List");
        buttonPanel.add(doublyLLbutton);

        /*
         * AVL Tree
         */
        avlTree = new AVLTree();
        avlTreePanel = new JPanel();
        avlTreePanel.setLayout(null);
        avlTreeScrool = new JScrollPane(avlTreePanel, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
                                    JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        avlTreeControl = new AVLTreePanel();
        
        /*
         * AVL Tree Button
         */
        var avlTreeButton = new JButton("AVL Tree");
        avlTreeButton.addActionListener(l -> {
            Container contentPane = getContentPane();
            // contentPane.remove(contentPaneBorderLayout.CENTER);
            // contentPane.remove(contentPane.BorderLayout.EAST);
            contentPane.add(BorderLayout.CENTER, avlTreeScrool);
            contentPane.add(BorderLayout.EAST, avlTreeControl);
            contentPane.revalidate();
            contentPane.repaint();
        });
        buttonPanel.add(avlTreeButton);
    }

    class LinkedListPanel extends JPanel{

        private static final long serialVersionUID = 1L;

        public LinkedListPanel() {
            setLayout(new GridLayout(15, 1));

            /*
             * Nume, Prenume, Varsta textfields
             */
            var numeTF = new TextField("Nume");
            this.add(numeTF);

            var prenumeTF = new TextField("Prenume");
            add(prenumeTF);

            var varstaTF = new TextField("Varsta");
            add(varstaTF);

            /*
             * Add Buttons
             */
            var addFirst = new JButton("Adauga la Inceput");
            addFirst.addActionListener(al -> {
                if (numeTF.getText().equals("") ||
                    prenumeTF.getText().equals("") ||
                    varstaTF.getText().equals("")) {
                    if (numeTF.getText().equals("")){
                        numeTF.setText("empty");
                    }

                    if (prenumeTF.getText().equals("")){
                        prenumeTF.setText("empty");
                    }
                    
                    if (varstaTF.getText().equals("")) {
                        varstaTF.setText("empty");                        
                    }

                    add(new JLabel("Campuri Goale!"), 0);
                } else {
                    linkedList.insertStart(new Person(numeTF.getText(), prenumeTF.getText(),
                                    Integer.parseInt(varstaTF.getText())));
                    lista.removeAll();
                    var iterator = linkedList.getIterator();
                    do {
                        lista.add(new JLabel(iterator.person.toString()));
                        iterator = linkedList.getNext(iterator);
                    } while (linkedList.hasNext(iterator));

                    

                    

                    add(new JLabel("Persoana Adaugata!"));
                    numeTF.setText("Nume");
                    prenumeTF.setText("Prenume");
                    varstaTF.setText("Varsta");
                    revalidate();
                    repaint();
                }
            });
            add(addFirst);

            // var addEnd = new JButton("Adauga la Sfarsit");
            // addEnd.addActionListener(al -> {
            //     if (numeTF.getText().equals("") ||
            //         prenumeTF.getText().equals("") ||
            //         varstaTF.getText().equals("")) {
            //         if (numeTF.getText().equals("")){
            //             numeTF.setText("empty");
            //         }

            //         if (prenumeTF.getText().equals("")){
            //             prenumeTF.setText("empty");
            //         }
                    
            //         if (varstaTF.getText().equals("")) {
            //             varstaTF.setText("empty");                        
            //         }

            //         add(new JLabel("Campuri Goale!"), 0);
            //     } else {
            //         lista.insertEnd(new Person(numeTF.getText(), prenumeTF.getText(),
            //                         Integer.parseInt(varstaTF.getText())));
            //         lista.buildList();

            //         add(new JLabel("Persoana Adaugata!"));
            //         numeTF.setText("Nume");
            //         prenumeTF.setText("Prenume");
            //         varstaTF.setText("Varsta");
            //     }
            // });
            // add(addEnd);
            
        }
    }

    class AVLTreePanel extends JPanel {

        private static final long serialVersionUID = 1L;

        public AVLTreePanel() {
            setLayout(new GridLayout(15, 1));

            var numarTF = new TextField("int");
            add(numarTF);

            var insert = new JButton("Adauga");
            insert.addActionListener(l -> {
                avlTree.head = avlTree.insert(avlTree.head, Integer.parseInt(numarTF.getText()));
                
                // int width = avlTreePanel.getWidth();
                int x = getContentPane().getWidth()/3;
                int y = 5;
                // var label = new JLabel("4");
                // label.setBounds(x, y, 170, 100);
                // avlTreePanel.add(label);
                // avlTreePanel.revalidate();
                // avlTreePanel.repaint();
                avlTreePanel.removeAll();
                buildTree(avlTree.head, x, y);
                numarTF.setText("int");
                avlTreePanel.revalidate();
                avlTreePanel.repaint();
            });
            add(insert);


        }

        public void buildTree(Node node, int x, int y) {
            if (node == null){
                System.out.println("null");
            }
            if (node != null) {
                var label = new JLabel(String.valueOf(node.nr));
                label.setBounds(x, y, 170, 100);
                avlTreePanel.add(label);
                System.out.println(label);
                buildTree(node.left, x-12, y+20);
                buildTree(node.right, x+12, y+20);
            }
        }
    }
}