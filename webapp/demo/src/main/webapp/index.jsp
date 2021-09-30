<%@ page language="java" contentType="text/html;chatset=UTF-8" pageEncoding="UTF-8"%>
<!doctype html>
<html>
<head>
<title>
this
</title>
<style>

</style>
</head>
<body>
<jsp:useBean id="test" scope="session" class="com.beans.test"/>
<%test.setNum(100);%>
<%=test.getNum()%>

</body>
</html>
