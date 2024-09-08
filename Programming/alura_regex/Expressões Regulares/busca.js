const fs = require('fs')
const bancoCsv = 'Diretório do Curso/buscas_csv/database.csv'
const banco = fs.readFileSync(bancoCsv, "utf-8")

const regex = /Anna/

const matchRegex = banco.match(regex)
console.log(matchRegex);