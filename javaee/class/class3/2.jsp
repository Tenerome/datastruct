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
String id=request.getParameter("id");
String name=request.getParameter("name");

out.println("您的学号:"+id);
out.println("您的姓名:"+name);
%>
</body>
</html>
