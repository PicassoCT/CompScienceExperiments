package UmlaufSort;

import java.util.ArrayList;


public class TheoComp {
	
	 boolean tasteField( ArrayList<BitObject> field)
	{ boolean conditionHoldsTrue=true;
		for (int i=0;i< field.size()-1;i++)
		{if (field.get(i).nrOfWorkcycles> field.get(i+1).nrOfWorkcycles)
		{conditionHoldsTrue=false;}
		}
			
		if (conditionHoldsTrue==true ){System.out.println("Stable State reached");}
		
	return conditionHoldsTrue;	
	}
	
	
	public static int UID =1;
	public static int circleNr=1;
	static ArrayList<ReadingHead> heads = new ArrayList<ReadingHead>();
	static ArrayList<BitObject>   inPutStream= new ArrayList<BitObject>();	
	static ArrayList<BitObject>   storedData= new ArrayList<BitObject>();
	
	
	 TheoComp(int nrOfReadingHeads, int objektAnzahl) 
	{
	for (int i=0;i<nrOfReadingHeads;i++)
	{
		ReadingHead temp;
		temp= new ReadingHead(false);
		heads.add(temp);
		
	}
	this.initSystem(objektAnzahl);
	}
	
	private void swapDice(ArrayList<BitObject> list)
	{int firstElement=(int) (Math.random()*list.size());
	 int secondElement=(int) (Math.random()*list.size());
	 BitObject temp;
	 temp=list.get(firstElement);
	 list.set(firstElement, list.get(secondElement));
	 list.set(secondElement, temp);
	}
	
	private void initSystem(int objektAnzahl)
	{
		for (int i=0;i < objektAnzahl;i++)
		{ double x= Math.random();
		
		 if (x <0.25f)			   { BitObject temp = new BitObject(UID,1);UID++;inPutStream.add(temp);}
		 if (x >=0.25f && x < 0.5f){ BitObject temp = new BitObject(UID,2);UID++;inPutStream.add(temp);}
		 if (x >=0.5f && x < 0.75f){ BitObject temp = new BitObject(UID,4);UID++;inPutStream.add(temp);}
		 if (x >=0.75f && x <=1)   { BitObject temp = new BitObject(UID,8);UID++;inPutStream.add(temp);}
			
			
		}
		for (int i=0;i < heads.size();i++)
		{heads.get(i).assignJob(inPutStream.get(1));
			
			
		}
		
	}
	
	private void emptyHeadsCycle()
	{boolean headsNotEmpty=true;
	System.out.println(circleNr+" n moves");
	if ( tasteField(storedData)==true  ) 
		{loopCondition =false;}
	TheoComp.circleNr=circleNr+1;
	while(headsNotEmpty)
	{    headsNotEmpty=false;
		for (int i=0;i < heads.size();i++)
			//if head.dataobject is not yet null
		{ if (heads.get(i).dataTooWorkOn!=null && heads.get(i).isStillBusy()==true)
			 {heads.get(i).dataTooWorkOn.runCycleStep();
			  heads.get(i).busy=heads.get(i).isStillBusy();
			  headsNotEmpty=true;}
		  
		  if (heads.get(i).dataTooWorkOn!=null &&heads.get(i).isStillBusy()==false)
		  	 {heads.get(i).storeBitObject();}
		}
		
	}
	
	}
	public static boolean loopCondition=true;
	public void operatingSystem () throws Exception
	{              printListFormatted(inPutStream);
		while(loopCondition)
		{
			for (int i=0;i < heads.size();i++)
			{   //perform a cycle
				if (heads.get(i).busy==true)
					 {heads.get(i).dataTooWorkOn.runCycleStep(); 
					  heads.get(i).busy=heads.get(i).isStillBusy();
					  }
				
			 // if head is no longer busy, after the cycle, store the object
			 if (heads.get(i).busy==false)
				{
				 
				 if (heads.get(i).dataTooWorkOn!=null)
				 {
					 heads.get(i).storeBitObject();
					 //and assign a new job and inPutStream is not empty
				if (inPutStream.size()>0)
					{
					heads.get(i).assignJob(inPutStream.get(0));
					}//theListis now empty
					else{
						emptyHeadsCycle();
						printListFormatted(storedData);
						System.out.println();
						System.out.println();
						inPutStream.addAll(storedData);
						//swapDice(inPutStream);
						//swapDice(inPutStream);
						//swapDice(inPutStream);
					 	storedData.clear();
							
						}
				 }else
				 {heads.get(i).assignJob(inPutStream.get(0));}
				
				
				}
			
			
			}
			/*a Cycle consists off running along the headlist, checking if anyone of them is unemployed,
			*and in Addition incrementing the workcount. If a head is found unemployed, the next Object is 
			*selcted from the List. If the list is empty, the cylce waits till all heads are finnished.
			*
			*It then prints the List, replaces the empty inPut Stream with the storedData, emptys the stored Data, and repeats another readWriteCycle
			*/
			
			
		}
		
		
		
	}

	private void printListFormatted(ArrayList<BitObject> X ) {
		int nrOfElementsInList=X.size();
		int counterUp=0;
		while(counterUp!=nrOfElementsInList && counterUp <nrOfElementsInList-25)
			{int internalCounter=0;String tempString= "";
				while(internalCounter<25)
				{tempString=tempString+X.get(counterUp+internalCounter).type;
					internalCounter++;
				}
			counterUp+=internalCounter;
			System.out.println(tempString);
				
			}
	
		
		
		
		}
		
		
	

}
