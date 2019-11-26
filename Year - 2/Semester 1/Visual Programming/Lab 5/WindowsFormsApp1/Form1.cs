using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using DatabaseHandler;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public SQLiteHandler connect = null;
        System.Timers.Timer t = null;
        public Form1()
        {
            InitializeComponent();
            //SetupDataGridView();
        }

        private void connectB_Click(object sender, EventArgs e)
        {
            killTimer();

            connect = SQLiteHandler.Instance;
            if (connect.ConnectToDb())
            {
                statusL.Text = "DB Connectat!";
                statusL.ForeColor = Color.Green;
                statusL.Visible = true;

                t = new System.Timers.Timer(2000);
                t.Elapsed += OnTimedEvent;
                t.Enabled = true;
            }
            else
            {
                statusL.Text = "Unable to connect!";
                statusL.ForeColor = Color.Red;
                statusL.Visible = true;

                t = new System.Timers.Timer(2000);
                t.Elapsed += OnTimedEvent;
                t.Enabled = true;
                connect.DisconnectFromDb();
                connect = null;
            }
        }

        delegate void clearTimerLabel();

        private void clearTL()
        {
            if (this.statusL.InvokeRequired)
            {
                clearTimerLabel d = new clearTimerLabel(clearTL);
                this.Invoke(d);
            }
            else
            {
                statusL.Visible = false;
            }
        }

        private void OnTimedEvent(Object source, System.Timers.ElapsedEventArgs e)
        {
            clearTL();
            t.Stop();
            t.Dispose();
            t = null;
        }

        private void killTimer()
        {
            if(t != null)
            {
                t.Stop();
                t.Dispose();
                t = null;
            }
        }

        private void disconnectB_Click(object sender, EventArgs e)
        {
            killTimer();

            connect.DisconnectFromDb();
            connect = null;
            statusL.Text = "DB DeConectat!";
            statusL.ForeColor = Color.Green;
            statusL.Visible = true;

            t = new System.Timers.Timer(2000);
            t.Elapsed += OnTimedEvent;
            t.Enabled = true;
        }

        private void SetupDataGridView()
        {
            dataGridView1.ColumnCount = 4;
            dataGridView1.Columns[0].Name = "Nume";
            dataGridView1.Columns[1].Name = "Prenume";
            dataGridView1.Columns[2].Name = "Adresa";
            dataGridView1.Columns[3].Name = "CNP";
        }

        private void populateGrid(DataTable dt)
        {
            //DataTable dt = connect.GetAllUsers();
            dt.Columns.RemoveAt(0);
            dataGridView1.DataSource = dt;
            //foreach(SQLiteHandler.User user in list)
            //{
            //    dataGridView1.Rows.Add(new string[] { user.Nume, user.Prenume, user.Adresa, user.CNP });
            //}
            dataGridView1.Update();
            dataGridView1.Refresh();
        }

        private void insertB_Click(object sender, EventArgs e)
        {
            killTimer();

            if (connect == null)
            {
                statusL.ForeColor = Color.Red;
                statusL.Text = "Nu exista conexiune DB!";
                statusL.Visible = true;

                t = new System.Timers.Timer(2000);
                t.Elapsed += OnTimedEvent;
                t.Enabled = true;
                return;
            }
            string stat = "Lipseste:";
            bool suntDate = true;
            if (numeTB.Text.Length == 0)
            {
                stat += "Nume, ";
                suntDate = false;
            }
            if (prenumeTB.Text.Length == 0)
            {
                stat += "Prenume, ";
                suntDate = false;
            }
            if (adresaTB.Text.Length == 0)
            {
                stat += "Adresa, ";
                suntDate = false;
            }
            if (cnpTB.Text.Length == 0)
            {
                stat += "CNP";
                suntDate = false;
            }

            if (!suntDate)
            {
                statusL.ForeColor = Color.Red;
                statusL.Text = stat;
                statusL.Visible = true;
            }
            else
            {
                if(connect.InsertUser(numeTB.Text, prenumeTB.Text, adresaTB.Text,
                                    cnpTB.Text))
                {
                    statusL.Text = "User Adaugat!";
                    statusL.ForeColor = Color.Green;
                    statusL.Visible = true;
                    
                    t = new System.Timers.Timer(2000);
                    t.Elapsed += OnTimedEvent;
                    t.Enabled = true;

                    populateGrid(connect.GetAllUsers());
                }
                else
                {
                    statusL.Text = "User NU a fost Adaugat!";
                    statusL.ForeColor = Color.Red;
                    statusL.Visible = true;

                    t = new System.Timers.Timer(2000);
                    t.Elapsed += OnTimedEvent;
                    t.Enabled = true;
                }
            }

        }

        private void deleteB_Click(object sender, EventArgs e)
        {
            killTimer();

            if (connect == null)
            {
                statusL.ForeColor = Color.Red;
                statusL.Text = "Nu exista conexiune DB!";
                statusL.Visible = true;

                t = new System.Timers.Timer(2000);
                t.Elapsed += OnTimedEvent;
                t.Enabled = true;
                return;
            }

            if(cnpTB.Text.Length == 0)
            {
                statusL.ForeColor = Color.Red;
                statusL.Text = "Introduceti CNP";
                statusL.Visible = true;
            }
            else
            {
                if (connect.DeleteUser(cnpTB.Text))
                {
                    statusL.Text = "User Sters!";
                    statusL.ForeColor = Color.Green;
                    statusL.Visible = true;

                    t = new System.Timers.Timer(2000);
                    t.Elapsed += OnTimedEvent;
                    t.Enabled = true;

                    populateGrid(connect.GetAllUsers());
                }
                else
                {
                    statusL.Text = "User NU a fost Sters!";
                    statusL.ForeColor = Color.Red;
                    statusL.Visible = true;

                    t = new System.Timers.Timer(2000);
                    t.Elapsed += OnTimedEvent;
                    t.Enabled = true;
                }
            }
        }

        private void getallB_Click(object sender, EventArgs e)
        {
            if (connect == null)
            {
                statusL.ForeColor = Color.Red;
                statusL.Text = "Nu exista conexiune DB!";
                statusL.Visible = true;

                t = new System.Timers.Timer(2000);
                t.Elapsed += OnTimedEvent;
                t.Enabled = true;
                return;
            }
            else
            {
                populateGrid(connect.GetAllUsers());
            }
        }

        private void cautaCNPB_Click(object sender, EventArgs e)
        {

        }
    }
}
