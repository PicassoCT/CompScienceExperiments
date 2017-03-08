package UmlaufSort;

public class BitObject {
	BitObject(int UniqueIdentifier, int cyclesToWork){
		this.UID=UniqueIdentifier;
		this.nrOfWorkcycles=cyclesToWork;
		switch (cyclesToWork)
		{case 8: {this.type='d';break;} 
		 case 4: {this.type='c';break;} 
		 case 2: {this.type='b';break;} 
		 case 1: {this.type='a';break;} 
		default:  {System.out.println("Error: Cylce Number ouf of bounds");}
			}
		this.saveCopyNrOfWorkCycles=this.nrOfWorkcycles;
		
	}
	int UID;
	int nrOfWorkcycles=0;
	int saveCopyNrOfWorkCycles=0;
	char type;
	
	//performs the cycle, returns true if the Object is done for

	
	void runCycleStep()
	{this.nrOfWorkcycles--;}
	


}
