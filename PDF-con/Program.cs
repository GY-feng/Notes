using System;
using System.Threading.Tasks;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using TencentCloud.Common;
using TencentCloud.Common.Profile;
using TencentCloud.Tmt.V20180321;
using TencentCloud.Tmt.V20180321.Models;
using PdfSharp.Pdf;
using PdfSharp.Drawing;

namespace PDF_con
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Credential cred = new Credential
                {
                    SecretId = "AKIDru3GUiyIe0OhuxpcGqEVbjegYO9lmaBY",
                    SecretKey = "JQM5ez73wc6MOp36ygDfw54rTxGPPFuO"
                };
                // 实例化一个client选项，可选的，没有特殊需求可以跳过
                ClientProfile clientProfile = new ClientProfile();
                // 实例化一个http选项，可选的，没有特殊需求可以跳过
                HttpProfile httpProfile = new HttpProfile();
                httpProfile.Endpoint = ("tmt.tencentcloudapi.com");
                clientProfile.HttpProfile = httpProfile;

                // 实例化要请求产品的client对象,clientProfile是可选的
                TmtClient client = new TmtClient(cred, "ap-guangzhou", clientProfile);
                // 实例化一个请求对象,每个接口都会对应一个request对象
                TextTranslateRequest req = new TextTranslateRequest();
                req.SourceText = "Hell";
                req.Source = "en";
                req.Target = "zh";
                req.ProjectId = 0;
                // 返回的resp是一个TextTranslateResponse的实例，与请求对象对应
                TextTranslateResponse resp = client.TextTranslateSync(req);
                // 输出json格式的字符串回包
                var remes = AbstractModel.ToJsonString(resp);
                //Console.WriteLine(remes);
                JObject j = JObject.Parse(remes);
                string mes = (string)j["TargetText"];
                Console.WriteLine(mes);

                string filePath = "transfer.pdf";
                using(PdfDocument doct=new PdfDocument())
                {
                    //添加页面：
                    PdfPage page = doct.AddPage();
                    //创建用于绘制的的对象：
                    XGraphics g = XGraphics.FromPdfPage(page);
                    // 创建一个字体
                    XFont font = new XFont("Verdana", 12);
                    g.DrawString(text,font,XBrushes.Black)


                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
            Console.ReadKey();
        }
    }
}
