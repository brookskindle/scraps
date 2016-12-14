#!/usr/bin/env python

from flask import Flask, jsonify, url_for, abort
app = Flask(__name__)


tasks = [
    {
        "id": 1,
        "title": u"create a flask api thing",
        "description": u"Someone somewhere is doing this, so should I too?",
    },
    {
        "id": 2,
        "title": u"buy books on amazon",
        "description": u"I need to buy instructional books on amazon.",
    },
]

@app.route("/api/v1.0/tasks/", methods=["GET"])
def get_tasks():
    return jsonify({"tasks": tasks})

@app.route("/api/v1.0/tasks/<int:task_id>/")
def get_task(task_id):
    task = [t for t in tasks if t["id"] == task_id]
    if not task:
        abort(404)
    return jsonify({"task": task[0]})


if __name__ == "__main__":
    app.run(debug=True)
