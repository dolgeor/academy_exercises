# README #

### Q/A

* How to format the output of the application? 
  Each taks is going to have a separate description how to output any information on the screen.
  
* Should we go back to initial view when an action is performed / ended? 
  No, we should stay in the each sub console.menu.
  
* Should we do a full match search by order id? 
  Yes, we should do a full match.
  
* Which format of the date should we use? 
  We should use English formating.
  
* Should we use date and time for orders? 
  We should store date and time in the datebase, but the search we should do by date only.

  
#### Prerequisites
 
* Git

* Maven

* Java 8
 
### Running the project with DB in a Docker Container

Steps:

###### Install the core jar in the local maven repository:

From root directory run the following command:

```
$ cd core
$ mvn clean install
```

###### Running the console project:

From root directory run the following command:

```
$ cd console
$ mvn clean package
$ java -jar target/console-1.0-SNAPSHOT.jar 
```

###### Running the web project:

From root directory run the following command:

```
$ cd mvc
$ mvn clean package
```

Then, configure the IDE to run a tomcat server, deploy the generated war (in target) and run tomcat.

Voila, you're set up!

Access the app on the localhost, by typing in browser:

```
localhost:8080/
```
