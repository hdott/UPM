using System;
using System.Drawing;
using System.Windows.Forms;
using System.Threading;
using System.IO;
using System.Diagnostics;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        private MyThread t;
        private static int direction = 1;
        static BooleanSwitch logging = new BooleanSwitch("Logg", "Logg description");
        private StreamWriter fs = null;

        public Form1()
        {
            InitializeComponent();
            //t = new Thread(new ThreadStart(run));
            t = new MyThread(new paint(run));
            
            colorDialog1.AllowFullOpen = false;
            colorDialog1.ShowHelp = true;
            colorDialog1.Color = Color.Black;

            colorDialog2.AllowFullOpen = false;
            colorDialog2.ShowHelp = true;
            colorDialog2.Color = Color.Red;

            logging.Enabled = true;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Console.WriteLine("pressed button1");
            if(!t.ThreadIsAlive())
            {
                t = new MyThread(new paint(run));
            }

            t.ThreadStart();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Console.WriteLine("pressed button2");
            t.ThreadAbort();
        }

        public delegate void paint();

        private void run()
        {
            //drawing setup
            SolidBrush brush = new SolidBrush(colorDialog2.Color);
            Font font = new Font("Arial", 16);
            Graphics g = this.CreateGraphics();

            Rectangle rct = this.ClientRectangle;
            PointF point = new PointF(rct.Right/2,
                                         rct.Bottom / 2);

            string msg = "Test";
            Console.WriteLine($"{this.Location.X}, {this.Location.Y}");
            Console.WriteLine($"{this.Width}, {this.Height}");
            Console.WriteLine($"{point.X}, {point.Y}");
            StringFormat drawFormat = new StringFormat();
            drawFormat.FormatFlags = StringFormatFlags.DirectionVertical;

            //logging setup
            if(fs != null)
            {
                fs.Close();
            }
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

            //Trace setup
            Trace.Listeners.Add(new TextWriterTraceListener(fs));
            Trace.AutoFlush = true;
            Trace.Indent();

            while (t.ThreadIsAlive())
            {
                //1 rightTop
                //2 leftTop
                //3 leftDown
                //4 rightDown
                

                if (point.X == (rct.Right-(msg.Length*15)) && direction == 1) direction = 2;
                if (point.X == (rct.Right-(msg.Length*15)) && direction == 4) direction = 3;
                if (point.X == (rct.X) && direction == 3) direction = 4;
                if (point.X == (rct.X) && direction == 2) direction = 1;
                if (point.Y == (rct.Bottom-16) && direction == 4) direction = 1;
                if (point.Y == (rct.Bottom-16) && direction == 3) direction = 2;
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

                brush.Color = colorDialog2.Color;
                g.DrawString(msg, font, brush, point);
                Trace.WriteLineIf(logging.Enabled, DateTime.Now.ToString("MM\\/dd\\/yy h\\:mm:ss:ms"));
                //if (logging.Enabled) Console.WriteLine($"{DateTime.Now.ToString("MM\\/dd\\/yy h\\:mm:ss:ms")}");
                Thread.Sleep(10);
                g.Clear(colorDialog1.Color);
            }

            fs.Close();
            Trace.Unindent();
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

        private void button6_Click(object sender, EventArgs e)
        {
            if (logging.Enabled)
            {
                logging.Enabled = false;
                label3.Text = "Off";
            } else
            {
                logging.Enabled = true;
                label3.Text = "On";
            }
        }
    }
}
