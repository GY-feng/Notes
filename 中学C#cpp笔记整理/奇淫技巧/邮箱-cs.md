```cs
using System;
using System.Threading;//启用多线程
using System.Windows.Forms;
using System.Net.Mail;
void sendmail()
{
    int a, b;
    int cishu = Convert.ToInt32(txtcishu.Text);
    int jiange = Convert.ToInt32(txtjiange.Text);

    a = cishu + 1;
    b = jiange * 1000;
    for (int i = 0; i < a; i++)
    {
        MailMessage mms = new MailMessage();
        mms.From = new MailAddress(txtform.Text);//部署邮件的发送地址
        mms.To.Add(txtto.Text);//部署邮件的接受地址
        mms.Subject = txtsubiect.Text;//获取标题
        mms.Body = txtbody.Text;//获取邮件的内容
        SmtpClient sct = new SmtpClient(); //实例化邮件传输协议类
        sct.Credentials = new System.Net.NetworkCredential(txtform.Text, txtpwd.Text);//部署传输协议里面的账号和密码（密码指的是邮箱的授权码）
        sct.Host = " smtp.163.com";//部署传输主机的IP
        sct.Send(mms);//发送邮件
        Thread.Sleep(jiange);
    }
}
```