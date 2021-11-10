<%@  page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<link rel="stylesheet" href="layui/css/layui.css">
<title>Insert title here</title>
</head>
<body>
    <form action="add" method="post">
    &nbsp;<br>
    学号:<input type="text" name="sno" value=""><br>
    姓名:<input type="text" name="sname" value=""><br>
    性别:<input type="radio" name="ssex" value="男"><input type="radio" name="ssex" value="女"><br>
    专业:<input type="text" name="smajor" value=""><br>
    分数:<input type="text" name="sgrade" value=""><br>
    &nbsp;&nbsp;&nbsp;<input type="submit" name="submit" value="添加">
    <input type="reset" name="reset" value="取消"><br>
</form>
</body>
</html>
