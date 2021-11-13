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
    <form action="register" method="post" name="form">
        账号:<input type="text" name="username" value="" id="username"><br>
        密码:<input type="password" name="password" value="" id="password">
        <input type="button"  name="submit" value="注册" onclick="checknull()">
    </form>
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
     
      if(name.value.length==0){
          alert("请输入账号");
          location.reload();
      }else if(pass.value.length==0){
        alert("请输入密码");
        location.reload();    
        }else{
             form.submit.focus();
             form.submit.click();
        }
   
    }
  
</script>
</html>