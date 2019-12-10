using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ex1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //openFileDialog1.ShowDialog();
            if(openFileDialog1.ShowDialog(this) == DialogResult.OK)
            {
                string path = openFileDialog1.InitialDirectory + openFileDialog1.FileName;
                label1.Text = path;
                CryptoG.Criptare(path);
            }
        }

        private void decriptBtN_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog(this) == DialogResult.OK)
            {
                string path = openFileDialog1.InitialDirectory + openFileDialog1.FileName;
                label1.Text = path;
                CryptoG.Decriptare(path);
            }
        }
    }
}
