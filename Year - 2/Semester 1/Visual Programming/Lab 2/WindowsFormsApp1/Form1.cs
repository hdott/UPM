using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.IO;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        private Thread t;
        private static int direction = 1;

        public Form1()
        {
            InitializeComponent();
            t = new Thread(new ThreadStart(run));
            
            colorDialog1.AllowFullOpen = false;
            colorDialog1.ShowHelp = true;
            colorDialog1.Color = Color.Black;

            colorDialog2.AllowFullOpen = false;
            colorDialog2.ShowHelp = true;
            colorDialog2.Color = Color.Red;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Console.WriteLine("pressed button1");
            if(!t.IsAlive)
            {
                t = new Thread(new ThreadStart(run));
            }

            t.Start();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Console.WriteLine("pressed button2");
            t.Abort();
        }

        private void run()
        {
            //drawing setup
            SolidBrush brush = new SolidBrush(colorDialog2.Color);
            Font font = new Font("Arial", 16);
            Graphics g = this.CreateGraphics();

            Rectangle rct = this.ClientRectangle;
            PointF point = new PointF(rct.Right/2,
                                         rct.Bottom / 2);
            

            Console.WriteLine($"{this.Location.X}, {this.Location.Y}");
            Console.WriteLine($"{this.Width}, {this.Height}");
            Console.WriteLine($"{point.X}, {point.Y}");
            StringFormat drawFormat = new StringFormat();
            drawFormat.FormatFlags = StringFormatFlags.DirectionVertical;

            //logging setup
            StreamWriter fs = null;
            try
            {
                if (File.Exists("testlog.txt"))
                {
                    File.Delete("testlog.txt");
                }
                fs = new StreamWriter("testlog.txt");
            } catch(Exception ex)
            {
                throw ex;
            }
            string logMsg = DateTime.Now.ToString("MM\\/dd\\/yy h\\:mm:ss tt");

            while (t.IsAlive)
            {
                //1 rightTop
                //2 leftTop
                //3 leftDown
                //4 rightDown
                

                if (point.X == (rct.Right) && direction == 1) direction = 2;
                if (point.X == (rct.Right) && direction == 4) direction = 3;
                if (point.X == (rct.X) && direction == 3) direction = 4;
                if (point.X == (rct.X) && direction == 2) direction = 1;
                if (point.Y == (rct.Bottom) && direction == 4) direction = 1;
                if (point.Y == (rct.Bottom) && direction == 3) direction = 2;
                if (point.Y == (rct.Y) && direction == 2) direction = 3;
                if (point.Y == (rct.Y) && direction == 1) direction = 4;


                switch (direction)
                {
                    case 1: 
                        point.X++;
                        point.Y--;
                        break;
                    case 2:
                        point.X--;
                        point.Y--;
                        break;
                    case 3:
                        point.X--;
                        point.Y++;
                        break;
                    case 4:
                        point.X++;
                        point.Y++;
                        break;
                    default:
                        break;

                }

                g.DrawString("LoooL", font, brush, point);
                Thread.Sleep(100);
                g.Clear(colorDialog1.Color);
            }

        }

        private void button3_Click(object sender, EventArgs e)
        {
            colorDialog1.ShowDialog();
            label1.Text = colorDialog1.Color.Name;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            colorDialog2.ShowDialog();
            label2.Text = colorDialog2.Color.Name;
        }
    }
}
