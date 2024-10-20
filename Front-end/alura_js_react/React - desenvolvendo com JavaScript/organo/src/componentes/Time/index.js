import Colaborador from '../Colaborador'
import './Time.css'

const Time = (props) => {
    let corPrimaria = {backgroundColor:props.corPrimaria}
    let corSecundaria = {borderColor:props.corSecundaria}

    return (
        props.colaboradores.length > 0 &&
        <>
            <section className="time" style={corPrimaria}>
                <h3 style={corSecundaria}>{props.nome}</h3>
                <div className='colaboradores'>
                    {props.colaboradores.map(colaborador => <Colaborador key={colaborador.nome} corDeFundo={props.corSecundaria} nome={colaborador.nome} cargo={colaborador.cargo} imagem={colaborador.imagem}/>)}
                </div>
            </section>
        </>
    )
}

export default Time