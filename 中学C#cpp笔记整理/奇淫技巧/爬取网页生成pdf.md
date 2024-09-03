```cs
using System;
using System.IO;
using System.Windows.Forms;

namespace 爬取网页生成pdf
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Console_TextChanged(object sender, EventArgs e)
        {
          //  Consoletxt.Text = "欢迎使用爬取网页工具,文件将会保存至：D:\\GetFile";
        }

        private void Startbut_Click(object sender, EventArgs e)
        {
          Consoletxt.Text= "欢迎使用爬取网页工具,文件将会保存至：D:\\GetFile";
          string WebAddress = WebAddresstxt.Text;
          string Filemane = Filenametxt.Text;
          Consoletxt.Text = "正在保存网页";
          string[] Getreturn = Start.GeneratePdf(WebAddress, Filemane);
          if (Getreturn==null)
           {
             Consoletxt.Text = "保存失败，原因未知";
           }
            Consoletxt.Text = "保存成功，保存到D:\\GetFile";

            }

        private void OpenFilebut_Click(object sender, EventArgs e)
        {
            string v_OpenFolderPath = @"D:\GetFile";
            System.Diagnostics.Process.Start("explorer.exe", v_OpenFolderPath);

        }
    }
    }
    class Start
    {
        /// <summary>
        /// 生成PDF
        /// </summary>
        /// <param name="relativeUrl">html网址</param>
        /// <param name="pdfName">PDF文件名称前缀</param>
        /// <param name="isA4">纸张大小是否使用A4 (默认:0:不使用  1:使用)</param>
        /// <returns></returns>
        public static string[] GeneratePdf(string relativeUrl, string pdfName, int isA4 = 0)
        {
            try
            {
                //需要下载的 投保单页面地址
                string url = relativeUrl;

                //pdf名称(文件名后面 增加一个时间 防止 文件名重复)
                string fileNameWithOutExtention = pdfName + DateTime.Now.ToString("_yyyyMMdd_HHmmssffff");


                // 保存文件的 完整 路径  (本地地址+文件名.pdf)
                string pdfSavePath = Path.Combine(@"D:\GetFile", string.Format("{0}.pdf", fileNameWithOutExtention));

                //exe地址 (自己写路径,文件夹放在哪里就写哪. 例如:E:\conf)
                string filePath = Path.Combine(@"C:\Users\张向明\Desktop\phantomjs-2.1.1-windows\bin", "phantomjs.exe");
                //rasterize.js 地址 
                string jsPath = Path.Combine(@"D:\代码练习\网页保存为PDF\网页保存为PDF", "rasterize.js");

                //传递的参数 (0:js地址  1:打印的URL地址  2:PDF保存地址  3:打印A4纸尺寸) (对应rasterize.js文件中的参数数组,  例如:system.args[0],system.args[1],system.args[2]  .....  可以取出对应的值  )
                string argument = string.Empty;
                if (isA4 != 0)
                {
                    //0位置的jspath 是给 exe 提供的 js地址, 后面的 123 是参数. 所以 js中并未使用system.args[0]
                    argument = string.Format(" --ignore-ssl-errors=yes  {0} \"{1}\" {2} \"{3}\" ", jsPath, url, pdfSavePath, "A4");
                }
                else
                {
                    argument = string.Format(" --ignore-ssl-errors=yes  {0} \"{1}\" {2} ", jsPath, url, pdfSavePath);
                }

                //调用 工具
                using (System.Diagnostics.Process exep = new System.Diagnostics.Process())
                {
                    System.Diagnostics.ProcessStartInfo startInfo = new System.Diagnostics.ProcessStartInfo();
                    startInfo.FileName = filePath;
                    startInfo.Arguments = argument;
                    startInfo.CreateNoWindow = true;
                    startInfo.UseShellExecute = false;
                    startInfo.RedirectStandardInput = true;
                    startInfo.RedirectStandardOutput = true;
                    startInfo.RedirectStandardError = true;
                    exep.StartInfo = startInfo;
                    exep.Start();
                    exep.WaitForExit();
                    char[] res = new char[2];
                    exep.StandardOutput.Read(res, 0, res.Length);
                    string sRes = new string(res);
                    if (sRes == "ok")
                    {
                        //成功后的操作

                    }
                }
                return new string[] { pdfSavePath };
            }
            catch (Exception e)
            {
                //log
            }
            return new string[] { null, null };
        }
    }

```