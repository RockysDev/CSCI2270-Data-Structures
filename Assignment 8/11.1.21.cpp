11/1
char []a "hello" h|e|l|l|o|\0 array
char *p = "world"  pointer to an array 

The name of an array is a pointer to the 1st eleemt of the array...
    contains the 1st elements address.

char x[3] = ['1','2','3']
x is a pointer to 1st element, pointer to a char

int main(int argc, char* argv[]){} // same as int argc, char ** argv
// terminal > ./a.out myprog -f input.txt 
argv[0] = ./a.out
argc = 4

char **argv points to an array of pointers.
    these pointers point to an array of chars. 
        argv** -> 0* -> [.,/,a,.,o,u,t, \0]
        
char *argv[] contains address of an array of pointers

 ---------- Assignment notes ----
 int **maze
    pointer of to array of ptrs with size of 5
        these ptrs go to array of ints.

 func createDefaultMaze(){
    int ** maze;
    maze = new int*[5];
    for(int i=0;i<5;i++){
        maze[i] = new int[n];
        for(int j=0;j<5;j++){
            maze[i][j] = 1;
        }
        
    }
    maze[0][0] = 0;
    maze[n-1][n-1] = 0;


}

createpath(0,3) makes this num in array a 0

convertmazetoadjlist{
    find where =! 0
    vertex  = fundvertix from oppsition(i,j) num
        addvertex(23)
        // creating a graph of all places where I have a 0
        
}

// Hashing 11/3

Big O of BST is O(log n) if its well balanced

Hashmap <- Java look up key get value; O(1)

Hashing
    Requires data to be specially organized
    Use of a hash table (array)
Compute h(x)
    Gives us the address of the item in the hash table
        Items are stored in no particular order
    
Hashtable or Hashmap

Data structure that maps a key to an index
Hash tables use a function to make a smaller representation of x
Hash tables store keys at the index 


Hash(my_node) = 71141232 <- Hash code, value or digest
    Hash Value is hex 16 base, 120 bits or 128

Same input same output.
Diff input, same output? <----- Collision

Hash function key mod 10 110%10 = array[6] = 116

void insert(key data){
    hash function(key) // tels us index
    item.data = data;
    hashArray[index] = item;
}

hash_func(word) -> HashCode = 32 bits in binary change to deci.

bucket_func(hashcode)// Value of first 8 bits minus 97 a = 97 ASCII
array x 23 xander.