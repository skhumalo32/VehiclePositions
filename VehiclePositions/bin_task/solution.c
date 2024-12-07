/* 
 * Use your preferred naming convention
 * Add comments to help others to understand your code and to document assumptions
 * You are welcome to add additional files if required
 */
   
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//defining the struct to hold vehicle data position
struct VehiclePosition {
    uint32_t position_id;
    char vehicle_registration[64];
    float latitude;
    float longitude;
    uint64_t timestamp;
}

int main(){
    
    //Declare binary file name
    const char* filename = "C:/bin_project/VehiclePositions/bin_task/VehiclePositions.dat";

    //Opening the binary file for reading
    FILE* file = fopen(filename, "rb");
    if (file == NULL){
        perror("File Open Error");
        return 1;
    }

    //Calculating number of elements in the array
    fseek(file, 0, SEEK_END); // File pointer to the end
    long file_size = ftell(file); //getting current pointer location
    rewind(file);

    
    //Allocayr memory to store contents
    unsigned char* buffer = (unsigned char*)malloc(file_size);
    if (buffer == NULL){
        perror("Memory Allocation error");
        fclose(file);
        return 1;
    }

    //Read file into the buffer
    size_t bytes_read = fread(buffer, 1, file_size, file);
    if (bytes_read != (size_t)file_size){
        perror("File Reading Error");
        free(buffer);
        fclose(file);
        return 1;
    }


    //Buffer contains the binar data from file.
    // Data Processing








    
    printf("Program Run Successful");
    fclose(file);
    free(buffer);
    return 0;

}