<%@ page language="java" contentType="text/html;chatset=UTF-8" pageEncoding="UTF-8"%>
<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>
登录成功
</title>
<style>

</style>
</head>
<body>
<%
    String username=(String)session.getAttribute("username");
    String isOK=(String)session.getAttribute("isOK");
    if(!isOK.equals("true"))
        response.sendRedirect("login.jsp");
%>
<%=username%>,登录成功,欢迎您
</body>
</html>
