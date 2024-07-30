from django.db import models as m

class Book(m.Model):
    book_name=m.CharField(max_length=50)
    book_author=m.CharField(max_length=100)
    published_Date=m.DateField()
    
    def __str__(self):
        return self.book_name