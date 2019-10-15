using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace WindowsFormsApp2
{
    class MyThread
    {
        private Thread t;

        public MyThread(Form1.paint pnt)
        {
            t = new Thread(new ThreadStart(pnt));
        }

        public void ThreadStart()
        {
            t.Start();
        }

        public  void ThreadAbort()
        {
            t.Abort();
        }

        public bool ThreadIsAlive()
        {
            return t.IsAlive;
        }
    }
}
