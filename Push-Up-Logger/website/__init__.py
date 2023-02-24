from flask import Flask
from os import path
from flask_sqlalchemy import SQLAlchemy #importing database
from flask_login import LoginManager

db = SQLAlchemy()  #just like constructor initializing database with variable db to use it later with variable name db

def create_app():
    
    app = Flask(__name__)

    from.views import view #views is a file name  and view is a variable in that file
    app.register_blueprint(view) #blueprint is only to manage files

    from.auth import auths 
    app.register_blueprint(auths)



    app.config['SECRET_KEY'] = 'hjshjhdjah kjshkjdhjs'    #Encypting session and cookies
    app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///db.sqlite' # Syntax for database
    db.init_app(app)      #initialize app with database

    
    from .model import User       # this code is used to store  data of signup details in database and with the help of this data we login
    with app.app_context():  
        db.create_all()           # database with the name of db.sqlite in instance folder is created by calling the function for 

    login_manager = LoginManager()    #database
    login_manager.login_view = 'auth.login'
    login_manager.init_app(app)

    @login_manager.user_loader    #user loader tell flask login to find a specific  user from id that is stored in session cookies
    def load_user(id):
        return User.query.get(int(id))

        #we use DB Browser for sqlite database

    return app





def create_database(app):       # function for creating database with the name of db.sqlite
     if not path.exists('website/' + db.sqlite):
        db.create_all(app=app)
        print('Created Database!')