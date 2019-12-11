using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DBMS
{
    public partial class Form1 : Form
    {
        private readonly DataBaseHandler conn;
        private DataTable dt;
        private string lastTable = "";
        public Form1()
        {
            InitializeComponent();
            conn = DataBaseHandler.Instance;
        }

        private void populateGrid(DataTable dt)
        {
            dataGridView1.DataSource = dt;
            dataGridView1.Update();
            dataGridView1.Refresh();
        }

        public void Controller(string path, string cmd)
        {
            if (cmd.Equals("NEW"))
            {
                conn.DisconnectDataBase();
                if (!conn.NewDataBase(path))
                {
                    MessageBox.Show("File", "File Already Exists!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
            if (cmd.Equals("OPEN"))
            {
                conn.DisconnectDataBase();
                if (!conn.OpenDataBase(path))
                {
                    MessageBox.Show("File", "File Does NOT Exist!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
            if (path.Equals("EXEC"))
            {
                string[] subs = cmd.Split(' ');
                Console.WriteLine(cmd);
                if (subs[0].ToUpper().Equals("CREATE"))
                {
                    Console.WriteLine("CREATE");
                    if (!conn.CreateTableCommand(cmd))
                    {
                        MessageBox.Show("Execute Error", $"Something went wrong with command:\n'{cmd}'",
                                        MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    }
                    else
                    {
                        lastTable = subs[2];
                        string tmp = $"SELECT * FROM '{lastTable}'";
                        populateGrid(conn.ReadCommand(tmp));
                    }
                }
                if (subs[0].ToUpper().Equals("SELECT"))
                {
                    Console.WriteLine("SELECT");
                    if ((dt = conn.ReadCommand(cmd)) == null)
                    {
                        MessageBox.Show("Execute Error", $"Something went wrong with command:\n'{cmd}'",
                                        MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    }
                    else
                    {
                        for (int i = 0; i < subs.Length; ++i)
                        {
                            if (subs[i].ToUpper().Equals("FROM"))
                            {
                                lastTable = subs[i + 1];
                                break;
                            }
                        }

                        populateGrid(dt);
                    }
                }
                if (subs[0].ToUpper().Equals("INSERT") || 
                    subs[0].ToUpper().Equals("DELETE") ||
                    subs[0].ToUpper().Equals("DROP"))
                {
                    Console.WriteLine("MODIFY");
                    if (!conn.ModifyCommand(cmd))
                    {
                        MessageBox.Show("Execute Error", $"Something went wrong with command:\n'{cmd}'",
                                        MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    }
                    else
                    {
                        lastTable = subs[2];                        

                        string tmp = $"SELECT * FROM '{lastTable}'";
                        populateGrid(conn.ReadCommand(tmp));
                    }
                }
            }
        }

        private void newDataBaseToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(saveFileDialog1.ShowDialog(this) == DialogResult.OK)
            {
                string path = saveFileDialog1.InitialDirectory + saveFileDialog1.FileName;
                label1.Text = path;
                Controller(path, "NEW");
            }
        }

        private void openDataBaseToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog(this) == DialogResult.OK)
            {
                string path = openFileDialog1.InitialDirectory + openFileDialog1.FileName;
                label1.Text = path;
                Controller(path, "OPEN");
            }
        }

        private void executeButton_Click(object sender, EventArgs e)
        {
            Controller("EXEC", cmdTextBox.Text);
            cmdTextBox.Clear();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            
        }

        private void cmdTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                Controller("EXEC", cmdTextBox.Text);
                cmdTextBox.Clear();
                e.Handled = true;
                e.SuppressKeyPress = true;
            }
        }
    }
}
