from flask import Blueprint, render_template, request, flash, redirect, url_for, Response
from werkzeug.security import generate_password_hash, check_password_hash
from flask_login import login_user, logout_user, login_required, current_user
from .model import User
from .model import Staff
from .model import Rooms
from .model import Mess
from .model import AdminUser
from .model import Laundry
from . import db
import re    #for email validation  (function for all types of validation)
from flask.helpers import send_file


import subprocess
import shlex
from subprocess import Popen, PIPE
from subprocess import check_output
from os import path
import os


#postress sql
#pg admin



auths = Blueprint('auths', __name__)



#  @ ka sat auths variable use ho ga lekin url_for ka lia blueprint name ' ' use ho ga

# def get_shell_script_output_using_communicate():
#     session = Popen(['./newshellscript.sh'], stdout=PIPE, stderr=PIPE)
#     stdout, stderr = session.communicate()
#     if stderr:
#         raise Exception("Error "+str(stderr))
#     return stdout.decode('utf-8')

# def get_shell_script_output_using_check_output():
#     stdout = check_output(['/home/maanz-ai/Desktop/finalyearproject/bjb_fulll/Push-Up-Logger-1/mathpractice_ws && newshellscript.sh']).decode('utf-8')


# @auths.route('/s',methods=['GET'])
# def home():
# #     # return send_file(f'/home/maanz-ai/mathpractice_ws/./shellscript.sh', mimetype="file.sh", conditional=True)
# #     #  return Response(new, mimetype="file.sh")


#     cmd = ['/home/maanz-ai/mathpractice_ws/./shellscript.sh']
#     return subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE, executable='/bin/bash')
    

# def get_shell_script_output_using_check_output():
#     (subprocess.run(["home/mathpractice_ws/shellscript.sh"], shell=False)) 

# @auths.route('/s',methods=['GET'])
# def go():
#     return get_shell_script_output_using_check_output()



# def get_shell_script_output_using_check_output():
#     app_path = os.getcwd()
#     path = app_path + os.path.sep 
#     os.chdir(path)
#     subprocess.run(["/home/maanz-ai/mathpractice_ws/bash shellscript.sh"])

# @auths.route('/s',methods=['GET'])
# def go():    
#     return get_shell_script_output_using_check_output()



# def get_shell_script_output_using_check_output():
#     stdout = check_output(['/home/maanz-ai/mathpractice_ws/./shellscript.sh']).decode('utf-8')
#     return stdout


# @auths.route('/s',methods=['GET'])
# def home():
#     return '<pre>'+get_shell_script_output_using_check_output()+'</pre>'





cmd = ['/home/maanz-ai/mathpractice_ws/./shellscript.sh']   # we write this for run the shell script
def execute(cmd):
    os.system(cmd)


@auths.route('/s', methods = ['GET'])
def executeScript():
    output = execute('/home/maanz-ai/mathpractice_ws/./shellscript.sh')
    return output












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



@auths.route('/loginadmin')
def loginadmin():
    return render_template('admin_login.html')

@auths.route('/loginadmin', methods=['POST'])
def login_admin_post():
    email = request.form.get('email')
    password = request.form.get('password')
    remember = True if request.form.get('remember') else False

    user = AdminUser.query.filter_by(adminemail=email).first()

    if user:
            if check_password_hash(user.adminpassword, password):
                flash('Logged in successfully!', category='success')
                login_user(user, remember=True)
                return redirect(url_for('view.adminprofile'))
            else:
                flash('Incorrect password, try again.', category='error')
                return redirect(url_for('auths.loginadmin'))  # if user doesn't exist or password is wrong, reload the page
    else:
            flash('Email does not exist.', category='error')

    return render_template("admin_login.html", user=current_user)



    


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
        new_user = User(email=email, fullname=name, password=generate_password_hash(password, method='sha256'))
        db.session.add(new_user)
        db.session.commit()
        # login_user(new_user, remember=True)
        flash('Account created!', category='success')
        return redirect(url_for('auths.login')) #auth  blueprint ka nam ha

    # return render_template("signup.html", user=current_user)   
    return redirect(url_for('auths.signup'))  #agar email pehla ka ho ga to flash (email alredy exist) to show karaya ga hi lekin is return auth.signup ki madad sa dobara hama signup function ma la jaya ga
    

 

@auths.route('/signupadmin')
def signupadmin():
    return render_template('admin_signup.html')

