# C_note_taking_SQL_compiler
A Dektop note taking app.Can search tagged notes with logic such as FIND(TAG1 OR TAG2 AND TAG3)  
# To add notes
ADD Note_ID
Note......
......  
END
# TAG Notes  
indication of end with -1
TAG todo NoteID_1 NoteID_2 NoteId_3 -1  
  
DISPLAY Note_ID  

# FIND by TAGS  
 FIND( todo ) => the system must find all notes that are tagged as ‘todo’  
 FIND AND( todo important ) ⇒ the system must find all notes that are tagged as
both ‘todo’ and ‘important’.  

FIND OR( todo AND( work important ) ) ⇒ the system must find all notes that
are tagged as either ‘todo’ or both ‘work’ and ‘important’.  

FIND AND( funny NOT( work ) ) ⇒ the system must find all notes that are tagged
as ‘funny’ but not ‘work’.  

FIND command sorted by the note id in
ascending order.  

# Test Case  
ADD 3  
Things todo for the 326 Hw !  
 * review dynamic memory allocation  
 * define the structs  
END  
TAG work 3 -1  
TAG todo 3 -1  
ADD 10  
Don't you know about the bird?  
Everybody's heard about the bird.  
END  
TAG fun 10 -1  
ADD 20  
*** Play with Lola & Luka ***  
          :)  
END  
TAG todo 20 -1   
TAG urgent 3 -1  
FIND AND( work )  
DISPLAY 3  
FIND AND( NOT( work ) fun )  
ADD 40  
Problems with pointers    
1. dangling pointers  
2. memory leaks   
END  
TAG pointer 40 -1  
TAG 426 40 -1  
TAG work 40 -1  
TAG new 20 40 -1  
FIND NOT( OR( todo urgent ) )  
ADD 50  
Flight details: ESB-TXL  
END  
TAG flight 50 -1  
TAG work 50 -1  
ADD 60  
Vacation: Azores   
* Flight: ESB-LIS  
END  
TAG flight 60 -1  
FIND AND( flight NOT( work ) )    
# RESULT
Results:  
Id: 3 Things todo for the 326 Hw !  
Id: 3  
Things todo for the 326 Hw !  
 * review dynamic memory allocation  
 * define the structs  
Results:  
Id: 10 Don't you know about the bird?  
Results:  
Id: 10 Don't you know about the bird?  
Id: 40 Problems with pointers  
Results:  
Id: 60 Vacation: Azores  
