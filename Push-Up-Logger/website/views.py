from flask import Blueprint, render_template, url_for, redirect, request, flash, abort
from flask_login import login_required, current_user
from . import db
from .model import User
from .model import Workout

view = Blueprint('view', __name__)  # commas ma nam kuch bi ho sakta ha 


@view.route('/')  #this view is a variable that we initialize above
def index():
   return render_template("index.html")   # it simply return the code written in index.html


@view.route('/profile')
@login_required
def profile():
   return render_template("profile.html",namme = current_user.fullname )  # it simply return the code written in profile.html
   





@view.route("/all")                                                                                         #READ
@login_required
def user_workouts():
    page = request.args.get('page',1,type=int) # for pagination on url it will we shown
    user = User.query.filter_by(email=current_user.email).first_or_404()
    # workouts = user.workouts 
    workouts =  Workout.query.filter_by(author=user).paginate(page=page, per_page=3)  #for pagination on per page there only three
    return render_template('all_workouts.html', workouts=workouts, user=user)




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