@auths.route('/signupadmin', methods=['POST'])   #jasa hi form ma data fill karna ka bad hum signup par click karan ga to post wala signup_post method call ho ga kyo ka hum na kuch data bhejna ha server ko
def signup_admin_post():

    email = request.form.get('email')
    name = request.form.get('fullname')
    password = request.form.get('password1')  #' password1' variable wo han jo hum na html form ka andar name dia hua han ,,, hum un html name ki madad sa un ka data yahan use kar rahan han
    passwordd = request.form.get('password2')

    pattern = r'\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,7}\b'
    print(email)

    # if this returns a user, then the email already exists in database
    user = AdminUser.query.filter_by(adminemail=email).first()    #extracting user email from database     # email(email variable in table in model.py)=email(variable initialize there)
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
        new_user = AdminUser(adminemail=email, adminfullname=name, adminpassword=generate_password_hash(password, method='sha256'))
        db.session.add(new_user)
        db.session.commit()
        login_user(new_user, remember=True)
        flash('Account created!', category='success')
        return redirect(url_for('auths.loginadmin')) #auth  blueprint ka nam ha

    # return render_template("signup.html", user=current_user)   
    return redirect(url_for('auths.signupadmin'))  #agar email pehla ka ho ga to flash (email alredy exist) to sho






@auths.route('/adminsignupclient')
def adminsignupclient():
        return render_template('profile.html')

@auths.route('/adminsignupclient', methods=['POST'])   #jasa hi form ma data fill karna ka bad hum signup par click karan ga to post wala signup_post method call ho ga kyo ka hum na kuch data bhejna ha server ko
def admin_signup_post():

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
        new_user = User(email=email, fullname=name, password=generate_password_hash(password, method='sha256'))
        db.session.add(new_user)
        db.session.commit()
        # login_user(new_user, remember=True)
        flash('Account created!', category='success')
        return redirect(url_for('auths.adminsignupclient')) #auth  blueprint ka nam ha

    # return render_template("signup.html", user=current_user)   
    return redirect(url_for('auths.adminsignupclient'))  #agar email pehla ka ho ga to flash (email alredy exist) to sho





@auths.route('/adminsignupstaff')
def adminsignupstaff():
    return render_template('admin_profile.html')

@auths.route('/adminsignupstaff', methods=['POST'])   #jasa hi form ma data fill karna ka bad hum signup par click karan ga to post wala signup_post method call ho ga kyo ka hum na kuch data bhejna ha server ko
def admin_signup_staff_post():

    name = request.form.get('fullname')
    number = request.form.get('phonenumber')  #' password1' variable wo han jo hum na html form ka andar name dia hua han ,,, hum un html name ki madad sa un ka data yahan use kar rahan han
    cnic = request.form.get('cnic')
    designation = request.form.get('designation')
    foreignkeyvariable = current_user.id
    # var = request.form.get('')
    

    phone = "^\\+?[9][2][3][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]$"
    cnicvalidation = "^[0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9]$"
    
    user = Staff.query.filter_by(numbermodel=number).first()    
    if user:
            flash('Staff user already exists.', category='error')
    elif len(name) < 2:
        flash('Name must be greater than 2 characters.', category='error') 
    elif re.fullmatch(phone, number) == None:
        flash('Mobile syntax is wrong', category='error')
    elif re.fullmatch(cnicvalidation, cnic) == None:
        flash('CNIC  syntax is wrong', category='error')
    elif len(designation) < 3:
        flash('Designation must be greater than 3 character.', category='error')
       
    else:
        new_user = Staff(namemodel=name,  numbermodel=number, cnicmodel=cnic, designationmodel=designation, user_idmodel = foreignkeyvariable)
        db.session.add(new_user)
        db.session.commit()
        # login_user(new_user, remember=True)
        flash('Staff Added !', category='success')
        return redirect(url_for('auths.adminsignupstaff')) #auth  blueprint ka nam ha

    # return render_template("signup.html", user=current_user)   
    return redirect(url_for('auths.adminsignupstaff'))  #agar email pehla ka ho ga to flash (email alredy exist) to sho



@auths.route('/customerregisterroom')
def customerregisterroom():
    return render_template('profile.html')

