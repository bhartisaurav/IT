class main
{
	public static void main(String args[]) throws InterruptedException
	{
		myThread kernel = new myThread("kernel");
                //System.out.println("Number of active threads from the given thread: " + Thread.activeCount()); //to get the active thread count
		kernel.setPriority(9);
		kernel.kernel_set_parameter(4,4);  //set size of freelist and hashqueue respectively.
		kernel.join(); //wait till thread execute its work.
		kernel.save_kernel_reference(); //get the object of kernel after calling kernel_set_parameter function.
 
		kernel.join(); //wait till thread execute its work.
		kernel.intializeFreeList(); //traverse the freelist and assign each buffer a block number.
		kernel.join(); //wait till thread execute its work.
		kernel.showFreeList(); // how the list of freelist buffer with block number and number of buffer in freelist.
		kernel.join(); //wait till thread execute its work.
		kernel.showHashQueue(); //initialize the hashqueue and initialy all are empty.
		kernel.join(); //wait till thread execute its work.

                //create the 4 objects of the thread and not started yet.
		myThread t = new myThread("Thread1"); 
		myThread t2 = new myThread("Thread2");
		myThread t3 = new myThread("Thread3");
		myThread t4 = new myThread("Thread4");
	  

		for(int i=1;i<=7;++i)
		{	
			t = new myThread("Thread"+Integer.toString(i)); //create a object of a thread. 
			t.start(); //now thread is in function.
			t.join(); //wait till thread execute its work.
			kernel.showHashQueue();
			kernel.showFreeList();
			// kernel.sleep(2000);
		}
		kernel.dontGiveUpLock = true;
		for(int i=8;i<=20;++i)
		{	
			t = new myThread("Thread"+Integer.toString(i));
			t.start();
			kernel.showHashQueue();
			kernel.join();
			kernel.showFreeList();
			kernel.join();
		}
	System.out.println("Number of active threads from the given thread: " + Thread.activeCount());
             
	}
}
