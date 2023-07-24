from flask import Flask,request
from os import path
import os
from flask_sqlalchemy import SQLAlchemy #importing database
from flask_login import LoginManager
import psycopg2
from dotenv import load_dotenv
from sqlalchemy.dialects import postgresql


db = SQLAlchemy()  #just like constructor initializing database with variable db to use it later with variable name db

def create_app():
    
    app = Flask(__name__)

    from.views import view #views is a file name  and view is a variable in that file
    app.register_blueprint(view) #blueprint is only to manage files

    from.auth import auths 
    app.register_blueprint(auths)

    from.views import vieww #views is a file name  and view is a variable in that file
    app.register_blueprint(vieww) #blueprint is only to manage files
    
    app.config['SECRET_KEY'] = 'abchfgdhfgjjhjhjhjh'    #Encrypting session and cookies
    # app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///db.sqlite' # Syntax for database
    app.config['SQLALCHEMY_DATABASE_URI'] = 'postgresql://postgres:123456789@localhost/newpostgress'  # postgresql = name of database(syntax),  postgres(default set)  = rootuser, tiger = 123456789, postgredatabase = name of database that we created
     
    # DB_HOST = "localhost"
    # DB_NAME = "postgresql"
    # DB_USER = "israr786@gmail.com"
    # DB_PASS = "123456789"
    # conn = psycopg2.connect(dbname = DB_NAME, user = DB_USER, password = DB_PASS, host = DB_HOST)
    
    db.init_app(app)      #initialize app with database


    from .model import User       # this code is used to store  data of signup details in database and with the help of this data we login
    # from .model import AdminUser
    from .model import Staff
    from .model import Rooms
    from .model import Mess
    from .model import Laundry
    with app.app_context():  
        db.create_all()           # database with the name of db.sqlite in instance folder is created by calling the function for 

    login_manager = LoginManager()    #database 
    
    login_manager.login_view = 'auths.login' 
    login_manager.login_view = 'auths.loginadmin'
    login_manager.init_app(app)

    @login_manager.user_loader
    def load_user(id):
        return User.query.get(int(id))
    

    # @login_manager.user_loader
    def load_users(idmodel):
        return Staff.query.get(int(idmodel))

    # @login_manager.user_loader   
    def load_userss(customerid):
        return Rooms.query.get(int(customerid))

    # @login_manager.user_loader
    def load_userssss(messid):
        return Mess.query.get(int(messid)) 

    # @login_manager.user_loader
    def load_usersss(laundryid):
        return Laundry.query.get(int(laundryid))        

        #we use DB Browser for sqlite database
    
    return app





# def create_database(app):       # function for creating database with the name of db.sqlite
#      if not path.exists('/website' + db.sqlite()):
#         db.create_all(app=app)
#         print('Created Database!')