@auths.route('/customerregisterroom', methods=['POST'])   #jasa hi form ma data fill karna ka bad hum signup par click karan ga to post wala signup_post method call ho ga kyo ka hum na kuch data bhejna ha server ko
def customer_register_room_post():
    email = request.form.get('email')
    name = request.form.get('fullname')
    number = request.form.get('phonenumber')  #' password1' variable wo han jo hum na html form ka andar name dia hua han ,,, hum un html name ki madad sa un ka data yahan use kar rahan han
    cnic = request.form.get('cnic')
    address = request.form.get('address')
    totalduration = request.form.get('totalduration')
    seater = request.form.get('seater')
    totalfees = request.form.get('totalfees')
    roomno = request.form.get('roomno')
    foreignkeyvariable = current_user.id
    # var = request.form.get('')
    

    phone = "^\\+?[9][2][3][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]$"
    cnicvalidation = "^[0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9][0-9]-[0-9]$"
    
    user = Rooms.query.filter_by(customeremail=email).first() 
    userr = Rooms.query.filter_by(customerroomno=roomno).first()   
    if user:
            flash('This User already registers.', category='error')
    elif len(name) < 2:
        flash('Name must be greater than 2 characters.', category='error') 
    elif re.fullmatch(phone, number) == None:
        flash('Mobile syntax is wrong', category='error')
    elif re.fullmatch(cnicvalidation, cnic) == None:
        flash('CNIC  syntax is wrong', category='error')
    elif len(address) < 8:
        flash('Address must be greater than 8 character.', category='error')
    elif len(totalduration) < 3:
        flash('Total Duration must be greater than 3 character.', category='error')
    elif len(seater) < 1:
        flash('It must be greater than 1 character.', category='error') 
    elif userr:
        flash('This Room is already booked', category='error') 
          
       
    else:
        new_user = Rooms( customeremail=email, customerfullname=name,  customercontactno=number, customercnic=cnic, customeraddress=address, customertotalduration = totalduration, customerseater = seater, customerfees = totalfees, customerroomno = roomno, customer_id = foreignkeyvariable)
        db.session.add(new_user)
        db.session.commit()
        # login_user(new_user, remember=True)
        flash('Congratulation!!! Room Booked For you !', category='success')
        return redirect(url_for('auths.customerregisterroom')) #auth  blueprint ka nam ha

    # return render_template("signup.html", user=current_user)   
    return redirect(url_for('auths.customerregisterroom'))  #agar email pehla ka ho ga to flash (email alredy exist) to sho






@auths.route('/adminsignupmess')
def adminsignupmess():
    return render_template('admin_profile.html')

@auths.route('/adminsignupmess', methods=['POST'])   #jasa hi form ma data fill karna ka bad hum signup par click karan ga to post wala signup_post method call ho ga kyo ka hum na kuch data bhejna ha server ko
def admin_signup_mess_post():

    day = request.form.get('day')
    breakfast = request.form.get('breakfast')  #' password1' variable wo han jo hum na html form ka andar name dia hua han ,,, hum un html name ki madad sa un ka data yahan use kar rahan han
    lunch = request.form.get('lunch')
    dinner = request.form.get('dinner')
    date = request.form.get('date')
    foreignkeymess = current_user.id
    # var = request.form.get('')
    

    if len(day) < 2:
        flash('Day must be greater than 2 chars', category='error') 
    elif len(breakfast) < 2:
        flash('Day must be greater than 2 chars', category='error') 
    elif len(lunch) < 2:
        flash('Day must be greater than 2 chars', category='error') 
    elif len(dinner) < 2:
        flash('Day must be greater than 2 chars', category='error') 
    elif len(date) < 2:
        flash('Day must be greater than 2 chars', category='error')         
       
    else:
        new_user = Mess(messday=day,  messbreakfast=breakfast, messlunch=lunch, messdinner =dinner,messdate=date, mess_adminid = foreignkeymess)
        db.session.add(new_user)
        db.session.commit()
        # login_user(new_user, remember=True)
        flash('Mess Info. Added !', category='success')
        return redirect(url_for('auths.adminsignupmess')) #auth  blueprint ka nam ha

    # return render_template("signup.html", user=current_user)   
    return redirect(url_for('auths.adminsignupmess'))  #agar email pehla ka ho ga to flash (email alredy exist) to sho



@auths.route('/clientsignuplaundry')
def adminsignuplaundry():
    return render_template('profile.html')

@auths.route('/clientsignuplaundry', methods=['POST'])   #jasa hi form ma data fill karna ka bad hum signup par click karan ga to post wala signup_post method call ho ga kyo ka hum na kuch data bhejna ha server ko
def admin_signup_laundry_post():

    name= request.form.get('name')
    contactno = request.form.get('contactno')  #' password1' variable wo han jo hum na html form ka andar name dia hua han ,,, hum un html name ki madad sa un ka data yahan use kar rahan han
    item = request.form.get('item')
    foreignkeylaundry = current_user.id
    
    phone = "^\\+?[9][2][3][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]$"

    if len(name) < 2:
        flash('Name must be greater than 2 chars', category='error') 
    elif re.fullmatch(phone, contactno) == None:
        flash('Mobile syntax is wrong', category='error')    
    elif len(item) < 2:
        flash('Item must be greater than 2 chars', category='error') 
           
       
    else:
        new_user = Laundry(laundaryname=name, laundarycontactno=contactno, laundryitem =item, laundry_id = foreignkeylaundry)
        db.session.add(new_user)
        db.session.commit()
        # login_user(new_user, remember=True)
        flash('Laundry Info. Added !', category='success')
        return redirect(url_for('auths.adminsignuplaundry')) #auth  blueprint ka nam ha

    # return render_template("signup.html", user=current_user)   
    return redirect(url_for('auths.adminsignuplaundry'))  #agar email pehla ka ho ga to flash (email alredy exist) t




@auths.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect(url_for('view.index'))