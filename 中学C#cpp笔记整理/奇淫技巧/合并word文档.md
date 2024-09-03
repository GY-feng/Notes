```cs
using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using Microsoft.Office.Interop.Word;
using System.Reflection;
namespace 合并作业
{
    class Program
    {
        static void Main(string[] args)
        {
            string templatePathAll = "C:\\Users\\张向明\\Desktop\\new.docx";//一般是一个空文档

            string filesPath = "C:\\Users\\张向明\\Desktop\\高一九语文作业";//一个文件夹目录，里面是需要合并的文档

            string Path = "C:\\Users\\张向明\\Desktop\\语文作业.docx";//输出文档路径

            //WordDocumentMerger wordDocMerger = new WordDocumentMerger();
            //wordDocMerger.InsertMerge(templatePathAll, filesPath, Path);
            //Console.WriteLine("已经合并完成");
            unsafe
            {
                int* pointera;
                int hello = 1010;
                pointera = &hello;
                Console.WriteLine(&hello);
            }
          //  getfilename();
        }
       static public void getfilename()
        {

            String path = "C:\\Users\\张向明\\Desktop\\高一九语文作业";
            String newfile = "C:\\Users\\张向明\\Desktop\\文件名.txt";

            String filename = "";
            ////第一种方法
            //var files = Directory.GetFiles(path, "*.txt");

            //foreach (var file in files)
            //    Console.WriteLine(file);

            //第二种方法
            DirectoryInfo folder = new DirectoryInfo(path);

            foreach (FileInfo file in folder.GetFiles("*.doc"))
            {
                string a = file.FullName;
                filename = filename + Environment.NewLine + a;
            }
            Console.WriteLine("获取文件名完成");
            //保存txt
            if (!System.IO.File.Exists(newfile))
            {
                FileStream stream = System.IO.File.Create(newfile);
                stream.Close();
                stream.Dispose();
            }
            using (StreamWriter writer = new StreamWriter(newfile, true))
            {
                writer.WriteLine(filename);

            }
            Console.WriteLine("保存到txt完成");
            Console.ReadKey();
        }
    }
    public class WordDocumentMerger
    {
        Microsoft.Office.Interop.Word.Application objApp = null;
        Document objDocLast = null;
        Document objDocBeforeLast = null;
        public WordDocumentMerger()
        {
            objApp = new Application();
        }
        #region 打开文件
        public void Open(string tempDoc)
        {
            object objTempDoc = tempDoc;
            object objMissing = System.Reflection.Missing.Value;

            objDocLast = objApp.Documents.Open(
               ref objTempDoc, //FileName 
               ref objMissing, //ConfirmVersions 
               ref objMissing, //ReadOnly 
               ref objMissing, //AddToRecentFiles 
               ref objMissing, //PasswordDocument 
               ref objMissing, //PasswordTemplate 
               ref objMissing, //Revert 
               ref objMissing, //WritePasswordDocument 
               ref objMissing, //WritePasswordTemplate 
               ref objMissing, //Format 
               ref objMissing, //Enconding 
               ref objMissing, //Visible 
               ref objMissing, //OpenAndRepair 
               ref objMissing, //DocumentDirection 
               ref objMissing, //NoEncodingDialog 
               ref objMissing //XMLTransform 
               );
            objDocLast.Activate();
        }
        #endregion

        #region 保存文件到输出模板
        public void SaveAs(string outDoc)
        {
            object objMissing = System.Reflection.Missing.Value;
            object objOutDoc = outDoc;
            objDocLast.SaveAs(
            ref objOutDoc, //FileName 
            ref objMissing, //FileFormat 
            ref objMissing, //LockComments 
            ref objMissing, //PassWord 
            ref objMissing, //AddToRecentFiles 
            ref objMissing, //WritePassword 
            ref objMissing, //ReadOnlyRecommended 
            ref objMissing, //EmbedTrueTypeFonts 
            ref objMissing, //SaveNativePictureFormat 
            ref objMissing, //SaveFormsData 
            ref objMissing, //SaveAsAOCELetter, 
            ref objMissing, //Encoding 
            ref objMissing, //InsertLineBreaks 
            ref objMissing, //AllowSubstitutions 
            ref objMissing, //LineEnding 
            ref objMissing //AddBiDiMarks 
            );
        }
        #endregion

        #region 循环合并多个文件（复制合并重复的文件）
        /// <summary> 
        /// 循环合并多个文件（复制合并重复的文件） 
        /// </summary> 
        /// <param name="tempDoc">模板文件</param> 
        /// <param name="arrCopies">需要合并的文件</param> 
        /// <param name="outDoc">合并后的输出文件</param> 
        public void CopyMerge(string tempDoc, string[] arrCopies, string outDoc)
        {
            object objMissing = Missing.Value;
            object objFalse = false;
            object objTarget = WdMergeTarget.wdMergeTargetSelected;
            object objUseFormatFrom = WdUseFormattingFrom.wdFormattingFromSelected;
            try
            {
                //打开模板文件 
                Open(tempDoc);
                foreach (string strCopy in arrCopies)
                {
                    objDocLast.Merge(
                    strCopy, //FileName 
                    ref objTarget, //MergeTarget 
                    ref objMissing, //DetectFormatChanges 
                    ref objUseFormatFrom, //UseFormattingFrom 
                    ref objMissing //AddToRecentFiles 
                    );
                    objDocBeforeLast = objDocLast;
                    objDocLast = objApp.ActiveDocument;
                    if (objDocBeforeLast != null)
                    {
                        objDocBeforeLast.Close(
                        ref objFalse, //SaveChanges 
                        ref objMissing, //OriginalFormat 
                        ref objMissing //RouteDocument 
                        );
                    }
                }
                //保存到输出文件 
                SaveAs(outDoc);
                foreach (Document objDocument in objApp.Documents)
                {
                    objDocument.Close(
                    ref objFalse, //SaveChanges 
                    ref objMissing, //OriginalFormat 
                    ref objMissing //RouteDocument 
                    );
                }
            }
            finally
            {
                objApp.Quit(
                ref objMissing, //SaveChanges 
                ref objMissing, //OriginalFormat 
                ref objMissing //RoutDocument 
                );
                objApp = null;
            }
        }
        /// <summary> 
        /// 循环合并多个文件（复制合并重复的文件） 
        /// </summary> 
        /// <param name="tempDoc">模板文件</param> 
        /// <param name="arrCopies">需要合并的文件</param> 
        /// <param name="outDoc">合并后的输出文件</param> 
        public void CopyMerge(string tempDoc, string strCopyFolder, string outDoc)
        {
            string[] arrFiles = Directory.GetFiles(strCopyFolder);

        }
        #endregion

        #region 循环合并多个文件（插入合并文件）
        /// <summary> 
        /// 循环合并多个文件（插入合并文件） 
        /// </summary> 
        /// <param name="tempDoc">模板文件</param> 
        /// <param name="arrCopies">需要合并的文件</param> 
        /// <param name="outDoc">合并后的输出文件</param> 
        public void InsertMerge(string tempDoc, List<string> arrCopies, string outDoc)
        {
            object objMissing = Missing.Value;
            object objFalse = false;
            object confirmConversion = false;
            object link = false;
            object attachment = false;
            try
            {
                //打开模板文件 
                Open(tempDoc);
                foreach (string strCopy in arrCopies)
                {
                    objApp.Selection.InsertFile(
                    strCopy,
                    ref objMissing,
                    ref confirmConversion,
                    ref link,
                    ref attachment
                    );
                }
                //保存到输出文件 
                SaveAs(outDoc);
                foreach (Document objDocument in objApp.Documents)
                {
                    objDocument.Close(
                    ref objFalse, //SaveChanges 
                    ref objMissing, //OriginalFormat 
                    ref objMissing //RouteDocument 
                    );
                   // num++;
                    //Console.WriteLine("现在是第"+num+"份文件");
                }
            }
            finally
            {
                objApp.Quit(
                ref objMissing, //SaveChanges 
                ref objMissing, //OriginalFormat 
                ref objMissing //RoutDocument 
                );
                objApp = null;
            }
        }
        /// <summary> 
        /// 循环合并多个文件（插入合并文件） 
        /// </summary> 
        /// <param name="tempDoc">模板文件</param> 
        /// <param name="arrCopies">需要合并的文件</param> 
        /// <param name="outDoc">合并后的输出文件</param> 
        public void InsertMerge(string tempDoc, string strCopyFolder, string outDoc)
        {
            string[] arrFiles = Directory.GetFiles(strCopyFolder);
            int t_filenum = arrFiles.Length;
            Console.WriteLine("现在文件夹里面有" + t_filenum + "个文件");
            Console.WriteLine("输入OK并按下enter键开始执行合并");
            if (Console.ReadLine() == "OK")
            {
                CopyMerge(tempDoc, arrFiles, outDoc);
            }
            else
            {
                Console.WriteLine("合并的操作被停止");
            }
            List<string> files = new List<string>();
            for (int i = 0; i < arrFiles.Count(); i++)
            {
                if (arrFiles[i].Contains("doc"))
                {
                    files.Add(arrFiles[i]);
                }
            }
            InsertMerge(tempDoc, files, outDoc);
        }
        #endregion

        #region 合并文件夹下的所有txt文件

        /// <summary>
        /// 合并多个txt文件
        /// </summary>
        /// <param name="infileName">文件存在的路劲</param>
        /// <param name="outfileName">输出文件名称</param>
        public void CombineFile(string filePath, string outfileName)
        {
            string[] infileName = Directory.GetFiles(filePath, "*.txt");
            int b;
            int n = infileName.Length;
            FileStream[] fileIn = new FileStream[n];
            using (FileStream fileOut = new FileStream(outfileName, FileMode.Create))
            {
                for (int i = 0; i < n; i++)
                {
                    try
                    {
                        fileIn[i] = new FileStream(infileName[i], FileMode.Open);
                        while ((b = fileIn[i].ReadByte()) != -1)
                            fileOut.WriteByte((byte)b);
                    }
                    catch (System.Exception ex)
                    {
                        Console.WriteLine(ex.Message);
                    }
                    finally
                    {
                        fileIn[i].Close();
                    }
                }
            }
        }
        #endregion
    }
}
```