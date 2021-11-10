<%@ page language="java" contentType="text/html;chatset=UTF-8" pageEncoding="UTF-8"%>
<%
String aa="hdwaw";
%>
<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>

</title>
<style>

</style>
</head>
<body>
<input type="submit" name="submit" onclick="pop()" value="">
<%=aa %>
</body>
<script>
    function pop(){
        var bb="<%=aa %>";
        alert(bb);
    }
</script>
</html>