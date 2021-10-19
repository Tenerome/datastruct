<%@ page language="java" contentType="text/html;chatset=UTF-8" pageEncoding="UTF-8" %>
    <!doctype html>
    <html>

    <head>
        <meta charset="UTF-8">
        <title>
            表单
        </title>
        <style>

        </style>
    </head>

    <body>
        <form action="output.jsp" method="post">
            <h3>请输入学生信息</h3>
            学号:<input type="text" name="no"><br>
            姓名:<input type="text" name="name"><br>
            性别:<input type="radio" name="sex" value="男">男
            <input type="radio" name="sex" value="女">女<br>
            爱好:<input type="checkbox" name="hobbies" value="文学">文学
            <input type="checkbox" name="hobbies" value="音乐">音乐
            <input type="checkbox" name="hobbies" value="体育">体育<br>
            专业:<select name="major">
                <option value="计算机科学与技术">计算机科学与技术</option>
                <option value="软件工程">软件工程</option>
                <option value="电子商务">电子商务</option>
            </select>
            <br>
                电话：<input type="text" name="phone"><br>

                <input type="submit" value="提交" />&nbsp;&nbsp;<input type="reset" value="重置">

        </form>

    </body>

    </html>