<%@ page contentType="text/html; charset=UTF-8" %>
<html>
<head>
<title>选修课管理系统</title>
<link rel="stylesheet" type="text/css" href="css/main.css" />
<link rel="stylesheet" type="text/css" href="css/table.css" />
</head>
<body>

    <div id="top"><h1 class="header">选修课管理系统</h1></div>
    <div id="main">
        <div id="leftMenu">
             <ul>
                 <li><a href="index.jsp?operate=welcome.jsp">主页</a></li>
                 <li><a href="index.jsp?operate=find.jsp">查询</a></li>
                 <li><a href="index.jsp?operate=add.jsp">添加</a></li>
                 <li><a href="index.jsp?operate=addMajor.jsp">专业维护</a></li>
                 <li><a href="#">退出</a></li>
            </ul>
        </div>
        <div id="content">        
        <jsp:include page='<%=request.getParameter("operate")==null?"welcome.jsp":request.getParameter("operate")%>'/>                
        
           
        </div>
    </div>
    <div id="footer">©2021 Tenerome:&nbsp;&nbsp;help&nbsp;&nbsp;feekback&nbsp;&nbsp;</div>

</body>
</html>