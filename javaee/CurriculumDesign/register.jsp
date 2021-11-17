<%@ page language="java" contentType="text/html;chatset=UTF-8" pageEncoding="UTF-8"%>
<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>
注册
</title>
</head>
<body>
<div class="pane"> 
    <form action="register" method="post" name="form" id="form">
        账号:<input type="text" name="username" value="" id="username"><br>
        密码:<input type="password" name="password" value="" id="password">
    </form>
    <button type="button" id="regist">注册</button>
</div>
</body>
<% 
String register=(String)request.getAttribute("register");
%>
<script>

    window.onload=function(){
        var regi="<%=register %>";
         if(regi=="false")
            alert("账号已存在");
    }
    
    function checknull() {
      var name =document.form.username;
      var pass=document.form.password;
      var subm=document.getElementById('form');
      if(name.value.length==0){
          alert("请输入账号");
      }else if(pass.value.length==0){
        alert("请输入密码");
        }else{
            subm.submit();
        }
   
    }
    
  
</script>
</html>