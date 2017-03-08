package UmlaufSort;



public class ReadingHead {
	 ReadingHead(boolean buisNessy) {
		this.busy=buisNessy;
	}
	 
	boolean busy;

	BitObject dataTooWorkOn;
	
	public void assignJob(BitObject dataObject)
	{this.busy=true;
	 this.dataTooWorkOn=dataObject;
	 TheoComp.inPutStream.remove(0);
	}
	
	public boolean  isStillBusy()
	{
	if (this.dataTooWorkOn.nrOfWorkcycles==0)
	{return false;}
	else{
		return true;
		}
	}
	
	
	void storeBitObject()
	{       this.dataTooWorkOn.nrOfWorkcycles=this.dataTooWorkOn.saveCopyNrOfWorkCycles;
			TheoComp.storedData.add(this.dataTooWorkOn);
		    this.busy=false;
		    this.dataTooWorkOn=null;
	}

}
