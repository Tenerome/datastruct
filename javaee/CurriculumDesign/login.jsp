<%@ page contentType="text/html; charset=UTF-8" %>
<%
	String login=(String)session.getAttribute("login");
%>
<html>
	<head>
		<meta charset="utf-8" />
		<title>登录</title>
		<link rel="stylesheet" type="text/css"href="./css/index.css"/>
		<link rel="stylesheet" type="text/css"href="./css/iconfont.css"/>
		<style>
		body{
			height: 100%;
			width: 100%;
            background: url('pic/bg1.jpg');
            background-size:cover;
		}
		</style>
	</head>
	<body>
		<div id="login-box">
			<h1>Login</h1>
			<form id='login' name='login' action="login" method="post">
			<div class="input-box">
				<i class="iconfont">&#xe609;</i>
				
				<input type="text" placeholder="UserName" name="username"/>
			</div>
			<div class="input-box">
				<i class="iconfont">&#xe605;</i>
				<input type="password" placeholder="UserPassword" name="password" />
			</div>
			<button>登录</button>
			</form>
		</div>
		
	</body>
<script type = "text/javascript">
        window.onload = function()
        {
            var ss="<%=login %>";
			if(ss=="false")
				alert("账号或密码错误");
        }
</script>
</html>

