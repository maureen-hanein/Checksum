#include <iostream>
#include <climits>

unsigned int add_checksum( unsigned int n);
void add_checksum( unsigned int array[], std::size_t capacity);
bool verify_checksum( unsigned int n);
unsigned int remove_checksum( unsigned int n);
void remove_checksum( unsigned int array[], std::size_t capacity);

#ifndef MARMOSET_TESTING
int main();
#endif

#ifndef MARMOSET_TESTING
int main() {
unsigned int value_to_protect{21352411};
unsigned int protected_value = add_checksum(value_to_protect);
std::cout << "The value " << value_to_protect
<< " with the checksum added is " << protected_value
<< "." << std::endl;
if (verify_checksum(protected_value))
{
std::cout << "The checksum is valid." << std::endl;
}
else {
std::cout << "The checksum is invalid." << std::endl;
}
const std::size_t QTY_VALUES {3};
unsigned int value_series[QTY_VALUES] {20201122, 20209913, 20224012};
add_checksum(value_series, QTY_VALUES);
std::cout << "Series with checksums added: ";
for (std::size_t series_index {0};
series_index < QTY_VALUES; series_index++)
{
std::cout << value_series[series_index] << " ";
}
std::cout << std::endl;
return 0;
}
#endif

//add checksum 

unsigned int add_checksum( unsigned int n) {

if (n> 99999999){
	return UINT_MAX ;
}
else {
int num = n;
int array[8]{};
for(int i=7; i>=0; --i) {
	array[i]= num%10;
	num = num/10;
}

array[7]= array[7]*2;
array[5]= array[5]*2;
array[3]= array[3]*2;
array[1]= array[1]*2;

array[7]=(array[7]%10) + (array[7]/10);
array[6]=(array[6]%10) + (array[6]/10);
array[5]=(array[5]%10) + (array[5]/10);
array[4]=(array[4]%10) + (array[4]/10);
array[3]=(array[3]%10) + (array[3]/10);
array[2]=(array[2]%10) + (array[2]/10);
array[1]=(array[1]%10) + (array[1]/10);
array[0]=(array[0]%10) + (array[0]/10);

int checksum; 
checksum = array[7] + array[6] + array[5] + array[4] + array[3] + array[2] +array[1] + array[0];
checksum = checksum *9;
checksum = checksum%10;

n= n*10;
n= n + checksum;
return n;
}
}

void add_checksum( unsigned int array[], std::size_t capacity) {
	for (int i=0; i< capacity; i++){
		array[i]= add_checksum( array[i]);
	}
}


//verify the checksum 
bool verify_checksum( unsigned int n) {
	int u = n/10;
if ( n > 999999999 || n != add_checksum(u)) {
	return false;
}

else {
    return true;
}
}

//remove checksum 
unsigned int remove_checksum( unsigned int n) {
 int a= n;
 if ( verify_checksum(a) == false) {
	return UINT_MAX; 
 }
 else {
	 n = n/10;
	 return n;
 }

}

void remove_checksum( unsigned int array[], std::size_t capacity) {

for (int i=0; i< capacity; i++){
		array[i]= remove_checksum( array[i]);
}
} 