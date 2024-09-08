const fs = require('fs')
const bancoCsv = 'Diretório do Curso/buscas_csv/database.csv'
const banco = fs.readFileSync(bancoCsv, "utf-8")

const regexTelefone = /\(\d{2}\)\s\d{4}-\d{4}/g

const matchTelefone = banco.match(regexTelefone)
console.log(matchTelefone)

const patternCel = /\(\d{2}\)\s\d{5}-\d{4}/g
const matchCelular = banco.match(patternCel)
console.log(matchCelular)