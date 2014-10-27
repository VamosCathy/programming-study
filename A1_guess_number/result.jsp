<%@ page language="java" isErrorPage="false" errorPage="error.jsp" contentType="text/html;charset=utf-8" %>
<html>
<head>
	<title>猜数字游戏</title>
</head>
<body>
	<%
	int gusnum;
	try{
		gusnum = Integer.parseInt(request.getParameter("gusnum"));//获得猜测的数字
	}
	catch(NumberFormatException nfex){
		throw new NumberFormatException("请输入一个整数！");
	}
	int max = ((Integer)session.getAttribute("maxNumber")).intValue();
	int min = ((Integer)session.getAttribute("minNumber")).intValue();
	int realnum = ((Integer)session.getAttribute("save")).intValue();

	int n = ((Integer)session.getAttribute("count")).intValue();
	n = n + 1;
	session.setAttribute("count",new Integer(n));

	if(gusnum == realnum){
	response.sendRedirect("bingo.jsp");
	}
	else if(gusnum > realnum){
	max = gusnum;
	session.setAttribute("maxNumber",new Integer(max));
	response.sendRedirect("larger.jsp");
	}
	else if(gusnum < realnum){
	min = gusnum;
	session.setAttribute("minNumber",new Integer(min));
	response.sendRedirect("smaller.jsp");
	}

	%>
</body>
</html>