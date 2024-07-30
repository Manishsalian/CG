from django import forms
from .models import Student, Course

class StudentForm(forms.ModelForm):
    class Meta:
        model = Student
        fields = ['usn', 'name', 'department']
        
class CourseForm(forms.ModelForm):
    students = forms.ModelMultipleChoiceField(queryset=Student.objects.all(), widget=forms.CheckboxSelectMultiple)
    class Meta:
        model = Course
        fields = ['course_id', 'course_name', 'students']
