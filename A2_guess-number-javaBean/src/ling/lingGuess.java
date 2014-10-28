package ling;
public class lingGuess
{ int answer,    
      guessNumber, 
      numGuess=0;  
  boolean success;
  String hint=null; 
  public void setAnswer(int n)
   { answer=n;
     numGuess=0;
   }  
  public int  getAnswer()
   {return answer;
   }
 public void  setGuessNumber(int n)
   { guessNumber=n;
     numGuess++;
     if(guessNumber==answer)
     { success=true;
         hint="Bingo！猜对了";}
    else if(guessNumber>answer)
    {   success=false;
         hint="比结果大了";}
     else if(guessNumber<answer)
     {  success=false;
         hint="比结果小了";    }
   }
  public int getGuessNumber()
   {return guessNumber;
   }
  public int getnumGuess()
   {return numGuess;
   }
  public String gethint()
   {return hint;
   }
  public boolean getsuccess()
   {return success;
   }
 }