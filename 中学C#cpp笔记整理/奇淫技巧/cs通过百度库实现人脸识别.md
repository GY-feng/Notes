人脸识别代码：
```cs
static void Main(string[] args)
{
    var API_KEY = "779kbhYPiKz7ZoxaiVQLYTZn";//ApiKEY码
    var SECRET_KEY = "CFaytkSZz9v5e5NADxCDArNEK90AbpoM";
    var client = new Baidu.Aip.Face.Face(API_KEY, SECRET_KEY);
    client.Timeout = 60000;//修改超过时间
    Console.WriteLine("请输入上传人脸的人脸的网页地址");
    var image = Convert.ToString(Console.ReadLine());
    var imageType = "URL";
    var groupId="group1";
    var userId = "user1";
    var result = client.UserAdd(image, imageType, groupId, userId); 
    Console.WriteLine(result);
    var options = new Dictionary<string, object> { { "user_info", "user's info" }, { "quality_control", "NORMAL" }, { "livenese_control", "LOW" } };
    //调用参数人脸识别
    result = client.UserAdd(image, imageType, groupId, userId, options);
    Console.WriteLine(result);
    Console.WriteLine("人脸上传成功");
    Console.ReadKey();

}
```
