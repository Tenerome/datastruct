<%@ page language="java" contentType="text/html;chatset=UTF-8" pageEncoding="UTF-8"%>
<%
	String login=(String)session.getAttribute("login");
%>
<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>
登录
</title>

</head>
<body>
<script type = "text/javascript">
        window.onload = function()
        {
            var ss="<%=login %>";
			if(ss=="false")
				alert("账号或密码错误");
        }
</script>

	<form id='login' name='login' action="login" method="post">
			用户名:<input type="text" id="username" name="username"><br>
			密码:<input type="password" id="password" name="password"><br>
			<input type="submit" value="登录"/>
			<input type="reset" value="取消">
	</form>
</body>
</html>