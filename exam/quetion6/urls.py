from django.urls import path
from .views import csv_file
from .views import pdffile
urlpatterns = [
    path('file/csv',csv_file,name='csv_file'),
    path('file/pdf',pdffile ,name='pdf_file')
]

