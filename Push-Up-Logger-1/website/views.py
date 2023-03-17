from flask import Blueprint, render_template, url_for, redirect, request, flash, abort
from flask_login import login_required, current_user
from . import db
from .model import User
from .model import Staff
from .model import Workout
from .model import Rooms
from .model import Mess
from .model import Laundry
from .model import AdminUser



view = Blueprint('view', __name__)  # commas ma nam kuch bi ho sakta ha 


@view.route('/')  #this view is a variable that we initialize above
def index():
   return render_template("index.html")   # it simply return the code written in index.html


@view.route('/profile')
@login_required
def profile():
   return render_template("profile.html",namme = current_user.fullname )  # it simply return the code written in profile.html

@view.route('/adminprofile')
@login_required
def adminprofile():
   return render_template("admin_profile.html",nammee = current_user.fullname )  # it simply return the code written in profile.html  and thats the form name
   




@view.route("/all")                                                                                         #READ
@login_required
def user_workouts():
    page = request.args.get('page',1,type=int) # for pagination on url it will we shown
    user = User.query.filter_by(email=current_user.email).first_or_404()
    # workouts = user.workouts 
    workouts =  Workout.query.filter_by(author=user).paginate(page=page, per_page=3)  #for pagination on per page there only three
    return render_template('all_workouts.html', workouts=workouts, user=user)


@view.route("/allclients")                                                                                         #READ
@login_required
def all_clients():
    students = User.query.all()
    return render_template('admin_profile.html', students=students)  # students variable ko retun karayan ga render template ma tab hi yeh kisi template ma insert ho ga

@view.route("/allstaff")                                                                                         #READ
@login_required
def all_staff():
    staffs = Staff.query.all()
    return render_template('admin_profile.html', staffs=staffs)

@view.route("/allroom")                                                                                         #READ
@login_required
def all_rooms():
    roomss = Rooms.query.all()
    return render_template('profile.html', roomss=roomss)  


@view.route("/allroomadmin")                                                                                         #READ
@login_required
def all_rooms_admin():
    roomss = Rooms.query.all()
    return render_template('admin_profile.html', roomss=roomss)

@view.route("/allmessadmin")                                                                                         #READ
@login_required
def all_mess_admin():
    messs = Mess.query.all()
    return render_template('admin_profile.html', messs=messs)   

@view.route("/allmessclient")                                                                                         #READ
@login_required
def all_mess_client():
    messs = Mess.query.all()
    return render_template('profile.html', messs=messs)  

@view.route("/alllaundryadmin")                                                                                         #READ
@login_required
def all_laundry_admin():
    laundrry = Laundry.query.all()
    return render_template('admin_profile.html', laundrry=laundrry)   

@view.route("/alllaundryclient")                                                                                         #READ
@login_required
def all_laundry_client():
    laundrry = Laundry.query.all()
    return render_template('profile.html', laundrry=laundrry) 






@view.route("/new")
@login_required
def new_workout():
    return render_template('create_workout.html')


@view.route("/new", methods=['POST'])                                                                     #CREATE
@login_required
def new_workout_post():
    pushups = request.form.get('pushups')
    comment = request.form.get('comment')
    print(pushups, comment)
    workout = Workout(pushups=pushups, comment=comment, author=current_user)
    db.session.add(workout)
    db.session.commit()
    flash('Your workout has been added!')
    return redirect(url_for('view.user_workouts'))





@view.route("/workout/<int:workout_id>/update", methods=['GET', 'POST'])                                    #UPDATE
@login_required
def update_workout(workout_id):
    workout = Workout.query.get_or_404(workout_id)   #agar workout na ho to 404 error aya ga
    if request.method == "POST":
        workout.pushups = request.form['pushups']
        workout.comment = request.form['comment']
        db.session.commit()
        flash('Your post has been updated!')
        return redirect(url_for('view.user_workouts'))

    return render_template('update_workout.html', workout=workout)


@view.route("/workout/<int:workout_id>/delete", methods=['GET', 'POST'])                                     #DELETE
@login_required
def delete_workout(workout_id):
    workout = Workout.query.get_or_404(workout_id)
    db.session.delete(workout)
    db.session.commit()
    flash('Your post has been deleted!')
    return redirect(url_for('view.user_workouts'))






@view.route("/staff/<int:staff_id>/update", methods=['GET', 'POST'])                                    #UPDATE
@login_required
def update_staff(staff_id):
    staff = Staff.query.get_or_404(staff_id)   #agar workout na ho to 404 error aya ga
    if request.method == "POST":
        staff.namemodel= request.form.get('fullname')
        staff.numbermodel = request.form.get('phonenumber')  #' password1' variable wo han jo hum na html form ka andar name dia hua han ,,, hum un html name ki madad sa un ka data yahan use kar rahan han
        staff.cnicmodel = request.form.get('cnic')
        staff.designationmodel = request.form.get('designation')
        staff.user_idmodel = current_user.id
        db.session.commit()
        flash('Your post has been updated!')
        return redirect(url_for('view.all_staff'))

    return render_template('admin_profile.html', staff=staff)


@view.route("/staff/<int:staff_id>/delete", methods=['GET', 'POST'])                                     #DELETE
@login_required
def delete_staff(staff_id):
    staff = Staff.query.get_or_404(staff_id)
    db.session.delete(staff)
    db.session.commit()
    flash('Your post has been deleted!')
    return redirect(url_for('view.all_staff'))