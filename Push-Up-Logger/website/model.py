from flask_login import UserMixin   #add flask login attributes to model
from datetime import datetime
from . import db


class User(db.Model,UserMixin):
    id = db.Column(db.Integer, primary_key=True)  # primary keys are required by SQLAlchemy
    email = db.Column(db.String(100), unique=True)
    password = db.Column(db.String(100))
    fullname = db.Column(db.String(1000))
    workouts = db.relationship('Workout', backref='author', lazy=True)


    # database ma ek bari data enter hi gya ha rows aur column ka to wo edit maunually hi ho ga


class Workout(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    pushups = db.Column(db.Integer, nullable=False)   #pushups not be zero
    date_posted = db.Column(db.DateTime, nullable=False, default=datetime.utcnow)    #.utcnow is a format of datetime we select any of them
    comment = db.Column(db.Text, nullable=False)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)