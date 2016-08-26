title: A sample markdown document

# Greetings!

This is a sample markdown document that also has the ability to use the jinja2
templating engine!
{% for i in range(10) %}
* i = {{i}}
{% endfor %}


That small list was rendered in jinja2, wasn't that cool?

```python
"""
Watch me write sample python code inline
"""
import sys

# I'm a random comment!

def main():
    print(sys.argv)

if __name__ == "__main__":
    main()
```

I can even embed images in markdown

![](https://media.giphy.com/media/H6CW8SL6vgVb2/giphy.gif)

now that's cool!
