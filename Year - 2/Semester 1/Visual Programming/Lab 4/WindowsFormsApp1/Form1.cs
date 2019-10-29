using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        private List<string> list = new List<string>();
        private SQLiteHandler dbHandler = null;

        public Form1()
        {
            InitializeComponent();
            webBrowser1.Navigate("www.google.ro");
        }

        private void logEvent(string str)
        {
            string msg = DateTime.Now.ToString("MM\\/dd\\/yy h\\:mm:ss:ms");
            msg += " Event: ";
            msg += str;

            Logging.Instance.Log(msg);
        }

        private void toolStripNavigate_Click(object sender, EventArgs e)
        {
            webBrowser1.Navigate(toolStripTextBox1.Text);

            logEvent("Button pressed [Navigate]");
        }

        private void toolStripBack_Click(object sender, EventArgs e)
        {
            webBrowser1.GoBack();

            logEvent("Button pressed [Back]");
        }

        private void toolStripForward_Click(object sender, EventArgs e)
        {
            webBrowser1.GoForward();

            logEvent("Button pressed [Forward]");
        }

        private void toolStripHome_Click(object sender, EventArgs e)
        {
            webBrowser1.Navigate("www.google.ro");

            logEvent("Button pressed [Home]");
        }

        private void toolStripTextBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                toolStripNavigate_Click(sender, new EventArgs());
                e.SuppressKeyPress = true;
            }
        }

        private void webBrowser1_Navigating(object sender, WebBrowserNavigatingEventArgs e)
        {
            bool alreadyBlocked = false;
            if(list.Count != 0)
            {
                foreach(string x in list){
                    if (e.Url.ToString().Contains(x))
                    {
                        alreadyBlocked = true;
                        e.Cancel = true;
                        MessageBox.Show("This website has been blocked for you: " + e.Url,
                            "Access Denied!", MessageBoxButtons.OK, MessageBoxIcon.Stop);
                        break;
                    }
                }
            }

            bool wasOpen = false;
            // check whether the db is already opened
            if (SQLiteHandler.Instance.isOpen())
            {
                wasOpen = true;
            }
            else
            {
                SQLiteHandler.Instance.ConnectToDb();
            }

            List<string> dbList = SQLiteHandler.Instance.GetAllKeywords(false);
            if (dbList.Count != 0)
            {
                foreach (string x in dbList)
                {
                    if (e.Url.ToString().Contains(x))
                    {
                        e.Cancel = true;
                        MessageBox.Show("This website has been blocked for you: " + e.Url,
                            "Access Denied!", MessageBoxButtons.OK, MessageBoxIcon.Stop);
                        break;
                    }
                }
            }

            if (!wasOpen)
            {
                SQLiteHandler.Instance.DisconnectFromDb();
            }

            if (e.Cancel == true)
            {
                logEvent("Loading BLOCKED " + e.Url);
            }
            else
            {
                logEvent("Loading " + e.Url);
            }
        }

        private void toolStripTextBox2_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                list.Add(toolStripTextBox2.Text);
                toolStripComboBox1.Text = toolStripTextBox2.Text + " added";
                toolStripTextBox2.Clear();

                toolStripComboBox1.Items.Clear();
                foreach(string x in list)
                {
                    toolStripComboBox1.Items.Add(x);
                }

                e.SuppressKeyPress = true;
            }
            
        }

        private void toolStripTextBox1_MouseDown(object sender, MouseEventArgs e)
        {
            toolStripTextBox1.SelectAll();
        }

        private void toolStripComboBox1_DropDown(object sender, EventArgs e)
        {
            toolStripComboBox1.Text = "";
        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }

        private void toolStripMenuItem2_Click(object sender, EventArgs e)
        {
            if(dbHandler == null)
            {
                dbHandler = SQLiteHandler.Instance;
                dbHandler.ConnectToDb();
            }
            else
            {
                MessageBox.Show("O conexiune exista deja!");
            }
        }

        private void toolStripMenuItem3_Click(object sender, EventArgs e)
        {
            if(dbHandler != null)
            {
                dbHandler.DisconnectFromDb();
                dbHandler = null;
            }
            else
            {
                MessageBox.Show("Nu exista o conexiune!");
            }
        }

        private void toolStripMenuItem4_Click(object sender, EventArgs e)
        {
            if(dbHandler != null)
            {
                Form2 form2 = new Form2();
                form2.ShowDialog();
            }
            else
            {
                MessageBox.Show("Nu exista o conexiune!\n" +
                                "Pentru a adauga keywords mai intai creati o" +
                                "conexiune!");
            }
            
        }

        private void toolStripMenuItem5_Click(object sender, EventArgs e)
        {
            if(dbHandler != null)
            {
                dbHandler.GetAllKeywords(true);
            }
            else
            {
                MessageBox.Show("Nu exista o conexiune!\n" +
                                "Pentru a vedea keywords mai intai creati o" +
                                "conexiune!");
            }
        }
    }
}
