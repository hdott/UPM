﻿namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
            Logging.Instance.Dispose();
            SQLiteHandler.Instance().DisconnectFromDb();
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.webBrowser1 = new System.Windows.Forms.WebBrowser();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripNavigate = new System.Windows.Forms.ToolStripButton();
            this.toolStripBack = new System.Windows.Forms.ToolStripButton();
            this.toolStripForward = new System.Windows.Forms.ToolStripButton();
            this.toolStripHome = new System.Windows.Forms.ToolStripButton();
            this.toolStripTextBox1 = new System.Windows.Forms.ToolStripTextBox();
            this.toolStripTextBox2 = new System.Windows.Forms.ToolStripTextBox();
            this.toolStripComboBox1 = new System.Windows.Forms.ToolStripComboBox();
            this.toolStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // webBrowser1
            // 
            this.webBrowser1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.webBrowser1.Location = new System.Drawing.Point(0, 0);
            this.webBrowser1.MinimumSize = new System.Drawing.Size(20, 20);
            this.webBrowser1.Name = "webBrowser1";
            this.webBrowser1.Size = new System.Drawing.Size(1235, 542);
            this.webBrowser1.TabIndex = 0;
            this.webBrowser1.Navigating += new System.Windows.Forms.WebBrowserNavigatingEventHandler(this.webBrowser1_Navigating);
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripNavigate,
            this.toolStripBack,
            this.toolStripForward,
            this.toolStripHome,
            this.toolStripTextBox1,
            this.toolStripTextBox2,
            this.toolStripComboBox1});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(1235, 25);
            this.toolStrip1.TabIndex = 1;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripNavigate
            // 
            this.toolStripNavigate.Image = ((System.Drawing.Image)(resources.GetObject("toolStripNavigate.Image")));
            this.toolStripNavigate.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripNavigate.Name = "toolStripNavigate";
            this.toolStripNavigate.Size = new System.Drawing.Size(74, 22);
            this.toolStripNavigate.Text = "Navigate";
            this.toolStripNavigate.Click += new System.EventHandler(this.toolStripNavigate_Click);
            // 
            // toolStripBack
            // 
            this.toolStripBack.Image = ((System.Drawing.Image)(resources.GetObject("toolStripBack.Image")));
            this.toolStripBack.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripBack.Name = "toolStripBack";
            this.toolStripBack.Size = new System.Drawing.Size(52, 22);
            this.toolStripBack.Text = "Back";
            this.toolStripBack.Click += new System.EventHandler(this.toolStripBack_Click);
            // 
            // toolStripForward
            // 
            this.toolStripForward.Image = ((System.Drawing.Image)(resources.GetObject("toolStripForward.Image")));
            this.toolStripForward.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripForward.Name = "toolStripForward";
            this.toolStripForward.Size = new System.Drawing.Size(70, 22);
            this.toolStripForward.Text = "Forward";
            this.toolStripForward.Click += new System.EventHandler(this.toolStripForward_Click);
            // 
            // toolStripHome
            // 
            this.toolStripHome.Image = ((System.Drawing.Image)(resources.GetObject("toolStripHome.Image")));
            this.toolStripHome.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripHome.Name = "toolStripHome";
            this.toolStripHome.Size = new System.Drawing.Size(60, 22);
            this.toolStripHome.Text = "Home";
            this.toolStripHome.Click += new System.EventHandler(this.toolStripHome_Click);
            // 
            // toolStripTextBox1
            // 
            this.toolStripTextBox1.Font = new System.Drawing.Font("Segoe UI", 9F);
            this.toolStripTextBox1.Name = "toolStripTextBox1";
            this.toolStripTextBox1.Size = new System.Drawing.Size(500, 25);
            this.toolStripTextBox1.KeyDown += new System.Windows.Forms.KeyEventHandler(this.toolStripTextBox1_KeyDown);
            this.toolStripTextBox1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.toolStripTextBox1_MouseDown);
            // 
            // toolStripTextBox2
            // 
            this.toolStripTextBox2.Font = new System.Drawing.Font("Segoe UI", 9F);
            this.toolStripTextBox2.Name = "toolStripTextBox2";
            this.toolStripTextBox2.Size = new System.Drawing.Size(100, 25);
            this.toolStripTextBox2.KeyDown += new System.Windows.Forms.KeyEventHandler(this.toolStripTextBox2_KeyDown);
            // 
            // toolStripComboBox1
            // 
            this.toolStripComboBox1.Name = "toolStripComboBox1";
            this.toolStripComboBox1.Size = new System.Drawing.Size(121, 25);
            this.toolStripComboBox1.DropDown += new System.EventHandler(this.toolStripComboBox1_DropDown);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1235, 542);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.webBrowser1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.WebBrowser webBrowser1;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton toolStripNavigate;
        private System.Windows.Forms.ToolStripButton toolStripBack;
        private System.Windows.Forms.ToolStripButton toolStripForward;
        private System.Windows.Forms.ToolStripButton toolStripHome;
        private System.Windows.Forms.ToolStripTextBox toolStripTextBox1;
        private System.Windows.Forms.ToolStripTextBox toolStripTextBox2;
        private System.Windows.Forms.ToolStripComboBox toolStripComboBox1;
    }
}

