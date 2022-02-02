class freeListEmptyEvent
{
	boolean freeListEmpty;
	freeListEmptyEvent()
	{ //constructor.
		System.out.println("\nFree List Now Empty\n");
		this.freeListEmpty = false;
	}
	void freeListEmptyNow()
	{
		this.freeListEmpty = true;
	}
	void freeListNotEmptyNow()
	{
		this.freeListEmpty = false;
	}
}
