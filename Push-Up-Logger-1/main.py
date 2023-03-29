from website import create_app


app = create_app()

if __name__ == '__main__':
    app.run(debug=True)



# pip install flask
# pip install flask-login
# pip install flask-sqlalchemy
# pip install flask-restful                                 
# pip install pipreqs

# for postgresql
# sudo apt-get install build-dep python-psycopg2
# pip install psycopg2-binary
# pip install python-dotenv

# python include dynamic typing which means that we resign diferernt data type to same variable

# var = 12
# var = "Israr"       but in other langauges except puthon it gives error



# /home/maanz-ai/Desktop/finalyearproject/bjb_fulll/Push-Up-Logger-1/mathpractice_ws




# sudo chmod +x newshellscript.sh               to solve the problem premision denied





# to create your own packages and send it to  your own servers.
















# <form method = "POST" action = "/search"> class = "d-flex">
# <input class = "form-control me-2" type = "search", name = "searched">
# <buttom class = "btn btn-outline-secondary" type = "submit"> Search </button>
# </form>


# @auths.route('/search' , methods =["POST"])
# def search():





#     search.html    search ka bad yeh dat show ho ga       search by name, id, email kuch bi hoskta ha
#     extends base.html
#     <div class="table-responsive" >
#                   <form method="GET"  action="/allclients" >
#                   <table class="table table-hover" style="width: 700px;">
#                     <thead class="thead-dark">
#                       <tr>
#                         <th scope="col"> <a href="{{url_for('view.all_clients')}}"> Id </a></th>
#                         <th scope="col">Email</th>
#                         <th scope="col">Full Name</th>
#                       </tr>
#                     </thead>
#                     <tbody>
                      
#                       {% for i in students %}
#                         <tr>
#                           <td>{{ i.id}}</td>
#                           <td>{{ i.email}}</td>
#                           <td>{{ i.fullname}}</td>
#                         </tr>
#                       {% endfor %}
                
#                       </tbody>
#                     </table>
#                 </form>
#     </div>


# class searchForm(Form):
#     UserName = StringField('Search course', validators=[DataRequired(), Length(max=60)])



# @app.route('/search', methods=['GET', 'POST'])
# def search():
#     searchForm = searchForm()
#     courses = models.User.query

#     if searchForm.validate_on_submit():
#         courses = courses.filter(models.User.fullname.like('%' + searchForm.UserName.data + '%'))

#     courses = courses.order_by(models.User.fullname).all()

#     return render_template('search.html', courses = courses)  
# 
# 
# 
# 
# 
# 
# 
# postgre addition of admin table
# 
# CREATE EXTENSION pgcrypto ;
# SELECT gen_salt('md5') ;
	
# INSERT INTO admin_user(adminid, adminemail, adminpassword, adminfullname)
# VALUES (1, 'admin1@gmail.com', crypt('123456789', gen_salt('md5')),'Israr');  