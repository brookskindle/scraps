import os

from flask import Flask, render_template_string, render_template, Markup
from flask_flatpages import FlatPages
from flask_flatpages.utils import pygmented_markdown

def my_renderer(text):
    prerendered_body = render_template_string(text)
    #return pygmented_markdown(prerendered_body)  # Fails to use extensions listed in FLATPAGES_MARKDOWN_EXTENSIONS
    return pygmented_markdown(prerendered_body, flatpages=pages)  # Correctly finds and uses FLATPAGES_MARKDOWN_EXTENSIONS

app = Flask(__name__)

@app.route("/")
def index():
    page = pages.get_or_404("sample")
    return render_template("post.html", post=page)

app.config['FLATPAGES_HTML_RENDERER'] = my_renderer
app.config['FLATPAGES_EXTENSION'] = ".md"
app.config['FLATPAGES_MARKDOWN_EXTENSIONS'] = ["extra"]
pages = FlatPages(app)

app.run(port=8000)
