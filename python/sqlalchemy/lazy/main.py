#!/usr/bin/env python
"""
To be ran in python 3.

This is a sample script that is meant to test the performance of the different
SQLAlchemy relationship loading techniques. If you're not sure what this is,
take a look at
http://docs.sqlalchemy.org/en/rel_1_0/orm/loading_relationships.html
"""

############################################################################
# Database modeling
############################################################################
from sqlalchemy import (
    create_engine, Column, Integer, String, ForeignKey
)
from sqlalchemy.orm import relationship
from sqlalchemy.ext.declarative import declarative_base

engine = create_engine("sqlite:///relationships.db")
Base = declarative_base()


class User(Base):
    __tablename__ = "user"

    id = Column(Integer, primary_key=True)
    name = Column(String)

    posts= relationship("Post", backref="user")
    posts_select = relationship("Post", lazy="select")
    posts_joined = relationship("Post", lazy="joined")
    posts_subquery = relationship("Post", lazy="subquery")
    posts_dynamic = relationship("Post", lazy="dynamic")


class Post(Base):
    __tablename__ = "post"

    id = Column(Integer, primary_key=True)
    content = Column(String(160), unique=False, nullable=False)
    user_id = Column(Integer, ForeignKey("user.id"), nullable=False)



######################################################################
# CLI SUPPORT
######################################################################
import click
from sqlalchemy.orm import sessionmaker
import time

Session = sessionmaker(bind=engine)
session = Session()

@click.group()
def cli():
    pass

@click.command()
@click.option("--name", prompt="Who is posting?", help="Give the user a name")
@click.option("--postcount", prompt="How many times has the user posted?",
            help="Add some number of posts to a specified user")
def seed(name, postcount):
    """
    Seed a database with a number of users and posts.
    """
    postcount = int(postcount)
    click.secho("Now seeding your database!", fg="green")
    user = session.query(User).filter_by(name=name).first()
    if user is None:
        click.secho("User {} not found, will create".format(name), fg="yellow")
        user = User(name=name)
        session.add(user)
        session.commit()
    content = "Hello, name is {}!".format(name)
    [user.posts.append(Post(content=content)) for i in range(postcount)]
    session.add(user)
    session.commit()

@click.command()
def benchmark():
    """
    Runs performance tests against the database.
    """
    user = session.query(User).first()
    name = user.name
    click.secho("Running benchmark against user={}!".format(name), fg="green")
    times = []

    # lazy="select"
    start = time.time()
    user.posts_select
    end = time.time()
    select_time = end - start
    times.append((select_time, 'lazy="select"'))

    # lazy="joined"
    start = time.time()
    user.posts_joined
    end = time.time()
    joined_time = end - start
    times.append((joined_time, 'lazy="joined"'))

    # lazy="subquery"
    start = time.time()
    user.posts_joined
    end = time.time()
    subquery_time = end - start
    times.append((subquery_time, 'lazy="subquery"'))

    # lazy="dynamic"
    start = time.time()
    user.posts_dynamic
    end = time.time()
    dynamic_time = end - start
    times.append((dynamic_time, 'lazy="dynamic"'))

    # Sort and display results
    times.sort(key=lambda t: t[0])
    for result in times:
        click.secho(
            "Benchmark for {}: {}".format(result[1], result[0]),
            fg="yellow"
        )


cli.add_command(seed)
cli.add_command(benchmark)

############################################################################
# Program execution
############################################################################

# Create our tables in the database
Base.metadata.create_all(engine)

if __name__ == "__main__":

    # run program
    cli()

# close the session
session.close()
