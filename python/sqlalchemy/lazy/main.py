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

engine = create_engine("sqlite:///relationships.db", echo=True)
Base = declarative_base()


class User(Base):
    __tablename__ = "user"

    id = Column(Integer, primary_key=True)
    name = Column(String)
    posts = relationship("Post", back_populates="user")


class Post(Base):
    __tablename__ = "post"

    id = Column(Integer, primary_key=True)
    content = Column(String(160), unique=False, nullable=False)
    user_id = Column(Integer, ForeignKey("user.id"), nullable=False)
    user = relationship("User", back_populates="post")


######################################################################
# CLI SUPPORT
######################################################################
import click
from sqlalchemy.orm import sessionmaker

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
        click.secho("User {} not found, will create".format(user), fg="yellow")
        user = User(name=name)
        session.add(user)
        session.commit()

@click.command()
def perform():
    """
    Runs performance tests against the database.
    """
    pass

cli.add_command(seed)
cli.add_command(perform)

############################################################################
# Program execution
############################################################################

if __name__ == "__main__":
    cli()
