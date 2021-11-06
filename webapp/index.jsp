<!DOCTYPE html>
<html lang="en">
    <head>
        <title></title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="css/style.css" rel="stylesheet">
    </head>
    <body>
        <%!//获取客户端的IP
        public String getRemoteIP(HttpServletRequest request) { 
            if (request.getHeader("x-forwarded-for") == null) { 
                return request.getRemoteAddr(); 
            } 
            return request.getHeader("x-forwarded-for"); 
        }%> 
        <%　　String ip = getRemoteIP(request);
            URL url = new URL("http://ip.taobao.com/service/getIpInfo.php?ip=" + ip);//使用的IP库是淘宝IP库
            HttpURLConnection urlConn = (HttpURLConnection)url.openConnection();
        
            InputStream res = urlConn.getInputStream();
            Scanner scanner = new Scanner(res);
            String urlContent = "";
            while (scanner.hasNextLine()) {
                urlContent += (String)scanner.nextLine();
            }
            
            System.out.println(urlContent);%>
    </body>

</html>