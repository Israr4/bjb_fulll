from flask import Blueprint, render_template, request, flash, redirect, url_for
from werkzeug.security import generate_password_hash, check_password_hash
from flask_login import login_user, logout_user, login_required, current_user
from email_validator import validate_email
from .model import User
from . import db
import re    #for email validation

auths = Blueprint('auths', __name__)

#  @ ka sat auths variable use ho ga lekin url_for ka lia blueprint name ' ' use ho ga

@auths.route('/login')
def login():
    return render_template('login.html')


@auths.route('/login', methods=['POST'])
def login_post():
    email = request.form.get('email')
    password = request.form.get('password')
    remember = True if request.form.get('remember') else False

    user = User.query.filter_by(email=email).first()

    if user:
            if check_password_hash(user.password, password):
                flash('Logged in successfully!', category='success')
                login_user(user, remember=True)
                return redirect(url_for('view.profile'))
            else:
                flash('Incorrect password, try again.', category='error')
                return redirect(url_for('auths.login'))  # if user doesn't exist or password is wrong, reload the page
    else:
            flash('Email does not exist.', category='error')

    return render_template("login.html", user=current_user)



    


@auths.route('/signup')
def signup():
    return render_template('signup.html')


@auths.route('/signup', methods=['POST'])   #jasa hi form ma data fill karna ka bad hum signup par click karan ga to post wala signup_post method call ho ga kyo ka hum na kuch data bhejna ha server ko
def signup_post():

    email = request.form.get('email')
    name = request.form.get('fullname')
    password = request.form.get('password1')  #' password1' variable wo han jo hum na html form ka andar name dia hua han ,,, hum un html name ki madad sa un ka data yahan use kar rahan han
    passwordd = request.form.get('password2')

    pattern = r'\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,7}\b'
    print(email)

    # if this returns a user, then the email already exists in database
    user = User.query.filter_by(email=email).first()    #extracting user email from database     # email(email variable in table in model.py)=email(variable initialize there)
    if user:
            flash('Email already exists.', category='error')
    elif re.fullmatch(pattern, email) == None:    #email validation checking
            flash('Email syntax is wrong', category='error') 
    elif len(email) < 4:
        flash('Email must be greater than 3 characters.', category='error')
    elif len(name) < 2:
        flash('First name must be greater than 1 character.', category='error')
    elif password != passwordd:
        flash('Passwords don\'t match.', category='error')
    elif len(password) < 7:
        flash('Password must be at least 7 characters.', category='error')
    else:
        new_user = User(email=email, first_name=name, password=generate_password_hash(password, method='sha256'))
        db.session.add(new_user)
        db.session.commit()
        # login_user(new_user, remember=True)
        flash('Account created!', category='success')
        return redirect(url_for('auths.login')) #auth  blueprint ka nam ha

    # return render_template("signup.html", user=current_user)   
    return redirect(url_for('auths.signup'))  #agar email pehla ka ho ga to flash (email alredy exist) to show karaya ga hi lekin is return auth.signup ki madad sa dobara hama signup function ma la jaya ga
    

 
@auths.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect(url_for('view.index'))