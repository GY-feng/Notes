截屏代码：
```cs
using System;
using System.Windows.Forms;
using System.Drawing;
using System.IO;
namespace _11._6截屏工具
{
    class Program
    {
        static void Main(string[] args)
        {
            string FileName=@"D:\\截屏";
            Console.WriteLine("欢迎使用截屏工具，正在检测您的磁盘...");
            if (Directory.Exists(FileName))
            {
                Console.WriteLine("D盘中已经存在FileName文件夹，截获的图片将会保存到FileName文件夹当中");
                while (true)
                {
                    Console.WriteLine("请您确认您D盘FileName中的先前截屏已保存，本次截屏将会覆盖先前的截屏内容");
                    Console.WriteLine("如确认保存完毕输入OK开始下一步操作，未完毕请按任意键");
                    string result = Console.ReadLine();
                    if (result == "OK")
                    {
                        break;

                    }
                }

            }
            else
            {
                Directory.CreateDirectory(FileName);
                Console.WriteLine("您的电脑D盘中不存在FileName文件夹，将为您创立该文件夹并将截图保存至其中");
            }
            Console.WriteLine("欢迎使用截屏工具，创作时间：11.6，版本：V1 作者：枫");
            Console.WriteLine("按下两个任意键以开始执行截屏操作");
            Console.ReadLine();
            Console.ReadLine();
            for (int i = 0; i < 1000; i++)
            {

                string newaddress = @"D:\\截屏\\截屏"+i+".jpg";
                Console.WriteLine("图片将保存到的地址是：" + newaddress);
                Console.WriteLine("截图已经截获，正在保存......");
                Bitmap bitmap = GetScreenCapture();
                bitmap.Save(newaddress);
                Console.WriteLine("截屏已经成功保存，");
                Console.WriteLine("按下两个任意键以继续执行截屏操作");
                Console.ReadLine();
                Console.ReadLine();
                Console.Clear();
                Console.WriteLine("欢迎使用截屏工具，创作时间：11.6，版本：V1 作者：枫");
            }
            Console.ReadKey();
        }
        #region 截取屏幕图像
        private static Bitmap GetScreenCapture()
        {
            Rectangle tScreenRect = new Rectangle(0, 0, Screen.PrimaryScreen.Bounds.Width, Screen.PrimaryScreen.Bounds.Height);
            Bitmap tSrcBmp = new Bitmap(tScreenRect.Width, tScreenRect.Height); // 用于屏幕原始图片保存
            Graphics gp = Graphics.FromImage(tSrcBmp);
            gp.CopyFromScreen(0, 0, 0, 0, tScreenRect.Size);
            gp.DrawImage(tSrcBmp, 0, 0, tScreenRect, GraphicsUnit.Pixel);
            return tSrcBmp;
        }
        #endregion 
    }
}
```