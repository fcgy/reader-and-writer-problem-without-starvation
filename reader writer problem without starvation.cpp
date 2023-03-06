public class Database {

 int rc = 0; // reader count
 boolean writing=false; // weather the process is busy with writing
 int waitingWriters = 0; // number of processes which are waiting for write 
 boolean readersTurn = false;
Semaphore s=0;// binary semaphore

// entry section for readers

public void startRead(){ 

if(writing || waitingWriters > 0 && !readersTurn){
    wait(s);
}
else{
    ++rc;
}

// DATA BASE ie. CRITICAL SECTION

public void readOver(){ //exit section for readers

--rc;
 readersTurn = false;
  if(readers == 0){
    
    signal(s);
    wait(s);
      } 
   }
}

//entry section for writers

 public void startWrite(){
    if(readers > 0 || writing){
++waitingWriters; 
wait(s);
 }

 // DATA BASE ie. CRITICAL SECTION

--waitingWriters;
 writing = true;

public void writeOver(){ //exit section for writers

writing = false;
 readersTurn = true;
 
  signal(s);
    wait(s);
      
      }
   }
}