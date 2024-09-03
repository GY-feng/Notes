```cs
namespace _8._10文件批量更名
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void btnOpenPath_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog f1 = new FolderBrowserDialog();
            if (f1.ShowDialog() == DialogResult.OK)
            {
                txtPath.Text = f1.SelectedPath;
            }
        }

        private void btnRename_Click(object sender, EventArgs e)
        {
            if (txtPath.Text != "")
            {
                if (txtNew.Text != "")
                {
                    string strOldPart = txtOld.Text.Trim();
                    string strNewPart = txtNew.Text.Trim();
                    DateTime StartTime = DateTime.Now;
                    try
                    {
                        DirectoryInfo di = new DirectoryInfo(txtPath.Text);
                        FileInfo[] filelist = di.GetFiles("*.*");
                        string strFileFolder = txtPath.Text;
                        int i = 0;
                        int TotalFiles = 0;
                        foreach (FileInfo fi in filelist)
                        {
                            string strOldFileName = fi.Name;
                            string strNewFileName = fi.Name.Replace(strOldPart, strNewPart);
                            string strNewFilePath = @strFileFolder + "\\" + strNewFileName;
                            filelist[i].MoveTo(@strNewFilePath);
                            TotalFiles += 1;
                            lstFiles.Items.Add("文件名：" + strOldFileName + "    已重命名为  " + strNewFileName + "");
                            i += 1;
                        }
                        DateTime EndTime = DateTime.Now;
                        TimeSpan ts = EndTime - StartTime;
                        Text = ("总耗时：" + ts.Hours + "时" + ts.Minutes + "分" + ts.Seconds + "秒" + ts.Milliseconds + "毫秒");
                    }
                    catch
                    {
                        MessageBox.Show("路径无效!");
                    }
                }
                else
                {
                    MessageBox.Show("没有匹配字符");
                }
            }
            else
            {
                MessageBox.Show("请先择择路径!");
            }
        }
    }
}
```