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
            if(list.Count != 0)
            {
                foreach(string x in list){
                    if (e.Url.ToString().Contains(x))
                    {
                        e.Cancel = true;
                        MessageBox.Show("This website has been blocked for you: " + e.Url,
                            "Access Denied!", MessageBoxButtons.OK, MessageBoxIcon.Stop);
                        break;
                    }
                }
            }

            if(e.Cancel == true)
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
    }
}
