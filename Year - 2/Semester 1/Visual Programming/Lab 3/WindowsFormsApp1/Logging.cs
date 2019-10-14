using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    public sealed class Logging
    {
        private static Logging instance = null;
        private static readonly object padlock = new object();
        private StreamWriter fs = null;

        Logging()
        {
            try
            {
                if (File.Exists("log.txt"))
                {
                    File.Delete("log.txt");
                }

                fs = new StreamWriter("log.txt");
            }
            catch (Exception ex)
            {
                throw ex;
            }

            Trace.Listeners.Add(new TextWriterTraceListener(fs));
            Trace.AutoFlush = true;
        }

        public static Logging Instance
        {
            get
            {
                lock (padlock)
                {
                    if(instance == null)
                    {
                        instance = new Logging();
                    }
                }

                return instance;
            }
        }

        public bool Log(string str)
        {
            Trace.WriteLine(str);
            
            return true;
        }

        public void Dispose()
        {
            fs.Dispose();

            if(instance != null)
            {
                instance = null;
            }
        }
    }
}
