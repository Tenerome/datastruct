<%@ page contentType="text/html; charset=UTF-8" %>
<%
	String ale=(String)session.getAttribute("alert");
%>
<script>
	function pop() {
		if(ale!=null)
			alert(ale);
	}
</script>
<div id="enter">
	<form id='login' name='login' action="login" method="post">
		<div>
			<label>用户名：</label>
			<input type="text" id="username" name="username">
			<span class="spants">请输入用户名</span>
		</div>
		<div>
			<label>密码：</label>
			<input type="password" id="password" name="password">
			<span class="spants">请输入密码</span>
		</div>
			
		<div class="addbt" style="border:0;">
			<input type="submit" value="登录" onclick="pop()" style="width:65px;"/>
			<input type="reset" value="取消" style="width:65px;"/>
		</div>
	</form>
</div>