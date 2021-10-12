<%@ page language="java" contentType="text/html;chatset=UTF-8" pageEncoding="UTF-8"%>
<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>
计数
</title>
<style>

</style>
</head>
<body>
<%
    Integer co=(Integer)application.getAttribute("count");
    int num=1;
    if(co!=null)
        num=co.intValue();
    if(session.isNew())
        num++;
    application.setAttribute("count",Integer.valueOf(num));
    out.println("您是第"+num+"位访问者");
%>

</body>
</html>
