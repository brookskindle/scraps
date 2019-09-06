// An example of destructuring to provide named parameters
// https://exploringjs.com/impatient-js/ch_callables.html#named-parameters

function positional (a, b, c) {
  console.log(a, b, c)
}

positional()
positional(34, 5)

function destructured ({a=-1, b=0, c=1}) {
  console.log(a, b, c)
}

destructured({a:4, b:12})
destructured({})

function destructuredOptionalParam ({a=-11, b='00', c=11}={}) {
  console.log(a, b, c)
}

destructuredOptionalParam()
destructuredOptionalParam({a: 555})
destructuredOptionalParam({})
destructuredOptionalParam(34)

function destructuredOptional ({a, b, c}={}) {
  console.log(a, b, c)
}

destructuredOptional()
destructuredOptional({c:55})

function positionalDescturture (a, {b=false, c}={b:'hi', c:'hello'}) {
  console.log(a, b, c)
}

positionalDescturture(4)
positionalDescturture(4, {c: 4})
