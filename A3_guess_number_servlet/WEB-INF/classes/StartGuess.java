import java.io.*;
import javax.servlet.http.*;
import javax.servlet.ServletException;

public class StartGuess extends HttpServlet {

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		int realnumber = (int) (Math.random() * 100) + 1;//实际的数字
		HttpSession se = request.getSession();
		se.setAttribute("maxNumber",100);
		se.setAttribute("minNumber",0);
		se.setAttribute("answer", realnumber);//answer表示猜测的数字
		se.setAttribute("resString", "游戏开始");
		se.setAttribute("guessCount", 0);//猜测次数
		request.getRequestDispatcher("/begin.jsp").forward(request,response);
	}
}