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
            algoCB.Items.Add("AES");
            algoCB.Items.Add("DES");
            algoCB.Items.Add("3DES");
            algoCB.Refresh();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //openFileDialog1.ShowDialog();
            if(openFileDialog1.ShowDialog(this) == DialogResult.OK)
            {
                string path = openFileDialog1.InitialDirectory + openFileDialog1.FileName;
                label1.Text = path;
                CryptoG.Criptare(path, algoCB.Text, int.Parse(sizeCB.Text));
            }
        }

        private void decriptBtN_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog(this) == DialogResult.OK)
            {
                string path = openFileDialog1.InitialDirectory + openFileDialog1.FileName;
                label1.Text = path;
                CryptoG.Decriptare(path, algoCB.Text, int.Parse(sizeCB.Text));
            }
        }

        private void algoCB_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(algoCB.SelectedItem == algoCB.Items[0])
            {
                sizeCB.Items.Clear();
                sizeCB.Items.Add(128);
                sizeCB.Items.Add(256);
                sizeCB.Refresh();
            }
            if (algoCB.SelectedItem == algoCB.Items[1])
            {
                sizeCB.Items.Clear();
                sizeCB.Items.Add(64);
                sizeCB.Refresh();
            }
            if (algoCB.SelectedItem == algoCB.Items[2])
            {
                sizeCB.Items.Clear();
                sizeCB.Items.Add(128);
                sizeCB.Items.Add(198);
                sizeCB.Refresh();
            }
        }
    }
}
