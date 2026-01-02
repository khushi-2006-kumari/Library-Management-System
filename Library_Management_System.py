# Library Management System:
#Question :
# Create a library class: 1.display books, 2. Lend book-who owns the book if not present
# 3. add book , 4. return book
# Make constructor: e.g. Khushi_library=Library(list_of_books, library_name)
# dictionary (books-name of person)
#Create  a main function & run an infinite while loop, asking users for their input

class Library:
    library_name="Om Library"

    def __init__(self,list_of_books,library_name):
        self.list_of_books=list_of_books
        self.library_name=library_name
        self.lend_record={}

    def display_books(self):
        print (self.list_of_books)


    def add_book(self):
        book=input("Thank You!Please write the name of book")
        self.list_of_books.append(book)

    def lend_book(self):
        book=input("Enter the book name for lending:\n").capitalize()
        if book not in self.list_of_books:
            print("Please enter valid input")
        if book in self.list_of_books:
            name=input("Enter your name:\n").capitalize()
            self.list_of_books.remove(book)
            self.lend_record[book]=name

        else:
            if self.lend_record.get(book):
                print(f"This Book is not available now, in library as this book is taken by {self.lend_record[book]}")

    def return_book(self):
        book=input("Enter the book's name for return:\n").capitalize()
        if book in self.lend_record:
            self.list_of_books.append(book)
            del self.lend_record[book]
        else:
            print("Please Enter the valid input")

if __name__=='__main__':
    list_of_books=['The stranger','Wings of Fire','Never Lie',' Dune' ,' The Plague']
    Om_Library=Library(list_of_books,'Om Library')


    #print("Welcome in Om library:")
    while True:
        print("Welcome in Om library:")
        user_input=int(input("What do you want to select: 1. Display, 2. Return, 3. add , 4. Lend, 5.Exit\n"))

        if user_input==5:
            break
        elif user_input==1:
            Om_Library.display_books()
        elif user_input==2:
            Om_Library.return_book()
        elif user_input==3:
            Om_Library.add_book()
        elif user_input==4:
            Om_Library.lend_book()















