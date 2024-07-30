# courses/urls.py
from django.urls import path
from .views import course_detail, course_list, add_course, add_student

urlpatterns = [
    path('', course_list, name='course_list'),
    path('course/<str:course_id>/', course_detail, name='course_detail'),
    path('add_student/', add_student, name='add_student'),
    path('create_course/', add_course, name='add_course'),
]
