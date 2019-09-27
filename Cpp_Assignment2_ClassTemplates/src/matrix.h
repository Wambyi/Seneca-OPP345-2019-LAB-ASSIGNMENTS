const int MAXROWS=2;
const int MAXCOLS=3;

template <class T>
class Matrix
{
  private:
   T doubleArray[MAXROWS][MAXCOLS];
   int rows;
   int cols;

  public:
   //Constructor
   Matrix();  //Set rows to MAXROWS and cols to MAXCOLS
	      //Initialize all the values of doubleArray to zero

   //Getter Functions
   void printMatrix();

   //Setter Functions
   void setMatrix(T [][MAXCOLS]); //set the doubleArray to what is sent
   void addMatrix(T [][MAXCOLS]); //add an array to doubleArray

   void addMatrix(T [][MAXCOLS], T [][MAXCOLS]);

   //No destructor needed
};



///------------------------Definitions--------------

template <class T>
Matrix<T>::Matrix()
{
   rows = MAXROWS;
   cols = MAXCOLS;
   for (int i=0; i< rows; i++)
   {
      for(int j=0; j< cols; j++)
      {
	 doubleArray[i][j] = '\0';
      }
   }
}

template <class T>
void Matrix<T>::printMatrix()
{
   for (int i=0; i< rows; i++)
   {
      for(int j=0; j< cols; j++)
      {
	 std::cout << doubleArray[i][j] << "   ";
      }
      std::cout << "\n";
   }
}

template <class T>
void Matrix<T>::setMatrix(T otherArray[][MAXCOLS])
{
   for (int i=0; i< rows; i++)
   {
      for(int j=0; j< cols; j++)
      {
	 doubleArray[i][j] = otherArray[i][j];
      }
   }
}

template <class T>
void Matrix <T>::addMatrix(T otherArray[][MAXCOLS])
{
   for (int i=0; i< rows; i++)
   {
      for(int j=0; j< cols; j++)
      {
	 doubleArray[i][j] += otherArray[i][j];
      }
   }
}

//Still not sure about how to make this part work**********
//template <class T>
//void Matrix<T>::addMatrix(Matrix otherMatrix)
//{
//   addMatrix(otherMatrix.doubleArray);
//}

