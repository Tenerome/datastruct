<%@ page language="java" contentType="text/html;chatset=UTF-8" pageEncoding="UTF-8"%>
<!doctype html>
<html>
<head>
<title>

</title>
<style>

</style>
</head>
<body>
<%
String user=request.getParameter("user");
String password=request.getParameter("password");
if(user.equals("admin") && password.equals("123456"))
    response.sendRedirect("index.jsp");
    
else
    response.sendRedirect("fail.jsp");
%>

</body>
</html>
