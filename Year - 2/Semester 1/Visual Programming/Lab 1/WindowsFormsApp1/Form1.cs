using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Go UP?", "UP", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
            textBox1.Text = "UP";
            Form1.ActiveForm.Top -= 10;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Go LEFT?", "LEFT", MessageBoxButtons.OK, MessageBoxIcon.Error);
            textBox1.Text = "LEFT";
            Form1.ActiveForm.Left -= 10;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Go RIGHT?", "RIGHT", MessageBoxButtons.AbortRetryIgnore, MessageBoxIcon.Exclamation);
            textBox1.Text = "RIGHT";
            Form1.ActiveForm.Left += 10;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Go DOWN?", "DOWN", MessageBoxButtons.RetryCancel, MessageBoxIcon.Question);
            textBox1.Text = "DOWN";
            Form1.ActiveForm.Top += 10;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Random _rand = new Random();
            this.BackColor = Color.FromArgb(_rand.Next(0, 255), _rand.Next(0, 255), _rand.Next(0, 255));
        }

        private void button6_Click(object sender, EventArgs e)
        {
            timer1.Stop();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            timer1.Interval = int.Parse(textBox2.Text);
        }
    }
}
