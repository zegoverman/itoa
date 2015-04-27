char* itoa(int a_Num) {
	//function to convert an integar into a null terminated string
	char *pointer;
	try{
		pointer = new char[]; 	//needs to be dynamically allocated so pointer is initialised
		//chose to use a new pointer so I don't need to specify a particular array size (it will expand to that needed for the int)
	}
	catch (bad_alloc xa){
		return "memory allocation failed";
	}
	int i = 10, j = 0, num = a_Num, remainder;
	if (a_Num >= 0){
		do{
			remainder = num % i;			//find the last digit of the number
			num = num / i;					//then find the number without the last digit (i.e 567 goes to 56) by dividing by 10 and make it the new num
			*(pointer + j) = '0' + remainder; //convert remainder into an ASCII character and put into the pointer
			j++;							//increment pointer position
		} while (num != 0);					//exits when you've reached the end of the int number
		*(pointer + j) = 0;					//null terminate the string
		
		for (int k = 0; k < j; k++, j--){   //now reverse the position of the characters 
			char temp = *(pointer + j - 1); //end of the pointer string
			*(pointer + j - 1) = *(pointer + k);
			*(pointer + k) = temp;
		}
	}
	else {
		do{
			remainder = num % i;			//find the last digit of the number
			num = num / i;					//then find the number without the last digit (i.e 567 goes to 56) by dividing by 10 and make it the new num
			*(pointer + j) = '0' - remainder; //convert remainder into an ASCII character and put into the pointer
			j++;							//increment pointer position
		} while (num != 0);					//exits when you've reached the end of the int number
		*(pointer + j) = '-';				//add the minus charcter to the end of the pointer
		*(pointer + j + 1) = 0;				//null terminate the string
		
		for (int k = 0; k < j; k++, j--){   //now reverse the position of the characters
			char temp = *(pointer + j);     //end of the pointer string
			*(pointer + j) = *(pointer + k);
			*(pointer + k) = temp;
		}
	}
	
	//The user needs to delete the pointer after using this function at some point! Probably the class destructor

	return pointer; 
}
