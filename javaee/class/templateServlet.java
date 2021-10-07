
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
 
@WebServlet("/templateServlet")
public class templateServlet extends HttpServlet {
 
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
         response.setContextType("text/html;charset=UTF-8");
  
    }
 
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
 
}