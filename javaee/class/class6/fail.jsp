<%@ page language="java" contentType="text/html;chatset=UTF-8" pageEncoding="UTF-8"%>
<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>
失败
</title>
<style>

</style>
</head>
<body>
<%
    String username=(String)session.getAttribute("username");
%>
<%=username%>,登录信息错误,请<a href="login.jsp">返回</a>重新登录

</body>
</html>
