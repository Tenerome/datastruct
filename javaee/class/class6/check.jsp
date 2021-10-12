<%@ page language="java" contentType="text/html;chatset=UTF-8" pageEncoding="UTF-8"%>
<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>
检查
</title>
<style>

</style>
</head>
<body>
<%
String username=request.getParameter("username");
String password=request.getParameter("password");
if(username.equals("admin")&&password.equals("123456")){
    session.setAttribute("username",username);
    session.setAttribute("isOK","true");
    response.sendRedirect("index.jsp");
}else{
    session.setAttribute("username",username);
    session.setAttribute("isOK","false");
    response.sendRedirect("fail.jsp");
}
%>
</body>
</html>
