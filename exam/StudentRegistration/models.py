from django.db import models

class Student(models.Model):
    
    usn=models.CharField(max_length=10,primary_key=True)
    name=models.CharField(max_length=100)
    department=models.CharField(max_length=30)
    
    def __str__(self):
        return self.usn


class Course(models.Model):
    
    course_id=models.CharField(max_length=10,primary_key=True)
    course_name=models.CharField(max_length=100)
    students=models.ManyToManyField(Student,related_name='courses')
    
    def __str__(self):
        return self.course_id
