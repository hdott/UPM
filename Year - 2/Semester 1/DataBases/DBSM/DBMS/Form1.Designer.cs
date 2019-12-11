namespace DBMS
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
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.menuStrip2 = new System.Windows.Forms.MenuStrip();
            this.fileStripMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.newDataBaseToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openDataBaseToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.cmdTextBox = new System.Windows.Forms.TextBox();
            this.executeButton = new System.Windows.Forms.Button();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.label1 = new System.Windows.Forms.Label();
            this.menuStrip2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Location = new System.Drawing.Point(0, 24);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // menuStrip2
            // 
            this.menuStrip2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileStripMenu});
            this.menuStrip2.Location = new System.Drawing.Point(0, 0);
            this.menuStrip2.Name = "menuStrip2";
            this.menuStrip2.Size = new System.Drawing.Size(800, 24);
            this.menuStrip2.TabIndex = 1;
            this.menuStrip2.Text = "menuStrip2";
            // 
            // fileStripMenu
            // 
            this.fileStripMenu.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newDataBaseToolStripMenuItem,
            this.openDataBaseToolStripMenuItem});
            this.fileStripMenu.Name = "fileStripMenu";
            this.fileStripMenu.Size = new System.Drawing.Size(37, 20);
            this.fileStripMenu.Text = "File";
            // 
            // newDataBaseToolStripMenuItem
            // 
            this.newDataBaseToolStripMenuItem.Name = "newDataBaseToolStripMenuItem";
            this.newDataBaseToolStripMenuItem.Size = new System.Drawing.Size(154, 22);
            this.newDataBaseToolStripMenuItem.Text = "New DataBase";
            this.newDataBaseToolStripMenuItem.Click += new System.EventHandler(this.newDataBaseToolStripMenuItem_Click);
            // 
            // openDataBaseToolStripMenuItem
            // 
            this.openDataBaseToolStripMenuItem.Name = "openDataBaseToolStripMenuItem";
            this.openDataBaseToolStripMenuItem.Size = new System.Drawing.Size(154, 22);
            this.openDataBaseToolStripMenuItem.Text = "Open DataBase";
            this.openDataBaseToolStripMenuItem.Click += new System.EventHandler(this.openDataBaseToolStripMenuItem_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 27);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(776, 366);
            this.dataGridView1.TabIndex = 2;
            // 
            // cmdTextBox
            // 
            this.cmdTextBox.Location = new System.Drawing.Point(12, 400);
            this.cmdTextBox.Name = "cmdTextBox";
            this.cmdTextBox.Size = new System.Drawing.Size(776, 20);
            this.cmdTextBox.TabIndex = 3;
            this.cmdTextBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.cmdTextBox_KeyDown);
            // 
            // executeButton
            // 
            this.executeButton.Location = new System.Drawing.Point(12, 426);
            this.executeButton.Name = "executeButton";
            this.executeButton.Size = new System.Drawing.Size(75, 23);
            this.executeButton.TabIndex = 4;
            this.executeButton.Text = "Execute";
            this.executeButton.UseVisualStyleBackColor = true;
            this.executeButton.Click += new System.EventHandler(this.executeButton_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(93, 431);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "label1";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.executeButton);
            this.Controls.Add(this.cmdTextBox);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.menuStrip2);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.menuStrip2.ResumeLayout(false);
            this.menuStrip2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.MenuStrip menuStrip2;
        private System.Windows.Forms.ToolStripMenuItem fileStripMenu;
        private System.Windows.Forms.ToolStripMenuItem newDataBaseToolStripMenuItem;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.TextBox cmdTextBox;
        private System.Windows.Forms.Button executeButton;
        private System.Windows.Forms.ToolStripMenuItem openDataBaseToolStripMenuItem;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Label label1;
    }
}

