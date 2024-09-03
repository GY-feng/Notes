操作Excle表格（需要安装某一些类库）
```cs
using System;
using ClosedXML.Excel;
using System.Windows.Forms;

namespace _10._1EXCEL操作
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        XLWorkbook wb1 = new XLWorkbook();
        private void button1_Click(object sender, EventArgs e)
        {
            wb1.AddWorksheet("我的表格");
            wb1.SaveAs(@"D:\Test\EXCEL\我的excel.xlsx");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            wb1 = new XLWorkbook(@"D:\Test\EXCEL\我的excel.xlsx");
            IXLWorksheet sheet1 = wb1.Worksheet(1);
            sheet1.Cell(Convert.ToInt32(textBox1.Text),Convert.ToInt32(textBox2.Text)).Value=textBox3.Text;
            wb1.Save();//SaveAs另存为，Save保存
        }

        private void button3_Click(object sender, EventArgs e)
        {
            wb1 = new XLWorkbook(@"D:\Test\EXCEL\我的excel.xlsx");
            wb1.AddWorksheet("SSSSSSSSSSSsssss");
            IXLWorksheet sheet1 = wb1.Worksheet(1);
            sheet1.Delete();
            wb1.Save();//SaveAs另存为，Save保存
        }
    }
}
```