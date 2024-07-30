# Generated by Django 5.0.7 on 2024-07-29 15:01

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Book',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('book_name', models.CharField(max_length=50)),
                ('book_author', models.CharField(max_length=100)),
                ('published_Date', models.DateField()),
            ],
        ),
    ]
