/**********
 * demo for lab1
 * Elayne Trimble
 * *******/

#include <iostream>
using namespace std;


struct flower{
    char color;
    int height;
};

/***creating a dynamically allocated 2d array***/
flower** create_garden_box(int rows, int cols){
    //create the dynamically allocated array of type flower*
    flower** garden = new flower*[rows];

    //allocating another array of size cols of type flower
    for(int i = 0; i < rows; i++){
        garden[i] = new flower[cols];
    }

    //set each spot with a color of flower
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << endl << "What color is the flower in this box(r-red, b-blue, y-yellow): ";
            cin >> garden[i][j].color;
            cout << "What's it's height?: ";
            cin >> garden[i][j].height;
        }
    }

    return garden;
}

/*Printing out the garden*/
void view_garden(flower** garden, int rows, int cols){
    cout << endl << "Here is your garden:" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << garden[i][j].color << " ";
        }
        cout << endl;
    }
}

/*deleting the allocated memory in heap*/
void free_garden(flower ** garden, int rows, int cols){
    for(int i = 0; i < rows; i++){
        delete [] garden[i];
    }
    
    delete [] garden;
}

int main(){
    //ask how many rows and cols
    cout << "How many rows and colums do you want on your garden: ";

    cout << "Rows: ";
    int rows;
    cin >> rows;

    cout << "Columns: ";
    int cols;
    cin >> cols;

    //send rows and cols into the create func
    flower** garden = create_garden_box(rows, cols);

    //print the garden
    view_garden(garden, rows, cols);

    //free the garden mem
    free_garden(garden, rows, cols);
}
