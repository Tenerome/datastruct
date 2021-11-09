import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.servlet.http.HttpServletRequest;

public class user {
    private String username, password;
    public user(String username,String password){
        super();
        this.username=username;
        this.password=password;
    }
    public user(){
        return user("","");
    }
    public user(HttpServletRequest request) {	
		this.username = request.getParameter("username")==null?"":request.getParameter("username");
		this.password = request.getParameter("password")==null?"":request.getParameter("password");
	}

    public boolean check(){
        
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

}