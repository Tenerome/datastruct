<%@ page language="java" contentType="text/html; charset=UTF-8"  pageEncoding="UTF-8"%>
<%@ page import="com.entity.Student"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>输出</title>
</head>
<body>
<%request.setCharacterEncoding("UTF-8"); %>
<jsp:useBean id="stu" class="com.entity.Student" scope="page"></jsp:useBean>
<jsp:setProperty name="stu" property="name" param="name"/>
<jsp:setProperty name="stu" property="no" param="no"/>
<jsp:setProperty name="stu" property="sex" param="sex"/>
<jsp:setProperty name="stu" property="major" param="major"/>
<jsp:setProperty name="stu" property="phone" param="phone"/>

<jsp:getProperty name="stu" property="no"/>
<jsp:getProperty name="stu" property="name"/>
<jsp:getProperty name="stu" property="major"/>
<jsp:getProperty name="stu" property="sex"/>
<jsp:getProperty name="stu" property="phone"/>

</body>
</html>