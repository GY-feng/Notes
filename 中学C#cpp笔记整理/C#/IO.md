# IO
文件/文件夹是否存在：
```cs
File.Exists(FileAdress);
Directory.Exists(DirectoryAdress);
```
```cs
FileInfo fileInfo = new FileInfo(FileNAme);
/*
FileInfo 是 System.IO 命名空间中的一个类，用来表示文件的信息。通过 FileInfo 对象，可以访问文件的各种属性和方法，例如文件是否存在、文件大小、创建时间等。
这里创建了一个 FileInfo 对象 fileInfo，它代表了名为 FileNAme 的文件（即 "测试.txt"）的信息。
*/
if (fileInfo.Exists)//判断文件是否存在，Exists为属性
{
    MessageBox.Show("文件已经存在");
}
```
```cs
static void Main(string[] args)
{
    //一，使用Exists判断指定的文件是否存在；
    //1,判断文件的存在
    Console.WriteLine(File.Exists(@"D:\Test"));
    Console.WriteLine(File.Exists(@"D:\Test\DOC\测试.doc"));
    string FileAddress = @"D:\Test\DOC\测试.doc";

    FileInfo fileInfo = new FileInfo(FileAddress);//要求传入一个文件地址
    if (fileInfo.Exists)
    {
        Console.WriteLine("CunZai");
    }
    //2，判断文件夹的存在
    string FileAddress2 = @"D:\Test\AA";
    Console.WriteLine(Directory.Exists(FileAddress2));
    DirectoryInfo directoryInfo = new DirectoryInfo(FileAddress2);
    if (directoryInfo.Exists)
    {
        Console.WriteLine("JIACunZai");
    }
    //二，创建文件，文件夹
    string CreateFileName = @"D:\Test\AA\TESTAA.CS";//创建文件的目录和创建的文件名字
    File.Create(CreateFileName);//创建文件的目录和创建的文件名字
    Console.WriteLine("文件创建成功");

    string CreateDirectoryName = @"D:\Test\BB\XINJIANWENJIANJIA";//创建文件夹的路径和创建的文件夹名字
    Directory.CreateDirectory(CreateDirectoryName);
    Console.WriteLine("文件夹创建成功");

    string CreateDirectoryName2 = @"D:\Test\BB\XINJIANWENJIANJIA222222222222222";
    DirectoryInfo directoryInfo1 = new DirectoryInfo(CreateDirectoryName2);//传入新建的文件的路径和名字
    directoryInfo1.Create();
}
```
复制和剪贴：
```cs
//COPY和MOVE
string BeforeCopy = @"D:\Test\IO5A\IO5A.doc";
string AfterCopy = @"D:\Test\IO5B\IO5A.doc";
File.Copy(BeforeCopy,AfterCopy);//将BeforeCopy复制到AfterCopy
////使用CopyTo,MoveTo则在目标路径下有相同文件时，则替换文件
File.Move(BeforeCopy, AfterCopy);
```
获取文件的信息：
```cs
private void button1_Click(object sender, EventArgs e)
{
    if (openFileDialog1.ShowDialog()==DialogResult.OK)
    {
        string ct, la, lw, n, fn, dn, ir;
        long l;
        textBox1.Text = openFileDialog1.FileName;
        FileInfo fileInfo = new FileInfo(openFileDialog1.FileName);
        n = fileInfo.Name;//获取文件名
        ct = fileInfo.CreationTime.ToShortDateString();//获取创建时间
        la = fileInfo. LastAccessTime.ToShortDateString();//获取上次访问文件的时间
        lw = fileInfo.LastWriteTime.ToShortDateString();//获取上次写入文件的时间
        fn = fileInfo.FullName;//获取文件完整目录
        dn = fileInfo.DirectoryName;//获取文件完整路径
        ir = fileInfo.IsReadOnly.ToString();//获取文件是否为只读
        l = fileInfo.Length;//获取文件的长度
        MessageBox.Show("文件的基本信息：\n文件名：" + n + "\n创建时间" + ct + "\n上次访问文件的时间" + la + "\n上次写入文件的时间" + lw + "\n文件完整目录" + fn + "\n文件完整路径" +
            dn + "\n文件是否为只读" + ir + "\n文件的长度" + l);
    }
}
```

使用Path类：
```cs
string str = @"D:\Test\张.wav";
//获得文件名
Console.WriteLine(Path.GetFileName(str));
//获得文件名但不包括扩展名
Console.WriteLine(Path.GetFileNameWithoutExtension(str));
//获得文件的扩展名
Console.WriteLine(Path.GetExtension(str));
//获得文件所在的文件夹的名字
Console.WriteLine(Path.GetDirectoryName(str));
//获得文件所在的全路径
Console.WriteLine(Path.GetFullPath(str));
//连接两个字符串作为路径
Console.WriteLine(Path.Combine(@"c:\TEST\","BBBBBBb.txt"));
Console.ReadKey();
```
写文件：
```cs
string FileAddress = @"D:\Test\WRITE\write.txt";
StreamReader streamReader = new StreamReader(FileAddress);
string TXTthing = streamReader.ReadLine();//Read the things in the file;
Console.WriteLine("文件原有内容：");
Console.WriteLine(TXTthing);
streamReader.Close();

StreamWriter streamWriter = new StreamWriter(FileAddress);

Console.WriteLine("请输入您想要传入的文字:");
string writethings = Console.ReadLine();

streamWriter.Write(writethings);
streamWriter.Close();
```
