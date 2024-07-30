from django.urls import path
from .views import StudentListView, StudentDetailView

urlpatterns = [
    path('student/', StudentListView.as_view(), name='student-list'),
    path('<int:pk>/', StudentDetailView.as_view(), name='student-detail'),
]
