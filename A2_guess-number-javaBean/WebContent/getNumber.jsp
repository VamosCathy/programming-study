<%@page pageEncoding="UTF-8" contentType="text/html; charset=UTF-8"%>
<%@ page import="ling.lingGuess" %> 
<HTML>
<BODY>
<%
	int n=(int)(Math.random()*100)+1;
%>
<jsp:useBean id="guess" class="ling.lingGuess" scope="session" >
</jsp:useBean>
<jsp:setProperty  name= "guess"  property="answer" value="<%=n%>" />
<p>1-100系统会随机产生一个随机数，用户可以猜测该数字是什么
<% String str=response.encodeRedirectURL("guess.jsp");
%>
<Form action="<%=str%>" method=post >
<BR>我觉得是： <Input type=text name="guessNumber">
<Input type=submit value="OK">
</FORM>
</BODy>
</html>