#ifndef AIRCRAFT_H
#define AIRCRAFT_H

class Aircraft{
public:
   Aircraft( const int = 0, const int = 0);
   int getRow() const;           // to access number of rows
   int  getColumn() const;       // to access number of column
   void setRow(const int);      // to initialize the number of row in
   void setColumn( const int);

private:
  int row;
  int column;        // the column will be converted into a char
                     // by the accessor
};

#endif
