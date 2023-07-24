from flask_login import UserMixin  #add flask login attributes to model
from datetime import datetime
from . import db
from flask_sqlalchemy import SQLAlchemy
from flask import request

# sqlite,postgresql,oracle and mysql is a database storage engine used to store and retrieve structural data from files
# while
# sqlalchemy is  a python library which provide object relational model 
 

class User(db.Model,UserMixin):
    id            = db.Column(db.Integer, primary_key=True)  # primary keys are required by SQLAlchemy
    email         = db.Column(db.String(100), unique=True)
    password      = db.Column(db.String(100))
    fullname      = db.Column(db.String(1000))
    role          = db.Column(db.String(20), nullable=False)
    workouts      = db.relationship('Workout', backref='author', lazy=True)
    register      = db.relationship('Rooms', backref='author', lazy=True)
    launddry      = db.relationship('Laundry', backref='author', lazy=True)
    adminrelation = db.relationship('Staff', backref='author', lazy=True)
    
    def get_id(self):                     # this function is used to avoid
        return (self.id)

    # def is_admin(self):
    #     return self.role == 'admin'
    
# class AdminUser(db.Model,UserMixin):
#     adminid       = db.Column(db.Integer, primary_key=True)  # primary keys are required by SQLAlchemy
#     adminemail    = db.Column(db.String(100), unique=True)
#     adminpassword = db.Column(db.VARCHAR(100))
#     adminfullname = db.Column(db.String(1000))
#     adminrelation = db.relationship('Staff', backref='author', lazy=True)

#     def get_id(self):                     # this function is used to avoid
#            return (self.adminid)


class Laundry(db.Model):
    laundryid         = db.Column(db.Integer, primary_key=True)
    laundaryname      = db.Column(db.String(1000))   #pushups not be zero
    laundarycontactno = db.Column(db.String(1000))   #.utcnow is a format of datetime we select any of them
    laundryitem       = db.Column(db.String(1000))
    laundry_id        = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)

    def get_id(self):                     # this function is used to avoid
           return (self.messid)


class Rooms(db.Model,UserMixin):
    customerid            = db.Column(db.Integer, primary_key=True)  # primary keys are required by SQLAlchemy
    customeremail         = db.Column(db.String(100), unique=True)
    customerfullname      = db.Column(db.String(1000))
    customercontactno     = db.Column(db.BIGINT, unique=True)
    customercnic          = db.Column(db.VARCHAR, unique=True)
    customeraddress       = db.Column(db.String(1000))
    customertotalduration = db.Column(db.String(1000))
    customerseater        = db.Column(db.VARCHAR)
    customerroomno        = db.Column(db.Integer,unique=True)
    customerfees          = db.Column(db.Integer)
    customer_id           = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)

    def get_id(self):                     # this function is used to avoid
           return (self.customerid)

    

class Mess(db.Model):
    messid        = db.Column(db.Integer, primary_key=True)
    messday       = db.Column(db.String(1000), unique=True)   #pushups not be zero
    messbreakfast = db.Column(db.String(1000))   #.utcnow is a format of datetime we select any of them
    messlunch     = db.Column(db.String(1000))
    messdinner    = db.Column(db.String(1000))
    messdate      = db.Column(db.String(1000))
    mess_adminid  = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)

    def get_id(self):                     # this function is used to avoid
           return (self.messid)

class Staff(db.Model):
    idmodel          = db.Column(db.Integer, primary_key=True)
    namemodel        = db.Column(db.Integer, nullable=False)   #pushups not be zero
    numbermodel      = db.Column(db.Integer, nullable=False)    #.utcnow is a format of datetime we select any of them
    cnicmodel        = db.Column(db.Text, nullable=False)
    designationmodel = db.Column(db.String(1000))
    user_idmodel     = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)

    def get_id(self):                     # this function is used to avoid
           return (self.idmodel)



    



    # database ma ek bari data enter hi gya ha rows aur column ka to wo edit maunually hi ho ga


class Workout(db.Model):
    id          = db.Column(db.Integer, primary_key=True)
    pushups     = db.Column(db.Integer, nullable=False)   #pushups not be zero
    date_posted = db.Column(db.DateTime, nullable=False, default=datetime.utcnow)    #.utcnow is a format of datetime we select any of them
    comment     = db.Column(db.Text, nullable=False)
    user_id     = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)
    # user_idd = db.Column(db.Integer, db.ForeignKey('admin_user.adminid'), nullable=False)