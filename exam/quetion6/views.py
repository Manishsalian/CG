from django.shortcuts import render
from .models import Book
from django.http import HttpResponse
import csv as c
import io
from reportlab.lib.pagesizes import letter
from reportlab.pdfgen import canvas
def csv_file(request):
    
    response=HttpResponse(content_type='text/csv')
    response['content-disposition']='attachment; filename=book.csv'

    writer=c.writer(response)
    
    writer.writerow(['book_name','book_author','published_Date'])
    
    book=Book.objects.all().values_list('book_name','book_author','published_Date')
    
    for b in book:
        writer.writerow(b)
    
    return response


def pdffile(request ):
    response=HttpResponse(content_type='application/pdf')
    response['content_disposition']='attachment;filename="book.pdf"'
    
    buffer= io.BytesIO()
    
    p=canvas.Canvas(buffer,pagesize=letter)
    
    
    p.drawString(100,300,"Book")
    y=750
    books=Book.objects.all()
    for b in books:
        p.drawString(100,y,f"Name:{b.book_name} Author:{b.book_author} published:{b.published_Date}")
        y-=20
    
    p.showPage()
    p.save()
    buffer.seek(0)
    return HttpResponse(buffer,content_type='application/pdf')