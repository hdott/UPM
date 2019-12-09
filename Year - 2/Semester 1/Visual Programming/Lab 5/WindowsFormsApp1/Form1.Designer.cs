namespace WindowsFormsApp1
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.numeTB = new System.Windows.Forms.TextBox();
            this.prenumeTB = new System.Windows.Forms.TextBox();
            this.adresaTB = new System.Windows.Forms.TextBox();
            this.cnpTB = new System.Windows.Forms.TextBox();
            this.insertB = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.connectB = new System.Windows.Forms.Button();
            this.disconnectB = new System.Windows.Forms.Button();
            this.deleteB = new System.Windows.Forms.Button();
            this.cautaCNPB = new System.Windows.Forms.Button();
            this.cautaNPB = new System.Windows.Forms.Button();
            this.getallB = new System.Windows.Forms.Button();
            this.statusL = new System.Windows.Forms.Label();
            this.pwdTB = new System.Windows.Forms.TextBox();
            this.pwdL = new System.Windows.Forms.Label();
            this.authBTN = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(2, 3);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Nume";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(2, 23);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Prenume";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(2, 42);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(40, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Adresa";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(2, 64);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(29, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "CNP";
            // 
            // numeTB
            // 
            this.numeTB.Location = new System.Drawing.Point(57, 3);
            this.numeTB.Name = "numeTB";
            this.numeTB.Size = new System.Drawing.Size(100, 20);
            this.numeTB.TabIndex = 4;
            // 
            // prenumeTB
            // 
            this.prenumeTB.Location = new System.Drawing.Point(57, 23);
            this.prenumeTB.Name = "prenumeTB";
            this.prenumeTB.Size = new System.Drawing.Size(100, 20);
            this.prenumeTB.TabIndex = 5;
            // 
            // adresaTB
            // 
            this.adresaTB.Location = new System.Drawing.Point(57, 42);
            this.adresaTB.Name = "adresaTB";
            this.adresaTB.Size = new System.Drawing.Size(100, 20);
            this.adresaTB.TabIndex = 6;
            // 
            // cnpTB
            // 
            this.cnpTB.Location = new System.Drawing.Point(57, 61);
            this.cnpTB.Name = "cnpTB";
            this.cnpTB.Size = new System.Drawing.Size(100, 20);
            this.cnpTB.TabIndex = 7;
            // 
            // insertB
            // 
            this.insertB.Location = new System.Drawing.Point(5, 180);
            this.insertB.Name = "insertB";
            this.insertB.Size = new System.Drawing.Size(75, 23);
            this.insertB.TabIndex = 8;
            this.insertB.Text = "Insert";
            this.insertB.UseVisualStyleBackColor = true;
            this.insertB.Click += new System.EventHandler(this.insertB_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(164, 3);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(624, 426);
            this.dataGridView1.TabIndex = 9;
            // 
            // connectB
            // 
            this.connectB.Location = new System.Drawing.Point(5, 121);
            this.connectB.Name = "connectB";
            this.connectB.Size = new System.Drawing.Size(75, 23);
            this.connectB.TabIndex = 10;
            this.connectB.Text = "Connect";
            this.connectB.UseVisualStyleBackColor = true;
            this.connectB.Click += new System.EventHandler(this.connectB_Click);
            // 
            // disconnectB
            // 
            this.disconnectB.Location = new System.Drawing.Point(5, 151);
            this.disconnectB.Name = "disconnectB";
            this.disconnectB.Size = new System.Drawing.Size(75, 23);
            this.disconnectB.TabIndex = 11;
            this.disconnectB.Text = "Disconnect";
            this.disconnectB.UseVisualStyleBackColor = true;
            this.disconnectB.Click += new System.EventHandler(this.disconnectB_Click);
            // 
            // deleteB
            // 
            this.deleteB.Location = new System.Drawing.Point(5, 210);
            this.deleteB.Name = "deleteB";
            this.deleteB.Size = new System.Drawing.Size(75, 23);
            this.deleteB.TabIndex = 12;
            this.deleteB.Text = "Delete";
            this.deleteB.UseVisualStyleBackColor = true;
            this.deleteB.Click += new System.EventHandler(this.deleteB_Click);
            // 
            // cautaCNPB
            // 
            this.cautaCNPB.Location = new System.Drawing.Point(5, 240);
            this.cautaCNPB.Name = "cautaCNPB";
            this.cautaCNPB.Size = new System.Drawing.Size(152, 23);
            this.cautaCNPB.TabIndex = 13;
            this.cautaCNPB.Text = "Cauta dupa CNP";
            this.cautaCNPB.UseVisualStyleBackColor = true;
            this.cautaCNPB.Click += new System.EventHandler(this.cautaCNPB_Click);
            // 
            // cautaNPB
            // 
            this.cautaNPB.Location = new System.Drawing.Point(5, 270);
            this.cautaNPB.Name = "cautaNPB";
            this.cautaNPB.Size = new System.Drawing.Size(152, 23);
            this.cautaNPB.TabIndex = 14;
            this.cautaNPB.Text = "Cauta dupa Nume, Prenume";
            this.cautaNPB.UseVisualStyleBackColor = true;
            this.cautaNPB.Click += new System.EventHandler(this.cautaNPB_Click);
            // 
            // getallB
            // 
            this.getallB.Location = new System.Drawing.Point(5, 300);
            this.getallB.Name = "getallB";
            this.getallB.Size = new System.Drawing.Size(152, 23);
            this.getallB.TabIndex = 15;
            this.getallB.Text = "Get All Users";
            this.getallB.UseVisualStyleBackColor = true;
            this.getallB.Click += new System.EventHandler(this.getallB_Click);
            // 
            // statusL
            // 
            this.statusL.AutoSize = true;
            this.statusL.Location = new System.Drawing.Point(2, 365);
            this.statusL.Name = "statusL";
            this.statusL.Size = new System.Drawing.Size(35, 13);
            this.statusL.TabIndex = 16;
            this.statusL.Text = "label5";
            this.statusL.Visible = false;
            // 
            // pwdTB
            // 
            this.pwdTB.Location = new System.Drawing.Point(57, 78);
            this.pwdTB.Name = "pwdTB";
            this.pwdTB.Size = new System.Drawing.Size(100, 20);
            this.pwdTB.TabIndex = 17;
            this.pwdTB.UseSystemPasswordChar = true;
            // 
            // pwdL
            // 
            this.pwdL.AutoSize = true;
            this.pwdL.Location = new System.Drawing.Point(2, 81);
            this.pwdL.Name = "pwdL";
            this.pwdL.Size = new System.Drawing.Size(53, 13);
            this.pwdL.TabIndex = 18;
            this.pwdL.Text = "Password";
            // 
            // authBTN
            // 
            this.authBTN.Location = new System.Drawing.Point(5, 329);
            this.authBTN.Name = "authBTN";
            this.authBTN.Size = new System.Drawing.Size(152, 23);
            this.authBTN.TabIndex = 19;
            this.authBTN.Text = "Authenticate User";
            this.authBTN.UseVisualStyleBackColor = true;
            this.authBTN.Click += new System.EventHandler(this.authBTN_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.authBTN);
            this.Controls.Add(this.pwdL);
            this.Controls.Add(this.pwdTB);
            this.Controls.Add(this.statusL);
            this.Controls.Add(this.getallB);
            this.Controls.Add(this.cautaNPB);
            this.Controls.Add(this.cautaCNPB);
            this.Controls.Add(this.deleteB);
            this.Controls.Add(this.disconnectB);
            this.Controls.Add(this.connectB);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.insertB);
            this.Controls.Add(this.cnpTB);
            this.Controls.Add(this.adresaTB);
            this.Controls.Add(this.prenumeTB);
            this.Controls.Add(this.numeTB);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox numeTB;
        private System.Windows.Forms.TextBox prenumeTB;
        private System.Windows.Forms.TextBox adresaTB;
        private System.Windows.Forms.TextBox cnpTB;
        private System.Windows.Forms.Button insertB;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button connectB;
        private System.Windows.Forms.Button disconnectB;
        private System.Windows.Forms.Button deleteB;
        private System.Windows.Forms.Button cautaCNPB;
        private System.Windows.Forms.Button cautaNPB;
        private System.Windows.Forms.Button getallB;
        private System.Windows.Forms.Label statusL;
        private System.Windows.Forms.TextBox pwdTB;
        private System.Windows.Forms.Label pwdL;
        private System.Windows.Forms.Button authBTN;
    }
}

