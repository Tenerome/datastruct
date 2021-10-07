package com.servlets;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

 
//@WebServlet("/servlet")
public class servlet extends HttpServlet {
 
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out=response.getWriter();
        out.println("Hello,World");
  
    }
 
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
 
}