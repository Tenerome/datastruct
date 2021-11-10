<%@ page language="java" contentType="text/html; charset=UTF-8"%>
<%@ page import="java.util.*"%>
<%@ page import="java.text.*"%>
<html>
<head>
<meta http-equiv="refresh" content="60">
<title>起始页</title>
</head>
<body>
<%
	Date d = new Date();
	SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm");
	String now = df.format(d);
%>
当前时间：<%=now %>
<h1>欢迎使用选修课管理系统</h1>


</body>
</html>