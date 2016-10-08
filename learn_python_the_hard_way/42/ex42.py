# Object inheritance!

class Animal(object):
    def __init__(self, name):
        self.name = name

    def say_name(self):
        print "I am an Animal named: %s" % self.name

class Dog(Animal):
    def __init__(self, name):
        super(Dog, self).__init__(name)

    def bark(self):
        print "Woof!"

dog = Dog("Spark")
dog.say_name()
dog.bark()
