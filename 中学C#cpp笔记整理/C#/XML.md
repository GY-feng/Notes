# XML
```cs
       public static void Xml_No_prop()
        {
            //在内存中创建一个XML对象
            XmlDocument doc = new XmlDocument();
            //创建了第一行
            XmlDeclaration dec = doc.CreateXmlDeclaration("1.0", "utf-8", null);
            //将第一行放到doc当中
            doc.AppendChild(dec);//追加子节点
            //给文档创建根节点
            XmlElement books = doc.CreateElement("Books");


            //将创建的根节点添加到xml文档中
            doc.AppendChild(books);
            //给根节点再添加一个子节点
            XmlElement book = doc.CreateElement("Book");
            //给根节点加子节点
            books.AppendChild(book);
            //继续给book添加子节点:


            XmlElement name = doc.CreateElement("Name");
            name.InnerText = "金瓶梅";
            books.AppendChild(name);


            XmlElement price = doc.CreateElement("Price");
            price.InnerXml = "100";
            book.AppendChild(price);


            XmlElement comment = doc.CreateElement("Comment");
            comment.InnerText = "GOOD";
            books.AppendChild(comment);

            doc.Save("new.xml");//相对路径一般在debug下面
        }
       public static void Xml_With_prop()
        {
            XmlDocument doc = new XmlDocument();
            doc.AppendChild( doc.CreateXmlDeclaration("1.0", "utf-8", null));


            XmlElement Order = doc.CreateElement("Order");           
            doc.AppendChild(Order);


            XmlElement customerName = doc.CreateElement("CustomerName");
            customerName.InnerXml = "ZJF";
            Order.AppendChild(customerName);

            XmlElement items = doc.CreateElement("Item");
            Order.AppendChild(items);

            XmlElement orderItem1 = doc.CreateElement("OrderItem");
            //给标签设置属性,并且给属性赋值
            orderItem1.SetAttribute("Name", "棒棒糖");
            orderItem1.SetAttribute("Count", "100");
            items.AppendChild(orderItem1);

            doc.Save("newXml2.xml");
        }
    }
```