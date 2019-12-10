namespace Ex1
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
            this.criptBtN = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.decriptBtN = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // criptBtN
            // 
            this.criptBtN.Location = new System.Drawing.Point(0, 0);
            this.criptBtN.Name = "criptBtN";
            this.criptBtN.Size = new System.Drawing.Size(75, 23);
            this.criptBtN.TabIndex = 0;
            this.criptBtN.Text = "Cripteaza";
            this.criptBtN.UseVisualStyleBackColor = true;
            this.criptBtN.Click += new System.EventHandler(this.button1_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // decriptBtN
            // 
            this.decriptBtN.Location = new System.Drawing.Point(0, 29);
            this.decriptBtN.Name = "decriptBtN";
            this.decriptBtN.Size = new System.Drawing.Size(75, 23);
            this.decriptBtN.TabIndex = 1;
            this.decriptBtN.Text = "Decripteaza";
            this.decriptBtN.UseVisualStyleBackColor = true;
            this.decriptBtN.Click += new System.EventHandler(this.decriptBtN_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 55);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "label1";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.decriptBtN);
            this.Controls.Add(this.criptBtN);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button criptBtN;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Button decriptBtN;
        private System.Windows.Forms.Label label1;
    }
}

