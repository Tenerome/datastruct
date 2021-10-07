<%@ page language="java" contentType="text/html;chatset=UTF-8" pageEncoding="UTF-8"%>
<!doctype html>
<html>
<head>
<title>
this is a table
</title>
<style>
#customers {
  font-family: Arial, Helvetica, sans-serif;
  border-collapse: collapse;
  width: 100%;
}

#customers td, #customers th {
  border: 1px solid #ddd;
  padding: 8px;
}

#customers tr:nth-child(even){background-color: #f2f2f2;}

#customers tr:hover {background-color: #ddd;}

#customers th {
  padding-top: 12px;
  padding-bottom: 12px;
  text-align: left;
  background-color: #4CAF50;
  color: white;
}
</style>
</head>
<body>
<%
out.println("<table id='customers'>");
for(int i=1;i<=200;i++){
    out.println("<tr>");
    for(int j=1;j<=10;j++){
        out.println("<td>");
        out.println(i+":"+j);
        out.println("</td>");
    }
    out.println("</tr>");
}
out.println("</table>");
%>
</body>
</html>
