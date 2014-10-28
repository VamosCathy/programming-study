import java.io.*;
import javax.servlet.http.*;
import javax.servlet.ServletException;

public class Guessing extends HttpServlet {

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		HttpSession se = request.getSession();
		//设置猜测次数
		Integer guessCount = (Integer)se.getAttribute("guessCount");
        guessCount++;
        se.setAttribute("guessCount", guessCount);

        String guessNumberString = request.getParameter("guessNumber");
        int guessNumber = Integer.parseInt(guessNumberString);
        se.setAttribute("guessNumber", guessNumber);

        Integer answer = (Integer)se.getAttribute("answer");//获得实际的数字
        String hint = "";
        if(guessNumber < answer){
        	hint = "你猜的数字偏小了，再猜猜？";
        	se.setAttribute("hint", hint);
        	se.setAttribute("minNumber",guessNumber);
        	request.getRequestDispatcher("/result.jsp").forward(request,
    				response);
        }else if(guessNumber>answer){
        	hint = "你猜的数字偏大了，再猜猜？";
        	se.setAttribute("hint", hint);
        	se.setAttribute("maxNumber",guessNumber);
        	request.getRequestDispatcher("/result.jsp").forward(request,
    				response);
        }else{
        	hint = "Bingo！";
        	se.setAttribute("hint", hint);
        	request.getRequestDispatcher("/bingo.jsp").forward(request,
    				response);
        }
	}
}