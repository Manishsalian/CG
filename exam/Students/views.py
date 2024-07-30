from django.views.generic import ListView, DetailView
from .models import StudentData

class StudentListView(ListView):
    model = StudentData
    template_name = 'student_list.html'

class StudentDetailView(DetailView):
    model = StudentData
    template_name = 'student_detail.html'
