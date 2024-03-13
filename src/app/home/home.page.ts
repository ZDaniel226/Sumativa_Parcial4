import { Component } from '@angular/core';
import { APIServiceService } from './../Services/apiservice.service';
import { Firestore, doc, setDoc, getDoc } from '@angular/fire/firestore';


@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage {

  constructor(private api: APIServiceService, private db: Firestore) {}


  //base de datos

  rutadetabla: any;
  tipoPokemon: string = '';

  numberValue: number = 0;
  cardTitle: string = 'Pokemon Card';
  pokemonImage: string = '';
  types: string = '';
  mainType: string = '';

  updatePokemonData() {
    this.getPokemonDataByID(this.numberValue, false);
  }

  async getPokemonDataByID(id: number, isSearchCard: boolean) {
    try {
      this.api.getPokemonID(id).subscribe((response => {
        const pokemon = response.name;
        const types: string = response.types.map((type: { type: { name: string } }) => type.type.name).join(', ');
        const mainType: string = response.types[0].type.name; // Obtiene el primer tipo como tipo principal

        if (isSearchCard) {
          this.cardTitle = pokemon;
          this.pokemonImage = response.sprites.front_default;
          this.types = types;

        } else {
          this.cardTitle = pokemon;
          this.pokemonImage = response.sprites.front_default;
          this.types = types;
          this.mainType = mainType; // Establece el tipo principal
          this.updateTipoPokemonFirestore(mainType); // Actualiza el tipo de Pokémon en Firestore
        }
      }));
    } catch (error) {
      console.log(error);
    }
  }

  async updateTipoPokemonFirestore(tipo: string) {
    try {
      this.rutadetabla = doc(this.db, 'pokedex', 'pokemon');
      await setDoc(this.rutadetabla, { tipo: tipo }, { merge: true }); // Fusionar los datos para evitar reemplazarlos
      console.log('Tipo de Pokémon enviado a Firestore:', tipo);
    } catch (error) {
      console.error('Error al enviar el tipo de Pokémon a Firestore:', error);
    }
  }

  increment() {
    if (this.numberValue < 100) {
      this.numberValue += 1;
      this.getPokemonDataByID(this.numberValue, false);
    }
  }

  decrement() {
    if (this.numberValue > 0) {
      this.numberValue -= 1;
      this.getPokemonDataByID(this.numberValue, false);
    }
  }

  search() {
    this.getPokemonDataByID(this.numberValue, true);
  }
  typeColors: { [key: string]: string } = {
    "normal": "#A8A77A",
    "fire": "#E62223",
    "water": "#2481F0",
    "electric": "#FAC100",
    "grass": "#3DA224",
    "ice": "#3DD9FF",
    "fighting": "#FF8100",
    "poison": "#913ECB",
    "ground": "#914F1A",
    "flying": "#82BAF0",
    "psychic": "#EF3F7A",
    "bug": "#97A61D",
    "rock": "#AFAA81",
    "ghost": "#6F3F70",
    "dark": "#4E3F3C",
    "dragon": "#4F60E2",
    "steel": "#60A2B9",
    "fairy": "#EF70F0"
  };

  getBackgroundColor(type: string): string {
    const color = this.typeColors[type.toLowerCase()];
    return color ? color : '#f5f5f5'; // Devuelve el color específico o el predeterminado si no se encuentra
  }

  
}
